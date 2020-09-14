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


#endif /* OTHELLO_HPP_ */
