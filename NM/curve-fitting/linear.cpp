#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of data points"<<endl;
    cin>>n;
    float x[n],y[n];
    cout<<"enter the data points x and y"<<endl;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    float sumxx=0,sumyy=0,sumxy =0, sumx =0,sumy=0,a,b;
    for(int i=0; i<n; i++){
        sumxx = sumxx + x[i]*x[i];
        sumx = sumx + x[i];
        sumy = sumy + y[i];
        sumxy = sumxy + x[i]*y[i];
    }
    b = (n*sumxy - sumx*sumy)/(n*sumxx - sumx*sumx);
    a = (sumy - b*sumx)/n;
    cout<<"the value of a and b are :"<<a<<" "<<b<<endl;
    return 0;
}