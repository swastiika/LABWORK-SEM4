#include<iostream>
#include<cmath>
using namespace std;
float f(float x, float y){
    return x+sqrt(y);
}
int main(){
    float x0,y0,xn,h,mean;
    cout<<"enter the initial values of x and y"<<endl;
    cin>>x0>>y0;
    cout<<"enter the final value of x and the step size"<<endl;
    cin>>xn>>h;
    while(x0<xn){
        mean = (f(x0,y0) + f(x0+h,y0 + h*f(x0,y0)))/2;
        y0 = y0 + mean*h;
        x0 = x0 +h;
    }
    cout<<"the value od t is"<<y0<<endl;
    return 0;
}