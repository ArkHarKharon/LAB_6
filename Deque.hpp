#pragma once

#include "Data.hpp"

class Deque
{
private:
    DeckNode* m_head;
    DeckNode* m_tail;
    int m_count_elements;

    void push_front(Data data);
    void push_back(Data data);
public:
    Deque();
    ~Deque();

    bool is_empty();

    void emplace_front(std::string tank_name, int hp, int damage, int speed);
    void emplace_back(std::string tank_name, int hp, int damage, int speed);
    void insert(std::string tank_name, int hp, int damage, int speed, int position);
    void pop_front();
    void pop_back();
    void erase(int position);

    void print();
};