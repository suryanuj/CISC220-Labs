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
#include "player.cpp"
using namespace std;

static int boardSize = 8;

class Othello {

		char matrix[9][9];
		Player player1;
		Player player2;
		int numPlayers;

	public:
		Othello();
		Othello(string st1, char c);
		Othello(string st1, char c, string st2, char c2);



	void makemat(){
		//char matrix[9][9];

		for(int i=1;i<9;i++){
			  for(int j=1;j<9;j++){
				matrix[i][j]='_';
			  }
		}

		matrix[4][5]='O';
		matrix[4][4]='B';
		matrix[5][5]='B';
		matrix[5][4]='O';

		//cout << matrix <<endl;
		//return matrix;

	}

	void printmat(){

		string charString="-01234567";
		for(int i=0; i<9; i++){
			matrix[0][i]=charString[i];
		}

		for(int i=1; i<9; i++){
			matrix[i][0]=charString[i];
		}

		int counter=0;
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				cout << matrix[i][j]<<"\t";
				counter++;

				if(counter%9==0){
					cout << endl;
				}
			}
		}
	}


	void placepiece(string player, char piece){
		int x;
		int y;

	  	bool flag=true;
	  	while(flag){
			cout<<"enter the x coordinate on the board: ";
				cin >> x;

			cout<<"enter the y coordinate on the board: ";
				cin >> y;

			if((x>=0 && x<=7)&&(y>=0 && y<=7)){
	        	if(matrix[x+1][y+1]=='_'){
	        		matrix[x+1][y+1]=piece;
	        		flag=false;
	        	}
	        }

			int flipped=countandflippieces();

			if(flipped<=0){
				cout << "Player forfeits turn!" << endl;
	      }
	    }
	}

	int countandflippieces(int i, int j, string player, char piece){

		//Checks down
		if(matrix[i+2][j+1]!=piece && matrix[i+2][j+1]!='_'){
	  	int counter=0;

	  	for(int k=i+2;k<(8-k);k++){
	  		if(matrix[k][j+1]==piece){
	  			for(int k=i+2;matrix[k][j+1]==piece;k++){
	  				counter++;
	  				matrix[k][j]=piece;}
	  			}
	    	}
		}
	}

	void ckwin(){
		int underScoreCount;
		int counter1;
		int counter2;
		bool canCheck=false;

		for(int i=1;i<9;i++){
			for(int j=1;j<9;i++){
				if(matrix[i][j]=='_'){
					underScoreCount++;
				}
			}
		}

		if(underScoreCount==0){
		for(int i=1;i<9;i++){
			for(int j=1;j<9;i++){
				if(matrix[i][j]==player1.getPiece()){
					counter1++;
				}
	        else {
	          counter2++
	          }
			}
	    }
	  }

	  if(counter1>counter2){
	    cout << "Player 1 won with: " << counter1 << "versus" << counter2 << endl;
	  }

	  else if(counter2>counter1){
	    cout << "Player 1 won with: " << counter1 << "versus" << counter2 << endl;
	  }

	  else{
	    cout << "Tie" << endl;
	  }

}

	void compplacepiece(Player p){

	}


};

#endif /* OTHELLO_HPP_ */
