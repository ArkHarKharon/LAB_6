#include "Stack.hpp"
#include "Queue.hpp"
#include "Deque.hpp"


enum class MainMenu
{
	STACK = 1,
	QUEUE,
	DEQUE,
	EXIT
};


enum class StackQueueMenu
{
	EMPTY = 1,
	EMPLACE,
	POP,
	PRINT,
	EXIT
};


enum class DequeMenu
{
	EMPLACE_FRONT = 1,
	EMPLACE_BACK,
	INSERT,
	POP_FRONT,
	POP_BACK,
	ERASE,
	PRINT,
	EXIT
};


class UserInterface
{
private:
	Stack m_stack;
	Queue m_queue;
	Deque m_deque;

	void stack_menu();
	void queue_menu();
	void deque_menu();
	void main_menu();

	void input_data(std::string &out_name, int &out_hp, int &out_damage, int &out_speed);
	void input_position(int& position);
	void input_data_and_position(int& position, std::string& out_name, int& out_hp, int& out_damage, int& out_speed);

public:
	UserInterface();
	void run();
};