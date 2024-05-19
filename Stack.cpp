#include "Stack.hpp"

Stack::Stack(): top_node{nullptr}, count_nodes{0}
{

}

Stack::~Stack()
{
	while (!is_empty())
		pop();
}

bool Stack::is_empty()
{
	return top_node == nullptr and count_nodes == 0;
}

void Stack::push(Data data)
{
	Node* new_node = new Node;
	new_node->node_data = data;
	new_node->next = top_node;
	top_node = new_node;

	count_nodes++;
}

void Stack::emplace(std::string tank_name, int hp, int damage, int speed)
{
	Data data(tank_name, hp, damage, speed);
	push(data);
}

void Stack::pop()
{
	if (!is_empty())
	{
		Node* buffer = top_node;
		top_node = top_node->next;
		delete buffer;

		count_nodes--;

		if (count_nodes == 0)
			top_node = nullptr;
	}
}


void Stack::print()
{
	std::cout << "Стэк: \n";

	for (Node* buffer = top_node; buffer != nullptr; buffer = buffer->next)
		buffer->node_data.get_info();

	std::cout << std::endl;
}
