//============================================================================
// Name        : CalcTemplate.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : No rights reserved!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

template<typename T>
class Display {
public:
	void show(T valor) {
		cout << "= " << valor << endl;
	}
};

template<typename T>
class Teclado {
	T _ultima_entrada;

public:
	Teclado(): _ultima_entrada(0) {}
	char le_entrada(){
		string entrada;
		stringstream ss; //Uso da stringstream para a conversão ser genérica
		//cin >> entrada; //Pega apenas a primeira palavra
		getline(cin,entrada); //Pega a linha toda!
		if ((entrada[0] >= '0') && (entrada[0] <= '9')) { // É um número
			ss << entrada;
			ss >> _ultima_entrada;
			return 0;
		} else {
			return entrada[0];
		}
	}
	T valor(){
		return _ultima_entrada;
	}
};

template<typename T>
class Calculadora {
	T _acc;
	char _last_op;
	Display<T> _display;
	Teclado<T> _teclado;

public:
	Calculadora(): _acc(0), _last_op('+') {}

	void run(){
		char op;

		cout << "Digite um número para inserir na calculadora, ou então uma das operacoes abaixo:" << endl;
		cout << " (+) - soma" << endl;
		cout << " (-) - subtracao" << endl;
		cout << " (*) - multiplicacao" << endl;
		cout << " (/) - divisao" << endl;
		cout << " (=) - apresenta valor do acumulador" << endl;
		cout << " (c) - limpa o acumulador" << endl;
		cout << " (q) - Encerra programa" << endl;

		while(1){
			op = _teclado.le_entrada();
			// Li um número, e tenho uma operacao pendente.
			if(op == 'q')
				return;
			if(op == 'c'){
				limpa();
			} else {
				if(op == '='){
					total();
				} else {
					if(op == 0 && _last_op != 0){
						switch(_last_op){
							case '+':
								soma(_teclado.valor());
								break;
							case '-':
								subtrai(_teclado.valor());
								break;
							case '*':
								multiplica(_teclado.valor());
								break;
							case '/':
								divide(_teclado.valor());
								break;
						}
						total();
					} else {
						_last_op = op;
					}
				}
			}
		}

	}

	void soma(T valor){
		_acc += valor;
	}
	void subtrai(T valor){
		_acc -= valor;
	}
	void multiplica(T valor){
		_acc *= valor;
	}
	void divide(T valor){
		_acc /= valor;
	}
	void limpa(){
		_acc = 0;
	}
	void total(){
		_display.show(_acc);
	}

};

int main() {
	Calculadora<int> calc;
	calc.run();
	Calculadora<float> calc2;
	calc2.run();
	return 0;
}
