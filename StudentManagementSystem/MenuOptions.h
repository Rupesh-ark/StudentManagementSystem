#pragma once
#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include<iostream>
#include<iomanip>

class MenuOptions{

	private:
	int userInput;

	public:

	void MainMenu(int wLeftSpace = 0, int height = 0) {
	
		system("cls");
		system("COLOR 3F");
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

		std::cin >> userInput;
	}
	
	void RecordsMenu(int wLeftSpace = 0, int height = 0) {

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
		
		std::cin >> userInput;

	}


	void IndexMenu(int wLeftSpace = 0, int height = 0) {

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

		std::cin >> userInput;
	}


};











#endif 

