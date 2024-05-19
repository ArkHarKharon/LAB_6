#pragma once
#include <iostream>
#include <string>

class Data
{
private:
	std::string m_tank_name;
	int m_hp;
	int m_damage;
	int m_speed;
public:
	Data(std::string tank_name, int hp = 0, int damage = 0, int speed = 0) :
		m_tank_name{tank_name},
		m_hp { hp },
		m_damage{ damage },
		m_speed{ speed }
	{
	
	}; //Конструктор для ф-ции emplace в стэке и очереди

	void get_info()
	{
		std::cout
			<< "\t\t\tTанк \"" << m_tank_name << "\"" << std::endl
			<< "Прочность: " << m_hp << std::endl
			<< "Урон: " << m_damage << std::endl
			<< "Скорость: " << m_speed << std::endl;
	}
};


struct Node //Для стэка и очереди
{
	Data node_data = {"0",0,0,0};
	Node* next = nullptr;
};


struct DeckNode //Для дэка
{
	Data node_data = { "0",0,0,0 };
	DeckNode* prev = nullptr;
	DeckNode* next = nullptr;
};