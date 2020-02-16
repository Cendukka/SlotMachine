#include "SlotMachineScene.h"
#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include<sstream>
#include <string>
using namespace std;


SlotMachineScene::SlotMachineScene()
{
	//Starting and initializing the game
	SlotMachineScene::start();
}

SlotMachineScene::~SlotMachineScene()
{
}

void SlotMachineScene::draw()
{
	//draw all gameobjects and labels
	m_pSlotMachine->draw();
	m_pSlotLabel->draw();
	m_pBetbutton->draw();
	m_pSpinbutton->draw();
	m_pQuitbutton->draw();
	m_pResetbutton->draw();
	m_pMoneyLabel->draw();
	m_pBetLabel->draw();
	m_pWinLabel->draw();
	m_pSlotLeft->draw(m_SlotLeftImageString);
	m_pSlotMiddle->draw(m_SlotMiddleImageString);
	m_pSlotRight->draw(m_SlotRightImageString);
}

void SlotMachineScene::update()
{
	//update the mouse positions and clicking events on the buttons
	m_pBetbutton->setMousePosition(m_mousePosition);
	m_pBetbutton->ButtonClick();
	m_pSpinbutton->setMousePosition(m_mousePosition);
	m_pSpinbutton->ButtonClick();
	m_pQuitbutton->setMousePosition(m_mousePosition);
	m_pQuitbutton->ButtonClick();
	m_pResetbutton->setMousePosition(m_mousePosition);
	m_pResetbutton->ButtonClick();
	
	//increase the bet on clicking bet button
	if(m_pBetbutton->ButtonClick())
	{
		increaseBet();
	}
	//Start the spinning on clicking spin button
	if(m_pSpinbutton->ButtonClick())
	{
		spin();
	}
	//Reset the game on clicking reset button
	if(m_pResetbutton->ButtonClick())
	{
		setBet(1);
		m_pBetLabel->setText("Bet: " + m_betAmountString);
		setMoney(50);
		m_pMoneyLabel->setText("Money: " + m_moneyString);
		m_pWinLabel->setText("Last win: ");
		m_SlotLeftImageString = "SlotleftSeven";
		m_SlotMiddleImageString = "SlotmiddleSeven";
		m_SlotRightImageString = "SlotrightSeven";
	}
	//quit the game on clicking quit button
	if(m_pQuitbutton->ButtonClick())
	{
		TheGame::Instance()->quit();
	}
	
}

void SlotMachineScene::clean()
{
	delete m_pSlotLabel;
	delete m_pBetbutton;
	delete m_pSpinbutton;
	delete m_pSlotMachineSlot[0];
	delete m_pSlotMachineSlot[1];
	delete m_pSlotMachineSlot[2];

	removeAllChildren();
}

void SlotMachineScene::handleEvents()
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
				m_pQuitbutton->setMouseButtonClicked(true);
				m_pResetbutton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pSpinbutton->setMouseButtonClicked(false);
				m_pBetbutton->setMouseButtonClicked(false);
				m_pQuitbutton->setMouseButtonClicked(false);
				m_pResetbutton->setMouseButtonClicked(false);
				//set the click flags to 0 so you can register clicks again
				m_pBetbutton->setOnlyRegisterClickOnce(0);
				m_pSpinbutton->setOnlyRegisterClickOnce(0);
				m_pQuitbutton->setOnlyRegisterClickOnce(0);
				m_pResetbutton->setOnlyRegisterClickOnce(0);
				break;
			}
			break;

		default:
			break;
		}
	}
}

void SlotMachineScene::start()
{

	setMoney(50);
	setBet(1);
	m_money = getMoney();
	m_betAmount = getBet();
	m_jackpot = 500;

	//allocate memory for wheels
	m_pSlotMachineSlot[0] = new SlotMachineWheel();
	m_pSlotMachineSlot[1] = new SlotMachineWheel();
	m_pSlotMachineSlot[2] = new SlotMachineWheel();

	//initialize slotmachine labels
	initializeLabels();

	//allocate memory for game objects
	m_pBetbutton = new BetButton();
	m_pBetbutton->setMouseButtonClicked(false);
	addChild(m_pBetbutton);
	m_pSpinbutton = new SpinButton();
	m_pSpinbutton->setMouseButtonClicked(false);
	addChild(m_pSpinbutton);
	m_pQuitbutton = new QuitButton();
	m_pQuitbutton->setMouseButtonClicked(false);
	addChild(m_pQuitbutton);
	m_pResetbutton = new ResetButton();
	m_pResetbutton->setMouseButtonClicked(false);
	addChild(m_pResetbutton);
	m_pSlotMachine = new SlotMachine();
	addChild(m_pSlotMachine);

	m_pSlotLeft = new SlotLeft();
	addChild(m_pSlotLeft);
	m_pSlotMiddle = new SlotMiddle();
	addChild(m_pSlotMiddle);
	m_pSlotRight = new SlotRight();
	addChild(m_pSlotRight);
}

