#include"MenuOptions.h"
#include"StudentManagement.h"

int main()
{
	int initialChoice = 0, mainMenuChoice = 0, recordsMenuChoice = 0, indexMenuChoice = 0;
	bool invalidFlag = false, repeatFlag = false;
	MenuOptions menu;
	StudentManagement sm;

	sm.operation.InitializeIndex();
	sm.operation.InitializeSIndex();
	do {
		menu.MainMenuOptions();
		std::cin >> initialChoice;

		switch (initialChoice)
		{
		case nMainMenuOptions::studentRecords:do
		{
			menu.RecordsMenuOptions();
			std::cin >> recordsMenuChoice;
			switch (recordsMenuChoice)
			{
			case nRecordMenuOptions::Insert: {
				system("cls");
				sm.Read();
				break;
			}
			case nRecordMenuOptions::Update: {
				system("cls");
				sm.Update();
				break;
			}

			case nRecordMenuOptions::Display: {
				system("cls");
				sm.Display();
				std::cin.get();
				break;
			}

			case nRecordMenuOptions::Delete: {
				system("cls");
				sm.DeleteStudent();
				break;
			}

			case nRecordMenuOptions::backToMM: {
				system("cls");
				menu.MainMenuOptions();
				break;
			}

			default: {
				std::cout << "Wrong choice please enter again";
				break;
			}
			}
		} while (recordsMenuChoice != nRecordMenuOptions::backToMM);

		case nMainMenuOptions::indexing:do
		{
			menu.IndexMenuOptions();
			std::cin >> indexMenuChoice;
			switch (indexMenuChoice)
			{
			case nIndexMenuOptions::simpleIndex:
				sm.Indexing();
				break;
			case nIndexMenuOptions::secondaryIndex: {
				sm.SecondaryIndexing();
				break;
			}
			case nIndexMenuOptions::invertedList: {
				sm.InvertedList();
				break;
			}
			case nIndexMenuOptions::backTOMMTwo: {
				menu.MainMenuOptions();
				break;
			}
			default:
				std::cout << "Wrong choice please enter again";
				break;
			}
		} while (indexMenuChoice != nIndexMenuOptions::backTOMMTwo);
		case nMainMenuOptions::exitMM:
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