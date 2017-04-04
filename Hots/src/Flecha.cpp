#include "Flecha.h"

Flecha::Flecha()
{
	SetStatus(false);
	SetPosicao(GetPosicao());
	SetDirecao(GetPosicao());
	SetVelocidade(0, 0);
	SetImagem("img/Flecha.png");
	gira = 0;
}

void Flecha::Update()
{
	SetVelocidade((GetDirecao() - GetPosicao())*3);

	if (GetPosicao().distance(GetDirecao()) < 1) 
		SetVelocidade(0, 0);
			
	SetPosicao(GetPosicao() + GetVelocidade() * ofGetLastFrameTime());
}

void Flecha::Draw(ofVec2f Camera)
{
	if (GetStatus()) {
		ofImage imagem = GetImagem();
		imagem.setAnchorPercent(0.5, 0.5);
		ofPushMatrix();
		ofTranslate(GetPosicao() - Camera);
		ofRotateZ(gira);
		imagem.draw(0, 0);
		ofPopMatrix();
	}
}

void Flecha::Mover(float x, float y)
{
	gira = ofRadToDeg(atan2f(y - GetPosicao().y, x - GetPosicao().x)) + 90;
}

ofVec2f Flecha::GetPosicao()
{
	return m_posicao;
}

ofVec2f Flecha::GetDirecao()
{
	return m_direcao;
}

ofVec2f Flecha::GetVelocidade()
{
	return m_velocidade;
}

ofImage Flecha::GetImagem()
{
	return m_imagem;
}

bool Flecha::GetStatus()
{
	return m_status;
}

void Flecha::SetPosicao(ofVec2f posicao)
{
	m_posicao = posicao;
}

void Flecha::SetPosicao(float x, float y)
{
	m_posicao.set(x, y);
}

void Flecha::SetDirecao(ofVec2f direcao)
{
	m_direcao = direcao;
}

void Flecha::SetDirecao(float x, float y)
{
	m_direcao.set(x, y);
}

void Flecha::SetVelocidade(ofVec2f velocidade)
{
	m_velocidade = velocidade;
}

void Flecha::SetVelocidade(float x, float y)
{
	m_velocidade.set(x, y);
}

void Flecha::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}

void Flecha::SetStatus(bool status)
{
	m_status = status;
}
