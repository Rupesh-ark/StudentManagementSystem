#pragma once
#ifndef PRIMARY_INDEX_H
#define PRIMARY_INDEX_H
#include<string>
#include<fstream>
#include <utility>

class primary_index
{
private:

	std::string usn, address;

public:

	primary_index();
	std::string GetUsn() const;
	std::string GetAddress() const;
	void SetUsn(std::string p_usn);
	void SetAddress(std::string p_address);
};

inline primary_index::primary_index() 
{
	usn = "";
	address = "";
}

inline std::string primary_index::GetUsn() const
{
	return usn;
}

inline std::string primary_index::GetAddress() const
{
	return address;
}

void primary_index::SetUsn(std::string p_usn)
{
	usn = std::move(p_usn);
}

inline void primary_index::SetAddress(std::string p_address)
{
	address = std::move(p_address);
}


#endif
