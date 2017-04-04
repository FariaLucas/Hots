#pragma once
#include "ofMain.h"

class WayPoint {

private:
	ofVec2f m_posicao;
	ofImage m_imagem;
	bool m_status;

public:

	WayPoint();
	WayPoint(int x, int y);

	ofVec2f GetPosicao();

	ofImage GetImagem();

	void Draw(ofVec2f Camera);
	
	void SetPosicao(int x, int y);
	void SetStatus(bool status);
	void InverterStatus();
	void SetImagem(string nomedoarquivo);

	bool GetStatus();
};
