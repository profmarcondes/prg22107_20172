/*
 * Ambiente.h
 *
 *  Created on: Aug 14, 2017
 *      Author: hugom
 */

#ifndef AMBIENTE_H_
#define AMBIENTE_H_

#include <string>
#include <iostream>

using namespace std;

class Ambiente {
private:
	string _nome;
	string _endereco;
	int    _capacidade;

public:
	Ambiente(string nome, string endereco, int capacidade){
		_nome = nome;
		_endereco = endereco;
		_capacidade = capacidade;
	}
	int capacidade() { return _capacidade; }

	static Ambiente* novoAmbiente(){
		string nome, endereco;
		int capacidade;
		cout << "-+- Criando um novo ambiente -+-" << endl;
		cout << "Informe o nome do ambiente: ";
		getline(cin,nome);
		cout << "Informe o endereco: ";
		getline(cin,endereco);
		cout << "Informe a capacidade: ";
		cin >> capacidade;
		return new Ambiente(nome, endereco, capacidade);
	}

};

#endif /* AMBIENTE_H_ */
