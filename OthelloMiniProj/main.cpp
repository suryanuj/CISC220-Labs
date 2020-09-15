/*
 * main.cpp
 *
 *  Created on: Sep 11, 2020
 *      Author: Suryanuj G.
 *      Partner: Nicholas P.
 */

#include <iostream>
#include <stdlib.h>
#include "Othello.hpp"
#include "player.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	Othello game("b1",'B',"s1",'O');
	Othello game2("b1",'B');
	Othello game3;
	game.playGame();
}


