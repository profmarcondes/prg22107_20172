/*
 * Evento.h
 *
 *  Created on: Aug 14, 2017
 *      Author: hugom
 */

#ifndef EVENTO_H_
#define EVENTO_H_

#include <string>
#include <vector>
#include "Ambiente.h"
#include "Ingresso.h"

using namespace std;

class Evento {
private:
	string     _nome;
	string 	   _data;
	Ambiente*  _local;
	double     _valorDoIngresso;
	vector<Ingresso*> _ingressos;

public:
	Evento(string nome, string data, double valor){
		_nome = nome;
		_data = data;
		_valorDoIngresso = valor;
		_local = 0;
	}

	void defineAmbiente(Ambiente * local){
		if(_local == 0){
			_local = local;
			// Criar os ingressos de acordo com a capacidade do local
			int numIngressos = _local->capacidade();
			while(numIngressos--)
				_ingressos.push_back(new Ingresso(_nome, numIngressos));
		} else {
			cout << "Error: Local para este evento ja esta definido." << endl;
		}
	}

	Ambiente* local(){ return _local; }

	int ingressosDisponiveis() { return _ingressos.size(); }

	Ingresso * compraIngresso() {
		Ingresso* tmp = _ingressos.back();
		_ingressos.pop_back();
		tmp->valor(_valorDoIngresso);
		return tmp;
	}

	void devolveIngresso(Ingresso * tkt){
		_ingressos.push_back(tkt);
	}

	static Evento* novoEvento(){
		string nome, data;
		double valor;
		cout << "-+- Criando um novo evento -+-" << endl;
		cout << "Informe o nome do evento: ";
		getline(cin,nome);
		cout << "Informe a data do evento: ";
		getline(cin,data);
		cout << "Informe o valor de ingresso do evento: ";
		cin >> valor;
		return new Evento(nome, data, valor);
	}
};

#endif /* EVENTO_H_ */
