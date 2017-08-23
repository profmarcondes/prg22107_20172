/*
 * Ingresso.h
 *
 *  Created on: Aug 14, 2017
 *      Author: hugom
 */

#ifndef INGRESSO_H_
#define INGRESSO_H_

class Ingresso {
private:
	string _evento;
	int    _cadeira;
	double _valor;

public:
	Ingresso(string evento, int cadeira){
		_evento = evento;
		_cadeira = cadeira;
		_valor = 0;
	}
	void valor(double valor){ _valor = valor; }
	double valor() { return _valor; }
};

#endif /* INGRESSO_H_ */
