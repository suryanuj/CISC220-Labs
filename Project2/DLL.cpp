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
						first = tmp->next;
						first->prev=NULL;
						numSongs--;
		 			}
					else if(tmp->next== NULL) { //REMOVES FROM LAST
						pop(); //IMPLEMENT POP METHOD HERE ONCE WORKING
		      			}
					else {  //REMOVES FROM MIDDLE
		       				tmp->prev->next=tmp->next;
						tmp->next->prev = tmp->prev;
						numSongs--;
		     		 	}
		      			cout << tmp->song->title <<", "<<tmp->song->artist<<"..............."<<tmp->song->min<<":"<<tmp->song->sec<< endl;
		      			delete tmp;
		      			return 1;

				 }
		  	}
		  	return 0;
		}
	Song *DLL::pop() {
		if(numSongs>1){
			DNode *temp = last;
			Song *x = temp->song;  //ASK TA
			last = last->prev;
			delete temp;
			last->next = NULL;
			numSongs--;
			return x;
		}
		else{
			DNode *temp = last;
			Song *x = temp->song;  //ASK TA
			delete temp;
			first->prev=NULL;
			first->next=NULL;
			last->prev=NULL;
			last->next=NULL;
			numSongs=0;
			return x;
		}
	}

	void DLL::moveUp(string t){
		DNode *tmp;
		DNode *swapWith;
		for (tmp = first;  tmp->song->title != t; tmp = tmp->next){
			if(tmp->prev==NULL){
				DNode *ogfirst=first;

				remove(first->song->title);		//removes original first

				first=ogfirst->next;	//Sets new first
				first->prev=NULL;		//Sets new first prev to null

				push(ogfirst->song->title,ogfirst->song->artist,ogfirst->song->min,ogfirst->song->sec);
				delete ogfirst;
				}

			tmp=tmp->next;
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
		if(tmp->next==NULL;){			//Case if we are moving last element forward
			DNode *a=tmp->prev->prev;
			DNode *b=tmp->prev;
			DNode *c=tmp;

			a->next=c;
			c->prev=a;
			c->next=b;
			b->prev=c;
			b->next=NULL;
		}
		if(swapWith->prev==NULL;){								//Condition if node and swap node prev is first

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
	void DLL::moveDown(string t){
			DNode *tmp;
			DNode *swapWith;
			for (tmp = first;  tmp->song->title != t; tmp = tmp->next){
				if(tmp->next==NULL){
					DNode *oglast=last;
					DNode *firstHolder=first;

					remove(last->song->title);		//Removes last Node

					last=oglast->prev;				//Sets last Node to node to previous to last node
					last->next=NULL;

					oglast->next=first->next;		//Sets last Node in list to first Node in list
					first=oglast;
					first->prev=NULL;

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
			if(swapWith->next==NULL){							//Condition if node and swap node only have one node next to them
				DNode *a=tmp->next;
				DNode *b=tmp;
				DNode *c=tmp->prev;

				a->prev=c;
				c->next=a;
				b->next=NULL;
				b->prev=a;
				a->next=b;
			}
			if(tmp->prev==NULL){
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

	DLL::~DLL(){						//Not sure if this function works. Once we create random we can test everything.
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

	void DLL::makeRandom(){
		DNode *templast = NULL;
		DNode *tempfirst = first;
		DNode *tempfirst_next=NULL;
		DNode *templast_next=NULL;

		for (int i=1; i <numSongs; i++){
			tempfirst=tempfirst->next;
			templast=tempfirst->next;
			templast->prev=NULL;

			tempfirst->next=NULL;
			tempfirst=first;

			tempfirst_next=tempfirst->next;
			tempfirst_next->prev=tempfirst;

			templast_next->next=templast->next;
			templast_next->prev=templast;

			first=templast;
			last=tempfirst;
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
	}
