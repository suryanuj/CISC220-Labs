/*
 * othello.cpp
 *
 *  Created on: Sep 11, 2020
*      Author: Nicholas Perugini
*      Partner: Suryanuj Gupta
 */
#include "othello.hpp"
#include "player.cpp"

//playGame Method:


Othello::Othello(){
	player1.piece='O';
	player1.name="computer";
	player2.piece='B';
	player2.name="computer";
	numPlayers=0;
}

Othello::Othello(string str1, char c){
	player1.piece=c;
	player1.name=str1;
	player2.piece='O';
	player2.name="computer";
	numPlayers=1;
}

Othello::Othello(string str1, char c1, string str2, char c2){
	player1.name=str1;
	player1.piece=c1;
	player2.name=str2;
	player2.piece=c2;
	numPlayers=2;
}






void Othello::playGame(){
	makemat();
	printmat();
	bool play = true;
	int fullsqrs = 0;
	Player p;
	p=player1;
	bool whichp = true;
	bool turn = true;

	if (rand()%2 == 0) { // p1 plays first
		p = player2;
		turn = false;
		whichp = false;
	}

	while ((play) && (fullsqrs < 64)){
		cout << endl << p.name <<" ("<<p.piece<<") choose your square: "<<endl;

		if ((numPlayers == 2) || ((numPlayers == 1) && turn)){
			placepiece(p);
		}

		else if ((numPlayers == 0) || ((numPlayers == 1) && (turn == false))){
			compplacepiece(p);
		}

		turn = !turn;
		printmat();
		if (whichp) {
			p = player2;
			whichp = false;
		}
		else {
			p=player1;
			whichp = true;
		}

		fullsqrs+=1;
	}
	ckwin();

}
/* *************************************************************************
and code for the main function, which should be in its own file with a .cpp
extension, located in the same project folder as your Othello Class and your Player
Class files
****************************************************************************/
