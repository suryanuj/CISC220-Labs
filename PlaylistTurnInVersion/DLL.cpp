/*
 *	Nick Perugini & Shaun Gupta
 */
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
	void DLL::remove(string t){
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

				 }
		  	}
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
		DNode *ogfirst=first;
		while(tmp->song->title != t){
			tmp=tmp->next;
		}

		if(tmp->prev==NULL && tmp->next!=NULL){									//This is the only condition that needs to be worked on. It is the condition where it goes from the start of the list to the end

			DNode *temp = last;
			DNode *n = new DNode(ogfirst->song->title,ogfirst->song->artist,ogfirst->song->min,ogfirst->song->sec);  // makes a new node
			last=n;
			last->prev=temp;
			last->next=NULL;
			temp->next=last;

			first=first->next;
			first->prev=NULL;

				}

		else if(tmp->prev->prev!=NULL && tmp->next!=NULL){			//Condition if node and swap node are in between two others

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
					last=b;
				}
		else if(tmp->prev->prev==NULL){								//Condition if node and swap node prev is first

					DNode *a=tmp->prev;
					DNode *b=tmp;
					DNode *c=tmp->next;

					a->next=c;
					a->prev=b;
					c->prev=a;
					b->prev=NULL;
					b->next=a;
					first=b;
				}
			}
	void DLL::moveDown(string t){
			DNode *tmp=first;
			while(tmp->song->title != t){
				tmp=tmp->next;
			}
			if(tmp->next==NULL){										//Condition if node is last in list
					DNode *oglast=tmp;
					DNode *firstHolder=first;

					pop();		//Sets last Node to node to previous to last node

					tmp->next=first->next;		//Sets last Node in list to first Node in list
					first=oglast;
					first->next=firstHolder;
					first->prev=NULL;
					firstHolder->prev=first;

					numSongs++; //Adds a song back since pop removes one


			}
			else if(tmp->next->next!=NULL && tmp->prev!=NULL){			//Condition if node and swap node are in between two others
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
			else if(tmp->next->next==NULL){							//Condition if node and swap node only have one node next to them (at end)
				DNode *a=tmp->next;
				DNode *b=tmp;
				DNode *c=tmp->prev;

				a->prev=c;
				c->next=a;
				b->next=NULL;
				b->prev=a;
				a->next=b;
				last=b;
			}
			else if(tmp->prev==NULL){							//Condition if node is first in list
				DNode *a=tmp->next->next;
				DNode *b=tmp->next;
				DNode *c=tmp;

				a->prev=c;
				c->next=a;
				c->prev=b;
				b->next=c;
				b->prev=NULL;
				first=b;

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

	DLL::~DLL(){
			DNode *current=first;

			while (current)
			{
				DNode* next = current->next;
				delete current;
				current = next;
			}

	}

	void DLL::makeRandom(){
		cout << "Shuffling..." << endl;
		DNode *tmp=first;
		int counter=0;
		while(counter<40){
			if(tmp==NULL || tmp==last){
				tmp=first;
			}
			int randnum = rand() % 3+1;
			if(randnum==1){
				moveUp(tmp->song->title);
			}
			else if(randnum==2){
				moveDown(tmp->song->title);		}
			else{
				moveUp(tmp->song->title);
				moveUp(tmp->song->title);
						}
			if(randnum!=2){
				tmp=tmp->next;
			}
			else{
				tmp=tmp->prev;
			}
			counter++;
		}
	}
