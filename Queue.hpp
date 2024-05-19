#pragma once
#include <iostream>

#include "Data.hpp"

class Queue {
    Node* m_head;
    Node* m_tail;
    int m_count_element;

    void push(Data data);
public:
    Queue();
    ~Queue();

    bool is_empty();

    void emplace(std::string tank_name, int hp, int damage, int speed);
    void pop();

    void print();
};