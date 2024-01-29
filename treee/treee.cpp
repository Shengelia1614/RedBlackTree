
#include "RedBalckTree.h"
#include <iostream>

using namespace std;
int main()
{
	int find=6;
	//building tree

	RedBlackTree tree;

	tree.insert(30);
	tree.insert(16);
	tree.insert(6);
	tree.insert(106);
	//tree.display();
	tree.insert(53);
	tree.insert(11);
	tree.insert(734);
	tree.insert(17);
	tree.insert(19);
	tree.insert(13);
	tree.insert(5);
	tree.insert(147);
	tree.insert(23);
	tree.insert(31);
	tree.insert(32);
	tree.insert(19);


	tree.display();
	/*
	*/
	//testing function that checks if element exists, is useful to use before deleting
	
	cout << endl << "does " << find << " exist  " << tree.realsearch(find) << endl;
	//deleting member
	tree.realdeletor(53);
	
	tree.realdeletor(6);

	tree.realdeletor(11);
	tree.realdeletor(147);
	tree.realdeletor(17);


	cout << endl << "does "<<find<<" exist  " << tree.realsearch(find) << endl;
	cout << endl;

	//testing ather things

	tree.display();
	cout << endl;
	RedBlackTree secondtree(tree);
	secondtree.display();
	cout << endl;
	RedBlackTree thirdtree;
	thirdtree = secondtree;
	thirdtree.display();
	cout << endl;


}

