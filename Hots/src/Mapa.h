#pragma once
#include "ofMain.h"

class Mapa {
private:
	ofImage m_mapa;
	ofVec2f m_posicao;

public:
	Mapa();

	ofVec2f GetPosicao();
	void SetPosicao(ofVec2f Pos);

	void Draw(ofVec2f Camera);
	void Update(ofVec2f Cam);
	void SetImagem(string nomedoarquivo);
};