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
	std::cout << "������� �������� �����: ";
	std::getline(std::cin, out_name);

	std::cout << "������� ��������� �����, ���� � �������� ����� ������: ";
	std::cin >> out_hp >> out_damage >> out_speed;

}


void UserInterface::input_position(int& position)
{
	std::cout << "������� ������ ��� ������� ��������: ";
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
			<< "\t\t\t����\n"
			<< "1) �������������� �� ������\n"
			<< "2) �������������� � ��������\n"
			<< "3) �������������� � �����\n"
			<< "4) �����\n\n"
			<< "��� �����: ";

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
			std::cout << "����� �������!";
			break;

		default:
			std::cout << "�������� ������!\n";
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
			<< "\t\t\t����\n"
			<< "1) �������� �� �������������\n"
			<< "2) ���������� ��������\n"
			<< "3) �������� ��������\n"
			<< "4) ����� ���������\n"
			<< "4) ������� � ����\n\n"
			<< "��� �����: ";

		std::cin >> stack_answer;

		switch (stack_answer)
		{
		case((int)StackQueueMenu::EMPTY):
			std::cout << "���� " << ((m_stack.is_empty()) ? ("") : ("�� ")) << "����!\n";
			break;

		case((int)StackQueueMenu::EMPLACE):
			input_data(tank_name, hp, damage, speed);
			m_stack.emplace(tank_name, hp, damage, speed);
			std::cout << "������!\n";
			break;

		case ((int)StackQueueMenu::POP):
			m_stack.pop();
			std::cout << "������!\n";
			break;

		case((int)StackQueueMenu::PRINT):
			m_stack.print();
			break;

		case((int)StackQueueMenu::EXIT):
			break;

		default:
			std::cout << "�������� ������!\n";
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
			<< "\t\t\t�������\n"
			<< "1) �������� �� �������������\n"
			<< "2) ���������� ��������\n"
			<< "3) �������� ��������\n"
			<< "4) ����� ���������\n"
			<< "4) ������� � ����\n\n"
			<< "��� �����: ";

		std::cin >> queue_answer;

		switch (queue_answer)
		{
		case((int)StackQueueMenu::EMPTY):
			std::cout << "������� " << ((m_queue.is_empty()) ? ("") : ("�� ")) << "�����!\n";
			break;

		case((int)StackQueueMenu::EMPLACE):
			input_data(tank_name, hp, damage, speed);
			m_queue.emplace(tank_name, hp, damage, speed);
			std::cout << "������!\n";
			break;

		case ((int)StackQueueMenu::POP):
			m_queue.pop();
			std::cout << "������!\n";
			break;

		case((int)StackQueueMenu::PRINT):
			m_queue.print();
			break;

		case((int)StackQueueMenu::EXIT):
			break;

		default:
			std::cout << "�������� ������!\n";
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
			<< "\t\t\t���\n"
			<< "1) ���������� �������� � ������\n"
			<< "2) ���������� �������� � �����\n"
			<< "3) ������� ��������\n"
			<< "4) ������� �������� �� ������\n"
			<< "5) ������� �������� �� �����\n"
			<< "6) �������� ��������\n"
			<< "7) ����� ���������\n"
			<< "8) ������� � ����\n\n"
			<< "��� �����: ";

		std::cin >> deque_answer;

		switch (deque_answer)
		{
		case((int)DequeMenu::EMPLACE_FRONT):
			input_data(tank_name, hp, damage, speed);
			m_deque.emplace_front(tank_name, hp, damage, speed);
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::EMPLACE_BACK):
			input_data(tank_name, hp, damage, speed);
			m_deque.emplace_back(tank_name, hp, damage, speed);
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::INSERT):
			input_data_and_position(position, tank_name, hp, damage, speed);
			m_deque.insert(tank_name, hp, damage, speed, position);
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::POP_FRONT):
			m_deque.pop_front();
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::POP_BACK):
			m_deque.pop_back();
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::ERASE):
			input_position(position);
			m_deque.erase(position);
			std::cout << "������!\n";
			break;

		case((int)DequeMenu::PRINT):
			m_deque.print();
			break;

		case((int)DequeMenu::EXIT):
			break;

		default:
			std::cout << "�������� ������!\n";
			break;

		}

	} while (deque_answer != (int)DequeMenu::EXIT);
}


