/*
 * DNode.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: Suryanuj Gupta and Nicholas Perugini
 */


#include "DNode.hpp"

//struct Node {
//    int data;
//    struct Node* prev;
//    struct Node* next;
//};

DNode::DNode(string s, string a, int lenmin, int lensec){
	song = new Song(s,a,lenmin,lensec);
	prev=NULL;
	next=NULL;
}

DNode::DNode(){
	song = new Song("unknown","none",0,0);
	prev=NULL;
	next=NULL;
}
