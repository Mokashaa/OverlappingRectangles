#include "rectangle.h"
/*
 * Rectangle.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Mohammad Okasha
 */
#include "rectangle.h"


rectangle::rectangle() :c1(), c2()
{

}


rectangle::rectangle(point c, point v) :c1(c), c2(v)
{

}

rectangle::rectangle(int x1, int y1, int x2, int y2) : c1(x1, y1), c2(x2, y2)
{

}
long rectangle::getC1_X(void)
{
	return this->c1.getX();
}
long rectangle::getC2_X(void)
{
	return this->c2.getX();
}
long rectangle::getC1_Y(void)
{
	return this->c1.getY();
}
long rectangle::getC2_Y(void)
{
	return this->c2.getY();
}
bool rectangle::dontOverlap(const rectangle &rect)
{
	// If one rectangle is on left side of other
	if (rect.c1.x >= this->c2.x || this->c1.x >= rect.c2.x)
		return true;

	// If one rectangle is above other
	if (rect.c1.y >= this->c2.y || this->c1.y >= rect.c2.y)
		return true;

	return false;
}

bool rectangle::dontOverlap_Group(const vector<rectangle> &rects)
{
	for (unsigned int i = 0; i < rects.size(); i++)
	{
		if (!this->dontOverlap(rects[i]))
		{
			return false;
		}
	}
	return true;
}
