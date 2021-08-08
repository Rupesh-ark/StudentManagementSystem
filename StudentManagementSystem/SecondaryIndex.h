#pragma once
#ifndef SECONDARYINDEX_H
#define SECONDARYINDEX_H
#include<string>

class SecondaryIndex
{
private:
	std::string studentName, studentUsn;
public:
	SecondaryIndex();
	~SecondaryIndex();
	std::string GetStudentName();
	std::string GetStudentUsn();
	void SetStudentName(std::string);
	void SetStudentUsn(std::string);
};

SecondaryIndex::SecondaryIndex()
{
	studentName = "";
	studentUsn = "";
}
SecondaryIndex::~SecondaryIndex()
{
}
std::string SecondaryIndex::GetStudentName()
{
	return studentName;
}
std::string SecondaryIndex::GetStudentUsn()
{
	return studentUsn;
}

void SecondaryIndex::SetStudentName(std::string pStudentName)
{
	studentName = pStudentName;
}

void SecondaryIndex::SetStudentUsn(std::string pStudentUsn)
{
	studentUsn = pStudentUsn;
}

#endif