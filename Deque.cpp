#include "Deque.hpp"


Deque::Deque() : m_head{ nullptr }, m_tail{nullptr}, m_count_elements(0)
{

}


Deque::~Deque()
{
    while (!is_empty())
        pop_front();
}


bool Deque::is_empty()
{
    return m_head == nullptr;
}


void Deque::push_front(Data data) {
    DeckNode* new_node = new DeckNode;
    new_node->node_data = data;
    new_node->next = m_head;
    new_node->prev = nullptr;

    if (is_empty()) {
        m_tail = new_node;
    }
    else {
        m_head->prev = new_node;
    }

    m_head = new_node;
    m_count_elements++;
}


void Deque::push_back(Data data) {
    DeckNode* new_node = new DeckNode;
    new_node->node_data = data;
    new_node->next = nullptr;
    new_node->prev = m_tail;

    if (is_empty()) {
        m_head = new_node;
    }
    else {
        m_tail->next = new_node;
    }

    m_tail = new_node;
    m_count_elements++;
}


void Deque::emplace_front(std::string tank_name, int hp, int damage, int speed)
{
    Data data(tank_name, hp, damage, speed);
    push_front(data);
}


void Deque::emplace_back(std::string tank_name, int hp, int damage, int speed)
{
    Data data(tank_name, hp, damage, speed);
    push_back(data);
}


void Deque::insert(std::string tank_name, int hp, int damage, int speed, int position)
{
    Data data(tank_name, hp, damage, speed);

    if (position < 0 || position > m_count_elements)
    {
        std::cout << "\n\tНеверный индекс." << std::endl;
        return;
    }

    if (position == 0)
        push_front(data);

    else if (position == m_count_elements)
        push_back(data);

    else
    {
        DeckNode* new_node = new DeckNode;
        new_node->node_data = data;

        DeckNode* current = m_head;
        for (int i = 0; i < position - 1; ++i)
            current = current->next;

        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
        m_count_elements++;
    }
}


void Deque::pop_front() 
{
    if (!is_empty()) 
    {
        DeckNode* temp = m_head;
        m_head = m_head->next;
        if (m_head != nullptr)
            m_head->prev = nullptr;

        else
            m_tail = nullptr;

        delete temp;
        m_count_elements--;
    }
}


void Deque::pop_back()
{
    if (!is_empty())
    {
        DeckNode* temp = m_tail;
        m_tail = m_tail->prev;
        if (m_tail != nullptr)
            m_tail->next = nullptr;

        else
            m_head = nullptr;

        delete temp;
        m_count_elements--;
    }
}


void Deque::erase(int position)
{
    if (is_empty() || position < 0 || position >= m_count_elements)
    {
        std::cout << "\n\tНеверный индекс." << std::endl;
        return;
    }

    if (position == 0) {
        pop_front();
    }
    else if (position == m_count_elements - 1) {
        pop_back();
    }
    else 
    {
        DeckNode* current = m_head;
        for (int i = 0; i < position; ++i)
            current = current->next;

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;

        m_count_elements--;
    }
}


void Deque::print() {
    if (is_empty())
        std::cout << "\n\tДек пуст." << std::endl;

    else
    {
        std::cout << "Дек: ";

        for (DeckNode* current = m_head; current != nullptr; current = current->next)
            current->node_data.get_info();

        std::cout << std::endl;
    }
}