void SlotMachineScene::spin()
{
	//check if the button hasn't been clicked 
	if (m_pSpinbutton->getOnlyRegisterClickOnce() == 0)
	{
		//check money
		if (getMoney() < getBet())
		{
			m_pWinLabel->setText("Not enough money to spin");
		//if enough money, do the magic
		}else {
			
			//decrease money according the bet
			decreaseMoney(m_betAmount);


			//spin the slots
			m_pSlotMachineSlot[0]->spin();
			m_pSlotMachineSlot[1]->spin();
			m_pSlotMachineSlot[2]->spin();

			int slotLeft = m_pSlotMachineSlot[0]->getWheelSlotNumber();
			int slotMiddle = m_pSlotMachineSlot[1]->getWheelSlotNumber();
			int slotRight = m_pSlotMachineSlot[2]->getWheelSlotNumber();

			//change the images on the slots

			changeLeftSlotImage(slotLeft);
			changeMiddleSlotImage(slotMiddle);
			changeRightSlotImage(slotRight);

			//check if you won
			checkIfWin();

			//show the win
			stringstream winStream;
			winStream << m_wins;
			winStream >> m_winsString;
			m_pWinLabel->setText("Your last win: " + m_winsString);
			//check if won jackpot
			checkIfWinJackpot();
		}

	}
	//set click flag after all spinning functions are done
	m_pSpinbutton->setOnlyRegisterClickOnce(1);
	
}



void SlotMachineScene::decreaseMoney(int theBet)
{
	//Check if no clicks has done before and decrease the bet amount from your money only once
	if (m_pSpinbutton->getOnlyRegisterClickOnce() == 0) {
		
		m_money -= m_betAmount;
		stringstream moneyStream;
		moneyStream << m_money;
		moneyStream >> m_moneyString;
		m_pMoneyLabel->setText("Money: " + m_moneyString);
		
	}
}


