#pragma once
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Tree {

private:
    Node<T>* rootTree = nullptr;
    int treeHeight = 0, size = 0;
public:
    Tree() {

    }

    int getSize();
    int getTreeHeight();

    void addNode(T x);
    void addNode(Node<T>* rootTree, T x);

    Node<T>* search(T key, Node<T>* node);
    Node<T>* search(T key);

    int searchMin(Node<T>* node);

    void deleteNode(T key);
    
    void printTreeOnConsole();
private:
    int searchMinRec(Node<T>* node);
    void deleteNode(T key, Node<T>* node);
    void recPreOrderWithPrint(Node<T>* node);
    void recPreOrderCalculateHeight(Node<T>* node, int tempSize);
};

template <typename T>
int Tree<T>::getSize()
{
    return size;
}

template <typename T>
int Tree<T>::getTreeHeight()
{
    recPreOrderCalculateHeight(rootTree, 0);
    return treeHeight;
}

template <typename T>
void Tree<T>::addNode(T x)
{
    if (rootTree != nullptr)			//���� �� �� ���������������,
        addNode(rootTree, x);		//�� ��������� ����������� �������
                                    //��� ���������� ��������.

    else				               //����� ������� �������� ����� ��������:
    {
        rootTree = new Node<T> (x);		   //���������������� �������� �������      
                                       //� ��������������� ������ ���������. 
        rootTree->_left = nullptr;	   //���������������� ��������� �� �����
        rootTree->_right = nullptr;	   //� ������ ������� ��� NULL
        rootTree->_parent = nullptr;
    }

    size++;
}

template <typename T>
void Tree<T>::addNode(Node<T>* rootTree, T x)
{

    if (Node<T>::compareNodes(rootTree, x))  	//���� ����� �������� �������� ������ ��� //�������� �������� � ����
    {
        if (rootTree->_left != nullptr)		//� ���� ����� ��������� ���� ���������������
            addNode(rootTree->_left, x);		//������� �������� ���� ����, ��� ������ //���� �������
        else		//����� (���� ����� ������� �� //���������������)
        {
            rootTree->_left = new Node<T>(x);		//������� ������� � �������� ����� ������� �� //����� ������ �������.
            rootTree->_left->_left = nullptr;    	//��������� ����� �������� ��������� 
            rootTree->_left->_right = nullptr;   	//� ������ �������� ��������� � NULL.
            rootTree->_left->_parent = rootTree;
        }
    }
    else	//����� ���� ����� �������� �������� �� //������ ��������� �������� � ���� 
    {
        if (rootTree->_right != nullptr)		//� ���� ������ ��������� ���������������,
            addNode(rootTree->_right, x);		//�� ������� �������� ���� ����, ��� ������� //�������
        else		//�����(���� ������ ������� �� //���������������)
        {
            rootTree->_right = new Node<T>(x);		//������� ������� � �������� ����� ������� �� //����� ������� �������.
            rootTree->_right->_left = nullptr;  	//��������� ����� �������� ���������
            rootTree->_right->_right = nullptr;      //� ������ �������� ��������� � NULL.
            rootTree->_right->_parent = rootTree;
        }
    }
}

template <typename T>
Node<T>* Tree<T>::search(T key, Node<T>* node)
{
    if (node != nullptr)	//���� ���� //���������������
    {
        if (key == node->getInf())	//� �������� �������� //���� ��������� � //������� �������� //���������.
            return node;	//������������ ��������� �� //��������� �������.
        if (key < node->getInf())	//�����, ���� 
        //������� �������� //�������� ������ //��������� �������� ����
            return search(key, node->_left);	//���������� ��� �� ������� //��� ������ �������.
        else							//�����
            return search(key, node->_right);	//���������� ��� �� ������� //��� ������� �������.
    }
    else return nullptr;					//����� ������������ NULL.
}

Node<Table>* Tree<Table>::search(Table key, Node<Table>* node)
{
    if (node != nullptr)	//���� ���� //���������������
    {
        if (key.price == node->getInf().price)	//� �������� �������� //���� ��������� � //������� �������� //���������.
            return node;	//������������ ��������� �� //��������� �������.
        if (key.price < node->getInf().price)	//�����, ���� 
        //������� �������� //�������� ������ //��������� �������� ����
            return search(key, node->_left);	//���������� ��� �� ������� //��� ������ �������.
        else							//�����
            return search(key, node->_right);	//���������� ��� �� ������� //��� ������� �������.
    }
    else return nullptr;					//����� ������������ NULL.
}


