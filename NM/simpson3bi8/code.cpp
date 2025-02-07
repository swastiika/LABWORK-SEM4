#include<iostream>
#include<cmath>
using namespace std;
float func(float x){
    return (1/(1+pow(x,2)));
}
int main(){
    float lower_limit,upper_limit,sub_interval;
    cout<<"enter the lower limit, upper limit and sub interval"<<endl;
    cin>>lower_limit>>upper_limit>>sub_interval;
    float step_size = (upper_limit - lower_limit)/sub_interval;
    float integraton = func(lower_limit) + func(upper_limit);
    int i=1;
    
    while(i<=sub_interval-1){
        float k = lower_limit + i*step_size;
        if(i%3==0){
            integraton = integraton + 2*func(k);
        }
        else {integraton = integraton + 3*func(k);}
        i++;
    }
    integraton = integraton * step_size*3/8;
    cout<<"integration="<<integraton<<endl;
    return 0;
}
