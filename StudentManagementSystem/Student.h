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

	//char usn[11], studentName[22], dob[11], gender[7], sem[2], phNo[11];

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
		if (pTextSem == "First")
			return Sem::First;
		else if (pTextSem == "Second")
			return Sem::Second;
		else if (pTextSem == "Third")
			return Sem::Third;
		else if (pTextSem == "Fourth")
			return Sem::Fourth;
		else if (pTextSem == "Fifth")
			return Sem::Fifth;
		else if (pTextSem == "Sixth")
			return Sem::Sixth;
		else if (pTextSem == "Seventh")
			return Sem::Seventh;
		else if (pTextSem == "Eight")
			return Sem::Eight;
		else
			return Sem::NotSet;
	}

	Gender TextToGender(std::string gender)
	{
		if (gender == "Male")
			return Gender::Male;
		else if (gender == "Female")
			return Gender::Female;
		else if (gender == "Others")
			return Gender::Others;
		else
			return Gender::NotSet;
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

		/*strcat(variableBuffer, "|");
		strcat(variableBuffer, studentName); strcat(variableBuffer, "|");

		strcat(variableBuffer, dob); strcat(variableBuffer, "|");
		
		strcat(variableBuffer, gender); strcat(variableBuffer, "|");
		
		strcat(variableBuffer, sem); strcat(variableBuffer, "|");
		strcat(variableBuffer, phNo); strcat(variableBuffer, "|");*/
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

	/*	stdfile.getline(usn, 11, '|');
		stdfile.getline(studentName, 22, '|');

		stdfile.getline(dob, 11, '|');
		
		stdfile.getline(gender, 7, '|');
		
		stdfile.getline(sem, 2, '|');
		stdfile.getline(phNo, 11, '|');*/
		
	}
	
	~Student()
	{
		
	}


};

#endif