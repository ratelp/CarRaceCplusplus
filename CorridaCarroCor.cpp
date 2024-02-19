#pragma once
#include <iostream>
#include "CorridaCarroCorHeader.h"

using namespace std;

//Função para colorir o terminal
void ajustarCor(int corTexto,int corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m";
}

//Função para retornar cor padrão do terminal
void resetCor() {
	cout << padrao;
}