void SlotMachineScene::setMoney(int money)
{
	m_money = money;
	stringstream moneyStream;
	moneyStream << m_money;
	moneyStream >> m_moneyString;
}
void SlotMachineScene::increaseBet()
{
	//Check if no clicks has done before and increase your bet only once per click
	if (m_pBetbutton->getOnlyRegisterClickOnce() == 0) {
		m_betAmount += 1;
		m_pBetbutton->setOnlyRegisterClickOnce(1);
		cout << m_betAmount << endl;
		//if bet is going over 5, set it to 1
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
void SlotMachineScene::setBet(int bet)
{
	
	m_betAmount = bet;
	
	stringstream betStream;
	betStream << m_betAmount;
	betStream >> m_betAmountString;
}

int SlotMachineScene::getMoney()
{
	return m_money;
}

int SlotMachineScene::getBet()
{
	return m_betAmount;
}

void SlotMachineScene::initializeLabels()
{
	SDL_Color green = { 0, 255, 50, 255 };
	SDL_Color blue = { 0, 50, 255, 255 };
	SDL_Color red = { 255, 00, 00, 255 };
	
	m_pSlotLabel = new Label("**The Epic Slot Machine!!**", "Dock51", 60, green, glm::vec2(400.0f, 40.0f));
	m_pSlotLabel->setParent(this);
	addChild(m_pSlotLabel);

	m_pMoneyLabel = new Label("Money: " + m_moneyString, "Dock51", 20, blue, glm::vec2(165.0f, 175.0f));
	m_pMoneyLabel->setParent(this);
	addChild(m_pMoneyLabel);

	m_pBetLabel = new Label("Bet: " + m_betAmountString, "Dock51", 20, blue, glm::vec2(300.0f, 425.0f));
	m_pBetLabel->setParent(this);
	addChild(m_pBetLabel);

	m_pWinLabel = new Label("Your last win: " + m_winsString, "Dock51", 20, green, glm::vec2(300.0f, 100.0f));
	m_pWinLabel->setParent(this);
	addChild(m_pWinLabel);

	
}

void SlotMachineScene::changeLeftSlotImage(int slotImage)
{
	switch (slotImage)
	{
	case bar1:
		m_SlotLeftImageString = "SlotleftBar1";
		break;
	case bar2:
		m_SlotLeftImageString = "SlotleftBar2";
		break;
	case bell:
		m_SlotLeftImageString = "SlotleftBell";
		break;
	case cherries:
		m_SlotLeftImageString = "SlotleftCherries";
		break;
	case clover:
		m_SlotLeftImageString = "SlotleftClover";
		break;
	case heart:
		m_SlotLeftImageString = "SlotleftHeart";
		break;
	case lemon:
		m_SlotLeftImageString = "SlotleftLemon";
		break;
	case lucky7:
		m_SlotLeftImageString = "SlotleftSeven";
		break;
	case melon:
		m_SlotLeftImageString = "SlotleftMelon";
		break;
	default:
		break;
	}
}

void SlotMachineScene::changeMiddleSlotImage(int slotImage)
{
	switch (slotImage)
	{
	case bar1:
		m_SlotMiddleImageString = "SlotmiddleBar1";

		break;
	case bar2:
		m_SlotMiddleImageString = "SlotmiddleBar2";
		break;
	case bell:
		m_SlotMiddleImageString = "SlotmiddleBell";
		break;
	case cherries:
		m_SlotMiddleImageString = "SlotmiddleCherries";
		break;
	case clover:
		m_SlotMiddleImageString = "SlotmiddleClover";
		break;
	case heart:
		m_SlotMiddleImageString = "SlotmiddleHeart";
		break;
	case lemon:
		m_SlotMiddleImageString = "SlotmiddleLemon";
		break;
	case lucky7:
		m_SlotMiddleImageString = "SlotmiddleSeven";
		break;
	case melon:
		m_SlotMiddleImageString = "SlotmiddleMelon";
		break;
	default:
		break;
	}
}

void SlotMachineScene::changeRightSlotImage(int slotImage)
{
	switch (slotImage)
	{
	case bar1:
		m_SlotRightImageString = "SlotrightBar1";

		break;
	case bar2:
		m_SlotRightImageString = "SlotrightBar2";
		break;
	case bell:
		m_SlotRightImageString = "SlotrightBell";
		break;
	case cherries:
		m_SlotRightImageString = "SlotrightCherries";
		break;
	case clover:
		m_SlotRightImageString = "SlotrightClover";
		break;
	case heart:
		m_SlotRightImageString = "SlotrightHeart";
		break;
	case lemon:
		m_SlotRightImageString = "SlotrightLemon";
		break;
	case lucky7:
		m_SlotRightImageString = "SlotrightSeven";
		break;
	case melon:
		m_SlotRightImageString = "SlotrightMelon";
		break;
	default:
		break;
	}
	
}

void SlotMachineScene::checkIfWin()
{
	int slotValue[3];
	//set wins to 0
	m_wins = 0;
	//get image combination from slots
	for (int i = 0; i < 3; i++)
	{
		slotValue[i] = m_pSlotMachineSlot[i]->getWheelSlotNumber();
	}
	//check your combination and save your wins
	m_wins += slotCombinationProfit(slotValue);
	//increase your money with wins
	m_money += m_wins;
	
}

void SlotMachineScene::checkIfWinJackpot()
{
	//generate jackpot number and player number, compare them, if match inform and raise money by jackpot
	int jackpotnumber = 0 + rand()% 501;
	int playerNumber = 0 + rand() % 501;
	//std::cout << jackpotnumber << " - " << playerNumber << std::endl;
	if(jackpotnumber== playerNumber)
	{
		m_money += m_jackpot;
		stringstream jackpotStream;
		jackpotStream << m_jackpot;
		jackpotStream >> m_jackpotString;
		m_pWinLabel->setText("YOU WON JACKPOT!!! GZ!! Your last win: " + m_winsString +" + Jackpot: "+ m_jackpotString);
	}
	
}

int SlotMachineScene::slotCombinationProfit(int slotValues[3])

{
	//check 
	
	//std::cout << slotValues[0] << slotValues[1] << slotValues[2] << std::endl;
	if (slotValues[0] == lucky7 && slotValues[1] == lucky7 && slotValues[2] == lucky7)
	{
		return getBet()*10;
	}
	if (slotValues[0] == heart && slotValues[1] == heart && slotValues[2] == heart)
	{
		return getBet()*8;
	}
	if (slotValues[0] == bar2 && slotValues[1] == bar2 && slotValues[2] == bar2)
	{
		return getBet()*7;
	}
	if (slotValues[0] == bar1 && slotValues[1] == bar1 && slotValues[2] == bar1)
	{
		return getBet()*7;
	}
	if (slotValues[0] == lucky7 && slotValues[1] == lucky7)
	{
		return getBet() * 6;
	}
	if (slotValues[1] == lucky7 && slotValues[2] == lucky7)
	{
		return getBet() * 6;
	}
	if (slotValues[0] == lucky7 && slotValues[2] == lucky7)
	{
		return getBet() * 6;
	}
	
	if (slotValues[0] == clover && slotValues[1] == clover && slotValues[2] == clover)
	{
		return getBet()*5;
	}
	if (slotValues[0] == melon && slotValues[1] == melon && slotValues[2] == melon)
	{
		return getBet()*4;
	}
	if (slotValues[0] == bell && slotValues[1] == bell && slotValues[2] == bell)
	{
		return getBet()*2;
	}
	if (slotValues[0] == lemon && slotValues[1] == lemon && slotValues[2] == lemon)
	{
		return getBet() * 2;
	}
	if (slotValues[0] == cherries && slotValues[1] == cherries && slotValues[2] == cherries)
	{
		return getBet()*2;
	}
	if (slotValues[0] == cherries && slotValues[1] == cherries)
	{
		return getBet()*1;
	}
	if (slotValues[1] == cherries && slotValues[2] == cherries)
	{
		return getBet() * 1;
	}
	if (slotValues[0] == cherries && slotValues[2] == cherries)
	{
		return getBet() * 1;
	}
	return 0;

}