#pragma once
#include "Planet.h"
class PlanetList
{
private:
    struct Node 
    {
        Planet* planets;
        Node* link;
        Node(Planet* p) : planets(p), link(nullptr) {}
    };
    Node* head;

public:
    PlanetList() : head(nullptr) {}

    void insert(Planet* planet) 
    {
        Node* newNode = new Node(planet);
        if (head == nullptr)
            head = newNode;
        else 
        {
            Node* current = head;
            while (current->link) 
            {
                current = current->link;
            }
            current->link = newNode;
        }
    }

    void remove(const char* planetName) 
    {
        Node* current = head;
        Node* previous = nullptr;

        while (current) {
            if (current->planets->Name == planetName) 
            {
                if (previous == nullptr) 
                    head = current->link;
                else 
                    previous->link = current->link;
   
                delete current;
                return;
            }
            previous = current;
            current = current->link;
        }
    }

    void removeAllplaent()
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->link;
            delete current->planets;  // 데이터 메모리 해제
            delete current;  // 노드 메모리 해제
            current = next;
        }
        head = nullptr;
    }

    Planet* find(const char* planetName)
    {
        Node* current = head;
        while (current) 
        {
            if (current->planets->Name == planetName) 
            {
                return current->planets;
            }
            current = current->link;
        }
        return nullptr;
    }

    void clear() 
    {
        Node* current = head;
        while (current) 
        {
            Node* next = current->link;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    int getListNum() const 
    {
        int count = 0;
        Node* current = head;
        while (current) 
        {
            count++;
            current = current->link;
        }
        return count;
    }
    
};

