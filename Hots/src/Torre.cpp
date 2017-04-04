#include "Torre.h"

Torre::Torre(int x, int y)
{
	m_posicao.x = x;
	m_posicao.y = y;

	SetImagem("img/Torre.png");
	SetAtaque(false);
	SetStatus(true);
	SetMeteoroNumero(0);
	
	for (int i = 0; i < 20; i++) {
		meteoro[i] = new Meteoro(); 
		meteoro[i]->SetPosicao(x + 55, y);
		}
}
void Torre::Update(ofVec2f Pos)
{
	if (GetStatus()) {
		if (Radar(Pos) && TempoDeAtaque()) 
			if (GetMeteoroNumero() <= 20) {
				Atacar(Pos);
				SetMeteoroNumero(GetMeteoroNumero() + 1);
				}
		if (GetMeteoroNumero() >= 20)
			SetMeteoroNumero(22);	
		for (int i = 0; i < 20; i++) 		
		meteoro[i]->Update();			
	}
}

bool Torre::TempoDeAtaque()
{
	if (ofGetElapsedTimeMillis() - m_tempo >= 1000)
		return true;
	else
		return false;
}
void Torre::Atacar(ofVec2f Pos)
{
	meteoro[m_numeroMeteoro]->Disparar(Pos);
	m_tempo = ofGetElapsedTimeMillis();
}

bool Torre::Radar(ofVec2f posicao)
{
	ofVec2f raio = (posicao - GetPosicao());
	float distancia = raio.length();

	if (distancia <= 300)
		return true;
	else
		return false;
}

void Torre::Draw(ofVec2f Camera)
{
	m_imagem.draw(GetPosicao()-Camera);
	
	for (int i = 0; i < 20; i++) 
		meteoro[i]->Draw(Camera); 
}

void Torre::SetMeteoroNumero(int numero)
{
	m_numeroMeteoro = numero;
}

void Torre::SetStatus(bool status)
{
	m_status = status;
}

void Torre::SetAtaque(bool ataque)
{
	m_ataque = ataque;
}

ofVec2f Torre::GetPosicao()
{
	return m_posicao;
}

int Torre::GetMeteoroNumero()
{
	return m_numeroMeteoro;
}

bool Torre::GetAtaque()
{
	return m_ataque;
}

bool Torre::GetStatus()
{
	return m_status;
}

void Torre::SetPosicao(ofVec2f Pos)
{
	m_posicao = Pos;
}

void Torre::SetImagem(string nomedoarquivo)
{
	m_imagem.load(nomedoarquivo);
}