//��������������� ��������� ��� �������
template <typename T>
int Tree<T>::searchMinRec(Node<T>* node)
{
    if (node->_left == nullptr)
    {
        return node->getInf();
    }
    else node = node->_left;;
}

template <typename T>
int Tree<T>::searchMin(Node<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else return searchMinRec(node);
}

template <typename T>
Node<T>* Tree<T>::search(T key)
{
    return search(key, rootTree);
}

template <typename T>
void Tree<T>::deleteNode(T key, Node<T>* node)
{
    Node* searchedNode = search(key, node);

    //��������� ������� - ������
    if (searchedNode == node) {
        if (searchedNode->_left != nullptr && searchedNode->_right == nullptr) {
            rootTree = node->_left;
        }
        else if (searchedNode->_left == nullptr && searchedNode->_right != nullptr) {
            rootTree = node->_right;
        }
        else if (searchedNode->_left != nullptr && searchedNode->_right != nullptr) {
            int minElem = searchMin(searchedNode->_left); //���� ����������� ������� � ������ 
            deleteNode(minElem, node); //������ ��������� ������� �� ���������, ������� �� ����� � ��������, �.�.
                                       //���� � ������������ �������� �� ����� ���� ���� ��������
            searchedNode->setInf(minElem); //������ ��� �� ����� ���������� ����
        }
        delete searchedNode;
    }
    //���� ��������� ������� ��� ��������
    else if (searchedNode->_left == nullptr && searchedNode->_right == nullptr) {
        if (searchedNode->_parent->_left == searchedNode) {
            searchedNode->_parent->_left = nullptr;
        }
        else {
            searchedNode->_parent->_right = nullptr;
        }
        delete searchedNode;
    }
    //������� ����� ������ ������ ������� �����
    else if (searchedNode->_left != nullptr && searchedNode->_right == nullptr) {
        if (searchedNode->_parent->_left == searchedNode) {
            searchedNode->_parent->_left = searchedNode->_left;
        }
        else {
            searchedNode->_parent->_right = searchedNode->_left;
        }
        delete searchedNode;
    }
    //������� ����� ������ ������ ������� ������
    else if (searchedNode->_left == nullptr && searchedNode->_right != nullptr)
    {
        if (searchedNode->_parent->_right == searchedNode) {
            searchedNode->_parent->_right = searchedNode->_right;
        }
        else {
            searchedNode->_parent->_left = searchedNode->_right;
        }
        delete searchedNode;
    }
    //������� ����� ��� �������
    else {
        int minElem = searchMin(searchedNode->_left); //���� ����������� ������� � ������ 
        deleteNode(minElem, node); //������ ��������� ������� �� ���������, ������� �� ����� � ��������, �.�.
                                   //���� � ������������ �������� �� ����� ���� ���� ��������
        searchedNode->setInf(minElem); //������ ��� �� ����� ���������� ����
    }
}

template <typename T>
void Tree<T>::deleteNode(T key)
{
    deleteNode(key, rootTree);
    size--;
}

template <typename T>
void Tree<T>::recPreOrderWithPrint(Node<T>* node)
{
    if (node != nullptr) {
        cout << node->getInf() << " ";
        recPreOrderWithPrint(node->_left);
        recPreOrderWithPrint(node->_right);
    }
}

void Tree<Table>::recPreOrderWithPrint(Node<Table>* node)
{
    if (node != nullptr) {
        cout << node->getInf().price << " ";
        recPreOrderWithPrint(node->_left);
        recPreOrderWithPrint(node->_right);
    }
}

template <typename T>
void Tree<T>::recPreOrderCalculateHeight(Node<T>* node, int tempSize)
{
    if (node != nullptr) {
        tempSize++;
        recPreOrderCalculateHeight(node->_left, tempSize);
        recPreOrderCalculateHeight(node->_right, tempSize);
    }
    else {
        if (tempSize > treeHeight) {
            treeHeight = tempSize;
        }
    }
}



template <typename T>
void Tree<T>::printTreeOnConsole()
{
    recPreOrderWithPrint(rootTree);
}