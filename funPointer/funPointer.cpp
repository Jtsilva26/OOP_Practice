#include <iostream>

using namespace std;

float add(float x, float y)
{
    return (x + y);
}

float subtract(float x, float y)
{
    return (x - y);
}

float divide(float x, float y)
{
    return (x / y);
}

float multiply(float x, float y)
{
    return (x * y);
}

// float assign_pi_to_dyn_3D(float ***list, float x, float y, float z)
// {
//     ***list = 3.14;
// }

int main(int argc, char *argv[])
{
    float x, y, z;
    cout << "Enter an x, y, and z: ";
    cin >> x >> y >> z;
    int count;
    float (*func[4])(float, float) = {add, subtract, divide, multiply};
    string funNames[4] = {"Add", "Subtract", "Divide", "Multiply"};
    // float x = atof(argv[1]), y = atof(argv[2]), z = atof(argv[3]);
    float result;

    // allocates memory to a 3d array
    // float ***point = new float **[x];
    // for (int i = 0; i < y; i++)
    // {
    //     point[i] = new float *[y];
    //     for (int j = 0; j < z; j++)
    //     {
    //         point[i][j] = new float[z];
    //     }
    // }

    // assign_pi_to_dyn_3D(point, x, y, z);

    // for (int i = 0; i < y; i++)
    // {
    //     for (int j = 0; j < z; j++)
    //     {
    //         delete point[i][j];
    //     }
    //     delete point[i];
    // }
    // delete point;

    for (int i = 0; i < 4; i++)
    {
        result = func[i](x, y);
        cout << funNames[i] << " Result: " << result << endl;
    }

    // func = add;
    // float value = func(1, 1);
    // cout << "The Value is: " << value << endl;
    return 0;
}