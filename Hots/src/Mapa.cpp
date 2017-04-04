#include "Mapa.h"

Mapa::Mapa()
{
	SetImagem("img/mapa.jpg");
}

void Mapa::Draw(ofVec2f Camera)
{
	ofVec2f posicao = GetPosicao() - Camera;
	m_mapa.draw(posicao);
}

void Mapa::Update(ofVec2f Cam)
{
	SetPosicao(GetPosicao() - Cam);
}

void Mapa::SetImagem(string nomedoarquivo)
{
	m_mapa.load(nomedoarquivo);
}

ofVec2f Mapa::GetPosicao()
{
	return m_posicao;
}

void Mapa::SetPosicao(ofVec2f Pos)
{
	m_posicao.set(Pos);
}
