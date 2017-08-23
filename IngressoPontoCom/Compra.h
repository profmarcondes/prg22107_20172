/*
 * Compra.h
 *
 *  Created on: Aug 10, 2017
 *      Author: hugom
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#include <vector>
#include "Usuario.h"
#include "Ingresso.h"

using namespace std;

class Compra {
private:
	double    _valor_total;
	Usuario*  _comprador;
	vector<Ingresso*> _ingressos;

public:
	Compra(Usuario* comprador) {
		_valor_total = 0;
		_comprador = comprador;
	}

	void calculaValor(){
		//Loop pra percorrer vetor de ingressos
		for (vector<Ingresso*>::iterator it = _ingressos.begin() ; it != _ingressos.end(); ++it)
		   _valor_total += (*it)->valor();
		_valor_total = _comprador->aplicaDesconto(_valor_total);
	}

	bool incluiIngresso(Ingresso* tkt){
		_ingressos.push_back(tkt);
		return true;
	}

	double valor(){ return _valor_total; }

};

#endif /* COMPRA_H_ */
