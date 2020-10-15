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
				tmp=tmp->next;

		}
	}
	int DLL::remove(string t){
		DNode *tmp;
		       for (tmp = first;  tmp != NULL; tmp = tmp->next)  {
				if (tmp->song->title== t) {
					if (tmp->prev== NULL) { //REMOVES FROM FRONT
						first = first->next;
						first->prev=NULL;
						numSongs--;
		 			}
					else if(tmp->next== NULL) { //REMOVES FROM LAST
						pop(); //IMPLEMENT POP METHOD HERE ONCE WORKING
		      			}
					else {  //REMOVES FROM MIDDLE
						DNode *tmpPlus=tmp->next;
						DNode *tmpMinus=tmp->prev;
		       			tmpPlus->prev=tmpMinus;
		       			tmpMinus->next=tmpPlus;
						numSongs--;
		     		 	}
		      			cout << "REMOVED: " << tmp->song->title <<", "<<tmp->song->artist<<"..............."<<tmp->song->min<<":"<<tmp->song->sec<< endl;
		      			delete tmp;
		      			return 1;

				 }
		  	}
		  	return 0;
		}
	void DLL::pop() {				//Set return type to void so that it can be used inside remove function
		if(numSongs>1){				//It seemed having it return a song type did not serve any purpose.
			last = last->prev;
			last->next = NULL;
			numSongs--;
		}
		else{
			first=NULL;
			last=NULL;
			first->prev=NULL;
			first->next=NULL;
			last->prev=NULL;
			last->next=NULL;
			numSongs=0;
		}
	}

	void DLL::moveUp(string t){										//Only works if not at the very start of the list
		DNode *tmp=first;
		DNode *swapWith;
		while(tmp->song->title != t){
			tmp=tmp->next;
		}
		if(tmp->prev==NULL){									//This is the only condition that needs to be worked on. It is the condition where it goes from the start of the list to the end

			first=first->next;
			first->prev=NULL;

			push(first->song->title,first->song->artist,first->song->min,first->song->sec);

		}

		swapWith=tmp->prev;
		if(swapWith->prev!=NULL && tmp->next!=NULL){			//Condition if node and swap node are in between two others

			DNode *a=tmp->prev->prev;
			DNode *b=tmp->prev;
			DNode *c=tmp;
			DNode *d=tmp->next;

			a->next=c;
			c->prev=a;
			c->next=b;
			b->prev=c;
			b->next=d;
			d->prev=b;
		}
		else if(tmp->next==NULL){			//Case if we are moving last element forward
			DNode *a=tmp->prev->prev;
			DNode *b=tmp->prev;
			DNode *c=tmp;

			a->next=c;
			c->prev=a;
			c->next=b;
			b->prev=c;
			b->next=NULL;
		}
		else if(swapWith->prev==NULL){								//Condition if node and swap node prev is first

			DNode *a=tmp->prev;
			DNode *b=tmp;
			DNode *c=tmp->next;

			a->next=c;
			a->prev=b;
			c->prev=a;
			b->prev=NULL;
			b->next=a;
		}
	}
	void DLL::moveDown(string t){								//Only works if not at the very end of the list
			DNode *tmp;
			DNode *swapWith;
			for (tmp = first;  tmp->song->title != t; tmp = tmp->next){
				if(tmp->next==NULL){										//This is the only condition that needs to be worked on. It should send the last Node to the start and make it the first Node
					DNode *oglast=last;										//It may have to be rewritten entirely
					DNode *firstHolder=first;

					remove(last->song->title);		//Removes last Node

					last=oglast->prev;				//Sets last Node to node to previous to last node
					last->next=NULL;

					oglast->next=first->next;		//Sets last Node in list to first Node in list
					first=oglast;
					first->prev=NULL;

					//push(firstholder->song->title,firstholder->song->artist,firstholder->song->min,firstholder->song->sec);

					delete oglast;
					delete firstHolder;
					}
				tmp=tmp->next;
			}
			swapWith=tmp->next;
			if(swapWith->next!=NULL && tmp->prev!=NULL){			//Condition if node and swap node are in between two others
				DNode *a=tmp->next->next;
				DNode *b=tmp->next;
				DNode *c=tmp;
				DNode *d=tmp->prev;

				a->prev=c;
				c->next=a;
				c->prev=b;
				b->next=c;
				b->prev=d;
				d->next=b;

			}
			else if(swapWith->next==NULL){							//Condition if node and swap node only have one node next to them
				DNode *a=tmp->next;
				DNode *b=tmp;
				DNode *c=tmp->prev;

				a->prev=c;
				c->next=a;
				b->next=NULL;
				b->prev=a;
				a->next=b;
			}
			else if(tmp->prev==NULL){
				DNode *a=tmp->next->next;
				DNode *b=tmp->next;
				DNode *c=tmp;

				a->prev=c;
				c->next=a;
				c->prev=b;
				b->next=c;
				b->prev=NULL;

			}
		}

	void DLL::listDuration(int *tm,int *ts){
		DNode *tmp = first;

		while (tmp != NULL) {
				*tm+=tmp->song->min;
				*ts+=tmp->song->sec;
				tmp=tmp->next;
		}

		if(*ts>60){				//Converts extra seconds to minutes
			int x=*ts/60;
			*tm+=x;
			*ts=*ts%60;
		}
	}

	DLL::~DLL(){								//This does not work
		DNode *current=first;
		DNode *next;

		while (current != NULL) {
			next=current->next;
			free(current);
			current=next;
		}
		first=NULL;
		last=NULL;
		first->prev=NULL;
		first->next=NULL;
		last->prev=NULL;
		last->next=NULL;
	}

	void DLL::makeRandom(){						//This does not work

//		DNode *last=NULL;
//		while (first->next != NULL){
//			if (last == NULL){
//				last=first->next;
//			}
//			else {
//				last->next=first->next;
//			}
//
//			DNode *next=first->next->next;
//			first->next->next = first;
//			first->next = next;
//			last=first;
//
//			next=first->next;
//			first->next=NULL;
//			first=next;
		DNode* firstNode=first;
		DNode* secondNode=first->next;
		DNode* lastNode = NULL;
		while (secondNode != NULL) {
			/* Append the first element of 'second' to the list. */
			if (lastNode == NULL) {
				lastNode = secondNode;
			}

			else {
				lastNode->next = secondNode;
				lastNode = secondNode;
			}

			/* Cut the head of 'second' from 'second.' */
			DNode* nextNode = secondNode->next;
			secondNode->next = NULL;
			secondNode = nextNode;
			/* Swap the two lists. */
			DNode* tmp = firstNode;
			firstNode = secondNode;
			secondNode = tmp;
		}
	}






		/*DNode *current = first;
		int randnum(1, numSongs);
		for (int i=0; i<numSongs; i++){
			if (*current->next != NULL;){
				current=current->next;
			}
			else {
				current = first;
				current=current->next;

			}
			if (*current->prev !=NULL){
				current -> prev -> next;
				first->prev;
				current->prev;
			}
			first=current;

		}*/
