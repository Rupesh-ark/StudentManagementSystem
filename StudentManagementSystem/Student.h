#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<fstream>
#include<stdlib.h>
#include<string>

enum class Gender
{
	Male,
	Female,
	Others,
	NotSet
};

enum class Sem
{
	First,
	Second,
	Third,
	Fourth,
	Fifth,
	Sixth,
	Seventh,
	Eight,
	NotSet
};

struct Date
{
	int Day;
	int Month;
	int Year;
};

class Student
{
private:

	std::string usn, studentName, phno;
	Date dob;
	Gender gender;
	Sem sem;

public:

	Student()
	{
		usn = "";
		studentName = "";
		dob.Day = 0;
		dob.Month = 0;
		dob.Year = 0;
		gender = Gender::NotSet;
		Sem sem = Sem::NotSet;
		phno = "";
	}

	Student(std::string pUsn, std::string pStudentName, Date pDob, Gender pGender, Sem pSem, std::string pPhno)
	{
		usn = pUsn;
		studentName = pStudentName;
		dob.Day = pDob.Day;
		dob.Month = pDob.Month;
		dob.Year = pDob.Year;
		gender = pGender;
		sem = pSem;
		phno = pPhno;
	}

	std::string GetUsn()
	{
		return usn;
	}

	std::string GetName()
	{
		return studentName;
	}
	
	void SetUSN(std::string pUsn)
	{
		usn = pUsn;
	}

	void SetStudentName(std::string pStudentName)
	{
		studentName = pStudentName;
	}

	void SetDob(Date pDob)
	{
		dob = pDob;
	}

	void SetGender(Gender pGender)
	{
		gender = pGender;
	}

	void SetSem(Sem pSem)
	{
		sem = pSem;
	}

	void SetPhone(std::string pPhno)
	{
		phno = pPhno;
	}

	std::string DateToText(Date pDate)
	{
		std::string dateText = "";
		dateText += std::to_string(pDate.Day);
		dateText += '/';
		dateText += std::to_string(pDate.Month);
		dateText += '/';
		dateText += std::to_string(pDate.Year);

		return dateText;
	}

	std::string GenderToText(Gender gender)
	{
		switch (gender)
		{
		case Gender::Male:
			return "Male";
		case Gender::Female:
			return "Female";
		case Gender::Others:
			return "Others";
		case Gender::NotSet:
			return "NotSet";
		default:
			break;
		}
	}

	std::string SemToText(Sem sem)
	{
		switch (sem)
		{
		case Sem::First:
			return "First";
		case Sem::Second:
			return "Second";
		case Sem::Third:
			return "Third";
		case Sem::Fourth:
			return "Fourth";
		case Sem::Fifth:
			return "Fifth";
		case Sem::Sixth:
			return "Sixth";
		case Sem::Seventh:
			return "Seventh";
		case Sem::Eight:
			return "Eight";
		case Sem::NotSet:
			return "Not Set";
		default:
			break;
		}
	}

	Date TextToDate(std::string pTextDate)
	{
		Date date;
		int j = 0, i = 0;

		char day[3], month[3], year[5];

		for (i = 0; i < 2; i++)
		{
			day[i] = pTextDate[j];
			j++;
		}
		day[i] = '\0';
		j++;
		
		for (i = 0; i < 2; i++)
		{
			month[i] = pTextDate[j];
			j++;
		}
		j++;
		month[i] = '\0';
	
		for (i = 0; i < 4; i++)
		{
			year[i] = pTextDate[j];
			j++;
		}
		year[j] = '\0';
	
		date.Day = std::atoi(day);
		date.Month = std::atoi(month);
		date.Year = std::atoi(year);

		return date;
		
	}

	Sem TextToSem(std::string pTextSem)
	{		
		if ((pTextSem == "First") || (pTextSem == "first"))
			return Sem::First;
		else if ((pTextSem == "Second") || (pTextSem == "second"))
			return Sem::Second;
		else if ((pTextSem == "Third") || (pTextSem == "third"))
			return Sem::Third;
		else if ((pTextSem == "Fourth") || (pTextSem == "fourth"))
			return Sem::Fourth;
		else if ((pTextSem == "Fifth") || (pTextSem == "fifth"))
			return Sem::Fifth;
		else if ((pTextSem == "Sixth") || (pTextSem == "sixth"))
			return Sem::Sixth;
		else if ((pTextSem == "Seventh")||(pTextSem == "seventh"))
			return Sem::Seventh;
		else if ((pTextSem == "Eight")||(pTextSem == "eight"))
			return Sem::Eight;
		else
			return Sem::NotSet;
	}

