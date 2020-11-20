#pragma once

#include <string>
#include "Table.h"

using std::string;

template <typename T>
class Node
{
public:
    Node* _left = nullptr;
    Node* _right = nullptr;
    Node* _parent = nullptr;

private:
    T inf;

public:
    Node();
    Node(T x);
    void setInf(T x);
    T getInf();
    static Node* addNode(Node* rootTree, T x);
	static bool compareNodes(Node<T>* a, T b); //возвращает true, если a < b
};

template <typename T>
Node<T>::Node()
{
	inf = 0;
}

template <typename T>
Node<T>::Node(T x)
{
	inf = x;
}

template <typename T>
void Node<T>::setInf(T x)
{
	inf = x;
}

template <typename T>
T Node<T>::getInf()
{
	return inf;
}

template <typename T>
Node<T>* Node<T>::addNode(Node* rootTree, T x)
{
	if (rootTree == nullptr) {
		rootTree = new Node(x);
		rootTree->_left = nullptr;
		rootTree->_right = nullptr;
		return rootTree;
	}
	else {
		if (rootTree->getInf() > x) {
			return Node::addNode(rootTree->_left, x);
			//вызвать функцию добавить от левого

		}
		else {
			return Node::addNode(rootTree->_right, x);
			//вызвать функцию добавить от правого
		}
	}
}

template<typename T> 
bool Node<T>::compareNodes(Node<T>* a, T b)
{
	return a->inf > b;
}

bool Node<string>::compareNodes(Node<string>* a, string b)
{
	return a->inf[0] > b[0];
}

bool Node<Table>::compareNodes(Node<Table>* a, Table b)
{
	return a->inf.price > b.price;
}

