#pragma once


#ifndef __SLOT_MACHINE_SCENE__
#define __SLOT_MACHINE_SCENE__

#include "Scene.h"
#include "Label.h"
#include "SlotImage.h"
#include "SpinButton.h"
#include "BetButton.h"
#include "QuitButton.h"
#include "ResetButton.h"
#include "SlotMachine.h"
#include "SlotMachineWheel.h"
#include "SlotLeft.h"
#include "SlotMiddle.h"
#include "SlotRight.h"


class SlotMachineScene : public Scene
{
public:
	
	SlotMachineScene();
	~SlotMachineScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	void spin();
	void decreaseMoney(int theBet);
	
	//setters
	void setMoney(int money);
	void increaseBet();
	void setBet(int bet);

	// getters
	glm::vec2 getMousePosition();
	int getMoney();
	int getBet();
	
	void initializeLabels();
	void changeLeftSlotImage(int slotImage);
	void changeMiddleSlotImage(int slotImage);
	void changeRightSlotImage(int slotImage);
	void checkIfWin();
	void checkIfWinJackpot();
	int slotCombinationProfit(int slotValues[3]);
private:
	
	void m_checkwinnings();
	int m_checkline(int line[3]);
	int m_money;
	int m_jackpot;
	int m_wins;
	int m_betAmount;
	
	std::string m_moneyString;
	std::string m_betAmountString;
	std::string m_winsString;
	std::string m_jackpotString;
	//Starting images for the slots
	std::string m_SlotLeftImageString = "SlotleftSeven";
	std::string m_SlotMiddleImageString = "SlotmiddleSeven";
	std::string m_SlotRightImageString = "SlotrightSeven";
	
	glm::vec2 m_mousePosition;
	
	Label* m_pSlotLabel;
	Label* m_pMoneyLabel;
	Label* m_pBetLabel;
	Label* m_pWinLabel;
	
	SpinButton* m_pSpinbutton;
	BetButton* m_pBetbutton;
	QuitButton* m_pQuitbutton;
	ResetButton* m_pResetbutton;
	SlotMachine* m_pSlotMachine;
	SlotLeft* m_pSlotLeft;
	SlotMiddle* m_pSlotMiddle;
	SlotRight* m_pSlotRight;
	SlotMachineWheel* m_pSlotMachineSlot[3];
	
};

#endif /* defined (__SLOT_MACHINE__) */