#include <iostream>

#include "Ambiente.h"
#include "Evento.h"
#include "Usuario.h"
#include "Compra.h"

using namespace std;

int main()
{
    cout << "Ingresso.com" << endl;

    Ambiente * cic = Ambiente::novoAmbiente();
    Evento* meuEvento = Evento::novoEvento();

    meuEvento->defineAmbiente(cic);

    Usuario * hugo = new Usuario("Hugo Marcondes", "hugo.marcondes@ifsc.edu.br");
    hugo->concedeDesconto(0.5);

    Compra* minhaCompra = new Compra(hugo);

    if(meuEvento->ingressosDisponiveis()){
    	Ingresso * tkt = meuEvento->compraIngresso();
    	minhaCompra->incluiIngresso(tkt);
    }

    minhaCompra->calculaValor();

    cout << "O valor total da compra foi de R$ " << minhaCompra->valor() << endl;

    return 0;
}
