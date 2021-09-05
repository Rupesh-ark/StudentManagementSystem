#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H
constexpr auto index_directory = "index.txt";
constexpr auto secondary_index_directory = "sIndex.txt";											
constexpr auto data_directory = "data.txt";
constexpr auto usn_std = 10;
constexpr auto phn_std = 10;
constexpr auto sem_one = 49;
constexpr auto sem_eight = 56;
constexpr auto max_indices = 50;
#include<iomanip>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<string>
#include<fstream>
#include<list>
#include <utility>
#include"primary_index.h"
#include "secondary_index.h"

class operations
{
private:

	std::fstream stdFile, indexFile, sIndexFile;
	primary_index primary[max_indices];
	secondary_index secondary[max_indices];
	std::string variableBuffer;
	int indexSize, sIndexSize;

public:

	operations()
	{
		indexSize = 0;
		sIndexSize = 0;
		variableBuffer = "";
	}

	primary_index* get_primary_at_pos(const int pos)
	{
		primary_index* primaryPointer = &primary[pos];
		return primaryPointer;
	}

	int GetIndexSize() const
	{
		return indexSize;
	}

	int get_secondary_index_size() const
	{
		return sIndexSize;
	}

	void set_variable_buffer(std::string p_variable_buffer)
	{
		variableBuffer = std::move(p_variable_buffer);
	}

	std::string get_variable_buffer() const
	{
		return variableBuffer;
	}

	static bool opener(std::fstream& file, const char* fileName, int mode)
	{
		file.open(fileName, mode);
		if (!file)
			return false;

		else
			return true;
	}

	int search(const std::string& fid) const
	{
		int low = 0, high = indexSize - 1;
		
		while (low <= high)
		{
			const int middle = (low + high) / 2;
			if (fid == primary[middle].GetUsn())
				return  middle;
			else if (fid > primary[middle].GetUsn())
				low = middle + 1;
			else
				high = middle - 1;
		}
		return -1;
	}

	bool remove(const std::string& usn, const std::string& secondary_key)
	{
		int secondary_position = 0, i;
		std::string temp_address;

		for (i = 0; i < sIndexSize; i++)
		{
			if (primary[i].GetUsn() == usn)
			{
				secondary_position = i;
				break;
			}
		}
		if (secondary[secondary_position].get_student_name() == secondary_key)
		{
			const int position = search(usn);
			stdFile.seekp(atoi(primary[position].GetAddress().c_str()), std::ios::beg);
			stdFile.put('$');
			for (i = position; i < indexSize; i++)
				primary[i] = primary[i + 1];
			indexSize--;
			for (i = secondary_position; i < sIndexSize; i++)
				secondary[i] = secondary[i + 1];
			sIndexSize--;
			return true;
		}
		else
			return false;
	}

	bool secondary_index_list(const std::string& student_name)
	{
		bool flag = false;
		std::cout << "\n\t\t" << student_name << ":";
		const bool open = opener(sIndexFile, secondary_index_directory, std::ios::in);
		if (open)
		{
			for (int j = 0; j < sIndexSize; j++)
			{
				if (student_name == secondary[j].get_student_name())
				{
					std::cout << secondary[j].get_student_usn() << ":";
					flag = true;
				}
			}
			sIndexFile.close();
		}
		return flag;
	}

	bool secondary_search(const std::string& studentName)
	{
		bool flag = false;
		std::list <int> listOfPos;
		opener(stdFile, data_directory, std::ios::in | std::ios::out);
		for (int j = 0; j < sIndexSize; j++)
		{
			if (studentName == secondary[j].get_student_name())
			{
				std::cout << "\n" << "\t\t" << (j + 1) << "\t\t" << std::setw(15) << secondary[j].get_student_usn() << std::setw(15) << secondary[j].get_student_name() << std::endl;
				flag = true;
			}
		}
		stdFile.close();
		return flag;
	}

	void initialize_index()
	{
		std::string tempUsn, tempAddress;
		indexFile.open(index_directory, std::ios::in);
		if (!indexFile)
		{
			indexSize = 0;
			return;
		}
		for (indexSize = 0;; indexSize++)
		{
			std::getline(indexFile, tempUsn, '|');
			std::getline(indexFile, tempAddress, '|');

			primary[indexSize].SetUsn(tempUsn);
			primary[indexSize].SetAddress(tempAddress);

			if (indexFile.eof())
				break;
		}
		indexFile.close();
	}

	void initialize_s_index()
	{
		std::string tempName, tempUsn;
		sIndexFile.open(secondary_index_directory, std::ios::in);
		if (!sIndexFile)
		{
			sIndexSize = 0;
			return;
		}
		for (sIndexSize = 0;; sIndexSize++)
		{
			std::getline(sIndexFile, tempName, '|');
			std::getline(sIndexFile, tempUsn, '|');
			secondary[indexSize].set_student_name(tempName);
			secondary[indexSize].set_student_usn(tempUsn);
			if (sIndexFile.eof())
				break;
		}
		sIndexFile.close();
	}

	void DeleteModifier(const std::string& key, int search)
	{
		int i, secondaryPos = 0;
		opener(stdFile, data_directory, std::ios::in | std::ios::out);
		stdFile.seekp(atoi(primary[search].GetAddress().c_str()), std::ios::beg);
		stdFile.put('$');
		for (i = search; i < indexSize; i++)
		{
			if (key == secondary[i].get_student_usn())
			{
				secondaryPos = i;
				break;
			}
		}

		for (i = secondaryPos; i < sIndexSize; i++)
			secondary[i] = secondary[i + 1];

		sIndexSize--;

		stdFile.close();
	}

	void DataWrite(const std::string& usn, const std::string& name)
	{
		int i;

		opener(stdFile, data_directory, std::ios::app);
		stdFile.seekg(0, std::ios::end);
		const int pos = (int)stdFile.tellg();
		stdFile << variableBuffer << "\n";

		for (i = indexSize; i > 0; i--)
		{
			if (usn < primary[i - 1].GetUsn())
				primary[i] = primary[i - 1];
			else
				break;
		}
		primary[i].SetUsn(usn);
		primary[i].SetAddress(std::to_string(pos));
		indexSize++;
		for (i = sIndexSize; i > 0; i--)
		{
			if (secondary[i - 1].get_student_name() == name)
				secondary[i] = secondary[i - 1];
			else if ((name == secondary[i - 1].get_student_name()) && (usn < secondary[i - 1].get_student_usn()))
				secondary[i] = secondary[i - 1];
			else
				break;
		}
		secondary[i].set_student_name(name);
		secondary[i].set_student_usn(usn);
		stdFile.close();
		sIndexSize++;
	}

	void index_write()
	{
		opener(indexFile, index_directory, std::ios::app);
		for (int i = 0; i < indexSize; i++)
			indexFile << primary[i].GetUsn() << '|' << primary[i].GetAddress() << "\n";
		indexFile.close();
	}

	void s_index_write()
	{
		opener(sIndexFile, secondary_index_directory, std::ios::app);
		for (int i = 0; i < sIndexSize; i++)
			sIndexFile << secondary[i].get_student_name() << '|' << secondary[i].get_student_usn() << "\n";
		sIndexFile.close();
	}

	bool is_usn_duplicate(const std::string& usn) const
	{
	
		const int search_flag = search(usn);
		if (search_flag != -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};
#endif