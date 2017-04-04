#pragma once

#include "ofMain.h"
#include "Personagem.h"
#include "Flecha.h"
#include "Mapa.h"
#include "WayPoint.h"
#include "Inimigo.h"
#include "Torre.h"
#include <vector>


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	ofVec2f camera;

	Mapa* map;
	Personagem* personagem;
	Flecha* flecha;
	Torre* torres[4];
	
	float time;

	int Timer = 0; 
	float InimigosPorSegundo = 1;
	float TempoDeSpawn = 10000; 

	bool CapaDeInvisibilidade = false;
	bool Nexus = false;

	vector<WayPoint> TrilhaA;
	vector<WayPoint> TrilhaB;
	vector<Inimigo> InimigosTrilhaA;
	vector<Inimigo> InimigosTrilhaB;
};
