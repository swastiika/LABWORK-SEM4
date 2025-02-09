#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4; 
const int TOP = 8;   
int xmin, ymin, xmax, ymax;
int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}
bool cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code_out;
            int x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }
            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    return accept;
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
    int x1, y1, x2, y2;
    cout << "Enter the line endpoints (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    setcolor(RED);
    line(x1, y1, x2, y2);
    cout << "Do you want to clip the line? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        if (cohenSutherlandClip(x1, y1, x2, y2)) {
        	setbkcolor(WHITE);
            cleardevice();
            setcolor(BLACK);
            rectangle(xmin, ymin, xmax, ymax);

            setcolor(GREEN);
            line(x1, y1, x2, y2);
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
