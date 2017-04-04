#pragma once
#include "ofMain.h"
#include "WayPoint.h"
#include <vector>


class Inimigo {
private:
	ofVec2f m_posicao, m_novaPosicao;
	ofImage m_imagem;
	int m_wayPoint, m_velocidade = 4;
	bool m_seguirPlayer, m_status;
	float angle;

public:
	Inimigo(int x, int y);

	void Update(vector<WayPoint>* Caminho, ofVec2f Posicao, int Tamanho);
	void Draw(ofVec2f Camera);
	void Mover(int Num);
	bool VerificarDistancia(ofVec2f Posicao, int Distancia);

	ofVec2f GetPosicao();
	ofVec2f GetNovaPosicao();
	ofImage GetImagem();
	int GetWayPoint();
	bool GetStatus();
	bool GetSeguir();

	void SetPosicao(ofVec2f Posicao);
	void SetPosicao(int x, int y);
	void SetImagem(string nomedoarquivo);
	void SetNovaPosicao(ofVec2f Posicao);
	void SetWayPoint(int numero);
	void SetSeguir(bool Conceder);
	void SetStatus(bool Status);
};
