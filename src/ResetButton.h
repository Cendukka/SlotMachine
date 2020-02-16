#pragma once
#ifndef __RESET_BUTTON__
#define __RESET_BUTTON__

#include "Button.h"


class ResetButton : public Button
{
public:
	ResetButton();
	~ResetButton();


	bool ButtonClick() override;
	//getters
	int getOnlyRegisterClickOnce();
	//setters
	void setOnlyRegisterClickOnce(int clickFlag);
private:
	bool m_isClicked;
	int m_pClickFlag;
};


#endif
