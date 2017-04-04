#include "WayPoint.h"

WayPoint::WayPoint()
{
}

WayPoint::WayPoint(int x, int y)
{
	SetPosicao(x, y);
	SetImagem("img/Nave.png");
	SetStatus(true);
}

ofVec2f WayPoint::GetPosicao()
{
	return m_posicao;
}

ofImage WayPoint::GetImagem()
{
	return m_imagem;
}

void WayPoint::Draw(ofVec2f Camera)
{	
	if (GetStatus()) {
		ofSetColor(100, 100, 255);
		ofDrawCircle(GetPosicao() - Camera, 6);
	}
	/*if (GetStatus()) 
		m_imagem.draw(GetPosicao() - Camera);*/
}

void WayPoint::SetPosicao(int x, int y)
{
	m_posicao.set(x, y);
}

void WayPoint::SetStatus(bool status)
{
	m_status = status;
}

void WayPoint::InverterStatus()
{
	if (GetStatus())
		SetStatus(false);
	if (!GetStatus())
		SetStatus(true);
}

void WayPoint::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}

bool WayPoint::GetStatus()
{
	return m_status;
}
