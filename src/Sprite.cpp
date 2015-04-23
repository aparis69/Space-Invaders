#include "Sprite.h"

Sprite::Sprite(int imIndex, int inx, int iny, int invx, int invy)
{
    imageIndex = imIndex;
    x = inx;
    y = iny;
    vx = invx;
    vy = invy;

    xSize = -1;
    ySize = -1;
}

Sprite::Sprite(int imIndex, int inx, int iny, int invx, int invy, int inXSize, int inYSize)
{
    imageIndex = imIndex;
    x = inx;
    y = iny;
    vx = invx;
    vy = invy;

    xSize = inXSize;
    ySize = inYSize;
}