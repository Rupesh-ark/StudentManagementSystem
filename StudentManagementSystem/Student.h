#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include <utility>

enum class gender
{
	male,
	female,
	others,
	not_set
};

enum class semester
{
	first,
	second,
	third,
	fourth,
	fifth,
	sixth,
	seventh,
	eight,
	not_set
};

struct date
{
	int day;
	int month;
	int year;
};

class student
{
private:

	std::string usn_, student_name_, phone_number_;
	date dob_{};
	gender gen_;
	semester sem_;

public:

	student()
	{
		usn_ = "";
		student_name_ = "";
		dob_.day = 0;
		dob_.month = 0;
		dob_.year = 0;
		gen_ = gender::not_set;
		sem_ = semester::not_set;
		phone_number_ = "";
	}

	student(std::string p_usn, std::string p_student_name, const date p_dob, const gender p_gender, const semester p_sem, std::string p_phone_number)
	{
		usn_ = std::move(p_usn);
		student_name_ = std::move(p_student_name);
		dob_.day = p_dob.day;
		dob_.month = p_dob.month;
		dob_.year = p_dob.year;
		gen_ = p_gender;
		sem_ = p_sem;
		phone_number_ = std::move(p_phone_number);
	}

	std::string get_usn() const
	{
		return usn_;
	}

	std::string get_name() const
	{
		return student_name_;
	}

	date get_dob() const
	{
		return dob_;
	}

	gender get_gender() const
	{
		return gen_;
	}

	semester get_sem() const
	{
		return sem_;
	}

	std::string GetPhone() const
	{
		return phone_number_;
	}

	void set_usn(std::string pUsn)
	{
		usn_ = std::move(pUsn);
	}

	void set_student_name(std::string pStudentName)
	{
		student_name_ = std::move(pStudentName);
	}

	void set_dob(date pDob)
	{
		dob_ = pDob;
	}

	void set_gender(gender pGender)
	{
		gen_ = pGender;
	}

	void set_sem(semester pSem)
	{
		sem_ = pSem;
	}

	void set_phone(std::string pPhno)
	{
		phone_number_ = std::move(pPhno);
	}

	std::string date_to_text(date pDate) const
	{
		std::string date_text = "";
		if (pDate.day < 9)
			date_text += "0";
		date_text += std::to_string(pDate.day);
		date_text += '/';
		if (pDate.month < 9)
			date_text += "0";
		date_text += std::to_string(pDate.month);
		date_text += '/';
		date_text += std::to_string(pDate.year);

		return date_text;
	}

	static std::string gender_to_text(const gender gen)
	{
		switch (gen)
		{
		case gender::male:
			return "male";
		case gender::female:
			return "female";
		case gender::others:
			return "others";
		case gender::not_set:
			return "not_set";
		default:
			return "";
		}
	}

	static std::string sem_to_text(const semester sem)
	{
		switch (sem)
		{
		case semester::first:
			return "first";
		case semester::second:
			return "second";
		case semester::third:
			return "third";
		case semester::fourth:
			return "fourth";
		case semester::fifth:
			return "fifth";
		case semester::sixth:
			return "sixth";
		case semester::seventh:
			return "seventh";
		case semester::eight:
			return "eight";
		case semester::not_set:
			return "Not Set";
		default:
			return "";
		}
	}

	static date text_to_date(const std::string& p_text_date)
	{
		date date_to_convert{};

		std::string day, month, year;

		day = p_text_date.substr(0, 2);
		month = p_text_date.substr(3, 5);
		year = p_text_date.substr(6, 9);

		date_to_convert.day = std::atoi(day.c_str());
		date_to_convert.month = std::atoi(month.c_str());
		date_to_convert.year = std::atoi(year.c_str());
		return date_to_convert;
	}

	static semester text_to_sem(const std::string& pTextSem)
	{
		if ((pTextSem == "first") || (pTextSem == "First"))
			return semester::first;
		if ((pTextSem == "second") || (pTextSem == "Second"))
			return semester::second;
		if ((pTextSem == "third") || (pTextSem == "Third"))
			return semester::third;
		if ((pTextSem == "fourth") || (pTextSem == "Fourth"))
			return semester::fourth;
		if ((pTextSem == "fifth") || (pTextSem == "Fifth"))
			return semester::fifth;
		if ((pTextSem == "sixth") || (pTextSem == "Sixth"))
			return semester::sixth;
		if ((pTextSem == "seventh") || (pTextSem == "Seventh"))
			return semester::seventh;
		if ((pTextSem == "eight") || (pTextSem == "Eight"))
			return semester::eight;
		return {};
	}

	static gender TextToGender(const std::string& gender)
	{
		if ((gender == "male") || (gender == "Male"))
			return gender::male;
		else if (gender == "female" || gender == "Female")
			return gender::female;
		else if (gender == "others" || gender == "Others")
			return gender::others;
		else
			return gender::not_set;
	}

	static bool isUSNValid(std::string studentUSN)
	{
		for (int i = 0; studentUSN[i] != '\0'; i++)
		{
			if (!isalpha(studentUSN[i]) && !isdigit(studentUSN[i]))
			{
				return false;
			}
		}

		if (studentUSN.size() != 10)
			return false;
		else
			return true;
	}

	static bool isNameValid(std::string studentName)
	{
		for (int i = 0; studentName[i] != '\0'; i++)
		{
			if (!isalpha(studentName[i]))
			{
				return false;
			}
		}
		return true;
	}

	static bool isPhoneValid(std::string phno)
	{
		for (int i = 0; phno[i] != '\0'; i++)
		{
			if (!isdigit(phno[i]))
			{
				return false;
			}
		}
		if (phno.size() > 10)
			return false;
		else
			return true;
	}

	static bool isDobValid(date date)
	{
		if (date.day > 31 || date.day <= 0)
			return false;
		if (date.month > 12 || date.month <= 0)
			return false;
		if (date.year < 1970 || date.year >= 2005)
			return false;
		return true;
	}

	static bool is_gender_valid(const std::string& p_gender)
	{
		const gender gen = TextToGender(p_gender);

		if (gen == gender::not_set)
			return false;
		return true;
	}

	static bool is_sem_valid(const std::string& p_semester)
	{
		const semester sem = text_to_sem(p_semester);
		if (sem == semester::not_set)
			return false;
		else
			return true;
	}
};
#endif