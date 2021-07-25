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
#include<iomanip>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<fstream>
#include<list>
#include"PrimaryIndex.h"
#include"SecondaryIndex.h"


struct Index
{
	char usn[11], address[5];
};

struct SIndex
{
	char sName[20], sUsn[11];
};

class Operations
{
private:

	char variableBuffer[100], secondaryKey[20];
	std::fstream stdFile, indexFile, sIndexFile;
	int indexSize, sIndexSize;
	Index index[50];
	SIndex sIndex[50];

public:


	void Opener(std::fstream& file, const char* fn, int mode)
	{
		file.open(fn, mode);
		if (!file)
		{
			std::cout << "The file doesn't exist";
			exit(1);
		}
	}

	int Search(char* fid)
	{
		int low = 0, high = indexSize - 1;
		int middle;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (strcmp(fid, index[middle].usn) == 0)
				return  middle;
			else if (strcmp(fid, index[middle].usn) > 0)
				low = middle + 1;
			else
				high = middle - 1;
		}
		return -1;
	}

	void Remove(char* usn, PrimaryIndex primaryIndex[], SecondaryIndex secondaryIndex[])
	{
		
		int position = 0, secondaryPosition = 0 , i = 0;
		std::string tempAddress;

		for (i = 0; i < sIndexSize; i++)
		{
			if (primaryIndex[i].GetUsn() == usn)
			{
				secondaryPosition = i;
				break;
			}
		}
		if (secondaryIndex[secondaryPosition].GetStudentName() == secondaryKey)
		{
			position = Search(usn);
			stdFile.seekp(atoi(primaryIndex[position].GetAddress().c_str()), std::ios::beg);
			stdFile.put('$');
			for (i = position; i < indexSize; i++)
				primaryIndex[i] = primaryIndex[i + 1];
			indexSize--;
			for (i = secondaryPosition; i < sIndexSize; i++)
				secondaryIndex[i] = secondaryIndex[i + 1];
			sIndexSize--;
			std::cout << "\n\n\n" << "RECORD DELETED SUCCESSFULLY\n";
		}
		else
			std::cout << "\nUsn and Name does not Match\n";
	}

	int GetPrimaryIndex(char* studentName, SecondaryIndex secondaryIndex[])
	{
		int i, j, index = -1;
		std::cout << "\n\t\t" << studentName << ":";
		Opener(sIndexFile, SINDEXDIREC, std::ios::in);
		for (j = 0; j < sIndexSize; j++)
			if (studentName == secondaryIndex[j].GetStudentName())
			{
				std::cout << secondaryIndex[j].GetStudentUsn() << ":";
				index = j;
			}
		sIndexFile.close();
		return index;
	}

	std::list <int> SecondarySearch(char* studentName, SecondaryIndex secondaryIndex[])
	{
		int j;
		std::list <int> listOfPos;
		Opener(stdFile,DATADIREC, std::ios::in | std::ios::out);
		for (j = 0; j < sIndexSize; j++)
			if (studentName == secondaryIndex[j].GetStudentName())
			{
				listOfPos.push_back(j);
			}

		return listOfPos;
	}

	void InitializeIndex(std::fstream& indexFile, PrimaryIndex primary[])
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

	void InitializeSIndex(std::fstream& sIndexFile, SIndex sId[])
	{
		sIndexFile.open(SINDEXDIREC, std::ios::in);
		if (!sIndexFile)
		{
			sIndexSize = 0;
			return;
		}
		for (sIndexSize = 0;; sIndexSize++)
		{
			sIndexFile.getline(sId[sIndexSize].sName, 20, '|');
			sIndexFile.getline(sId[sIndexSize].sUsn, 10, '\n');
			if (sIndexFile.eof())
				break;
		}
		sIndexFile.close();
	}

	void IndexWrite(PrimaryIndex primary[])
	{
		int i;
		Opener(indexFile, INDEXDIREC, std::ios::out);
		for (i = 0; i < indexSize; i++)
			indexFile << primary[i].GetUsn() << '|' << primary[i].GetAddress() << "\n";
	}

	void SIndexWrite(SIndex sId[])
	{
		int i;
		Opener(sIndexFile, SINDEXDIREC, std::ios::out);
		for (i = 0; i < sIndexSize; i++)
			sIndexFile << sId[i].sName << '|' << sId[i].sUsn << "\n";
	}
};
#endif