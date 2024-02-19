#pragma once
#include <iostream>
#include "CorridaCarroPacoteHeader.h"
#include "CorridaCarroCorHeader.h"

using namespace std;

//variável global para ser utilizada nas funções transmitir e receber
unsigned int rede = 0;

// função para coletar os dados de empacotar e transmitir para variável global rede.
void transmitir(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista) {
	rede = empacotar(passo, cor, posicao, velocidade, pista);
	cout << "Transmitindo dados..." << endl;
	ajustarCor(preto,cor);
	cout << rede;
	resetCor();
}

//Função para receber os dados da variável global e colocar as informações no terminal
unsigned int receber() {
	// variável para o resultado do óleo ser passado como true ou false
	bool resultado;
	cout << "\nRecebendo dados..." << endl;

	//Frame
	ajustarCor(cor(rede),preto);
	cout << "Frame: ";
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << passo(rede) << " ";
	resetCor();

	//Posição
	ajustarCor(cor(rede), preto);
	cout << " Pos: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << posicao(rede) << " ";
	resetCor();

	//Velocidade
	ajustarCor(cor(rede), preto);
	cout << " Vel: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << velocidade(rede) << " ";
	resetCor();

	//Estado da pista
	ajustarCor(cor(rede), preto);
	cout << " Oil: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	if (pista(rede) == 1) {
		cout << " " << "true" << " " << endl;
	}
	else {
		cout << " " << "false" << " " << endl;
	}
	resetCor();
	return rede;
}

// Função que utilizando das informações de receber para gerar a nova posição do carro.
unsigned int processar(unsigned int dados) {
	unsigned short posicaoAtual = posicao(dados);
	unsigned short velo = velocidade(dados);
	unsigned short oleo = pista(dados);
	unsigned short novaPosicao = posicaoAtual + (velo - oleo);
	cout << "Processando dados..." << endl;
	ajustarCor(cor(dados), preto);
	cout << "Próxima posição: " << novaPosicao << "\n\n";
	resetCor();
	return novaPosicao;
}