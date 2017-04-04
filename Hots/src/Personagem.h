#pragma once
#include "ofMain.h"
#include "Flecha.h"

class Personagem {

private:
	ofVec2f m_posicao, m_direcao, m_velocidade, m_lastposicao;
	ofImage m_imagem;
	float gira;
	int m_FlechaNumero;
	bool m_disparando, m_status;;

public:
	Personagem();
	void Update();
	void Draw(ofVec2f Camera);
	void Mover(float x, float y);
	
	ofVec2f GetPosicao();	
	ofVec2f GetDirecao();
	ofVec2f GetVelocidade();
	ofImage GetImagem();

	void SetPosicao(ofVec2f posicao);
	void SetPosicao(float x, float y);
	void SetDirecao(ofVec2f direcao);
	void SetDirecao(float x, float y);
	void SetVelocidade(ofVec2f velocidade);
	void SetVelocidade(float x, float y);
	void SetImagem(string nomedoarquivo);
	void SetStatus(bool status);
	
	bool rodando = true;
	bool GetStatus();
	int GetFlechaNumero();
};