	Gender TextToGender(std::string gender)
	{
		if ((gender == "Male") || (gender == "male"))
			return Gender::Male;
		else if (gender == "Female" || gender == "female")
			return Gender::Female;
		else if (gender == "Others" || gender == "others")
			return Gender::Others;
		else
			return Gender::NotSet;
	}

	bool isUSNValid(std::string studentUSN)
	{
		int search, i, count = 0;

		for (i = 0; studentUSN[i] != '\0'; i++)
		{
			count++;
			if (!isalpha(studentUSN[i]) || !isdigit(studentUSN[i] != 0))
			{
				return false;
			}
		}

		if (studentUSN.size() > 10)
			return false;
	}


	bool isNameValid(std::string studentName)
	{
		int i = 0;
		for (i = 0; studentName[i] != '\0'; i++)
		{
			if (!isalpha(studentName[i]))
			{
				return false;
			}
		}
	}

	bool isPhoneValid(std::string phno)
	{
		int i;

		for (i = 0; phno[i] != '\0'; i++)
		{
			if (!isdigit(phno[i]))
			{
				return false;
			}
		}
		if (phno.size() > 10)
			return false;
	}

	bool isDobValid(Date date)
	{

		if (date.Day > 31 || date.Day <= 0)
			return false;
		if (date.Month > 12 || date.Month <=0)
			return false;
		if (date.Year < 1970 || date.Year >= 2005)
			return false;
		else
			return true;
	}

	bool isGenderValid(std::string gender)
	{
		Gender gen;
		gen = TextToGender(gender);

		if (gen == Gender::NotSet)
			return false;
		else
			return true;
	}

	bool isSemValid(std::string semester)
	{
		Sem sem;
		sem = TextToSem(semester);
		if (sem == Sem::NotSet)
			return false;
		else
			return true;
	}

	void Read()
	{
		bool flag = false;
		std::string inputBuffer;
		do {

			if (!flag)
			{
				std::cout << "You entered invalid/duplicate usn, please try again."<<std::endl;
			}
			std::cout << "Please Enter Valid USN: ";
			std::cin >> inputBuffer;
			flag = isUSNValid(inputBuffer);
		} while (!flag);

		SetUSN(inputBuffer);
		flag = true;
		do {

			if (!flag)
			{
				std::cout << "You entered invalid name, please try again."<< std::endl;
			}
			std::cout << "Please Enter Valid Name: ";
			std::cin >> inputBuffer;
			flag = isNameValid(inputBuffer);
		} while (!flag);

		SetStudentName(inputBuffer);
		flag = true;
		
		do {

			if (!flag)
			{
				std::cout << "You entered invalid dob, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid dob(DD/MM/YYYY): ";
			std::cin >> inputBuffer;
			flag = isDobValid(TextToDate(inputBuffer));
		} while (!flag);

		SetDob(TextToDate(inputBuffer));
		flag = true;
		
		do {
			
			if (!flag)
			{
				std::cout << "You have entered invalid gender, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Gender:";
			std::cin >> inputBuffer;
			flag = isGenderValid(inputBuffer);
		} while (!flag);

		SetGender(TextToGender(inputBuffer));
		flag = true;

		do {
			if (!flag)
			{
				std::cout << "You have entered invalid semester, please try again." << std::endl;
			}
			std::cout << "Please Enter Valid Semester:";
			std::cin >> inputBuffer;
			flag = isSemValid(inputBuffer);
		} while (!flag);

	}


	void Pack(std::string variableBuffer)
	{


		variableBuffer += usn; 
		variableBuffer += "|";
		variableBuffer += studentName;
		variableBuffer += "|";
		variableBuffer += DateToText(dob);
		variableBuffer += "|";
		variableBuffer += GenderToText(gender);
		variableBuffer += "|";
		variableBuffer += SemToText(sem);
		variableBuffer += "|";
		variableBuffer += phno;
		variableBuffer += "|";

	
	}
	
	void Unpack(std::fstream& stdfile)
	{
		char leftoverBuffer[62];

		std::string textDob, textGender, textSem;

		std::getline(stdfile, usn, '|');
		std::getline(stdfile, studentName, '|');
		std::getline(stdfile, textDob, '|');

		dob = TextToDate(textDob);
		std::getline(stdfile, textGender, '|');

		gender = TextToGender(textGender);
		std::getline(stdfile, textSem, '|');

		sem = TextToSem(textSem);
		std::getline(stdfile, phno, '|');

		stdfile.getline(leftoverBuffer, 62, '\n');
		
	}
	
	~Student()
	{
		
	}

};

#endif