#pragma once
#include "ofMain.h"
#include "Meteoro.h"

class Torre {
private:
	ofVec2f m_posicao;
	ofImage m_imagem;	
	Meteoro* meteoro[20];
	int m_numeroMeteoro, m_tempo;
	bool m_ataque, m_status;

public:
	Torre(int x, int y);

	ofVec2f GetPosicao();

	int GetMeteoroNumero();

	bool Radar(ofVec2f posicao);
	bool GetAtaque();
	bool GetStatus();
	bool TempoDeAtaque();
	
	void Atacar(ofVec2f Pos);
	void Update(ofVec2f Pos);
	void SetPosicao(ofVec2f Pos);
	void SetImagem(string nomedoarquivo);
	void Draw(ofVec2f Camera);
	void SetMeteoroNumero(int numero);
	void SetStatus(bool status);
	void SetAtaque(bool ataque);
};