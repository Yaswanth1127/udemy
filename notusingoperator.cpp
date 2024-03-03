#include<iostream>
using namespace std;
int getProduct(int a,int b){
    int sum,i;
    sum=0;
    for( i=1;i<=a;i++){
        sum=sum+b;
    }
    return sum;
}
int main(){
    int a,b;
    cin>>a >> b;
    cout<<getProduct(a,b);
}


