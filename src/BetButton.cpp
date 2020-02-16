#include "BetButton.h"
#include "Game.h"

BetButton::BetButton()
// call super constructor
	:Button(
		"../Assets/textures/bet.png",
		"bet",
		BET_BUTTON, glm::vec2(400.0f, 425.0f)), m_isClicked(false)
{
	
}

BetButton::~BetButton()
{
}

void BetButton::setOnlyRegisterClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}

int BetButton::getOnlyRegisterClickOnce()
{
	return m_pClickFlag;
}

bool BetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			
			m_isClicked = true;
			
			
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


