/*
 * Dictionary.h
 *
 *  Created on: Mar 28, 2017
 *      Author: hugom
 */

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include "Word.h"
#include <string>
#include <vector>

using namespace std;
using std::vector;

class Dictionary {
public:
	Dictionary();
	void add_word(Word* a);
	Word* select_word();
	~Dictionary();
private:

	vector<Word*> _word_list;
};

#endif /* DICTIONARY_H_ */
