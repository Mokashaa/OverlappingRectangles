/*
 * Point.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Mohammad Okasha
 */

#include "Point.h"

point::point() : x(0), y(0)
{	}
point::point(long x, long y) : x(x), y(y)
{	}

long point::getX(void)
{
	return this->x;
}

long point::getY(void)
{
	return this->y;
}

void point::setX(long x)
{
	this->x = x;
}
void point::setY(long y)
{
	this->y = y;
}
void point::set(long x, long y)
{
	this->x = x;
	this->y = y;
}
