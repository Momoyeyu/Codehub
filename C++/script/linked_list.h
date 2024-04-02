#pragma once
#include <iostream>
#include <string>

class Node
{
private:
	std::string m_string;	// data
public:
	Node* last_node;		// ptr of last node
	Node* next_node;		// ptr of next node
public:
	Node();					// constructor for header
	Node(std::string str);	// constructor for nodes
	~Node();				// destructor
	std::string& GetString()	// get data's pointer
	{
		return m_string;
	}
	void SetString(std::string& str) 
	{
		m_string = str;
	}
	void Linknext(Node* next)
	{
		next->last_node = this;
		next_node = next;
	}
	friend void m_xor(Node* head, std::string& key);
};

Node::Node() // constructor for header
	: m_string("Empty"), last_node(nullptr), next_node(nullptr) {}

Node::Node(std::string str) // constructor for nodes
	: m_string(str), last_node(nullptr), next_node(nullptr) {}

Node::~Node() // destructor
{
	if (last_node != nullptr)
		last_node->next_node = this->next_node;
	if (next_node != nullptr)
		next_node->last_node = this->last_node;
}

// functions:

// xor operation for a bunch of nodes with a single key
void m_xor(Node* head, std::string& key)
{
	Node* cur_node = head->next_node;
	while (cur_node != nullptr)
	{
		for (int i = 0, j = 0; i < cur_node->m_string.size(); i++, j++)
		{
			if (j == key.size())
				j = 0;
			cur_node->m_string[i] = cur_node->m_string[i] ^ key[j];
		}
		cur_node = cur_node->next_node;
	}
}

void PrintNodeData(Node* head, int hex)
{
	Node* cur_node = head->next_node;
	for (int i = 1; cur_node != nullptr; i++)
	{
		std::cout << "[" << i << "]: ";
		std::string& data = cur_node->GetString();
		for (int j = 0; j < data.size(); j++) {
			if (hex)
				std::cout << std::hex << (int)data[j];
			else
				std::cout << std::dec << data[j];
		}
		std::cout << "\n";
		cur_node = cur_node->next_node;
	}
}