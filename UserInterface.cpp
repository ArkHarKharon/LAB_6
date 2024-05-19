#include "UserInterface.hpp"


UserInterface::UserInterface()
{

}


void UserInterface::run()
{
	setlocale(0, "");

	main_menu();
}


void UserInterface::input_data(std::string &out_name, int &out_hp, int &out_damage, int &out_speed)
{
	std::cin.ignore(32767, '\n');
	std::cout << "Введите название танка: ";
	std::getline(std::cin, out_name);

	std::cout << "Введите прочность танка, урон и скорость через пробел: ";
	std::cin >> out_hp >> out_damage >> out_speed;

}


void UserInterface::input_position(int& position)
{
	std::cout << "Введите нормер для вставки элемента: ";
	std::cin >> position;
}


void UserInterface::input_data_and_position(int& position, std::string& out_name, int& out_hp, int& out_damage, int& out_speed)
{
	input_position(position);
	input_data(out_name, out_hp, out_damage, out_speed);
}


void UserInterface::main_menu()
{
	int menu_answer{};
	do
	{
		std::cout
			<< "\t\t\tМЕНЮ\n"
			<< "1) Взаимодействие со стеком\n"
			<< "2) Взаимодействие с очередью\n"
			<< "3) Взаимодействие с деком\n"
			<< "4) Выход\n\n"
			<< "Ваш выбор: ";

		std::cin >> menu_answer;

		switch (menu_answer)
		{
		case ((int)MainMenu::STACK):
			stack_menu();
			break;

		case ((int)MainMenu::QUEUE):
			queue_menu();
			break;


		case ((int)MainMenu::DEQUE):
			deque_menu();
			break;


		case ((int)MainMenu::EXIT):
			std::cout << "Всего доброго!";
			break;

		default:
			std::cout << "Неверный индекс!\n";
			break;
		}

	} while (menu_answer != ((int)MainMenu::EXIT));
}


void UserInterface::stack_menu()
{
	system("cls");
	int stack_answer{};
	std::string tank_name{};
	int hp{}, damage{}, speed{};

	do
	{
		std::cout
			<< "\t\t\tСТЕК\n"
			<< "1) Проверка на заполненность\n"
			<< "2) Добавление элемента\n"
			<< "3) Удаление элемента\n"
			<< "4) Вывод элементов\n"
			<< "4) Возврат в меню\n\n"
			<< "Ваш выбор: ";

		std::cin >> stack_answer;

		switch (stack_answer)
		{
		case((int)StackQueueMenu::EMPTY):
			std::cout << "Стек " << ((m_stack.is_empty()) ? ("") : ("не ")) << "пуст!\n";
			break;

		case((int)StackQueueMenu::EMPLACE):
			input_data(tank_name, hp, damage, speed);
			m_stack.emplace(tank_name, hp, damage, speed);
			std::cout << "Готово!\n";
			break;

		case ((int)StackQueueMenu::POP):
			m_stack.pop();
			std::cout << "Готово!\n";
			break;

		case((int)StackQueueMenu::PRINT):
			m_stack.print();
			break;

		case((int)StackQueueMenu::EXIT):
			break;

		default:
			std::cout << "Неверный индекс!\n";
			break;
		}

	} while (stack_answer != (int)StackQueueMenu::EXIT);
}


void UserInterface::queue_menu()
{
	system("cls");
	int queue_answer{};
	std::string tank_name{};
	int hp{}, damage{}, speed{};

	do
	{
		std::cout
			<< "\t\t\tОЧЕРЕДЬ\n"
			<< "1) Проверка на заполненность\n"
			<< "2) Добавление элемента\n"
			<< "3) Удаление элемента\n"
			<< "4) Вывод элементов\n"
			<< "4) Возврат в меню\n\n"
			<< "Ваш выбор: ";

		std::cin >> queue_answer;

		switch (queue_answer)
		{
		case((int)StackQueueMenu::EMPTY):
			std::cout << "Очередь " << ((m_queue.is_empty()) ? ("") : ("не ")) << "пуста!\n";
			break;

		case((int)StackQueueMenu::EMPLACE):
			input_data(tank_name, hp, damage, speed);
			m_queue.emplace(tank_name, hp, damage, speed);
			std::cout << "Готово!\n";
			break;

		case ((int)StackQueueMenu::POP):
			m_queue.pop();
			std::cout << "Готово!\n";
			break;

		case((int)StackQueueMenu::PRINT):
			m_queue.print();
			break;

		case((int)StackQueueMenu::EXIT):
			break;

		default:
			std::cout << "Неверный индекс!\n";
			break;
		}

	} while (queue_answer != (int)StackQueueMenu::EXIT);
}


void UserInterface::deque_menu()
{
	system("cls");
	int deque_answer{};
	std::string tank_name{};
	int position{}, hp{}, damage{}, speed{};

	do
	{
		std::cout
			<< "\t\t\tДЕК\n"
			<< "1) Добавление элемента в начало\n"
			<< "2) Добавление элемента в конец\n"
			<< "3) Вставка элемента\n"
			<< "4) Изъятие элемента из начала\n"
			<< "5) Изъятие элемента из конца\n"
			<< "6) Удаление элемента\n"
			<< "7) Вывод элементов\n"
			<< "8) Возврат в меню\n\n"
			<< "Ваш выбор: ";

		std::cin >> deque_answer;

		switch (deque_answer)
		{
		case((int)DequeMenu::EMPLACE_FRONT):
			input_data(tank_name, hp, damage, speed);
			m_deque.emplace_front(tank_name, hp, damage, speed);
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::EMPLACE_BACK):
			input_data(tank_name, hp, damage, speed);
			m_deque.emplace_back(tank_name, hp, damage, speed);
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::INSERT):
			input_data_and_position(position, tank_name, hp, damage, speed);
			m_deque.insert(tank_name, hp, damage, speed, position);
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::POP_FRONT):
			m_deque.pop_front();
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::POP_BACK):
			m_deque.pop_back();
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::ERASE):
			input_position(position);
			m_deque.erase(position);
			std::cout << "Готово!\n";
			break;

		case((int)DequeMenu::PRINT):
			m_deque.print();
			break;

		case((int)DequeMenu::EXIT):
			break;

		default:
			std::cout << "Неверный индекс!\n";
			break;

		}

	} while (deque_answer != (int)DequeMenu::EXIT);
}


