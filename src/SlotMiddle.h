#pragma once
#ifndef __SLOT_MIDDLE__
#define __SLOT_MIDDLE__


#include "DisplayObject.h"

class SlotMiddle : public DisplayObject
{
public:
	SlotMiddle();
	~SlotMiddle();
	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};

#endif
