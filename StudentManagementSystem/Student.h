#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<fstream>
class Student
{
private:

	char usn[11], studentName[20], dob[20], gender[6], sem[2], phNo[11];
public:

	Student()
	{
		strcpy(usn, "");
		strcpy(studentName, "");
		strcpy(dob, "");
		strcpy(gender, "");
		strcpy(sem, "0");
		strcpy(phNo, "");
	}

	Student(char* pUsn, char* pStudentName, char* pDob, char* pGender, char* pSem, char* pPhno)
	{
		strcpy(usn, pUsn);
		strcpy(studentName, pStudentName);
		strcpy(dob, pDob);
		strcpy(gender, pGender);
		strcpy(sem, pSem);
		strcpy(phNo, pPhno);
	}

	char* GetUsn()
	{
		return usn;
	}

	char* GetName()
	{
		return studentName;
	}
	
	void SetUSN(char* pUsn)
	{
		strcpy(usn, pUsn);
	}

	void SetStudentName(char* pStudentName)
	{
		strcpy(studentName, pStudentName);
	}

	void SetDob(char* pDob)
	{
		strcpy(dob, pDob);
	}

	void SetGender(char* pGender)
	{
		strcpy(gender,pGender);
	}

	void SetSem(char* pSem)
	{
		strcpy(sem,pSem);
	}

	void SetPhone(char* pPhno)
	{
		strcpy(phNo, pPhno);
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
	
	~Student()
	{
		
	}


};

#endif