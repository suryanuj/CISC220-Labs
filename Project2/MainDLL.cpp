/*
 * MainDLL.cpp
 *
 *  Created on: Oct 15, 2020
 *      Author: Suryanuj Gupta and Nicholas Perugini
 */


#include <iostream>
#include <stdlib.h>
#include "Playlist.hpp"
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	//Playlist *list = new Playlist;
	Playlist *list = new Playlist("Halloween.txt");
}

