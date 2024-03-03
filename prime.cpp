#include<iostream>
using namespace std;
int prime(int n){
    int flag;
     flag=1;
    int i;
    for(i=2;i<=n-1;i++){
        if(n%i==0){
            flag=0;
            break;
        }
        
    }
    if(flag==1){
        return 1;
    }
   
 return 0;

}
int main(){
    int n;
    cin>>n;
    cout<<prime(n);

}