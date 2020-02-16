#pragma once

#ifndef __SLOT_MACHINE__
#define __SLOT_MACHINE__


#include "DisplayObject.h"


class SlotMachine : public DisplayObject
{
public:
	SlotMachine();
	~SlotMachine();


	void draw() override;
	void update() override;
	void clean() override;
	
private:
	
};

#endif /*Defined __SLOT_MACHINE__ */