#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
	Tree<double> tree;

	/*
	Table table1, table2, table3, table4, table5, table6, table7, table8, table9;
	table1.price = 6;
	table2.price = 15;
	table3.price = 25;
	table4.price = 17.4; 
	table5.price = 105;
	table6.price = 7;
	table7.price = 9;
	table8.price = 5;
	table9.price = 4;

	tree.addNode(table1);
	tree.addNode(table2);
	tree.addNode(table3);
	tree.addNode(table4);
	tree.addNode(table5);
	tree.addNode(table6);
	tree.addNode(table7);
	tree.addNode(table8);
	tree.addNode(table9);
	tree.printTreeOnConsole();
	

	//��������
	//������ ����
	tree.deleteNode(table7);
	tree.printTreeOnConsole();

	//������ ������
	tree.deleteNode(table1);
	tree.printTreeOnConsole();
	*/

	tree.addNode(5.5);
	tree.addNode(15);
	tree.addNode(25);
	tree.addNode(17.4);
	tree.addNode(105);
	tree.addNode(7);
	tree.addNode(9);
	tree.addNode(2);
	tree.addNode(1);
	tree.addNode(3);
	
	tree.printTreeOnConsole();
	tree.deleteNode(15);
	tree.printTreeOnConsole();
	tree.deleteNode(7);



	tree.deleteTree();

	return 0;
}

////������ ��� �������� �������� ������ �����
//tree.addNode("anadvn");
//tree.addNode("bnadvn");
//tree.addNode("knajdvn");
//tree.addNode("cndvn");
//tree.addNode("onajdvn");
//tree.deleteNode("onajdvn");
//tree.printTreeOnConsole();

//������ ��� �������� �������� ������ �����
//tree.addNode("anadvn");
//tree.addNode("bnadvn");
//tree.addNode("knajdvn");
//tree.addNode("cndvn");
//tree.addNode("onajdvn");

//������ ��� �������� �������� ������ double
//tree.addNode(5.5);
//tree.addNode(15);
//tree.addNode(25);
//tree.addNode(17.4);
//tree.addNode(105);
//tree.addNode(7);
//tree.addNode(9);
//tree.addNode(4);
//tree.deleteNode(5);
//tree.deleteNode(7);
//tree.deleteNode(25);