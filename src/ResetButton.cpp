#include "ResetButton.h"

ResetButton::ResetButton()
// call super constructor
	:Button(
		"../Assets/textures/reset.png",
		"reset",
		RESET_BUTTON, glm::vec2(50.0f, 500.0f)), m_isClicked(false)
{

}

ResetButton::~ResetButton()
{
}

bool ResetButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
		}
		return true;
	}


	return false;
}

int ResetButton::getOnlyRegisterClickOnce()
{
	return m_pClickFlag;
}

void ResetButton::setOnlyRegisterClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}

