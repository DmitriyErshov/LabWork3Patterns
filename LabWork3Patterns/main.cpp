#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
	Tree<Table> tree;

	Table table1, table2, table3, table4, table5, table6, table7;
	table1.price = 5.5;
	table2.price = 15;
	table3.price = 17.4;
	table4.price = 105;
	table5.price = 7;
	table6.price = 9;
	table7.price = 4;

	tree.addNode(table1);
	tree.addNode(table2);
	tree.addNode(table3);
	tree.addNode(table4);
	tree.addNode(table5);
	tree.addNode(table6);
	tree.addNode(table7);
	tree.printTreeOnConsole();

	cout << endl << "Tree height:" << tree.getTreeHeight();


	return 0;
}

//tree.addNode("anadvn");
//tree.addNode("bnadvn");
//tree.addNode("knajdvn");
//tree.addNode("cndvn");
//tree.addNode("onajdvn");
//tree.addNode(5.5);
//tree.addNode(15);
//tree.addNode(25);
//tree.addNode(17.4);
//tree.addNode(105);
//tree.addNode(7);
//tree.addNode(9);
//tree.addNode(4);
////tree.deleteNode(5);
////tree.deleteNode(7);
////tree.deleteNode(25);