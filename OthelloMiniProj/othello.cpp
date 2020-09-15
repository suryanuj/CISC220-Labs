/*
 * othello.cpp
 *
 *  Created on: Sep 11, 2020
*      Author: Suryanuj G.
*      Partner: Nicholas P.
 */
#include "othello.hpp"

//playGame Method:


Othello::Othello(){
	player1();
	player2();
	player2.setPiece('B');
	numPlayers=0;
}

Othello::Othello(string st1, char c){
	player1(st1,c);
	player2();
	numPlayers=1;
}

Othello::Othello(string st1, char c, string st2, char c2){
	player1(st1,c);
	player2(st2,c);
	numPlayers=2;
}






void Othello::playGame(){
	 makemat();
	 printmat();
	 /*bool play = true;
	 int fullsqrs = 0;
	 player p = p1;
	 bool whichp = true;
	 bool turn = true;

	 if (rand()%2 == 0) { // p1 plays first
		p = p2;
		turn = false;
		whichp = false;
	 }

	 while ((play) && (fullsqrs < 64)){
		cout << endl << p.name <<" ("<<p.piece<<") choose your square: "<<endl;

		if ((numplayers == 2) || ((numplayers == 1) && turn)){
			placepiece(p);
		}

		else if ((numplayers == 0) || ((numplayers == 1) && (turn == false))){
			compplacepiece(p);
		}

		turn = !turn;
		printmat();
		if (whichp) {
			p = p2;
			whichp = false;
		}
		else {
			p=p1;
			whichp = true;
		}

		fullsqrs+=1;*/
	}
	//ckwin();

//}
/* *************************************************************************
and code for the main function, which should be in its own file with a .cpp
extension, located in the same project folder as your Othello Class and your Player
Class files
****************************************************************************/
