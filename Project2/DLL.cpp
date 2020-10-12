
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

		if (numSongs==0){
			DNode *n = new DNode(t,a,m,s);  // makes a new node
			first=n;
			last=n;
			first->prev=NULL;
			first->next=NULL;
			last->prev=NULL;
			last->next=NULL;
			numSongs=1;
		}

		else {
			DNode *temp = last;
			DNode *n = new DNode(t,a,m,s);  // makes a new node
			last=n;
			last->prev=temp;
			last->next=NULL;
			temp->next=last;
			numSongs++;
		}
	}

	void DLL::printList(){
		DNode *tmp = first;

		while (tmp != NULL) {
				tmp->song->printSong();

		}



