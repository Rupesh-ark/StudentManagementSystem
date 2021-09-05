#pragma once
#ifndef MENUOPTIONS_H
#define MENUOPTIONS_H
#include<iostream>
#include<iomanip>

enum n_main_menu_options
{
	student_records = 1,
	indexing = 2,
	exit_mm = 3
};

enum n_record_menu_options
{
	insert = 1,
	update = 2,
	display = 3,
	delete_ = 4,
	back_to_mm = 5
};

enum n_index_menu_options
{
	simple_index_options = 1,
	secondary_index_options = 2,
	inverted_list_options = 3,
	back_to_mm_two_options = 4
};

class menu_options {
public:
	static void MainMenuOptions(int wLeftSpace = 80, int height = 6) {
		system("cls");
		system("COLOR 1F");
		for (int i = 0; i < height; i++)
			std::cout << std::endl;

		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      |       |   |       Student Management System           |   |       |       **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Student Records                      ---->          choose  option '1'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Indexing                             ---->          choose  option '2'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Exit                                 ---->          choose  option '3'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
	}

	static void RecordsMenuOptions(int wLeftSpace = 80, int height = 6) {
		system("cls");
		system("COLOR 2F");
		for (int i = 0; i < height; i++)
			std::cout << std::endl;

		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      |       |   |        Student Records                    |   |       |       **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Insert                               ---->          choose  option '1'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      update                               ---->          choose  option '2'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      display                              ---->          choose  option '3'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      delete_                               ---->          choose  option '4'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **      Back                                 ---->          choose  option '5'      **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **                                                                                  **\n ";
		std::cout << std::setw(wLeftSpace) << "\t\t\t  **************************************************************************************\n ";
	}

	static void IndexMenuOptions(int wLeftSpace = 80, int height = 6) {
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
