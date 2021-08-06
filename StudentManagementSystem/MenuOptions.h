#pragma once
#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include<iostream>
#include<iomanip>

enum nMainMenuOptions
{
	studentRecords = 1,
	indexing = 2,
	exit =3
};

enum nRecordMenuOptions
{
	Insert = 1,
	Update = 2,
	Display = 3,
	Delete = 4,
	back = 5
};

enum nIndexMenuOptions
{
	simpleIndex = 1,
	secondaryIndex = 2,
	invertedList = 3,
	back = 4
};

class MenuOptions{


public:

	void MainMenuOptions(int wLeftSpace = 80, int height = 6) {
	
		system("cls");
		system("COLOR 1F");
		for (int i = 0; i < height; i++)
			std::cout << std::endl;

		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **************************************************************************************\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **      |       |   |       Student Management System           |   |       |       **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **      Student Records                      ---->          choose  option '1'      **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **      Indexing                             ---->          choose  option '2'      **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **      Exit                                 ---->          choose  option '3'      **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) <<"\t\t\t  **************************************************************************************\n ";

	}
	
	void RecordsMenuOptions(int wLeftSpace = 80, int height = 6) {

		system("cls");
		system("COLOR 2F");
		for (int i = 0; i < height; i++)
			std::cout << std::endl;

		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      |       |   |        Student Records                    |   |       |       **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Insert                               ---->          choose  option '1'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Update                               ---->          choose  option '2'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Display                              ---->          choose  option '3'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Delete                               ---->          choose  option '4'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Back                                 ---->          choose  option '5'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
	
	}


	void IndexMenuOptions(int wLeftSpace = 80, int height = 6) {

		system("cls");
		system("COLOR 5F");
		for (int i = 0; i < height; i++)
		std::cout << std::endl;

		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      |       |   |        Student Records                    |   |       |       **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Simple Index                         ---->          choose  option '1'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Secondary Index                      ---->          choose  option '2'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Inverted List                        ---->          choose  option '3'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Back                                 ---->          choose  option '4'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
	
	}

};

#endif 

