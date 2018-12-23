#pragma once
#ifndef LAB_TRIANGLE_H
#define LAB_TRIANGLE_H

/*
 * -1 - not triangle
 *  0 - nothing
 *  1 - isosceles
 *  2 - equilateral
 */

int getTriangleType(long a = 0, long b = 0, long c = 0) {
    int type = 0;
    if (a <= 0 || b <= 0 || c <= 0) {
        type = -1;
    }
    else if (a + b <= c || a + c <= b || b + c <= a) {
        type = -1;
    }
    else if (a == b && b == c) {
        type = 2;
    }
    else if (a == b || a == c || b == c) {
        type = 1;
    }
    else {
        type = 0;
    }
    return type;
}

#endif //LAB_TRIANGLE_H
