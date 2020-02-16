#include "SlotMachineWheel.h"
#include "Game.h"
#include <ctime>


SlotMachineWheel::SlotMachineWheel()
{
	//set the seed of random function to current time
	srand((int)(time(NULL)));
	//insert random number between 0-8
	m_wheelSlotNumber = (0 + rand() % 9);
	
}

SlotMachineWheel::~SlotMachineWheel()
{
}

void SlotMachineWheel::draw()
{
}

void SlotMachineWheel::update()
{
}

void SlotMachineWheel::clean()
{
}

void SlotMachineWheel::spin()
{
	// set the amount of spins, spin and set the number to the wheel slot
	int spins = (10 + rand() % 50);
	
	for (int i = 0; i < spins; i++) {
		
		m_wheelSlotNumber++;
		if (m_wheelSlotNumber > 8)
		{
			m_wheelSlotNumber = 0;
		}
	}
}

int SlotMachineWheel::getWheelSlotNumber()
{
	return m_wheelSlotNumber;
}
