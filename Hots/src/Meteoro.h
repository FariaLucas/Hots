#pragma once
#include "ofMain.h"

class Meteoro {
private:
	ofVec2f m_posicao, m_novaposicao;
	ofImage m_imagem;
	bool m_status;
	float gira;

public:

	Meteoro();
	void Update();
	void Draw(ofVec2f Camera);

	ofImage GetImagem();

	ofVec2f GetPosicao();
	ofVec2f GetNovaPosicao();
	
	bool GetStatus();
	bool Parar();

	void Mover(float x, float y);
	void Disparar(ofVec2f posicao);
	void SetPosicao(ofVec2f posicao);
	void SetPosicao(int x, int y);
	void SetNovaPosicao(ofVec2f posicao);
	void SetNovaPosicao(int x, int y);
	void SetStatus(bool status);
	void SetImagem(string nomedoarquivo);
	
};