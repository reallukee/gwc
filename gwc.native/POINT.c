//
// :.:.:.:.:.
// GWC.Native
// v0.2.0
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// POINT.c
//  Licenza MIT
//

#include "Point.h"

typedef struct Point
{
    int x;
    int y;
} Point;



Point* point_new(int x, int y)
{
    Point* point = (Point*)calloc(1, sizeof(Point));

    if (point == NULL)
    {
        return NULL;
    }

    if (x < 0)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = 0;
    }

    point->x = x;
    point->y = y;

    return point;
}

void point_delete(Point* point)
{
    if (point != NULL)
    {
        free(point);

        point = NULL;
    }
}



int point_getX(const Point* point)
{
    return point->x;
}

void point_setX(Point* point, int value)
{
    if (value < 0)
    {
        return;
    }

    point->x = value;
}

int point_getY(const Point* point)
{
    return point->y;
}

void point_setY(Point* point, int value)
{
    if (value < 0)
    {
        return;
    }

    point->y = value;
}



bool point_equal(const Point* point, const Point* other)
{
    if (point == NULL || other == NULL)
    {
        return false;
    }

    return point->x == other->x &&
           point->y == other->y;
}

bool point_notequal(const Point* point, const Point* other)
{
    if (point == NULL || other == NULL)
    {
        return false;
    }

    return point->x != other->x &&
           point->y != other->y;
}
