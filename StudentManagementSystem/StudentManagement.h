#pragma once
#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H
#include "operations.h"
#include "Student.h"

class student_management
{
private:
	std::fstream stdFile;
public:

	student student;
	operations operation;

	std::string Pack() const
	{
		std::string variableBuffer;
		variableBuffer += student.get_usn();
		variableBuffer += "|";
		variableBuffer += student.get_name();
		variableBuffer += "|";
		variableBuffer += student.date_to_text(student.get_dob());
		variableBuffer += "|";
		variableBuffer += student::gender_to_text(student.get_gender());
		variableBuffer += "|";
		variableBuffer += student::sem_to_text(student.get_sem());
		variableBuffer += "|";
		variableBuffer += student.GetPhone();
		variableBuffer += "|";

		return variableBuffer;
	}

	void Unpack()
	{
		std::string leftoverBuffer;
		std::string usn, studentName, textDob, textGender, textSem, phno;

		std::getline(stdFile, usn, '|');
		student.set_usn(usn);

		std::getline(stdFile, studentName, '|');
		student.set_student_name(studentName);

		std::getline(stdFile, textDob, '|');
		student.set_dob(student::text_to_date(textDob));

		std::getline(stdFile, textGender, '|');
		student.set_gender(student::TextToGender(textGender));

		std::getline(stdFile, textSem, '|');
		student.set_sem(student::text_to_sem(textSem));

		std::getline(stdFile, phno, '|');
		student.set_phone(phno);

		//	std::getline(stdFile, leftoverBuffer, '\n');
	}

	void read()
	{
		bool flag = true;
		std::string inputBuffer;
		do {
			if (!flag)
			{
				std::cout << "You entered invalid/duplicate usn_, please try again: " << std::endl;
			}
			std::cout << "Please Enter Valid USN: ";
			std::cin >> inputBuffer;
			flag = student::isUSNValid(inputBuffer) && operation.is_usn_duplicate(inputBuffer);
		} while (!flag);

		student.set_usn(inputBuffer);
		flag = true;
		do {
			if (!flag)
			{
				std::cout << "You entered invalid name, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Name: ";
			std::cin >> inputBuffer;
			flag = student::isNameValid(inputBuffer);
		} while (!flag);

		student.set_student_name(inputBuffer);
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You entered invalid dob, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid dob(DD/MM/YYYY): ";
			std::cin >> inputBuffer;
			flag = student::isDobValid(student::text_to_date(inputBuffer));
		} while (!flag);

		student.set_dob(student::text_to_date(inputBuffer));
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid gen, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Gender:";
			std::cin >> inputBuffer;
			flag = student.is_gender_valid(inputBuffer);
		} while (!flag);

