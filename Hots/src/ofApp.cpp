#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofSetFrameRate(60);

	personagem = new Personagem();
	flecha = new Flecha();
	map = new Mapa();

	torres[0] = new Torre(1880, 1180);
	torres[1] = new Torre(1880, 480);
	torres[2] = new Torre(1365, 1700);
	torres[3] = new Torre(2420, 1690);

	TrilhaA.push_back(WayPoint(1206, 1784));
	TrilhaA.push_back(WayPoint(1282, 2171));
	TrilhaA.push_back(WayPoint(1602, 2347));
	TrilhaA.push_back(WayPoint(1991, 2302));
	TrilhaA.push_back(WayPoint(2394, 2287));
	TrilhaA.push_back(WayPoint(2701, 2102));
	TrilhaA.push_back(WayPoint(2706, 1793));
	TrilhaA.push_back(WayPoint(2379, 1596));
	TrilhaA.push_back(WayPoint(1911, 1554));
	TrilhaA.push_back(WayPoint(1514, 1578));

	TrilhaB.push_back(WayPoint(1174, 1320));
	TrilhaB.push_back(WayPoint(1357, 1535));
	TrilhaB.push_back(WayPoint(1670, 1501));
	TrilhaB.push_back(WayPoint(1962, 1514));
	TrilhaB.push_back(WayPoint(2242, 1536));
	TrilhaB.push_back(WayPoint(2557, 1482));
	TrilhaB.push_back(WayPoint(2740, 1240));
	TrilhaB.push_back(WayPoint(2473, 983));
	TrilhaB.push_back(WayPoint(1955, 855));
	TrilhaB.push_back(WayPoint(1503, 915));
	TrilhaB.push_back(WayPoint(1162, 1076));

	InimigosTrilhaA.push_back(Inimigo(1206, 1784));
	InimigosTrilhaB.push_back(Inimigo(1174, 1320));

}

//--------------------------------------------------------------
void ofApp::update() {
	camera.set(personagem->GetPosicao().x - (ofGetWidth() / 2), personagem->GetPosicao().y - (ofGetHeight() / 2));
	
	personagem->Update();
	flecha->Update();

	//  Radar da Torre
	for (int i = 0; i < 4; i++)
		torres[i]->Update(personagem->GetPosicao());
	

	//  Spawn de Inimigos
	if (ofGetElapsedTimeMillis() - Timer >= TempoDeSpawn * InimigosPorSegundo) {
		InimigosTrilhaA.push_back(Inimigo(1206, 1784));
		InimigosTrilhaB.push_back(Inimigo(1174, 1320));
		Timer = ofGetElapsedTimeMillis();
		}

	//  Inimigos na Trilha
	for (unsigned int i = 0; i < InimigosTrilhaA.size(); i++)
		InimigosTrilhaA.at(i).Update(&TrilhaA, personagem->GetPosicao(), TrilhaA.size());
	for (unsigned int i = 0; i < InimigosTrilhaB.size(); i++)
		InimigosTrilhaB.at(i).Update(&TrilhaB, personagem->GetPosicao(), TrilhaB.size());

}

//--------------------------------------------------------------
void ofApp::draw() {
	
	if (Nexus)
		ofBackground(255);

	if (!Nexus) {
		ofBackground(2, 0, 6);
		map->Draw(camera);
		personagem->Draw(camera);
		flecha->Draw(camera);

		for (int i = 0; i < 4; i++)
			torres[i]->Draw(camera);


		for (unsigned int i = 0; i < InimigosTrilhaA.size(); i++)
			InimigosTrilhaA.at(i).Draw(camera);
		for (unsigned int i = 0; i < InimigosTrilhaB.size(); i++)
			InimigosTrilhaB.at(i).Draw(camera);



		if (CapaDeInvisibilidade) {
			for (int i = 0; i < TrilhaA.size(); i++)
				TrilhaA.at(i).Draw(camera);

			for (int i = 0; i < TrilhaB.size(); i++)
				TrilhaB.at(i).Draw(camera);

			for (int i = 0; i < TrilhaA.size(); i++) {
				ofSetColor(255, 255, 255);
				int Contador = i + 1;
				if (Contador >= TrilhaA.size()) Contador = 0;
				ofDrawArrow(TrilhaA.at(i).GetPosicao() - camera, TrilhaA.at(Contador).GetPosicao() - camera, 4);
				}
			for (int i = 0; i < TrilhaB.size(); i++) {
				ofSetColor(255, 255, 255);
				int Contador = i + 1;
				if (Contador >= TrilhaB.size()) Contador = 0;
				ofDrawArrow(TrilhaB.at(i).GetPosicao() - camera, TrilhaB.at(Contador).GetPosicao() - camera, 4);
				}
			}
	}
	if (Nexus) {
		time += ofGetLastFrameTime();
		if (time >= 0.6) {
			Nexus = false;
			time = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	std::cout << key << std::endl;

	//    I
	if (key == 'i') {
		if (CapaDeInvisibilidade)
			CapaDeInvisibilidade = false;
		else
			CapaDeInvisibilidade = true;
	}

	if (key == 'b') {
		Nexus = true;
		personagem->SetPosicao(3401, 1396);
		personagem->SetDirecao(3401, 1396);
	}

	//  Operador "+" 
		if (key == 43) 
			InimigosPorSegundo -= 0.01;	
	//  Operador "-"
		if (key == 45) 
			InimigosPorSegundo += 0.01;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {


	if (button == 0) {
		personagem->Mover(camera.x + x, camera.y + y);
		personagem->SetDirecao(camera.x + x, camera.y + y);
		personagem->rodando = false;
		}

	if (button == 2) {
		flecha->SetStatus(true);
		personagem->Mover(camera.x + x, camera.y + y);
		flecha->SetPosicao(personagem->GetPosicao());
		flecha->SetDirecao(camera.x+x, camera.y + y);
		flecha->Mover(camera.x + x, camera.y + y);
		flecha->atira = true;
		}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	
	if (button == 2) 
		flecha->atira = false;
		
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {
	
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
