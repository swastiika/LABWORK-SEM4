#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of data"<<endl;
    cin>>n;
    float x[n],y[n],xn,yn,p[n];
    cout<<"enetr the data points x  and y"<<endl;
    for(int i=0; i<n; i++){
        cout<<"x["<<i<<"] y["<<i<<"]";
        cin>>x[i]>>y[i];
    }
    cout<<"enter the value of x for interpolation"<<endl;
    cin>>xn;
    y[n] =0;
    for(int i=0; i<n; i++){
        p[i]=1;
        for(int j=0; j<n; j++){
               if(i!=j){
                p[i] = p[i]*(xn - x[j])/(x[i] - x[j]);
               }
        }
        yn = yn + p[i]*y[i];
    }
    cout<<yn<<endl;
    return 0;
}