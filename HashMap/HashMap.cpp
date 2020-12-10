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
#include <iostream>
#include <cstring>
using namespace std;

hashMap::hashMap(bool hash1, bool coll1) {
	map=new hashNode*[251];
	for( int i=0;i<251;i++){
		map[i]=NULL;
	}

	first="";
	numKeys=0;
	mapSize=251;
	hashfn=hash1;
	collfn=coll1;
	collisions=0;
	hashcoll=0;
}

void hashMap::addKeyValue(string k, string v) {


	while(map[k] != NULL){
		if (map[k] == v){
			*tmp=k
			while(tmp->next!=NULL){
			tmp=tmp->next;
			}
			tmp->next=v;
		}

		else{
			hashMap();
		}

	}

	if (map[k] == NULL){
		map[k]=v;
	}

	int counter=0;

	for (int i=0; i<mapSize; i++){
		if (map[i]!= NULL) ;
			counter+=1;
	}

	if (counter>(mapSize*.7)){
		reHash();
	}
}


int hashMap::getIndex(string k) {


	int sumNull=0;
	for (int i=0; i<mapSize; i++){
		if(map[i]==NULL){
			sumNull=sumNull+1;
		}
	}

	if (sumNull >= (.3*mapSize)){
		calcHash1(k);
	}
	else{
		reHash();
	}

}

int hashMap::calcHash2(string k){

	int sum=0;
	for (int i=0; i<k.length(); i++){
		sum=+(int(k[i]));
	}

	return sum%mapSize;

}
int hashMap::calcHash1(string k){

	int sum=0;
	for (int i=0; i<k.length(); i++){
		sum=+(int(k[i])*7)+i;
	}

	return sum%mapSize;


}
bool hashMap::isPrime(int n){
	if (n%2 == 0 || n%3 == 0){
		return false;
	}
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

int hashMap::getClosestPrime(int n) {
	int prime = n;
	bool flag = true;

	while (flag) {
		prime++;

		if (isPrime(prime))
			flag = false;
	}

	return prime;
}
void hashMap::reHash() {


	int sumNull=0;
	for (int i=0; i<mapSize; i++){
		if(map[i]==NULL){
			sumNull=sumNull+1;
		}
	}

	if (sumNull < (.3*mapSize)){
		int newMapSize=mapSize*2;
		mapSize=getClosestPrime(newMapSize);
	}
	//int newMap[mapSize];
	//int counter=0;
	//for (int i=0; i<mapSize;i++){
		//newMap[i]=map[i];
		/*while(map[i]->next!=NULL){
			newmap[i]->next=map[i]->next;
			newmap->next
	}*/
	//**map=mapSize;
}


int hashMap::coll1(int h, int i, string k) {

	while (map[i] != NULL) {
		int newnum=0;
		for (int i=0; i<k.length(); i++){
			newnum=+(int(k[i])+(i^i));
		}
		newnum=newnum%mapSize;

//		if (newnum == NULL)
//			return i=newnum;
//	}
		if (newnum == 0)
		return i=newnum;
	}
}


int hashMap::coll2(int h, int i, string k) {
	while (map[i] == NULL) {
		i=i+1;

		if (i>=mapSize){
			i=0;
		}
	}
}

int hashMap::findKey(string k) {
//NOTE: THIS METHOD CANNOT LOOP from index 0 to end of hash array looking for the key.  That destroys any efficiency in run-time. 
	int hash = calcHash1(k);

	if (map[hash] != NULL){
		return hash;
	}
	else{
		return -1;
	}

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


