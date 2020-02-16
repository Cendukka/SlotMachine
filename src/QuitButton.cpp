#include "QuitButton.h"

QuitButton::QuitButton()
// call super constructor
	:Button(
		"../Assets/textures/quit.png",
		"quit",
		QUIT_BUTTON, glm::vec2(50.0f, 550.0f)), m_isClicked(false)
{

}

QuitButton::~QuitButton()
{
}

bool QuitButton::ButtonClick()
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

int QuitButton::getOnlyRegisterClickOnce()
{
	return m_pClickFlag;
}

void QuitButton::setOnlyRegisterClickOnce(int clickFlag)
{
	m_pClickFlag = clickFlag;
}

