/*
 * Rectangle.h
 *
 *  Created on: Oct 23, 2019
 *      Author: Mohammad Okasha
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Point.h"
#include <vector>

using namespace std;
class rectangle {
	point c1;
	point c2;

public:
	rectangle();
	rectangle(point c, point v);
	rectangle(int x1, int y1, int x2, int y2);
	long getC1_X(void);
	long getC1_Y(void);
	long getC2_X(void);
	long getC2_Y(void);
	bool dontOverlap(const rectangle &rect);
	bool dontOverlap_Group(const vector<rectangle> &rects);

};



#endif /* RECTANGLE_H_ */
