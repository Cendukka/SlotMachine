#pragma once
#ifndef __SLOT_LEFT__
#define __SLOT_LEFT__


#include "DisplayObject.h"

class SlotLeft : public DisplayObject
{
public:
	SlotLeft();
	~SlotLeft();
	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};

#endif
