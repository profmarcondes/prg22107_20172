/*
 * Hangman.h
 *
 *  Created on: Mar 28, 2017
 *      Author: hugom
 */

#ifndef HANGMAN_H_
#define HANGMAN_H_

#include <algorithm>
#include <vector>
#include "Dictionary.h"
#include "Player.h"

#include <iostream>
using namespace std;

class Player;

class Hangman {
public:
	Hangman(Player * p);
	bool run();
	int  gameScore();

private:
	void printStatus();
	Player *	 _player;
	Dictionary 	 _vocabulary;
	Word * 		 _hang_word;
	vector<char> _wrong_tries;
};

#endif /* HANGMAN_H_ */
