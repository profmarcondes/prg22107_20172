/*
 * Usuario.h
 *
 *  Created on: Aug 14, 2017
 *      Author: hugom
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>
using namespace std;

class Usuario {
private:
	string _nome;
	string _email;
	float  _desconto;

public:
	Usuario(string nome, string email): _nome(nome), _email(email), _desconto(0) { }

	double aplicaDesconto(double value){
		if(_desconto < 1 && _desconto > 0)
			return value * (1 - _desconto);
		return value;
	}

	void concedeDesconto(float desconto){
		if (desconto <= 0.5 && desconto > 0)
			_desconto = desconto;
	}
};

#endif /* USUARIO_H_ */
