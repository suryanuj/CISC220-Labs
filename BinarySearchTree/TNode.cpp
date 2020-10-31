/*
 * TNode.cpp
 *
 *  Created on: Oct 30, 2020
 *      Author: Suryanuj Gupta & Nicholas Perugini
 */

#include <iostream>
#include <string>
#include "TNode.hpp"
using namespace std;

TNode::TNode(string s) {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase(s);
}
TNode::TNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	data = new Phrase();
}
TNode::~TNode(){
	cout <<"Deleting "<<data->phrase<<endl;
}
void TNode::printNode() {
	cout << data->phrase<<","<<height<<endl;
}
