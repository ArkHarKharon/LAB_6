#pragma once
#include <iostream>

#include "Data.hpp"

class Stack
{
private:
	Node* top_node;
	int count_nodes;

	void push(Data data);
public:
	Stack();
	~Stack();

	bool is_empty();

	void emplace(std::string tank_name, int hp, int damage, int speed);
	void pop();

	void print();
};