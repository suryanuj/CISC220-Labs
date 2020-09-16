/*
 * player.hpp
 *
 *  Created on: Sep 13, 2020
 *      Author: suryanuj
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Player {
	string name;
	char piece;

	public:
		Player ();
		Player (string name1, char piece1);

		// Setter
		void setPiece(char s);
		char getPiece();

};




#endif /* OTHELLO_HPP_ */
