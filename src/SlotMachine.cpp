#include "SlotMachine.h"
#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include<sstream>
#include <string>
using namespace std;

SlotMachine::SlotMachine()
{
	SlotMachine::start();
}

SlotMachine::~SlotMachine()
{
}

void SlotMachine::draw()
{
	m_pSlotLabel->draw();
	m_pBetbutton->draw();
	m_pSpinbutton->draw();
	m_pMoneyLabel->draw();
	m_pBetLabel->draw();
	//m_pJackbotLabel->draw();
}

void SlotMachine::update()
{
	m_pBetbutton->setMousePosition(m_mousePosition);
	m_pBetbutton->ButtonClick();
	m_pSpinbutton->setMousePosition(m_mousePosition);
	m_pSpinbutton->ButtonClick();

	if(m_pBetbutton->ButtonClick())
	{
		increaseBet();
	}
	if(m_pSpinbutton->ButtonClick())
	{
		spin();
	}
	
}

void SlotMachine::spin()
{
	decreaseMoney(m_betAmount);
	//check money
	if(getMoney() < 0)
	{
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}
	int spins = (rand() % 50) + 10;
		
		for (int i = 0; i < spins; i++) {
			m_internalPtr++;
				if (m_internalPtr > 8) { m_internalPtr = 0; }
		}
}
void SlotMachine::decreaseMoney(int theBet)
{
	if (m_pSpinbutton->getOnlyRegisterClickOnce() == 0) {
		m_pSpinbutton->setOnlyRegisterClickOnce(1);
		m_credits -= m_betAmount;
		stringstream moneyStream;
		moneyStream << m_credits;
		moneyStream >> m_creditsString;
		m_pMoneyLabel->setText("Money: " + m_creditsString);
		
	}
}




void SlotMachine::clean()
{
	delete m_pSlotLabel;
	delete m_pBetbutton;
	removeAllChildren();
}

void SlotMachine::setMoney(int money)
{
	m_credits = money;
	stringstream moneyStream;
	moneyStream << m_credits;
	moneyStream >> m_creditsString;
}
void SlotMachine::increaseBet()
{
	if (m_pBetbutton->getOnlyRegisterClickOnce() == 0) {
		m_betAmount += 1;
		m_pBetbutton->setOnlyRegisterClickOnce(1);
		cout << m_betAmount << endl;
		if (m_betAmount > 5)
		{
			setBet(1);
		}
		stringstream betStream;
		betStream << m_betAmount;
		betStream >> m_betAmountString;
		m_pBetLabel->setText("Bet: " + m_betAmountString);
	}
}
void SlotMachine::setBet(int bet)
{
	
		m_betAmount = bet;
	
	stringstream betStream;
	betStream << m_betAmount;
	betStream >> m_betAmountString;
}

int SlotMachine::getMoney()
{
	return m_credits;
}

int SlotMachine::getBet()
{
	return m_betAmount;
}


void SlotMachine::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::SLOTMACHINE);
				break;

			}
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinbutton->setMouseButtonClicked(true);
				m_pBetbutton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinbutton->setMouseButtonClicked(false);
				m_pBetbutton->setMouseButtonClicked(false);
				//set the click flags to 0 so you can register clicks again
				m_pBetbutton->setOnlyRegisterClickOnce(0);
				m_pSpinbutton->setOnlyRegisterClickOnce(0);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void SlotMachine::start()
{
	SDL_Color green = { 0, 255, 50, 255 };
	SDL_Color blue = { 0, 50, 255, 255 };
	SDL_Color red = { 255, 00, 00, 255 };
	setMoney(50);
	setBet(1);
	m_credits += getMoney();
	m_betAmount = getBet();
	

	srand((int)time(NULL));
	
	m_internalPtr = (rand() % 9);
	for (int i = 0; i < 9; i++) {
			m_slots[i] = i + 1;
	}

	
	m_pSlotLabel = new Label("**Epic Slot Machine!!**", "Dock51", 80, green, glm::vec2(400.0f, 40.0f));
	m_pSlotLabel->setParent(this);
	addChild(m_pSlotLabel);
	
	m_pMoneyLabel = new Label("Money: "+m_creditsString, "Dock51", 20, blue, glm::vec2(200.0f, 400.0f));
	m_pMoneyLabel->setParent(this);
	addChild(m_pMoneyLabel);
	
	m_pBetLabel = new Label("Bet: "+m_betAmountString, "Dock51", 20, red, glm::vec2(300.0f, 400.0f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);
	/*
	m_pJackbotLabel = new Label(m_creditsString, "Dock51", 80, red, glm::vec2(200.0f, 300.0f));
	m_pJackbotLabel->setParent(this);
	addChild(m_pJackbotLabel);*/
	

	
	
	m_pBetbutton = new BetButton();
	m_pBetbutton->setMouseButtonClicked(false);
	addChild(m_pBetbutton);
	m_pSpinbutton = new SpinButton();
	m_pSpinbutton->setMouseButtonClicked(false);
	addChild(m_pSpinbutton);

	/*m_pInstructionsLabel = new Label("Press 1 to Play", "Dock51", 40, blue, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel->setParent(this);
	addChild(m_pInstructionsLabel);*/
}

