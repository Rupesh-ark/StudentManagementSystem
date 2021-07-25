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

// enum class VariableType
// {
// 	usn,
// 	name,
// 	dob,
// 	gender,
// 	sem,
// 	phNo
// };

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

	// bool IsValid(char* validate, VariableType vt)
	// {
	// 	bool flag = true;
	// 	int i = 0, len = 0;

	// 	switch (vt)
	// 	{
	// 	case VariableType::usn:
	// 	{
	// 		for (i = 0; validate[i] != '\0'; i++)
	// 		{
	// 			len++;
	// 			if (isalpha(validate[i]) == 0 && isdigit(validate[i]) == 0) {
	// 				return false;
	// 			}
	// 		}

	// 		if (len != USNSTD)
	// 			flag = false;

	// 		return flag;
	// 	}
	// 	case VariableType::name:
	// 	{
	// 		for (i = 0; validate[i] != '\0'; i++)
	// 		{
	// 			if (isalpha(validate[i]) == 0)
	// 				return false;
	// 		}
	// 		return flag;
	// 	}
	// 	case VariableType::dob:
	// 	{
	// 		for (i = 0; validate[i] != '\0'; i++) {
	// 			len++;
	// 			if (isdigit(validate[i]) == 0 && validate[i] != '/') {
	// 				return false;
	// 			}
	// 		}

	// 		if (len != USNSTD)
	// 			flag = false;
	// 		return flag;
	// 	}
	// 	case VariableType::gender:
	// 	{
	// 		for (i = 0; validate[i] != '\0'; i++)
	// 		{
	// 			if (isalpha(validate[i]) == 0)
	// 				return false;
	// 		}
	// 		return flag;
	// 	}
	// 	case VariableType::sem:
	// 	{
	// 		if (validate[0] <= SEMONE && validate[0] >= SEMEIGHT)
	// 			return false;
	// 	}
	// 	case VariableType::phNo:
	// 	{
	// 		for (i = 0; validate[i] != '\0'; i++) {
	// 			len++;
	// 			if (isdigit(validate[i]) == 0) {
	// 				return false;
	// 			}
	// 		}

	// 		if (len != PHNSTD)
	// 			flag = false;
	// 		return flag;
	// 	}
	// 	default:
	// 	{
	// 		break;
	// 	}
	// 	}
	// 	return flag;
	// }

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

	void Remove(char* usn)
	{
		//char rmid[10];
		int pos, spos, i;
		//cout << "\nENTER THE PRODUCT NUMBER LISTED ABOVE TO DELETE..:\t";
		//cin >> rmid;
		for (i = 0; i < sIndexSize; i++)
		{
			if (strcmp(index[i].usn, usn) == 0)
			{
				spos = i;
				break;
			}
		}
		if (strcmp(sIndex[spos].sName, secondaryKey) == 0)
		{
			pos = Search(usn);
			stdFile.seekp(atoi(index[pos].address), std::ios::beg);
			stdFile.put('$');
			for (i = pos; i < indexSize; i++)
				index[i] = index[i + 1];
			indexSize--;
			for (i = spos; i < sIndexSize; i++)
				sIndex[i] = sIndex[i + 1];
			sIndexSize--;
			std::cout << "\n\n\n" << "RECORD DELETED SUCCESSFULLY\n";
		}
		else
			std::cout << "\nUsn and Name does not Match\n";
	}

	int GetPrimaryIndex(char* studentName)
	{
		int i, j, index = -1;
		std::cout << "\n\t\t" << studentName << ":";
		Opener(sIndexFile, SINDEXDIREC, std::ios::in);
		for (j = 0; j < sIndexSize; j++)
			if (strcmp(studentName, sIndex[j].sName) == 0)
			{
				std::cout << sIndex[j].sUsn << ":";
				index = j;
			}
		sIndexFile.close();
		return index;
	}

	int SecondarySearch(char* studentName)
	{
		int j, pos = -1, count = 0;

		std::cout << "\n" << "\t\tTHE SEARCHED RECORD DETAILS ARE...:";
		std::cout << "\n" << "\t\t" << "S.No" << "\t\t" << "USN" << "Student Name" << std::endl;
		Opener(stdFile,DATADIREC, std::ios::in | std::ios::out);
		for (j = 0; j < sIndexSize; j++)
			if (strcmp(studentName, sIndex[j].sName) == 0)
			{
				count = count + 1;
				std::cout << "\n" << "\t\t" << count << "\t\t" << sIndex[j].sUsn << sIndex[j].sName << std::endl;
				pos = j;
			}

		return pos;
	}

	void InitializeIndex(std::fstream& indexFile, Index id[])
	{
		indexFile.open(INDEXDIREC, std::ios::in);
		if (!indexFile)
		{
			indexSize = 0;
			return;
		}
		for (indexSize = 0;; indexSize++)
		{
			indexFile.getline(id[indexSize].usn, 10, '|');
			indexFile.getline(id[indexSize].address, 5, '\n');
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

	void IndexWrite(Index id[])
	{
		int i;
		Opener(indexFile, INDEXDIREC, std::ios::out);
		for (i = 0; i < indexSize; i++)
			indexFile << id[i].usn << '|' << id[i].address << "\n";
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