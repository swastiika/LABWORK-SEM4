#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;
void bezierCurve(int x[], int y[], int n) {
    double xu, yu, u;
    for (u = 0.0; u <= 1.0; u += 0.0005) {
        xu = 0;
        yu = 0;
        for (int i = 0; i < n; i++) {
            double binCoeff = 1;
            for (int j = 0; j < i; j++)
                binCoeff *= (n - 1 - j) / (double)(j + 1);

            double basis = binCoeff * pow(u, i) * pow(1 - u, n - 1 - i);
            xu += basis * x[i];
            yu += basis * y[i];
        }
        putpixel((int)xu, (int)yu, BLACK);
    }
}

void drawDottedLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int steps = max(dx, dy);
    double Xinc = (double)(x2 - x1) / steps;
    double Yinc = (double)(y2 - y1) / steps;

    double x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        if (i % 4 == 0) 
            putpixel((int)x, (int)y, BLUE);
        x += Xinc;
        y += Yinc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();
    int n;
    cout << "Enter the number of control points: ";
    cin >> n;
    int x[n], y[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter coordinates for Point-" << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        setcolor(RED);
        circle(x[i], y[i], 5);
        floodfill(x[i], y[i], RED);
    }
    setcolor(BLUE);
    for (int i = 0; i < n - 1; i++) {
        drawDottedLine(x[i], y[i], x[i + 1], y[i + 1]);
    }
    
    setcolor(BLACK);
    bezierCurve(x, y, n);

    getch();
    closegraph();
    return 0;
}
