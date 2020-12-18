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

    ~Tree() {
        deleteTree();
    }

    int getSize();
    int getTreeHeight();

    void addNode(T x);
    void addNode(Node<T>* rootTree, T x);

    Node<T>* search(T key, Node<T>* node);
    Node<T>* search(T key);

    Node<T>* searchMin(Node<T>* node);
    Node<T>* searchMax(Node<T>* node);

    void deleteNode(T key);

    void deleteTree();
    
    void printTreeOnConsole();

    void printTreeGraphic();
private:
    Node<T>* searchMinRec(Node<T>* node);
    Node<T>* searchMaxRec(Node<T>* node);
    void deleteNodeRec(T key);
    void recPreOrderWithPrint(Node<T>* node);
    void recPreOrderCalculateHeight(Node<T>* node, int tempSize);
    void deleteTreeRec(Node<T>* node);
    void printRec(Node<T>* node, int h);
};

template <typename T>
int Tree<T>::getSize()
{
    return size;
}

template <typename T>
int Tree<T>::getTreeHeight()
{
    treeHeight = 0;
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

//����������� ������� ���������� ������ ����
template <typename T>
void Tree<T>::addNode(Node<T>* rootTree, T x)
{

    if (Node<T>::compareNodes(rootTree, x) == 1)  	//���� ����� �������� �������� ������ ��� //�������� �������� � ����
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
    else if(Node<T>::compareNodes(rootTree, x) == -1)	//����� ���� ����� �������� �������� ������ ��������� �������� � ���� 
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
    //������� �������� ��������
    else {
        size--; //�.�. ������������� ������� addNode �������������� size, �� � ������ ��������� ��� ����� ������������ ��� 
    }
}

template <typename T>
Node<T>* Tree<T>::search(T key, Node<T>* node)
{
    if (node != nullptr)	//���� ���� //���������������
    {
        if (Node<T>::compareNodes(node, key) == 0)	//� �������� �������� //���� ��������� � //������� �������� //���������.
            return node;	                        //������������ ��������� �� //��������� �������.
        if (Node<T>::compareNodes(node, key) == 1)	//�����, ���� �������� ������ ����
        //������� �������� //�������� ������ //��������� �������� ����
            return search(key, node->_left);	//���������� ��� �� ������� //��� ������ �������.
        else							//�����
            return search(key, node->_right);	//���������� ��� �� ������� //��� ������� �������.
    }
    else return nullptr;					//����� ������������ NULL.
}



//��������������� ��������� ��� �������
template <typename T>
Node<T>* Tree<T>::searchMinRec(Node<T>* node)
{
    if (node->_left == nullptr)
    {
        return node;
    }
    else 
        return searchMinRec(node->_left);
}

template<typename T>
inline Node<T>* Tree<T>::searchMaxRec(Node<T>* node)
{
    if (node->_right == nullptr)
    {
        return node;
    }
    else
        return searchMinRec(node->_right);
}

template <typename T>
Node<T>* Tree<T>::searchMin(Node<T>* node)
{
    return searchMinRec(node);
}

template<typename T>
inline Node<T>* Tree<T>::searchMax(Node<T>* node)
{
    return searchMaxRec(node);
}

template <typename T>
Node<T>* Tree<T>::search(T key)
{
    return search(key, rootTree);
}

template <typename T>
void Tree<T>::deleteNodeRec(T key)
{
    Node<T>* searchedNode = search(key, rootTree);

    if (searchedNode == nullptr) {
        size++; //�.�. ������������� ������� deleteNode �������������� size, �� � ������ ��������� ��� ����� ������������ ��� �������� ��������
        return;
    }


    //��������� ������� - ������
    //������������ ������ ��������, �.�. �� �� ����� ������������ ������
    if (searchedNode == rootTree) {     
        if (searchedNode->_left != nullptr && searchedNode->_right == nullptr) {
            Node<T>* left = rootTree->_left;
            delete rootTree;
            left->_parent = nullptr;
            rootTree = left;
        }
        else if (searchedNode->_left == nullptr && searchedNode->_right != nullptr) {
            Node<T>* right = rootTree->_right;
            delete rootTree;
            right->_parent = nullptr;
            rootTree = right;
        }
        //������ ���� �� ����� 232 �.�. ����� �� �� ������ ���� ���� ������� ����� ������
        else if (searchedNode->_left != nullptr && searchedNode->_right != nullptr) {
            Node<T>* minNode = searchMin(searchedNode->_right); //���� ������������ ������� � ������ ���������
            T minElemT = minNode->getInf();
            deleteNodeRec(minElemT); //������ ��������� ������� �� ���������, ������� �� ����� � ��������, �.�.
                                        //���� � ������������ �������� �� ����� ���� ���� ��������
            rootTree->setInf(minElemT); //������ ��� �� ����� ���������� ����
        } 
        //����� ������ ��� �����������
        else {
            delete rootTree;
            rootTree = nullptr;
        }
    }
    //���� ��������� ������� ��� ��������(����)
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
        //������������� ������ �������
        searchedNode->_left->_parent = searchedNode->_parent;
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
        //������������� ������ �������
        searchedNode->_right->_parent = searchedNode->_parent;
        delete searchedNode;
    }
    //������� ����� ��� �������
    else {
        Node<T>* minNode = searchMin(searchedNode->_right); //���� ����������� ������� � ������ ���������
        T minElemT = minNode->getInf();
        deleteNodeRec(minElemT); //������ ��������� ������� �� ���������, ������� �� ����� � ��������, �.�.
                                    //���� � ������������ �������� �� ����� ���� ���� ��������
        searchedNode->setInf(minElemT); //������ ��� �� ����� ���������� ����
    }
}

template <typename T>
void Tree<T>::deleteNode(T key)
{
    deleteNodeRec(key);
    size--;
}

template<typename T>
void Tree<T>::deleteTree()
{
    deleteTreeRec(rootTree);
    treeHeight = 0;
    size = 0;
}

//������������ ������
template<typename T>
void Tree<T>::deleteTreeRec(Node<T>* node)
{
    if (node != nullptr) {
        deleteTreeRec(node->_left);
        deleteTreeRec(node->_right);
        delete node;
    }
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

//������ "������"
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
    cout << endl;
    cout << "Tree height: " << getTreeHeight() << endl;
    cout << "Tree size: " << getSize() << endl;
}

template<typename T>
void Tree<T>::printRec(Node<T>* node, int h)
{
    if (node != NULL)
    {
        printRec(node->_left, h + 1);

        for (int i = 1; i <= h; i++)

            cout << "\t";

        cout << node->getInf() << endl;

        printRec(node->_right, h + 1);
    }
}

void Tree<Table>::printRec(Node<Table>* node, int h)
{
    if (node != NULL)
    {
        printRec(node->_left, h + 1);

        for (int i = 1; i <= h; i++)

            cout << "\t";

        cout << node->getInf().price << endl;

        printRec(node->_right, h + 1);
    }
}

template<typename T>
void Tree<T>::printTreeGraphic()
{
    printRec(rootTree, getTreeHeight());
    cout << "_______________________________________________________________________________________" << endl;
}
