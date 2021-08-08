#include"MenuOptions.h"
#include"Student.h"

int main()
{
	int initialChoice = 0, mainMenuChoice = 0, recordsMenuChoice = 0, indexMenuChoice = 0;
	bool invalidFlag = false, repeatFlag = false;
	MenuOptions menu;
	Student student;

	student.operation.InitializeIndex();

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
				student.Read();
				student.operation.IndexWrite();
				student.operation.SIndexWrite();
				break;
			}
			case nRecordMenuOptions::Update: {
				system("cls");
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