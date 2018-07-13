/*
 * mirror_reflection.cpp
 *
 *  Created on: Jul 12, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/mirror-reflection/description/
 *
 *  Credits:
 *  This algorithm is copied from: https://blog.csdn.net/zjucor/article/details/80790193
 *
 */

#include <iostream>

using namespace std;


/*
 * Assume that there are no top and bottom mirrors. So now the light will keep
 * reflecting off the right and left mirrors alternately and it will keep
 * moving upwards continuously. In each reflection, it traverses a vertical
 * distance = q. We will keep a track of the vertical distance traversed after each reflection.
 * Now, even though we assumed that the top and bottom mirrors are not present,
 * we still need to model their presence mathematically while calculating the vertical distance
 * traversed (otherwise, the vertical distance traversed will keep increasing monotonically).
 * We model their presence by subtracting p from vertical distance traversed each time it exceeds p.
 * The point when vertical distance traversed becomes exactly p, we have hit one of the corners.
 * In order to find out which corner, we keep a track of vertical and horizontal direction that we are
 * currently traveling in using 2 variables:
 * updown: vertical direction - true=up, false=down
 * rightleft: horizontal direction - true=right, false=left
 * Since we start at bottom west, initially, updown=true, rightleft=true
 * In each iteration, rightleft will flip (since we assumed no top/bottom mirrors, light will keep doing
 * left and right alternately.
 * updown will flip only if the vertical distance traversed exceeds p.
 */
int mirror_reflection(int p, int q)
{
	// Total "adjusted" vertical distance traversed
	int verticalDistTraversed = 0;
	// vertical and horizontal direction trackers
	// Note: We could use enums to indicate directions more obviously but
	// operating on bools is faster at runtime
	bool updown = true, rightleft = true;

	// while(1) is needed because we want to check for verticalDistTraversed == p
	// immediately after the first reflection dist (q) is traversed.
	// Other option is to add the first 'q' dist outside the loop and use a do-while loop.
	while(1)
	{
		// In each reflection, it traverses a vertical distance = q.
		verticalDistTraversed += q;

		// If the vertical dist traversed =p, then we have hit a corner.
		// the actual corner is determined by the updown and rightleft direction trackers.
		if (verticalDistTraversed == p)
		{
			if (updown) return rightleft ? 1 : 2;
			else if (rightleft) return 0;
		}

		// If vertical dist traversed exceeds p, then we need to subtract p from it
		// to model the presence of top/down mirrors. Also, the vertical direction
		// gets flipped
		if (verticalDistTraversed > p)
		{
			verticalDistTraversed -= p;
			updown = !updown;
		}

		// light will keep reflecting off the right and left mirrors alternately in each iteration
		rightleft = !rightleft;
	}
}

int main()
{
	cout << "mirror reflection: " << mirror_reflection(2,1) << "\n";
}
