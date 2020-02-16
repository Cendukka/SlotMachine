#pragma once
#ifndef __SLOT_RIGHT__
#define __SLOT_RIGHT__


#include "DisplayObject.h"

class SlotRight : public DisplayObject
{
public:
	SlotRight();
	~SlotRight();
	void draw() override;
	void update() override;
	void clean() override;
	void draw(std::string imageID);
};

#endif
