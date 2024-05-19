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
	
	}; //����������� ��� �-��� emplace � ����� � �������

	void get_info()
	{
		std::cout
			<< "\t\t\tT��� \"" << m_tank_name << "\"" << std::endl
			<< "���������: " << m_hp << std::endl
			<< "����: " << m_damage << std::endl
			<< "��������: " << m_speed << std::endl;
	}
};


struct Node //��� ����� � �������
{
	Data node_data = {"0",0,0,0};
	Node* next = nullptr;
};


struct DeckNode //��� ����
{
	Data node_data = { "0",0,0,0 };
	DeckNode* prev = nullptr;
	DeckNode* next = nullptr;
};