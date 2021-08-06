#pragma once
#ifndef PRIMARYINDEX_H
#define PRIMARYINDEX_H
#include<string>
#include<fstream>

class PrimaryIndex
{
private:
	
	std::string usn, address;

public:

	PrimaryIndex();
	~PrimaryIndex();
	std::string GetUsn();
	std::string GetAddress();
	void SetUsn(std::string usn);
	void SetAddress(std::string usn);

};

PrimaryIndex::PrimaryIndex()
{

	usn = "";
	address = "";

}

std::string PrimaryIndex::GetUsn()
{
	return usn;
}

std::string PrimaryIndex::GetAddress()
{
	return address;
}

void PrimaryIndex::SetUsn(std::string pUsn)
{
	usn = pUsn;
}

void PrimaryIndex::SetAddress(std::string pAddress)
{
	address = pAddress;
}



PrimaryIndex::~PrimaryIndex()
{


}





#endif