#include "SlotRight.h"
#include "Game.h"
SlotRight::SlotRight()
{
	TheTextureManager::Instance()->load("../Assets/textures/Lucky7.png",
		"SlotrightSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar1.png",
		"SlotrightBar1", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar2.png",
		"SlotrightBar2", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bell.png",
		"SlotrightBell", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherries.png",
		"SlotrightCherries", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/clover.png",
		"SlotrightClover", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/heart.png",
		"SlotrightHeart", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/lemon.png",
		"SlotrightLemon", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/melon.png",
		"SlotrightMelon", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SlotrightSeven");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(590, 300));
	setType(SLOT_RIGHT);
}

SlotRight::~SlotRight()
{
}

void SlotRight::draw()
{

}

void SlotRight::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}


void SlotRight::update()
{
}

void SlotRight::clean()
{
	TextureManager::Instance()->clean();
}
