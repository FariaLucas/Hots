#include "Personagem.h"
#include "Flecha.h"
#include "ofApp.h"

Personagem::Personagem() 
{
	SetPosicao(696.012, 1393.16);
	SetDirecao(GetPosicao());
	SetVelocidade(0, 0);
	SetImagem("img/personagem.png");
	gira = 50;
}

void Personagem::Update()
{
	SetVelocidade((GetDirecao() - GetPosicao()) * 1.3);

	if (GetPosicao().distance(GetDirecao()) < 1)
		SetVelocidade(0, 0);
	SetPosicao(GetPosicao() + GetVelocidade() * ofGetLastFrameTime());		
}

void Personagem::Draw(ofVec2f Camera)
{	
	ofImage imagem = GetImagem();
	imagem.setAnchorPercent(0.5, 0.5);
	ofPushMatrix();
	ofTranslate(GetPosicao() - Camera);
	ofRotateZ(gira);
	imagem.draw(0, 0);
	ofPopMatrix();	
}

void Personagem::Mover(float x, float y)
{
	rodando = true;
	gira = ofRadToDeg(atan2f(y - GetPosicao().y, x - GetPosicao().x)) + 140;
}

ofVec2f Personagem::GetPosicao()
{
	return m_posicao;
}



ofVec2f Personagem::GetDirecao()
{
	return m_direcao;
}

ofVec2f Personagem::GetVelocidade()
{
	return m_velocidade;
}

ofImage Personagem::GetImagem()
{
	return m_imagem;
}

void Personagem::SetPosicao(ofVec2f posicao)
{
	m_posicao = posicao;
}

void Personagem::SetPosicao(float x, float y)
{
	m_posicao.set(x, y);
}



void Personagem::SetDirecao(ofVec2f direcao)
{
	m_direcao = direcao;
}

void Personagem::SetDirecao(float x, float y)
{
	m_direcao.set(x, y);
}

void Personagem::SetVelocidade(ofVec2f velocidade)
{
	m_velocidade = velocidade;
}

void Personagem::SetVelocidade(float x, float y)
{
	m_velocidade.set(x, y);
}

void Personagem::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}

void Personagem::SetStatus(bool status)
{
	m_status = status;
}

bool Personagem::GetStatus()
{
	return m_status;
}

int Personagem::GetFlechaNumero()
{
	return m_FlechaNumero;
}
