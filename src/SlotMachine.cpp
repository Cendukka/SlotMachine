#include "SlotMachine.h"
#include "Game.h"

SlotMachine::SlotMachine()
{
	TheTextureManager::Instance()->load("../Assets/textures/slotMachineWithSpots.png",
		"Slotmachine", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SlotMachine");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH*0.5, Config::SCREEN_HEIGHT*0.5));
	setType(SLOT_MACHINE);
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;



	TheTextureManager::Instance()->draw("Slotmachine", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);

}

void SlotMachine::update()
{
}

void SlotMachine::clean()
{
}
