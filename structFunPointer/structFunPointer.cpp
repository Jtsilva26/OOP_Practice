/*
Jordan Silva
CSCI 511
09/13/23
*/

#include <iostream>

using namespace std;

struct Triangle
{
    char color; //'r'==red, 'g'==green, 'b'==blue
    char shade; //'l'==light, 'd'==dark
    short base;
    short height;
};

struct VT_Tri
{
    typedef void (*VT_drawTri)(struct Triangle *tri);
    typedef double (*VT_areaTri)(struct Triangle *tri);
    VT_drawTri drawTriOutput;
    VT_areaTri areaTriOutput;
};

struct Circle
{
    char color;
    char shade;
    double radius;
};

struct VT_Cir
{
    typedef void (*VT_drawCir)(struct Circle *cir);
    typedef double (*VT_areaCir)(struct Circle *cir);
    VT_drawCir drawCirOutput;
    VT_areaCir areaCirOutput;
};

void setTriangle(struct Triangle *tri, char col, char sha, short b, short h)
{
    tri->color = 'r';
    tri->shade = 'd';
    tri->base = 10;
    tri->height = 5;
}

void setCircle(struct Circle *cir, char col, char sha, double r)
{
    cir->color = 'b';
    cir->shade = 'l';
    cir->radius = 25.3;
}

void drawTriangle(struct Triangle *tri)
{
    cout << tri->shade << " " << tri->color << " Triangle, base=" << tri->base << ", height=" << tri->height << endl;
}

void drawCircle(struct Circle *cir)
{
    cout << cir->shade << " " << cir->color << " circle, radius=" << cir->radius << endl;
}

double areaTriangle(struct Triangle *tri)
{
    return ((tri->base * tri->height) / 2);
}

double areaCircle(struct Circle *x)
{
    return (3.14 * (x->radius * x->radius));
}

int main()
{
    struct Triangle x;
    struct Circle y;
    struct VT_Tri a;
    struct VT_Cir b;
    a.drawTriOutput = drawTriangle;
    b.drawCirOutput = drawCircle;
    a.areaTriOutput = areaTriangle;
    b.areaCirOutput = areaCircle;
    char color, shade;
    short base, height;
    setTriangle(&x, x.color, x.shade, x.base, x.height);
    setCircle(&y, y.color, y.shade, y.radius);
    a.drawTriOutput(&x);
    cout << "Area of a Triangle: " << a.areaTriOutput(&x) << endl;
    b.drawCirOutput(&y);
    cout << "Area of a Circle: " << b.areaCirOutput(&y) << endl;
}