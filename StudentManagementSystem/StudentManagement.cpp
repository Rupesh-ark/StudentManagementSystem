#include"Operations.h"

class StudentManagement
{
private:

	char usn[11], studentName[20], dob[20], gender[6], phNo[11];
	char sem[2];
	Operations operations;
public:

	StudentManagement()
	{
		strcpy(usn, "");
		strcpy(studentName, "");
		strcpy(dob, "");
		strcpy(gender, "");
		strcpy(sem, "0");
		strcpy(phNo, "");
	}

	void StudentInput()
	{
		int k, value, flag;
		//StudentManagement a;

		std::cout << "\n\tEnter the USN :";
		std::cin >> usn;
		flag = operations.IsValid(usn, VariableType::usn);
		if (!flag) {
			StudentInput();
		}

		std::cout << "\n\tEnter the Student name    :";
		std::cin >> studentName;
		flag = operations.IsValid(studentName, VariableType::name);
		if (!flag) {
			std::cout << "Student Name accept only characters" << std::endl;
			std::cout << "\n\tEnter the Student name    :";
			std::cin >> studentName;
		}
		std::cout << "\n\tEnter the Sex :";
		std::cin >> gender;
		flag = operations.IsValid(gender, VariableType::gender);
		if (!flag) {
			std::cout << "Sex accept only characters upto a certain length" << std::endl;
			std::cout << "\n\tEnter the sex :";
			std::cin >> gender;
		}
		std::cout << "\n\tEnter the date of birth:";
		std::cin >> dob;
		flag = operations.IsValid(dob, VariableType::dob);
		if (!flag) {
			std::cout << "Date of Birth accept only characters and / symbol" << std::endl;
			std::cout << "\n\tEnter the Date of Birth:";
			std::cin >> dob;
		}
		std::cout << "\n\tEnter the Phone number  :";
		std::cin >> phNo;
		flag = operations.IsValid(phNo, VariableType::phNo);
		if (!flag) {
			std::cout << "Phone number accept only numbers" << std::endl;
			std::cout << "\n\tEnter the Phone number  :";
			std::cin >> phNo;
		}
		std::cout << "\n\tEnter the sem  :";
		std::cin >> sem;
		flag = operations.IsValid(sem, VariableType::sem);
		if (!flag) {
			std::cout << "\n\tEnter the sem  :";
			std::cin >> sem;
		}
	}
	void StudentDisplay()
	{
	}

	void Pack(char* variableBuffer)
	{
		strcpy(variableBuffer, usn); strcat(variableBuffer, "|");
		strcat(variableBuffer, studentName); strcat(variableBuffer, "|");
		strcat(variableBuffer, dob); strcat(variableBuffer, "|");
		strcat(variableBuffer, gender); strcat(variableBuffer, "|");
		strcat(variableBuffer, sem); strcat(variableBuffer, "|");
		strcat(variableBuffer, phNo); strcat(variableBuffer, "|");
	}
	void Unpack(std::fstream& stdfile)
	{
		char leftoverBuffer[70];
		stdfile.getline(usn, 11, '|');
		stdfile.getline(studentName, 20, '|');
		stdfile.getline(dob, 20, '|');
		stdfile.getline(gender, 6, '|');
		stdfile.getline(sem, 2, '|');
		stdfile.getline(phNo, 11, '|');
		stdfile.getline(leftoverBuffer, 70, '\n');
	}

	~StudentManagement()
	{
		std::cout << "Instance Deleted";
	}


};