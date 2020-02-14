
#pragma once
#ifndef __BET_BUTTON__
#define __BET_BUTTON__

#include "Button.h"


class BetButton : public Button
	
{
	
public:
	BetButton();
	~BetButton();
	//setters
	void setOnlyRegisterClickOnce(int clickFlag);
	//getters
	int getOnlyRegisterClickOnce();
	
	bool ButtonClick() override;
private:
	bool m_isClicked;
	int m_pClickFlag;
	
};

#endif /* defined (__BET_BUTTON__) */