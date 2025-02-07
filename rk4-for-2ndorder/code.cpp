#include<iostream>
#include<cmath>
using namespace std;

float f(float x, float y, float z) {
    return z;
}

float g(float x, float y, float z) {
    return ((3 * y) - (2 * z));
}

int main() {
    float x, y, xn, z, k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    cout << "enter the initial value of x, y, z" << endl;
    cin >> x >> y >> z;

    float h;
    cout << "enter the step size" << endl;
    cin >> h;

    cout << "enter the final value of x" << endl;
    cin >> xn;

    cout << "x  y   z" << endl;

    while (x < xn) {
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);

        k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);

        k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);

        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);

        k = (k1 + 2 * (k2 + k3) + k4) / 6;
        l = (l1 + 2 * (l2 + l3) + l4) / 6;

        y = y + k;
        z = z + l;
        x = x + h;

        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}