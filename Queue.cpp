#include "Queue.hpp"

Queue::Queue() : m_head{nullptr}, m_tail{nullptr}, m_count_element{0}
{

}


Queue::~Queue()
{
	while (!is_empty())
		pop();
}


void Queue::push(Data data)
{

	Node* new_node = new Node;
	new_node->node_data = data;

	if (m_head == nullptr) 
		m_head = m_tail = new_node;

	else 
	{
		m_tail->next = new_node;
		m_tail = new_node;
	}

	m_count_element++;
}


void Queue::emplace(std::string tank_name, int hp, int damage, int speed)
{
	Data data(tank_name, hp, damage, speed);
	push(data);
}


void Queue::pop()
{
	if (!is_empty())
	{
		Node* buffer = m_head;
		m_head = m_head->next;
		delete buffer;

		m_count_element--;

		if (m_count_element == 0)
			m_head = m_tail = nullptr;
	}
}


bool Queue::is_empty()
{
	return m_head == nullptr and m_count_element == 0;
}


void Queue::print()
{

	std::cout << "Очередь: ";

	for (Node* buffer = m_head; buffer != nullptr; buffer = buffer->next)
		buffer->node_data.get_info();

	std::cout << std::endl;
}