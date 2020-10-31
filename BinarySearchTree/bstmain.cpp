/*
 * bstmain.cpp
 *
 *  Created on: Oct 30, 2020
 *      Author: Suryanuj Gupta & Nicholas Perugini
 */

#include "BST.hpp"
#include <iostream>
using namespace std;

int main() {
	string arr[] = {"e","g","f","a","c","d","b"};
	BST *tree = new BST();
	for (int i = 0; i < 7; i++) {
		cout << arr[i]<<", ";
		tree->insert(arr[i]);
	}
	cout << endl;
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	tree->clearTree();
	cout <<"************************************" << endl;
	string arr3[] = {"i","was","contemplating","the","immortal","words","of","socrates","who","said,","i","drank","what"};
	for (int i = 0; i < 13; i++) {
		cout << arr3[i]<<", ";
		tree->insert(arr3[i]);
	}
	cout << endl;
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	cout << endl<<"REMOVING DRANK" << endl;
	tree->remove("drank");
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	cout << endl<<"REMOVING IMMORTAL" << endl;
	tree->remove("immortal");
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	cout << endl<<"REMOVING WAS" << endl;
	tree->remove("was");
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	cout << endl<<"REMOVING I" << endl;
	tree->remove("i");
	tree->printTreePre();
	tree->printTreeIO();
	tree->printTreePost();
	tree->clearTree();
	return 0;
}

