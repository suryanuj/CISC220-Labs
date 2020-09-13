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

class Player {

	public:
		string name;
		char piece;

		Player ();
		Player (string name1, char piece1);
};




#endif /* OTHELLO_HPP_ */
