#include "Inimigo.h"

Inimigo::Inimigo(int x, int y)
{
	SetImagem("img/Nave.png");
	SetPosicao(x, y);
	SetWayPoint(0);
	SetStatus(true);
}

void Inimigo::Update(vector<WayPoint>* Caminho, ofVec2f Posicao, int Tamanho)
{
	if (VerificarDistancia(Posicao, 100)) 
		SetSeguir(true);
	else
		SetSeguir(false);

	if (!GetSeguir()) {
		SetNovaPosicao(Caminho->at(GetWayPoint()).GetPosicao());
		Mover(m_velocidade);

		if (VerificarDistancia(GetNovaPosicao(), 2)) {
			SetWayPoint(GetWayPoint() + 1);
			if (GetWayPoint() >= Tamanho)
				SetWayPoint(0);
			}
		}
	if (GetSeguir()) {
		SetNovaPosicao(Posicao);
		Mover(1);
		}

}

void Inimigo::Draw(ofVec2f Camera)
{
	angle = ofRadToDeg(atan2f(GetPosicao().y - GetNovaPosicao().y, GetPosicao().x - GetNovaPosicao().x)) + 90;

	if (GetStatus()) {
		ofVec2f position = GetPosicao() - Camera;
		m_imagem.setAnchorPercent(0.5, 0.5);
		ofPushMatrix();
		ofTranslate(position.x, position.y);
		ofRotateZ(angle);
		m_imagem.draw(0, 0, m_imagem.getWidth() * 0.5, m_imagem.getHeight() * 0.5);
		ofPopMatrix();
		}
}

void Inimigo::Mover(int Num)
{
	if (GetStatus()) 
		SetPosicao(GetPosicao() - ((GetPosicao() - GetNovaPosicao()).normalize() * Num));	
}

bool Inimigo::VerificarDistancia(ofVec2f Posicao, int Distancia)
{
	ofVec2f raioPermitido = (Posicao - GetPosicao());
	float distancia = raioPermitido.length();
	if (distancia <= Distancia) 
		return true;
	else
		return false;
}

int Inimigo::GetWayPoint()
{
	return m_wayPoint;
}

bool Inimigo::GetStatus()
{
	return m_status;
}

bool Inimigo::GetSeguir()
{
	return m_seguirPlayer;
}

ofImage Inimigo::GetImagem()
{
	return m_imagem;
}

ofVec2f Inimigo::GetPosicao()
{
	return m_posicao;
}

ofVec2f Inimigo::GetNovaPosicao()
{
	return m_novaPosicao;
}

void Inimigo::SetPosicao(ofVec2f Posicao)
{
	m_posicao = Posicao;
}

void Inimigo::SetPosicao(int x, int y)
{
	m_posicao.set(x, y);
}

void Inimigo::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}

void Inimigo::SetNovaPosicao(ofVec2f Posicao)
{
	m_novaPosicao = Posicao;
}

void Inimigo::SetWayPoint(int numero)
{
	m_wayPoint = numero;
}

void Inimigo::SetSeguir(bool Conceder)
{
	m_seguirPlayer = Conceder;
}

void Inimigo::SetStatus(bool Status)
{
	m_status = Status;
}
