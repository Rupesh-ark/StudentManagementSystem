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

	std::fstream std_file_, index_file_, s_index_file_;
	primary_index primary_[max_indices];
	secondary_index  secondary_[max_indices];
	std::string variable_buffer_;
	int index_size_, s_index_size_;

public:

	operations()
	{
		index_size_ = 0;
		s_index_size_ = 0;
		variable_buffer_ = "";
	}

	primary_index* get_primary_at_pos(const int pos)
	{
		primary_index* primaryPointer = &primary_[pos];
		return primaryPointer;
	}

	int GetIndexSize() const
	{
		return index_size_;
	}

	int get_secondary_index_size() const
	{
		return s_index_size_;
	}

	void set_variable_buffer(std::string p_variable_buffer)
	{
		variable_buffer_ = std::move(p_variable_buffer);
	}

	std::string get_variable_buffer() const
	{
		return variable_buffer_;
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
		int low = 0, high = index_size_ - 1;
		
		while (low <= high)
		{
			const int middle = (low + high) / 2;
			if (fid == primary_[middle].GetUsn())
				return  middle;
			else if (fid > primary_[middle].GetUsn())
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

		for (i = 0; i < s_index_size_; i++)
		{
			if (primary_[i].GetUsn() == usn)
			{
				secondary_position = i;
				break;
			}
		}
		if (secondary_[secondary_position].get_student_name() == secondary_key)
		{
			const int position = search(usn);
			std_file_.seekp(atoi(primary_[position].GetAddress().c_str()), std::ios::beg);
			std_file_.put('$');
			for (i = position; i < index_size_; i++)
				primary_[i] = primary_[i + 1];
			index_size_--;
			for (i = secondary_position; i < s_index_size_; i++)
				secondary_[i] = secondary_[i + 1];
			s_index_size_--;
			return true;
		}
		else
			return false;
	}

	bool secondary_index_list(const std::string& student_name)
	{
		bool flag = false;
		std::cout << "\n\t\t" << student_name << ":";
		const bool open = opener(s_index_file_, secondary_index_directory, std::ios::in);
		if (open)
		{
			for (int j = 0; j < s_index_size_; j++)
			{
				if (student_name == secondary_[j].get_student_name())
				{
					std::cout << secondary_[j].get_student_usn() << ":";
					flag = true;
				}
			}
			s_index_file_.close();
		}
		return flag;
	}

	bool secondary_search(const std::string& studentName)
	{
		bool flag = false;
		std::list <int> listOfPos;
		opener(std_file_, data_directory, std::ios::in | std::ios::out);
		for (int j = 0; j < s_index_size_; j++)
		{
			if (studentName == secondary_[j].get_student_name())
			{
				std::cout << "\n" << "\t\t" << (j + 1) << "\t\t" << std::setw(15) << secondary_[j].get_student_usn() << std::setw(15) << secondary_[j].get_student_name() << std::endl;
				flag = true;
			}
		}
		std_file_.close();
		return flag;
	}

	void initialize_index()
	{
		std::string tempUsn, tempAddress;
		index_file_.open(index_directory, std::ios::in);
		if (!index_file_)
		{
			index_size_ = 0;
			return;
		}
		for (index_size_ = 0;; index_size_++)
		{
			std::getline(index_file_, tempUsn, '|');
			std::getline(index_file_, tempAddress, '|');

			primary_[index_size_].SetUsn(tempUsn);
			primary_[index_size_].SetAddress(tempAddress);

			if (index_file_.eof())
				break;
		}
		index_file_.close();
	}

	void initialize_s_index()
	{
		std::string tempName, tempUsn;
		s_index_file_.open(secondary_index_directory, std::ios::in);
		if (!s_index_file_)
		{
			s_index_size_ = 0;
			return;
		}
		for (s_index_size_ = 0;; s_index_size_++)
		{
			std::getline(s_index_file_, tempName, '|');
			std::getline(s_index_file_, tempUsn, '|');
			secondary_[index_size_].set_student_name(tempName);
			secondary_[index_size_].set_student_usn(tempUsn);
			if (s_index_file_.eof())
				break;
		}
		s_index_file_.close();
	}

	void DeleteModifier(const std::string& key, int search)
	{
		int i, secondaryPos = 0;
		opener(std_file_, data_directory, std::ios::in | std::ios::out);
		std_file_.seekp(atoi(primary_[search].GetAddress().c_str()), std::ios::beg);
		std_file_.put('$');
		for (i = search; i < index_size_; i++)
		{
			if (key == secondary_[i].get_student_usn())
			{
				secondaryPos = i;
				break;
			}
		}

		for (i = secondaryPos; i < s_index_size_; i++)
			secondary_[i] = secondary_[i + 1];

		s_index_size_--;

		std_file_.close();
	}

	void DataWrite(const std::string& usn, const std::string& name)
	{
		int i;

		opener(std_file_, data_directory, std::ios::app);
		std_file_.seekg(0, std::ios::end);
		const int pos = (int)std_file_.tellg();
		std_file_ << variable_buffer_ << "\n";

		for (i = index_size_; i > 0; i--)
		{
			if (usn < primary_[i - 1].GetUsn())
				primary_[i] = primary_[i - 1];
			else
				break;
		}
		primary_[i].SetUsn(usn);
		primary_[i].SetAddress(std::to_string(pos));
		index_size_++;
		for (i = s_index_size_; i > 0; i--)
		{
			if (secondary_[i - 1].get_student_name() == name)
				secondary_[i] = secondary_[i - 1];
			else if ((name == secondary_[i - 1].get_student_name()) && (usn < secondary_[i - 1].get_student_usn()))
				secondary_[i] = secondary_[i - 1];
			else
				break;
		}
		secondary_[i].set_student_name(name);
		secondary_[i].set_student_usn(usn);
		std_file_.close();
		s_index_size_++;
	}

	void index_write()
	{
		opener(index_file_, index_directory, std::ios::app);
		for (int i = 0; i < index_size_; i++)
			index_file_ << primary_[i].GetUsn() << '|' << primary_[i].GetAddress() << "\n";
		index_file_.close();
	}

	void s_index_write()
	{
		opener(s_index_file_, secondary_index_directory, std::ios::app);
		for (int i = 0; i < s_index_size_; i++)
			s_index_file_ << secondary_[i].get_student_name() << '|' << secondary_[i].get_student_usn() << "\n";
		s_index_file_.close();
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