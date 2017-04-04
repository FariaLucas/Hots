#pragma once
#include "ofMain.h"


class Flecha {
private:
	ofVec2f m_posicao, m_direcao, m_velocidade;
	ofImage m_imagem;
	float gira;
	bool m_status;

public:
	Flecha();
	
	void Update();
	void Draw(ofVec2f Camera);
	void Mover(float x, float y);

	
	ofVec2f GetPosicao();
	ofVec2f GetDirecao();
	ofVec2f GetVelocidade();
	ofImage GetImagem();

	bool GetStatus();
	
	void SetPosicao(ofVec2f posicao);
	void SetPosicao(float x, float y);
	void SetDirecao(ofVec2f direcao);
	void SetDirecao(float x, float y);
	void SetVelocidade(ofVec2f velocidade);
	void SetVelocidade(float x, float y);
	void SetImagem(string nomedoarquivo);

	void SetStatus(bool status);
	
	bool atira = false;
};