/*
 * BST.cpp
 *
 *  Created on: Oct 30, 2020
 *      Author: Suryanuj Gupta & Nicholas Perugini
 */

#include "BST.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}

BST::BST(string s) {
	root = new TNode(s);
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}

	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}

	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}

	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}

	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}

	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

bool BST::insert(string s){
	TNode *tmp1 = new TNode(s);
	if (root != NULL){
		TNode *tmp2 = root;

		while (tmp2 != NULL){
			if((tmp1->student->last) > (tmp2->student->last)){
				if(tmp2->right == NULL){
					tmp2->right = tmp1;
					tmp1->parent = tmp2;
					setHeight(tmp1);
					return true;
				}
				tmp2 = tmp2 ->right;
			}

			else if ((tmp1->student->last) < (tmp2->student->last)){
				if(tmp2->left == NULL){
					tmp2->left = tmp1;
					tmp1->parent = tmp2;
					setHeight(tmp1);
					return true;
				}
				tmp2 = tmp2->left;
			}

			else if (tmp1->student->last == s){
				return false;
			}
		}
	}

	else{
		root = tmp1;
		setHeight(tmp1);
		return true;
	}
	return false;
}

TNode * BST::findRec(TNode *root, string s){
	if (root==NULL){
		return NULL;
	}

	else if ((root->student->last).compare(s)==0){
		return root;
	}

	else if ((root->student->last).compare(s)<0){
		return findRec(root->right,s);
	}

		return findRec(root->left,s);
	}

TNode *BST::find(string s){
	return findRec(root,s);
	}

void BST::printTreeIO(TNode *n) {
	if (n == NULL) {
		return;
	}

	else {
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreePre(TNode *n){
	if (n == NULL) {
			return;
		}

	else {
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BST::printTreePost(TNode *n){
	if (n == NULL) {
			return;
	}
	else {
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
		}
}

TNode *BST::remove(string s){
	TNode * tmp = find(s);
	        if(tmp->right == NULL && tmp->left == NULL){
	                return removeNoKids(tmp);
	        }

	        else if(((tmp->right == NULL) && (tmp->left != NULL)) || ((tmp->right != NULL) && (tmp->left == NULL))){
	                if(tmp->left == NULL){
	                        return removeOneKid(tmp, false);
	                }

	                else if(tmp->right == NULL){
	                        return removeOneKid(tmp, true);
	                }
	        }

	        else if(((tmp->right != NULL) && (tmp->left != NULL))){		//Root case
	        	TNode * tmp2 = tmp;
					tmp2 = tmp2->left;

					while(tmp2->right != NULL){
						tmp2 = tmp2->right;
					}
					tmp->student->phrase = tmp2->data->phrase;

					if(tmp2->left == NULL){
						removeNoKids(tmp2);
					}

					else{
						removeOneKid(tmp2, true);
					}
			        return tmp2;
				}
}

TNode *BST::removeNoKids(TNode *tmp){
	    if(tmp->parent->student->last < tmp->student->last){
	                tmp->parent->right = NULL;
	        }

	        else{
	                tmp->parent->left = NULL;
	        }
        setHeight(tmp->parent);
	    return tmp;
	}

TNode *BST::removeOneKid(TNode *tmp,bool leftFlag){
	 if(tmp->parent->left==tmp){
	                if(leftFlag==true){
	                        tmp->parent->left = tmp->left;
	                        tmp->left->parent = tmp->parent;
	                }

	                else{
	                        tmp->parent->left = tmp->right;
	                        tmp->right->parent = tmp->parent;
	                }
	                TNode *tmpRem=tmp;

	                while(tmpRem->left!=NULL){
	                	tmpRem=tmpRem->left;
	                }
	                setHeight(tmpRem);
	        }
	        else {
	                if(leftFlag==true){
	                        tmp->parent->right = tmp->left;
	                        tmp->left->parent = tmp->parent;
	                }

	                else{
	                        tmp->parent->right = tmp->right;
	                        tmp->right->parent = tmp->parent;
	                }
	                TNode *tmpRem=tmp;

	                while(tmpRem->right!=NULL){
	                	tmpRem=tmpRem->right;
	                	                }
	                	                setHeight(tmpRem);
	        }
	        return tmp;
}

void BST::setHeight(TNode * n){
	while(n!=root){
		n=n->parent;
		if(n->right != NULL && n->left != NULL){
			if((n->right->height < n->left->height)){
				n->height = n->left->height+1;
			}

			else{
				n->height = n->right->height + 1;
			}
		}

		else if((n->left==NULL) && (n->right==NULL)){
			n->height=1;
		}

		else if(n->left == NULL){
			n->height = n->right->height+1;
		}

		else{
			n->height = n->left->height + 1;
		}
	}
}
