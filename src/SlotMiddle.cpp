#include "SlotMiddle.h"
#include "Game.h"
SlotMiddle::SlotMiddle()
{
	TheTextureManager::Instance()->load("../Assets/textures/Lucky7.png",
		"SlotmiddleSeven", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar1.png",
		"SlotmiddleBar1", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/Bar2.png",
		"SlotmiddleBar2", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/bell.png",
		"SlotmiddleBell", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/cherries.png",
		"SlotmiddleCherries", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/clover.png",
		"SlotmiddleClover", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/heart.png",
		"SlotmiddleHeart", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/lemon.png",
		"SlotmiddleLemon", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("../Assets/textures/melon.png",
		"SlotmiddleMelon", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SlotmiddleSeven");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400, 300));
	setType(SLOT_MIDDLE);
}

SlotMiddle::~SlotMiddle()
{
}

void SlotMiddle::draw()
{

}

void SlotMiddle::draw(std::string imageID)
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;



	TheTextureManager::Instance()->draw(imageID, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void SlotMiddle::update()
{
}

void SlotMiddle::clean()
{
}
