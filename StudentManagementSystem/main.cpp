#include"MenuOptions.h"
#include"StudentManagement.h"

int main()
{
	int initial_choice = 0, records_menu_choice = 0, index_menu_choice = 0;
	student_management sm;

	sm.operation.initialize_index();
	sm.operation.initialize_s_index();
	do {
		menu_options::MainMenuOptions();
		std::cin >> initial_choice;

		switch (initial_choice)
		{
		case n_main_menu_options::student_records:do
		{
			menu_options::RecordsMenuOptions();
			std::cin >> records_menu_choice;
			switch (records_menu_choice)
			{
			case n_record_menu_options::insert: {
				system("cls");
				sm.read();
				break;
			}
			case n_record_menu_options::update: {
				system("cls");
				sm.update();
				break;
			}

			case n_record_menu_options::display: {
				system("cls");
				sm.display();
				std::cin.get();
				break;
			}

			case n_record_menu_options::delete_: {
				system("cls");
				sm.delete_student();
				break;
			}

			case n_record_menu_options::back_to_mm: {
				system("cls");
				menu_options::MainMenuOptions();
				break;
			}

			default: {
				std::cout << "Wrong choice please enter again";
				break;
			}
			}
		} while (records_menu_choice != n_record_menu_options::back_to_mm);

		case n_main_menu_options::indexing:do
		{
			menu_options::IndexMenuOptions();
			std::cin >> index_menu_choice;
			switch (index_menu_choice)
			{
			case n_index_menu_options::simple_index_options:
				sm.indexing();
				break;
			case n_index_menu_options::secondary_index_options: {
				sm.secondary_indexing();
				break;
			}
			case n_index_menu_options::inverted_list_options: {
				sm.inverted_list();
				break;
			}
			case n_index_menu_options::back_to_mm_two_options: {
				menu_options::MainMenuOptions();
				break;
			}
			default:
				std::cout << "Wrong choice please enter again";
				break;
			}
		} while (index_menu_choice != n_index_menu_options::back_to_mm_two_options);

		case n_main_menu_options::exit_mm:
		{
			std::exit(0);
		}

		default:
			std::cout << "Wrong choice please enter again";
			break;
		}
	} while (initial_choice != 3);

	return 0;
}