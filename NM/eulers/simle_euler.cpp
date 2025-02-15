#include<bits/stdc++.h>
using namespace std;
float f(float x, float y){
    return x+y;
}
int main(){
    float x0,y0,xn,h;
    cout<<"enter the initial value of x and y"<<endl;
    cin>>x0>>y0;
    cout<<"enter the value of h and final value of x for which the y is to be found"<<endl;
    cin>>h>>xn;
   #
    while(x0<xn){
        y0 = y0 + h*f(x0,y0);
        x0 = x0 +h;
    }
    cout<<"the value of y:"<<y0<<endl;
    return 0;
}