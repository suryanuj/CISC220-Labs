/*
 * othello.hpp
 *
 *  Created on: Sep 13, 2020
 *      Author: suryanuj
 */

#ifndef OTHELLO_HPP_
#define OTHELLO_HPP_
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Othello {
	string st1;
	char c;
	string st2;
	char c2;

	public:
		Othello();
		Othello(string st1, char c);
		Othello(string st1, char c, string st2, char c2);

};

char makemat()
{
	char matrix[8][8];

	for(int i=0;i<8;i++){
	      for(int j=0;j<8;j++){
	        matrix[i][j]='_';
	      }
	matrix[3][4]='O';
    matrix[3][3]='B';
    matrix[4][4]='B';
    matrix[4][3]='O';

    //cout << matrix <<endl;
    return matrix;
};

void printmat()
{
	cout << matrix <<endl;
}

#endif /* OTHELLO_HPP_ */
