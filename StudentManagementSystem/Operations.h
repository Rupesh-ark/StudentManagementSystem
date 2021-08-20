#pragma once
#ifndef OPERATIONS_H
#define OPERATIONS_H
#define INDEXDIREC "index.txt"
#define SINDEXDIREC "sIndex.txt"
#define DATADIREC "data.txt"
#define USNSTD 10
#define PHNSTD 10
#define SEMONE 49
#define SEMEIGHT 56
#define MAXINDICES 50
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<string>
#include<fstream>
#include<list>
#include"PrimaryIndex.h"
#include"SecondaryIndex.h"

class Operations
{
private:

	std::fstream stdFile, indexFile, sIndexFile;
	PrimaryIndex primary[MAXINDICES];
	SecondaryIndex secondary[MAXINDICES];
	std::string variableBuffer;
	int indexSize, sIndexSize;

public:

	Operations()
	{
		indexSize = 0;
		sIndexSize = 0;
		variableBuffer = "";
	}

	PrimaryIndex* GetPrimaryAtPos(int pos)
	{
		PrimaryIndex* primaryPointer;
		primaryPointer = &primary[pos];
		return primaryPointer;
	}

	std::fstream& GetStdFile()
	{
		return stdFile;
	}

	int GetIndexSize()
	{
		return indexSize;
	}

	int GetSecondaryIndexSize()
	{
		return sIndexSize;
	}

	void SetVariableBuffer(std::string pVariableBuffer)
	{
		variableBuffer = pVariableBuffer;
	}

	std::string GetVariableBuffer()
	{
		return variableBuffer;
	}

	bool Opener(std::fstream& file, const char* fileName, int mode)
	{
		file.open(fileName, mode);
		if (!file)
			return false;

		else
			return true;
	}

	int Search(std::string fid)
	{
		int low = 0, high = indexSize - 1;
		int middle;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (fid == primary[middle].GetUsn())
				return  middle;
			else if (fid > primary[middle].GetUsn())
				low = middle + 1;
			else
				high = middle - 1;
		}
		return -1;
	}

	bool Remove(std::string usn, std::string secondaryKey)
	{
		int position = 0, secondaryPosition = 0, i = 0;
		std::string tempAddress;

		for (i = 0; i < sIndexSize; i++)
		{
			if (primary[i].GetUsn() == usn)
			{
				secondaryPosition = i;
				break;
			}
		}
		if (secondary[secondaryPosition].GetStudentName() == secondaryKey)
		{
			position = Search(usn);
			stdFile.seekp(atoi(primary[position].GetAddress().c_str()), std::ios::beg);
			stdFile.put('$');
			for (i = position; i < indexSize; i++)
				primary[i] = primary[i + 1];
			indexSize--;
			for (i = secondaryPosition; i < sIndexSize; i++)
				secondary[i] = secondary[i + 1];
			sIndexSize--;
			return true;
		}
		else
			return false;
	}

	bool SecondaryIndexList(std::string studentName)
	{
		int j, index = -1;
		bool flag = false;
		bool open;
		std::cout << "\n\t\t" << studentName << ":";
		open = Opener(sIndexFile, SINDEXDIREC, std::ios::in);
		if (open)
		{
			for (j = 0; j < sIndexSize; j++)
			{
				if (studentName == secondary[j].GetStudentName())
				{
					std::cout << secondary[j].GetStudentUsn() << ":";
					flag = true;
				}
			}
			sIndexFile.close();
		}
		return flag;
	}

	bool SecondarySearch(std::string studentName)
	{
		int j;
		bool flag = false;
		std::list <int> listOfPos;
		Opener(stdFile, DATADIREC, std::ios::in | std::ios::out);
		for (j = 0; j < sIndexSize; j++)
		{
			if (studentName == secondary[j].GetStudentName())
			{
				std::cout << "\n" << "\t\t" << (j + 1) << "\t\t" << std::setw(15) << secondary[j].GetStudentUsn() << std::setw(15) << secondary[j].GetStudentName() << std::endl;
				flag = true;
			}
		}
		stdFile.close();
		return flag;
	}

	void InitializeIndex()
	{
		std::string tempUsn, tempAddress;
		indexFile.open(INDEXDIREC, std::ios::in);
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

	void InitializeSIndex()
	{
		std::string tempName, tempUsn;
		sIndexFile.open(SINDEXDIREC, std::ios::in);
		if (!sIndexFile)
		{
			sIndexSize = 0;
			return;
		}
		for (sIndexSize = 0;; sIndexSize++)
		{
			std::getline(sIndexFile, tempName, '|');
			std::getline(sIndexFile, tempUsn, '|');
			secondary[indexSize].SetStudentName(tempName);
			secondary[indexSize].SetStudentUsn(tempUsn);
			if (sIndexFile.eof())
				break;
		}
		sIndexFile.close();
	}

	void DeleteModifier(std::string key, int search)
	{
		int i = 0, secondaryPos = 0;
		Opener(stdFile, DATADIREC, std::ios::in | std::ios::out);
		stdFile.seekp(atoi(primary[search].GetAddress().c_str()), std::ios::beg);
		stdFile.put('$');
		for (i = search; i < indexSize; i++)
		{
			if (key == secondary[i].GetStudentUsn())
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

	void DataWrite(std::string usn, std::string name)
	{
		int i = 0, pos = 0;

		Opener(stdFile, DATADIREC, std::ios::app);
		stdFile.seekg(0, std::ios::end);
		pos = (int)stdFile.tellg();
		stdFile << variableBuffer << std::endl;

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
			if (secondary[i - 1].GetStudentName() == name)
				secondary[i] = secondary[i - 1];
			else if ((name == secondary[i - 1].GetStudentName()) && (usn < secondary[i - 1].GetStudentUsn()))
				secondary[i] = secondary[i - 1];
			else
				break;
		}
		secondary[i].SetStudentName(name);
		secondary[i].SetStudentUsn(usn);
		stdFile.close();
		sIndexSize++;
	}

	void IndexWrite()
	{
		Opener(indexFile, INDEXDIREC, std::ios::out);
		for (int i = 0; i < indexSize; i++)
			indexFile << primary[i].GetUsn() << '|' << primary[i].GetAddress() << "\n";
		indexFile.close();
	}

	void SIndexWrite()
	{
		Opener(sIndexFile, SINDEXDIREC, std::ios::out);
		for (int i = 0; i < sIndexSize; i++)
			sIndexFile << secondary[i].GetStudentName() << '|' << secondary[i].GetStudentUsn() << "\n";
		sIndexFile.close();
	}

	bool isUSNDuplicate(std::string USN)
	{
		int search;

		search = Search(USN);
		if (search != -1)
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