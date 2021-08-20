#pragma once
#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H
#include "Operations.h"
#include "Student.h"

class StudentManagement
{
private:

public:

	Student student;
	Operations operation;

	std::string Pack()
	{
		std::string variableBuffer;
		variableBuffer += student.GetUsn();
		variableBuffer += "|";
		variableBuffer += student.GetName();
		variableBuffer += "|";
		variableBuffer += student.DateToText(student.GetDOB());
		variableBuffer += "|";
		variableBuffer += student.GenderToText(student.GetGender());
		variableBuffer += "|";
		variableBuffer += student.SemToText(student.GetSem());
		variableBuffer += "|";
		variableBuffer += student.GetPhone();
		variableBuffer += "|";

		return variableBuffer;
	}

	void Unpack(std::fstream stdFile)
	{
	

		std::string leftoverBuffer;

		std::string usn, studentName, textDob, textGender, textSem, phno;

	

		std::getline(stdFile, usn, '|');
		student.SetUSN(usn);

		std::getline(stdFile, studentName, '|');
		student.SetStudentName(studentName);

		std::getline(stdFile, textDob, '|');
		student.SetDob(student.TextToDate(textDob));

		std::getline(stdFile, textGender, '|');
		student.SetGender(student.TextToGender(textGender));

		std::getline(stdFile, textSem, '|');
		student.SetSem(student.TextToSem(textSem));

		std::getline(stdFile, phno, '|');
		student.SetPhone(phno);

		std::getline(stdFile, leftoverBuffer, '\n');

		stdFile.close();
	}

	void Read()
	{
		bool flag = true;
		std::string inputBuffer;
		do {
			if (!flag)
			{
				std::cout << "You entered invalid/duplicate usn, please try again: " << std::endl;
			}
			std::cout << "Please Enter Valid USN: ";
			std::cin >> inputBuffer;
			flag = student.isUSNValid(inputBuffer) && operation.isUSNDuplicate(inputBuffer);
		} while (!flag);

		student.SetUSN(inputBuffer);
		flag = true;
		do {
			if (!flag)
			{
				std::cout << "You entered invalid name, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Name: ";
			std::cin >> inputBuffer;
			flag = student.isNameValid(inputBuffer);
		} while (!flag);

		student.SetStudentName(inputBuffer);
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You entered invalid dob, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid dob(DD/MM/YYYY): ";
			std::cin >> inputBuffer;
			flag = student.isDobValid(student.TextToDate(inputBuffer));
		} while (!flag);

		student.SetDob(student.TextToDate(inputBuffer));
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid gender, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Gender:";
			std::cin >> inputBuffer;
			flag = student.isGenderValid(inputBuffer);
		} while (!flag);

