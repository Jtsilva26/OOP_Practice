/*
Jordan Silva
CSCI 511
09/13/23
*/

#include <iostream>

using namespace std;

struct Triangle;
struct Circle;

struct VT_Tri
{
    typedef void (*VT_drawTri)(struct Triangle *tri);
    typedef double (*VT_areaTri)(struct Triangle *tri);
    VT_drawTri drawTriOutput;
    VT_areaTri areaTriOutput;
};

struct VT_Cir
{
    typedef void (*VT_drawCir)(struct Circle *cir);
    typedef double (*VT_areaCir)(struct Circle *cir);
    VT_drawCir drawCirOutput;
    VT_areaCir areaCirOutput;
};

struct Triangle
{
    char color; //'r'==red, 'g'==green, 'b'==blue
    VT_Tri vttri;
    char shade; //'l'==light, 'd'==dark
    short base;
    short height;
};

struct Circle
{
    char color;
    VT_Cir vtcir;
    char shade;
    double radius;
};

union shape_ptr
{
    struct Circle *cir_ptr;
    struct Triangle *tri_ptr;
};

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

void setTriangle(struct Triangle *tri, char col, char sha, short b, short h)
{
    cout << "Enter a Color, Shade, Base, and Height for Triangle: [ex] r d 10 5" << endl;
    cin >> tri->color >> tri->shade >> tri->base >> tri->height;
    // tri->color = 'r';
    // tri->shade = 'd';
    // tri->base = 10;
    // tri->height = 5;
    tri->vttri.drawTriOutput = &drawTriangle;
    tri->vttri.areaTriOutput = &areaTriangle;
}

void setCircle(struct Circle *cir, char col, char sha, double r)
{
    cout << "Enter a Color, Shade, and Radius for Circle: [ex] r d 10" << endl;
    cin >> cir->color >> cir->shade >> cir->radius;
    // cir->color = 'b';
    // cir->shade = 'l';
    // cir->radius = 25.3;
    cir->vtcir.drawCirOutput = &drawCircle;
    cir->vtcir.areaCirOutput = &areaCircle;
}

void do_poly(union shape_ptr shape)
{
    shape.tri_ptr->vttri.drawTriOutput(shape.tri_ptr);
    cout << shape.tri_ptr->vttri.areaTriOutput(shape.tri_ptr) << endl;
}

/*
Since both structs are in union they share the exact same spots in memory. So
once triangle has been called and created when its time to use circle since both structures
are formatted the same and read in memory sequentially it over writes the memory from triangle
and is then used for circle. This is only possible since they are structured the same otherwise it wouldn't work.
 */

int main()
{
    union shape_ptr shapes[4];
    struct Triangle x1, y1;
    struct Circle x2, y2;

    setTriangle(&x1, x1.color, x1.shade, x1.base, x1.height);
    setTriangle(&y1, y1.color, y1.shade, y1.base, y1.height);
    setCircle(&x2, x2.color, x2.shade, x2.radius);
    setCircle(&y2, y2.color, y2.shade, y2.radius);
    shapes[0].tri_ptr = &x1;
    shapes[1].tri_ptr = &y1;
    shapes[2].cir_ptr = &x2;
    shapes[3].cir_ptr = &y2;

    for (int i = 0; i < 4; i++)
    {
        do_poly(shapes[i]);
    }
    return 0;

    // struct Triangle x;
    // struct Circle y;
    // struct VT_Tri a;
    // struct VT_Cir b;
    // a.drawTriOutput = drawTriangle;
    // b.drawCirOutput = drawCircle;
    // a.areaTriOutput = areaTriangle;
    // b.areaCirOutput = areaCircle;
    // setTriangle(&x, x.color, x.shade, x.base, x.height);
    // setCircle(&y, y.color, y.shade, y.radius);

    // a.drawTriOutput(&x);
    // cout << "Area of a Triangle: " << a.areaTriOutput(&x) << endl;
    // b.drawCirOutput(&y);
    // cout << "Area of a Circle: " << b.areaCirOutput(&y) << endl;
}