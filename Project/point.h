/*
 * Point.h
 *
 *  Created on: Oct 23, 2019
 *      Author: Mohammad Okasha
 */

#ifndef POINT_H_
#define POINT_H_


class point {
	long x;
	long y;

public:
	point();
	point(long x, long y);
	long getX(void);
	long getY(void);
	void setX(long x);
	void setY(long y);
	void set(long x, long y);
	friend class rectangle;
};


#endif /* POINT_H_ */
