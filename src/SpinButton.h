#pragma once
#ifndef __SPIN_BUTTON__
#define __SPIN_BUTTON__

#include "Button.h"

class SpinButton : public Button
{
public:
	SpinButton();
	~SpinButton();


	bool ButtonClick() override;
	//getters
	int getOnlyRegisterClickOnce();
	//setters
	void setOnlyRegisterClickOnce(int clickFlag);
private:
	bool m_isClicked;
	int m_pClickFlag;
};

#endif /* defined (__SPIN_BUTTON__) */