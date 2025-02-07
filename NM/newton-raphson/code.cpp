#include<iostream>
#include<cmath>
using namespace std;
float func(float x){
    // return (pow(x,3) - (4*x) -9);
    return ((x*sin(x) + cos(x)));
}
float deriva(float x){
    // return ((3*pow(x,2)) -4);
    return (x*cos(x));
}
int main(){
    float x0,x1,e,err;
    int count,n;
    cout<<"emter the initial guess"<<endl;
    cin>>x0;
    cout<<"enter the tolerable error"<<endl;
    cin>>e;
    cout<<"enter the maximum number of iterations"<<endl;
    cin>>n;
    count =0;
    do{
        if(fabs(deriva(x0)<=e)){
            cout<<"mathematical error"<<endl;
            return 0;

        }
        x1 = x0 -func(x0)/deriva(x0);
        err = fabs(x1-x0);
        x0 =x1;
        count++;
        if(count==n){
            cout<<"not convergent"<<endl;
            return 0;
        }
        
    }
    while (err>e);
    cout<<x1<<endl;
    return 0;

   
}