		student.set_gender(student::TextToGender(inputBuffer));
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid semester, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Semester:";
			std::cin >> inputBuffer;
			flag = student.is_sem_valid(inputBuffer);
		} while (!flag);

		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid phone number, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Phone Number:";
			std::cin >> inputBuffer;
			flag = student::isPhoneValid(inputBuffer);
		} while (!flag);

		student.set_phone(inputBuffer);

		operation.set_variable_buffer(Pack());
		operation.DataWrite(student.get_usn(), student.get_name());
		operation.index_write();
		operation.s_index_write();
	}

	void update()
	{
		std::string tempUSN;
		std::list <int> usnPosList;
		std::cout << "\nEnter student id for which you want to update the data: ";
		std::cin >> tempUSN;
		const int search = operation.search(tempUSN);
		if (search == -1)
		{
			std::cout << "\nRecord not found";
		}
		else
		{
			operation.DeleteModifier(tempUSN, search);
			read();
		}
		std::cin.get();
	}

	void display()
	{
		int count = 0;
		int max = operation.GetIndexSize();
		operations::opener(stdFile, data_directory, std::ios::in);
		stdFile.seekg(0, std::ios::beg);

		std::cout << "\n";
		std::cout << std::setw(10) << "USN" << std::setw(15) << "NAME" << std::setw(15) << "DOB" << std::setw(20) << "Gender" << std::setw(15) << "Semester" << std::setw(15) << "Phone" << std::endl;
		while (!stdFile.eof())
		{
			Unpack();
			if (student.get_usn()[0] != '$')
			{
				std::cout << std::setw(10) << student.get_usn() << std::setw(15) << student.get_name() << std::setw(15) << student.date_to_text(student.get_dob()) << std::setw(20) <<
					student::gender_to_text(student.get_gender()) << std::setw(15) << student::sem_to_text(student.get_sem()) << std::setw(15) << student.GetPhone() << std::endl;
				count++;
			}
		}
		stdFile.close();
		std::cin.get();
	}

	void delete_student()
	{
		std::string studentName;
		std::string studentUSN;
		std::cout << "\nEnter the student name: \t";
		std::cin >> studentName;
		std::cout << "\n" << "\t\t" << "SL.NO." << "\t\t" << std::setw(15) << "USN" << std::setw(15) << "NAME" << std::endl;
		const int flag = operation.secondary_search(studentName);
		if (!flag)
			std::cout << "\nRecord Not Found";

		else
		{
			std::cout << "\nEnter the product number listed above to delete: \t";
			std::cin >> studentUSN;
			const int secondFlag = operation.remove(studentUSN, studentName);
			if (secondFlag)
				std::cout << "\n\nRecord deleted Successfully";
			else
				std::cout << "\n Product number and name does not match";
			operation.index_write();
			operation.s_index_write();
		}
		std::cin.get();
	}

	void index_display(int pos)
	{
		std::fstream temp_std_file;
		operations::opener(temp_std_file, data_directory, std::ios::in);
		temp_std_file.seekg(atoi(operation.get_primary_at_pos(pos)->GetAddress().c_str()), std::ios::beg);
		std::cout << "\n\n\n";
		std::cout << std::setw(25) << " " << "DISPLAYING RECORDS\n\n\n";
		Unpack();
		std::string usn = student.get_usn();
		std::string studentName = student.get_name();
		std::string dob = student.date_to_text(student.get_dob());
		std::string gender = student::gender_to_text(student.get_gender());
		std::string sem = student::sem_to_text(student.get_sem());
		std::string phone_number = student.GetPhone();

		std::cout << std::setw(20) << " " << " USN  :  " << usn << "\n\n\n";
		std::cout << std::setw(20) << " " << " NAME  :  " << studentName << "\n\n\n";
		std::cout << std::setw(20) << " " << " Dob  :  " << dob << "\n\n\n";
		std::cout << std::setw(20) << " " << " Gender :  " << gender << "\n\n\n";
		std::cout << std::setw(20) << " " << " Sem :  " << sem << "\n\n\n";
		std::cout << std::setw(20) << " " << " Phone :  " << phone_number << "\n\n\n";

		temp_std_file.clear();
		temp_std_file.close();
	}

	void indexing()
	{
		std::string temp_key;
		std::cout << "\n\n\n Enter the primary key: \t";
		std::cin >> temp_key;
		const int search_pos = operation.search(temp_key);
		if (search_pos != -1)
		{
			index_display(search_pos);
			std::cout << "\n\n Successful search: ";
		}
		else
		{
			std::cout << "\n Record Not Found";
		}
		std::cin.get();
	}

	void secondary_indexing()
	{
		std::string studentName;
		std::cout << "\nEnter the student name: \t";
		std::cin >> studentName;
		const bool flag = operation.secondary_search(studentName);
		if (!flag)
			std::cout << "\nRecord not found!";

		std::cin.get();
	}

	void inverted_list()
	{
		std::string tempStudentName;
		std::cout << "\n\t\tInverted List\n";
		std::cout << "\n\n\tENTER THE PRODUCT NAME TO SEARCH :\t";
		std::cin >> tempStudentName;
		const bool flag = operation.secondary_index_list(tempStudentName);
		if (!flag)
			std::cout << "\nNo records found";
		else
			indexing();
	}
};

#endif