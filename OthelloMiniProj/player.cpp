/*
 * player.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Nick Perugini
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "player.hpp"

using namespace std;

Player::Player(){
	name="computer";
	piece='O';
}

Player::Player(string name1, char piece1){
	name=name1;
	piece=piece1;
}

/*void Player::setPiece (char s){
	piece = s;
}

char Player::getPiece(){
	return piece;
}
*/
