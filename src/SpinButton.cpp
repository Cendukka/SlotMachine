#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
	// call super constructor
	:Button(
		"../Assets/textures/spin.png",
		"spin",
		START_BUTTON, glm::vec2(450, 400.0f)), m_isClicked(false)
{
	
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if(!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
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

int SpinButton::getOnlyRegisterClickOnce()
{
	return m_pClickFlag;
}

void SpinButton::setOnlyRegisterClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}


