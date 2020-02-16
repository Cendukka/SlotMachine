#include "SlotLeft.h"
#include "Game.h"

SlotLeft::SlotLeft()
{
	TheTextureManager::Instance()->load("../Assets/textures/Lucky7.png",
		"SlotleftSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar1.png",
		"SlotleftBar1", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar2.png",
		"SlotleftBar2", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bell.png",
		"SlotleftBell", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherries.png",
		"SlotleftCherries", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/clover.png",
		"SlotleftClover", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/heart.png",
		"SlotleftHeart", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/lemon.png",
		"SlotleftLemon", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/melon.png",
		"SlotleftMelon", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SlotleftSeven");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(210, 300));
	setType(SLOT_LEFT);
}

SlotLeft::~SlotLeft()
{
}

void SlotLeft::draw()
{
	
}

void SlotLeft::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void SlotLeft::update()
{
}

void SlotLeft::clean()
{
}
