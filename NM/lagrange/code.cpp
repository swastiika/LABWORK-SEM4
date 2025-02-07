#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of data"<<endl;
    cin>>n;
    float x[n],y[n],xp,yp,p[n];
    cout<<"enter the data x and y"<<endl;
    for(int i=0; i<n; i++){
    cin>>x[i]>>y[i];
    }
    cout<<"enter the value of x to be interpolated"<<endl;
    cin>>xp;
    yp =0;
    for(int i=0; i<n; i++){
        p[i] =1;
        for(int j=0; j<n; j++){
            if(i!=j){
                p[i] = p[i] *(xp-x[j])/(x[i]-x[j]);
            }
          

        }
          cout<<"p["<<i<<"]:"<<p[i]<<endl;
        yp = yp + p[i] *y[i];
    }
    cout<<yp<<endl;

}