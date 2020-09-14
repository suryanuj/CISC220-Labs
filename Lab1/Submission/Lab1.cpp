/*
 * Lab1.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Suryanuj G.
 *      Partner: Nicholas P.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Below are the Function DECLARATIONS
void func1(string s, int ct);
void func2(string s, int len);
void func3(string s, int len);
void func4(string str,int len,int ind1,int size);
void func5(string s, int len, int orig[],int size, int fsize);
void func6(string s, int len, int x, int y);
void func7(char arr[], int len, int rot);
void func8(string s, int len, int arr[], int len2);
void func9(string s7,int len,int msize);
void func10(string s,int len,int msize);
void func11(string s,int len,int msize);
bool func12a(string somechars,int len, char c,int ind);
void func12b(string decipher,int len1,string notchars,int len2,int ind);


int main() {

	cout << "Hello World!" << endl;
	string str0 = "ha";
	int x = 12;
	func1(str0,x);

	string string1 = "ketxlurbaesrwainuts";
	func2(string1,19);

	string string2 = "psheskmarcaphulc";
	func3(string2,16);

	string str3 = "blek_vpbq_utxsreknmoihs_neubr_symluljiwsez_aksivnzdw";
	func4(str3,52,6,34);

	string base1 = "woelihnbatmeudoirhdxkj";
	int orig[] = {2,4,1,7,2,-2,3,1,3,7,-8};
	func5(base1,22,orig,11,3);
	int orig2[]={2,1,3,2,1,-2,8,-3,9,-1,3};
	func5(base1,22,orig2,11,5);

	string s4 = "ekvmburwacvxezq_ypotural_ukinvnterzs_powezikrdpvnbjesbsk!";
	func6(s4, 57, 3, 4);

	char arr5[] = {'a','s','x','j','t','i','h','o','q','e','p','w','v','t','z','m','i','h','y','m','k','d','i','c'};
	int len = 24;
	func7(arr5,len,7);

	string s6 = "xezuhnbl_uiplypdhqlb";
	len = 20;
	int arr6[] = {2351,92837,482,65,1039,233,23095,1,2037,693842,283};
	int len2 = 11;
	func8(s6,len,arr6,len2);

	string s7 = "gboehdkixkwpmngzicosygmeuqlaltcvwdge";
	len = 36;
	func9(s7,len,6);

	string s8 = "gboehdpixkwpangzicjsygmeaqlaltmvwdgeabndckswoshbk";
	len = 49;
	func10(s8,len,7);

	string s9 ="w_orp_eshmueryasaa_nootetkdtbueteei_ars!vsfib_t!e_fslg_!rye_yra_";
	len = 64;
	func11(s9,len,8);

	string somechars="rstlne";
	string test = "arktole";
	for (int i = 0; i < 7; i++) {
		if (func12a(somechars,6,test[i],0)) {
			cout << test[i] << " in charset"<<endl;
		 }
		else {
			cout << test[i] << " not in charset"<<endl;
		 }
	 }

	string decipher = "bchzxivkjndpqsjiffrguxhjtb_firskz_azlckmjoxkrspktc_ctprwepjznftjkyzxtkpwvueqnrqtckuyb!";
	int len1 = 86;
	string notchars = "bcfjkpqruvxz";
	int len1a = 12;
	func12b(decipher,len1,notchars,len1a,0);

	return 0;
}

/**********************************************************************************/
/* Function Definitions                                                           */
/* This is where you write the function definitions                               */
/**********************************************************************************/
	/*****************************************************/


//Below are the Function DEFINITIONS

void func1(string s, int ct) {
	for(int i=0;i<ct;i++){
		cout << s << " ";
	}

	cout << endl;
}

void func2(string s, int len){
	int y=1;
	while (y<len){
		cout << s[y];
		y+=2;
	}

	cout<< endl;
}

