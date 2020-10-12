/*
 * DNode.cpp
 *
 *  Created on: Oct 11, 2020
 *      Author: suryanuj
 */


#include "DNode.hpp"

//struct Node {
//    int data;
//    struct Node* prev;
//    struct Node* next;
//};

DNode::DNode(string s, string a, int lenmin, int lensec){
	song->title=s;
	song->artist=a;
	song->min=lenmin;
	song->sec=lensec;
}

DNode::DNode(){
	song->title="unknown";
	song->artist="none";
	song->min=0;
	song->sec=0;
}


