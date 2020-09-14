/*
 * player.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: suryanuj
 */

#include "player.hpp"

Player::Player (){

	name="computer";
	piece='O';
}


Player::Player (string name1, char piece1){

	name=name1;
	piece=piece1;
}
