#pragma once

#ifndef __SLOT_MACHINE_WHEEL__
#define __SLOT_MACHINE_WHEEL__

#include "GameObject.h"

class SlotMachineWheel : public GameObject
{

public:

	SlotMachineWheel();
	~SlotMachineWheel();

	void draw() override;
	void update() override;
	void clean() override;

	void spin();
	int getWheelSlotNumber();



private:
	
	int m_wheelSlotNumber;

	
};



#endif /*Defined __SLOT_MACHINE_WHEEL__ */


