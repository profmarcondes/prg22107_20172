//============================================================================
// Name        : HelloOO.cpp
// Author      : Prof. Marcondes
// Version     : v0.1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class Pessoa {
    //Atributos
    private:
        int _idade;

    //Metodos
    public:
        Pessoa(){ _idade = 0; }
        Pessoa(int idade){ _idade = idade; }
        int idade(){ return _idade; }
        void parabens_pra_voce(){ _idade++; }
        //void idade(int idade) { if(idade >0) _idade = idade; }
};

int main()
{
    cout << "Hello world!" << endl;

    Pessoa meuObjeto(37);

    cout << "A idade do meuObjeto é " << meuObjeto.idade() << endl;

    meuObjeto.parabens_pra_voce();

    cout << "A idade do meuObjeto é " << meuObjeto.idade() << endl;

    return 0;
}
