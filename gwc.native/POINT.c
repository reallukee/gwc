//
// :.:.:.:.:.
// GWC.Native
// v0.3.3
// :.:.:.:.:.
//
// https://github.com/reallukee/gwc
//
// POINT.c
//  Licenza MIT
//

#include "POINT.h"

typedef struct gPOINT
{
    int x;
    int y;
} gPOINT;



gPOINT* point_new(int x, int y)
{
    gPOINT* point = (gPOINT*)calloc(1, sizeof(gPOINT));

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

void point_delete(gPOINT* point)
{
    if (point != NULL)
    {
        free(point);

        point = NULL;
    }
}



int point_getX(const gPOINT* point)
{
    return point->x;
}

void point_setX(gPOINT* point, int value)
{
    if (value < 0)
    {
        return;
    }

    point->x = value;
}

int point_getY(const gPOINT* point)
{
    return point->y;
}

void point_setY(gPOINT* point, int value)
{
    if (value < 0)
    {
        return;
    }

    point->y = value;
}



bool point_equal(const gPOINT* point, const gPOINT* other)
{
    if (point == NULL || other == NULL)
    {
        return false;
    }

    return point->x == other->x &&
           point->y == other->y;
}

bool point_notequal(const gPOINT* point, const gPOINT* other)
{
    if (point == NULL || other == NULL)
    {
        return false;
    }

    return point->x != other->x &&
           point->y != other->y;
}
