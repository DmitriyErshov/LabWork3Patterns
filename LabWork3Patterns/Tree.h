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
    if (rootTree != nullptr)			//Если он не инициализирован,
        addNode(rootTree, x);		//то вызовется рекурсивная функция
                                    //для добавления элемента.

    else				               //Иначе Функция поместит новое значение:
    {
        rootTree = new Node<T> (x);		   //инициализируется корневой элемент      
                                       //в соответствующую ячейку структуры. 
        rootTree->_left = nullptr;	   //Инициализируется указатель на левый
        rootTree->_right = nullptr;	   //и правый элемент как NULL
        rootTree->_parent = nullptr;
    }

    size++;
}

template <typename T>
void Tree<T>::addNode(Node<T>* rootTree, T x)
{

    if (Node<T>::compareNodes(rootTree, x))  	//Если новое ключевое значение меньше чем //ключевое значение в узле
    {
        if (rootTree->_left != nullptr)		//И если левый указатель узла инициализирован
            addNode(rootTree->_left, x);		//Функция вызывает саму себя, для левого //узла потомка
        else		//Иначе (если левый потомок не //инициализирован)
        {
            rootTree->_left = new Node<T>(x);		//Функция создаст и поместит новый элемент на //место левого потомка.
            rootTree->_left->_left = nullptr;    	//Установит левый дочерний указатель 
            rootTree->_left->_right = nullptr;   	//и правый дочерний указатель в NULL.
            rootTree->_left->_parent = rootTree;
        }
    }
    else	//Иначе Если новое ключевое значение не //меньше ключевого значения в узле 
    {
        if (rootTree->_right != nullptr)		//И если правый указатель инициализирован,
            addNode(rootTree->_right, x);		//То функция вызывает саму себя, для правого //потомка
        else		//Иначе(если правый потомок не //инициализирован)
        {
            rootTree->_right = new Node<T>(x);		//Функция создаст и поместит новый элемент на //место правого потомка.
            rootTree->_right->_left = nullptr;  	//Установит левый дочерний указатель
            rootTree->_right->_right = nullptr;      //и правый дочерний указатель в NULL.
            rootTree->_right->_parent = rootTree;
        }
    }
}

template <typename T>
Node<T>* Tree<T>::search(T key, Node<T>* node)
{
    if (node != nullptr)	//Если узел //инициализирован
    {
        if (key == node->getInf())	//И ключевое значение //узла совпадает с //искомым ключевым //значением.
            return node;	//Возвращается указатель на //найденный элемент.
        if (key < node->getInf())	//Иначе, если 
        //искомое ключевое //значение меньше //ключевого значения узла
            return search(key, node->_left);	//Вызывается эта же функция //для левого потомка.
        else							//Иначе
            return search(key, node->_right);	//Вызывается эта же функция //для правого потомка.
    }
    else return nullptr;					//Иначе возвращается NULL.
}

Node<Table>* Tree<Table>::search(Table key, Node<Table>* node)
{
    if (node != nullptr)	//Если узел //инициализирован
    {
        if (key.price == node->getInf().price)	//И ключевое значение //узла совпадает с //искомым ключевым //значением.
            return node;	//Возвращается указатель на //найденный элемент.
        if (key.price < node->getInf().price)	//Иначе, если 
        //искомое ключевое //значение меньше //ключевого значения узла
            return search(key, node->_left);	//Вызывается эта же функция //для левого потомка.
        else							//Иначе
            return search(key, node->_right);	//Вызывается эта же функция //для правого потомка.
    }
    else return nullptr;					//Иначе возвращается NULL.
}


//вспомогательная процедура для прохода
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

    //удаляемый элемент - корень
    if (searchedNode == node) {
        if (searchedNode->_left != nullptr && searchedNode->_right == nullptr) {
            rootTree = node->_left;
        }
        else if (searchedNode->_left == nullptr && searchedNode->_right != nullptr) {
            rootTree = node->_right;
        }
        else if (searchedNode->_left != nullptr && searchedNode->_right != nullptr) {
            int minElem = searchMin(searchedNode->_left); //ищем минимальный элемент в правом 
            deleteNode(minElem, node); //удалим найденный элемент из поддерева, функция не уйдет в рекурсию, т.к.
                                       //если у минимального элемента не может быть двух потомков
            searchedNode->setInf(minElem); //ставим его на место удаляемого узла
        }
        delete searchedNode;
    }
    //если найденный элемент без потомков
    else if (searchedNode->_left == nullptr && searchedNode->_right == nullptr) {
        if (searchedNode->_parent->_left == searchedNode) {
            searchedNode->_parent->_left = nullptr;
        }
        else {
            searchedNode->_parent->_right = nullptr;
        }
        delete searchedNode;
    }
    //элемент имеет только одного потомка слева
    else if (searchedNode->_left != nullptr && searchedNode->_right == nullptr) {
        if (searchedNode->_parent->_left == searchedNode) {
            searchedNode->_parent->_left = searchedNode->_left;
        }
        else {
            searchedNode->_parent->_right = searchedNode->_left;
        }
        delete searchedNode;
    }
    //элемент имеет только одного потомка справа
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
    //элемент имеет два потомка
    else {
        int minElem = searchMin(searchedNode->_left); //ищем минимальный элемент в правом 
        deleteNode(minElem, node); //удалим найденный элемент из поддерева, функция не уйдет в рекурсию, т.к.
                                   //если у минимального элемента не может быть двух потомков
        searchedNode->setInf(minElem); //ставим его на место удаляемого узла
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