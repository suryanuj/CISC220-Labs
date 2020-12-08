/*
 * HashMap.cpp
 *
 *  Created on: May 4, 2020
 *      Author: 13027
 */


#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <math.h>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {

	if (hash1 = true){
		calcHash1(k);
	}
	else {
		calcHash2(k);
	}


	if (coll1 = true){
		coll1(h,i,k);
	}

	else {
		coll2(h,i,k);
	}

//	int mapSize[0];
//	for (int i=0; i<mapSize;i++){
//		mapSize[i]=NULL;
//	}
}
void hashMap::addKeyValue(string k, string v) {


	while(hashMap[k]!=NULL){
		if (hashMap[k]==v){
			*tmp=k
			while(tmp->next!=NULL){
			tmp=tmp->next;
			}
			tmp->next=(whatever is being hashed)
		}

		else{
			hashMap();
		}

	}

	if (hashMap[k]==NULL){
		hashMap[k]=v;
	}

	int counter=0;

	for (int i=0; i<mapSize; i++){
		if (hashMap[i]!= NULL) ;
			counter+=1;
	}

	if (counter>(hashMap*.7)){
		rehash()
	}
}




}
int hashMap::getIndex(string k) {

	if (){


}

int hashMap::calcHash2(string k){
}
int hashMap::calcHash1(string k){
}
void hashMap::getClosestPrime() {
}
void hashMap::reHash() {
	mapSize=mapSize*2;
	int values1[mapSize];
	int counter=0;
	for (int i=0; i<mapSize;i++){
		values1[i]=map[i];
	}
	map=values1;
	delete values1;
}
}
int hashMap::coll1(int h, int i, string k) {
}
int hashMap::coll2(int h, int i, string k) {
}
int hashMap::findKey(string k) {
//NOTE: THIS METHOD CANNOT LOOP from index 0 to end of hash array looking for the key.  That destroys any efficiency in run-time. 
}


void hashMap::printMap() {
	cout << "In printMap()" << endl;
	for (int i = 0; i < mapSize; i++) {
		//cout << "In loop" << endl;
		if (map[i] != NULL) {
			cout << map[i]->keyword << ": ";
			for (int j = 0; j < map[i]->currSize;j++) {
				cout << map[i]->values[j] << ", ";
			}
			cout << endl;
		}
	}
}