		student.SetGender(student.TextToGender(inputBuffer));
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid semester, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Semester:";
			std::cin >> inputBuffer;
			flag = student.isSemValid(inputBuffer);
		} while (!flag);

		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid phone number, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Phone Number:";
			std::cin >> inputBuffer;
			flag = student.isPhoneValid(inputBuffer);
		} while (!flag);

		student.SetPhone(inputBuffer);

		operation.SetVariableBuffer(Pack());
		operation.DataWrite(student.GetUsn(), student.GetName());
		operation.IndexWrite();
		operation.SIndexWrite();
	}

	void Update()
	{
		int search;
		std::string tempUSN;
		std::list <int> usnPosList;
		std::cout << "\nEnter student id for which you want to update the data: ";
		std::cin >> tempUSN;
		search = operation.Search(tempUSN);
		if (search == -1)
		{
			std::cout << "\nRecord not found";
		}
		else
		{
			int i = 0;
			operation.DeleteModifier(tempUSN, search);
			Read();
		}
		std::cin.get();
	}

	void Display()
	{
		int count = 0;
		int max = operation.GetIndexSize();
		std::fstream stdFile;
		operation.Opener(stdFile, DATADIREC, std::ios::in);
		stdFile.seekg(0, std::ios::beg);

		std::cout << "\n";
		std::cout << std::setw(10) << "USN" << std::setw(15) << "NAME" << std::setw(15) << "DOB" << std::setw(20) << "Gender" << std::setw(15) << "Semester" << std::setw(15) << "Phone" << std::endl;
		while (!stdFile.eof())
		{   
				Unpack();
			if (student.GetUsn()[0] != '$')
			{
				std::cout << std::setw(10) << student.GetUsn() << std::setw(15) << student.GetName() << std::setw(15) << student.DateToText(student.GetDOB()) << std::setw(20) << student.GenderToText(student.GetGender()) << std::setw(15) << student.SemToText(student.GetSem()) << std::setw(15) << student.GetPhone() << std::endl;
				count++;
			}
		}
		stdFile.close();
		std::cin.get();
	}

	void DeleteStudent()
	{
		int flag = false, secondFlag = false;
		std::string studentName;
		std::string studentUSN;
		std::cout << "\nEnter the student name: \t";
		std::cin >> studentName;
		std::cout << "\n" << "\t\t" << "SL.NO." << "\t\t" << std::setw(15) << "USN" << std::setw(15) << "NAME" << std::endl;
		flag = operation.SecondarySearch(studentName);
		if (!flag)
			std::cout << "\nRecord Not Found";

		else
		{
			std::cout << "\nEnter the product number listed above to delete: \t";
			std::cin >> studentUSN;
			secondFlag = operation.Remove(studentUSN, studentName);
			if (secondFlag)
				std::cout << "\n\nRecord deleted sucessfully";
			else
				std::cout << "\n Product number and name does not match";
			operation.IndexWrite();
			operation.SIndexWrite();
		}
		std::cin.get();
	}

	void IndexDisplay(int pos)
	{
		std::fstream tempStdFile;
		operation.Opener(tempStdFile, DATADIREC, std::ios::in);
		tempStdFile.seekg(atoi(operation.GetPrimaryAtPos(pos)->GetAddress().c_str()), std::ios::beg);
		std::cout << "\n\n\n";
		std::cout << std::setw(25) << " " << "DISPLAYING RECORDS\n\n\n";
		Unpack();
		std::string usn = student.GetUsn();
		std::string studentName = student.GetName();
		std::string dob = student.DateToText(student.GetDOB());
		std::string gender = student.GenderToText(student.GetGender());
		std::string sem = student.SemToText(student.GetSem());
		std::string phno = student.GetPhone();

		std::cout << std::setw(20) << " " << " USN  :  " << usn << "\n\n\n";
		std::cout << std::setw(20) << " " << " NAME  :  " << studentName << "\n\n\n";
		std::cout << std::setw(20) << " " << " Dob  :  " << dob << "\n\n\n";
		std::cout << std::setw(20) << " " << " Gender :  " << gender << "\n\n\n";
		std::cout << std::setw(20) << " " << " Sem :  " << sem << "\n\n\n";
		std::cout << std::setw(20) << " " << " Phone :  " << phno << "\n\n\n";

		tempStdFile.clear();
		tempStdFile.close();
	}

	void Indexing()
	{
		int searchPos;
		std::string tempKey;
		std::cout << "\n\n\n Enter the primary key: \t";
		std::cin >> tempKey;
		searchPos = operation.Search(tempKey);
		if (searchPos != -1)
		{
			IndexDisplay(searchPos);
			std::cout << "\n\n Sucessfull search: ";
		}
		else
		{
			std::cout << "\n Record Not Found";
		}
		std::cin.get();
	}

	void SecondaryIndexing()
	{
		bool flag;
		std::string studentName;
		std::cout << "\nEnter the student name: \t";
		std::cin >> studentName;
		flag = operation.SecondarySearch(studentName);
		if (!flag)
			std::cout << "\nRecord not found!";

		std::cin.get();
	}

	void InvertedList()
	{
		bool flag = false;
		std::string tempStudentName;
		std::cout << "\n\t\tInverted List\n";
		std::cout << "\n\n\tENTER THE PRODUCT NAME TO SEARCH :\t";
		std::cin >> tempStudentName;
		flag = operation.SecondaryIndexList(tempStudentName);
		if (!flag)
			std::cout << "\nNo records found";
		else
			Indexing();
	}
};

#endif