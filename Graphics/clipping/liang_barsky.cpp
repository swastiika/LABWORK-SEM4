#include <iostream>
#include <graphics.h>
using namespace std;

int xmin, ymin, xmax, ymax;
bool liangBarskyClip(float x1, float y1, float x2, float y2, float &nx1, float &ny1, float &nx2, float &ny2) {
    float p[4], q[4];
    p[0] = -(x2 - x1);
    p[1] = x2 - x1;
    p[2] = -(y2 - y1);
    p[3] = y2 - y1;

    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;

    float t1 = 0.0, t2 = 1.0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return false; 
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) {
                t1 = max(t1, t); 
            } else {
                t2 = min(t2, t); 
            }
        }
    }

    if (t1 > t2) return false;
    nx1 = x1 + t1 * (x2 - x1);
    ny1 = y1 + t1 * (y2 - y1);
    nx2 = x1 + t2 * (x2 - x1);
    ny2 = y1 + t2 * (y2 - y1);

    return true;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();

    cout << "Enter the clipping window (xmin, ymin, xmax, ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    setcolor(BLACK);
    rectangle(xmin, ymin, xmax, ymax);

    float x1, y1, x2, y2;
    cout << "Enter the line endpoints (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    setcolor(RED);
    line(x1, y1, x2, y2);

    cout << "Do you want to clip the line? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        float nx1, ny1, nx2, ny2;
        if (liangBarskyClip(x1, y1, x2, y2, nx1, ny1, nx2, ny2)) {
            cleardevice(); 
            setbkcolor(WHITE); 
            setcolor(BLACK);
            rectangle(xmin, ymin, xmax, ymax);
            setcolor(GREEN); 
            line(nx1, ny1, nx2, ny2);
            cout << "Line clipped and displayed." << endl;
        } else {
            cout << "The line is completely outside the window and cannot be clipped." << endl;
        }
    } else {
        cout << "Line clipping skipped." << endl;
    }

    getch();
    closegraph();
    return 0;
}
