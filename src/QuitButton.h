#pragma once
#ifndef __QUIT_BUTTON__
#define __QUIT_BUTTON__

#include "Button.h"


class QuitButton : public Button
{
public:
	QuitButton();
	~QuitButton();
	
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
