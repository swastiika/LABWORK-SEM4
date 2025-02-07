#include<iostream>
#include<cmath>
using namespace std;
float func(float x){
    return (1/(1+pow(x,2)));
}
int main(){
  float lower_limit,upper_limit,sub_interval;
  cout<<"enter the lower limit,upper limit and number of sub interval"<<endl;
  cin>>lower_limit>>upper_limit>>sub_interval;
  float step_size = (upper_limit - lower_limit)/sub_interval;
  float integration = func(lower_limit) + func(upper_limit);
  int i=1; 
  float k;
  while(i<=sub_interval-1){
        k = lower_limit + i*step_size;
        if(i%2==0){
            integration = integration + 2*func(k);

        }
        else{
            integration = integration + 4*func(k);
        }
        i++;
  }
  integration = integration*step_size/3;
  cout<<"integral value"<<integration;
  return 0;
}