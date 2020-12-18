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
	tree.printTreeGraphic();
	

	//удаление
	//удалим лист
	tree.deleteNode(table7);
	tree.printTreeOnConsole();

	//удалим корень
	tree.deleteNode(table1);
	tree.printTreeGraphic();
	*/

	//тестирование дерева double
	
	//tree.addNode(5.5);
	//tree.addNode(15);
	//tree.addNode(25);
	//tree.addNode(17.4);
	//tree.addNode(105);
	//tree.addNode(7);
	//tree.addNode(9);
	//tree.addNode(2);
	//tree.addNode(1);
	//tree.addNode(3);
	//
	//tree.printTreeGraphic();
	//tree.deleteNode(15);
	////tree.printTreeGraphic();
	//tree.deleteNode(7);

	//tree.printTreeGraphic();

	//tree.deleteTree();

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
	tree.printTreeGraphic();

	tree.deleteNode(5.5);

	tree.printTreeGraphic();

	tree.deleteNode(2);
	
	tree.printTreeGraphic();

	tree.deleteNode(1);

	tree.printTreeGraphic();

	tree.deleteNode(7);

	tree.printTreeGraphic();

	tree.deleteNode(25);

	tree.printTreeGraphic();

	tree.deleteNode(15);

	tree.printTreeGraphic();

	tree.deleteNode(9);

	tree.printTreeGraphic();

	tree.deleteNode(105);

	tree.printTreeGraphic();

	tree.deleteNode(17.4);

	tree.printTreeGraphic();

	tree.deleteNode(3);

	tree.printTreeGraphic();
	//данные для проверки создания дерева строк
	//tree.addNode("anadvn");
	//tree.addNode("bnadvn");
	//tree.addNode("knajdvn");
	//tree.addNode("cndvn");
	//tree.addNode("onajdvn");
	//tree.printTreeGraphic();

	////данные для проверки создания дерева double
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
	

	return 0;
}