void func3(string s, int len) {
	char p[len];
	for(int i=0;i<len;i++){
		p[i]=s[i];
	}

	for(int i=len-1;i>=0;i=i-2){
		cout << p[i];
	}

	cout << endl;
}

void func4(string str,int len,int ind1,int size){
	char p[len];
	int counter=0;

	for(int i=counter;i<ind1;i++){
		p[i]=str[i];
		counter = i;
	}

	for(int i=size+ind1;i>=ind1;i--){
		p[counter]=str[i];
		counter++;
	}

	for(int i=size+ind1;i<=len;i++){
		p[i]=str[i];
	}

	for(int i=0;i<len;i=i+2){
		cout << p[i];
	}

	cout << endl;
}

void func5(string s,int len,int orig[],int size,int fsize){
    int k=size-fsize+1;
    if(k<0)
        return;
    int arr[k];

    for(int i=0;i<k;i++){
        int sum=0;

		for(int j=i;j<i+fsize;j++){
			sum+=orig[j];
		}

        arr[i]=sum;
    }

    for(int i=0;i<k;i++){
        if(arr[i]<len){
            cout << s.at(arr[i]);
        }
    }

    cout << endl;
}


void func6(string s, int len, int x, int y){
	for(int i=0;i<len;i++){
		if(i%x==0 && i%y!=0){
		cout << s[i];
		}

		else if(i%x!=0 && i%y==0){
			cout << s[i];
			}
		}
	cout << endl;
}

void func7(char arr[], int len, int rot){
	for (int i = 0; i < (rot%len); i++) {
		char temp = arr[0];

		for (int j = 0; j < len - 1; j++){
			arr[j] = arr[j + 1];
		}

		arr[len - 1] = temp;
	}

	for (int i =0; i<len;i=i+3){
		cout << arr[i];
	}

	cout << endl;
}

void func8(string s, int len, int arr[], int len2) {
	int count = 0;
	for (int i =0; i<len2; i++){
		for(int j=0; j<sizeof(arr[i]);j++){
			count = count+j;
		}
	}

	int div = count/len;
	cout << s[div] << endl;
}

void func9(string s7,int len,int msize){
	char matrix[msize][msize];
	int k=0;
	for(int i=0;i<msize;i++){
		for(int j=0;j<msize;j++){
			matrix[i][j]=s7[k];
			k+=1;
		}
	}

	for(int i=0; i<msize; i++){
		for (int j=0; j < msize; j++){
			if (i == j)
			cout<<matrix[i][j]<<"";
		}
	}

	cout << endl;
}

void func10(string s,int len,int msize){
	char matrix[msize][msize];
	int k=0;
	for(int i=0;i<msize;i++){
		for(int j=0;j<msize;j++){
			matrix[i][j]=s[k];
			k+=1;
		}
	}

	for(int i=0; i<msize; i++){
		for (int j=0; j < msize; j++){
			if ((i + j) == (msize - 1))
			cout<<matrix[i][j]<<"";
		}
	}

	cout << endl;
}

void func11(string s,int len,int msize) {
	char matrix[msize][msize];
	int k=0;

	for(int i=0;i<msize;i++){
		for(int j=0;j<msize;j++){
			matrix[i][j]=s[k];
			k+=1;
		}
	}

	int t=0, r=0;
	while (r<msize){
		for(t=0; t<msize; t++){
				 cout<<matrix[t][r];
		}

		r+=1;
	}

	cout << endl;
}

bool func12a(string somechars, int len, char c, int ind) {
    if ((ind >= 0 )&& (ind < len))
        return somechars[ind] == c || func12a(somechars, len, c, ind + 1);

    else
    	return false;
}

void func12b(string decipher,int len1,string notchars,int len2,int ind){
	while (ind < len1){
		if(func12a(notchars, len2, decipher[ind],0) == false){
	    	 cout<<decipher[ind];
	    }
		return func12b(decipher,len1,notchars,len2,ind+1);
	}
}
