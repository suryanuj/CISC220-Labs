
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = n;
		numSongs=1;
	}

	void DLL::push(string t, string a, int m, int s){
		DNode *temp = first;

		temp = temp->next;


		DNode *n = new DNode(numSongs);
		n->prev = temp->prev;
		temp->prev->next = n;
		n->next = temp;
		temp->prev = n;
		numSongs ++;

//		DNode *n = new DNode (t,a,m,s);
//
//		if (numSongs=0){
//			first->prev=NULL;
//			last->next=NULL;
//			n.song
//		}
//		else {
//			DNode *temp = last;
//			int x = temp->song;
//			prev->last
//
//
//			last->prev=
		}



