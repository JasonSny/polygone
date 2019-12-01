
#include "TP-PolygoneH.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float calcul(float x1, float y1, float x2, float y2, float peri)
{
    float segmentxvy = x2 - x1; //Mouvement de X vers Y
    float segmentyvx = y2 - y1; //Mouvement de Y vers X
    float value = 0;

    if (segmentxvy == 0)
    {
        peri = segmentyvx;
    }
    if (segmentyvx == 0)
    {
        peri = segmentxvy;
    }
    else
    {
        value=(segmentxvy*segmentxvy)+(segmentyvx*segmentyvx);
        peri=sqrt(value);
    }
    return (peri);
}
int calc(Coordonnees point)
{

    float peri=0;

    peri+=calcul(point.x1, point.y1, point.x2, point.y2, peri);
    peri+=calcul(point.x2, point.y2, point.x3, point.y3, peri); //Calcul en "Cascade"
    peri+=calcul(point.x3, point.y3, point.x4, point.y4, peri);
    peri+=calcul(point.x4, point.y4, point.x5, point.y5, peri);
    peri+=calcul(point.x5, point.y5, point.x6, point.y6, peri);
    peri+=calcul(point.x6, point.y6, point.x1, point.y1, peri);

    printf(" Le perimetre du polygone est de : %.2f", peri);
    return (peri);
}

int main(int argc, char *argv[])
{
    Coordonnees point;

    point.x1=2;
    point.y1=0;
    point.x2=6;
    point.y2=0;
    point.x3=10;
    point.y3=2;
    point.x4=8;
    point.y4=6;
    point.x5=2;
    point.y5=8;
    point.x6=0;
    point.y6=4;
    calc(point);
}
