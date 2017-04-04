#include "Meteoro.h"

Meteoro::Meteoro()
{
	SetStatus(false);
	SetImagem("img/Meteoro.png");
}

void Meteoro::Update()
{
	if (GetStatus()) {	
		if (Parar()) 
			SetPosicao(GetPosicao() - ((GetPosicao() - GetNovaPosicao()).normalize() * 3.5));
		else
			SetStatus(false);
		
		if (GetPosicao() == GetNovaPosicao()) 
			SetStatus(false);
	}
}

void Meteoro::Draw(ofVec2f Camera)
{
	if (GetStatus()) {
		ofVec2f position = GetPosicao() - Camera;
		m_imagem.setAnchorPercent(0.5, 0.5);
		float angle = ofRadToDeg(atan2f(GetPosicao().y - GetNovaPosicao().y, GetPosicao().x - GetNovaPosicao().x)) + 40;

		ofPushMatrix();
		ofTranslate(position.x, position.y);
		ofRotateZ(angle);
		m_imagem.draw(0, 0);
		ofPopMatrix();
	}
}

void Meteoro::Mover(float x, float y)
{
	gira = ofRadToDeg(atan2f(y - GetPosicao().y, x - GetPosicao().x)) + 150;
}

void Meteoro::Disparar(ofVec2f posicao)
{
	SetNovaPosicao(posicao);
	SetStatus(true);
}

bool Meteoro::Parar()
{
	ofVec2f raio = (GetPosicao() - GetNovaPosicao());
	float distancia = raio.length();

	if (distancia >= 2) 
		return true;
	else
		return false;
}

ofImage Meteoro::GetImagem()
{
	return m_imagem;
}

ofVec2f Meteoro::GetPosicao()
{
	return m_posicao;
}

ofVec2f Meteoro::GetNovaPosicao()
{
	return m_novaposicao;
}

bool Meteoro::GetStatus()
{
	return m_status;
}

void Meteoro::SetPosicao(ofVec2f posicao)
{
	m_posicao = posicao;
}

void Meteoro::SetPosicao(int x, int y)
{
	m_posicao.set(x, y);
}

void Meteoro::SetNovaPosicao(ofVec2f posicao)
{
	m_novaposicao = posicao;
}

void Meteoro::SetNovaPosicao(int x, int y)
{
	m_novaposicao.set(x, y);
}

void Meteoro::SetStatus(bool status)
{
	m_status = status;
}

void Meteoro::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}
