#pragma once


#ifndef __SLOT_MACHINE__
#define __SLOT_MACHINE__

#include "Scene.h"
#include "Label.h"
#include "SpinButton.h"
#include "BetButton.h"

class SlotMachine : public Scene
{
public:
	enum SlotImage {
		bar1 = 1,
		bar2,
		bell,
		cherries,
		clover,
		heart,
		lemon,
		lucky7,
		melon
	};
	SlotMachine();
	~SlotMachine();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	void spin();
	void bet(int);
	void insertcoin();
	void insertbill(double);
	void printscreen();
	int* read();
	// getters
	glm::vec2 getMousePosition();
	int getMoney();
	int getBet();

	//setters
	void setMoney(int money);
	void setBet(int bet);
	void increaseBet();
	void decreaseMoney(int theBet);
private:

	int m_slots[9];
	int m_internalPtr;
	void m_checkwinnings();
	int m_checkline(int line[3]);
	int m_credits;
	std::string m_creditsString;
	int m_betAmount;
	std::string m_betAmountString;



	glm::vec2 m_mousePosition;
	Label* m_pSlotLabel;
	Label* m_pMoneyLabel;
	Label* m_pBetLabel;
	Label* m_pJackbotLabel;
	SpinButton* m_pSpinbutton;
	BetButton* m_pBetbutton;
};

#endif /* defined (__SLOT_MACHINE__) */