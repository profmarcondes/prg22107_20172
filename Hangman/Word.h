/*
 * Word.h
 *
 *  Created on: Mar 28, 2017
 *      Author: hugom
 */

#ifndef WORD_H_
#define WORD_H_

#include <iostream>
#include <string>
using namespace std;

class Word {
public:
	Word(string name, string hint);

	bool hasLetter(char a);
	int missing();
	string str() { return _word; }
	string hint() { return _hint; }
	string visible() { return _visible; }
	int size(){ return _word.size(); }
	void print();
	void reset();

private:
	string _word;
	string _hint;
	string _visible;

};

#endif /* WORD_H_ */
