#include <iostream>

using namespace std;

/*
Unions are similar to structures, except each member of a union is placed
starting at an identical storage location. Rather then a higher storage location.

Since it's the same storage location memory can be lost from being overwritten from the value before
*/

/*
Using a double and a long int both use 8 bytes therefore they have the same memory size meaning when its memory is overwritten it should be a correct value
*/
union myUnion
{
    double dub;
    long int longer;
    int integer;
    float floater;
    char character;
    int *integerPointer;
};

int main()
{
    myUnion s = {5};
    // myUnion letter = {'a'};
    cout << s.dub << endl;
    cout << s.longer << endl;
    cout << s.integer << endl;
    cout << s.floater << endl;
    cout << s.character << endl;
    cout << s.integerPointer << endl;
}