#pragma once
#include "CorridaCarroPacoteHeader.h"

//Prótipo das funções

//Para biblioteca de REDE
void transmitir(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista);
unsigned int receber();
unsigned int processar(unsigned int dados);
