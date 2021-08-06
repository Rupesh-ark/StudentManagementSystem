#include"MenuOptions.h"
#include"Student.h"
#include"Operations.h"


int main()
{
	int initialChoice = 0,mainMenuChoice = 0,recordsMenuChoice = 0,indexMenuChoice = 0;
	bool invalidFlag = false, repeatFlag = false;
	std::string inputBuffer;
	std::fstream indexFile,secondaryIndexFile;
	MenuOptions menu;
	Student student;
	Operations operation;
	PrimaryIndex *primaryIndex;
	SecondaryIndex *secondaryIndex;
	operation.InitializeIndex(indexFile,primaryIndex);


	do {
	
		menu.MainMenuOptions();
		std::cin >> initialChoice;

		switch (initialChoice)
		{

		case nMainMenuOptions::studentRecords:do
		{	
			menu.RecordsMenuOptions();
			std::cin>>recordsMenuChoice;
			switch (recordsMenuChoice)
			{
			case nRecordMenuOptions::Insert: {

				system("cls");
				

			}

			default:{

				std::cout << "Wrong choice please enter again";
				break;
			}
			}
		} while (recordsMenuChoice != nRecordMenuOptions::back);
		

		case nMainMenuOptions::indexing:do
		{
			menu.IndexMenuOptions();

		} while (indexMenuChoice != nIndexMenuOptions::back);
		case nMainMenuOptions::exit:
		{
			std::exit(0);
		}

		default:
			std::cout << "Wrong choice please enter again";
			break;
		}



	} while (initialChoice != 3);



	

	return 0;
}