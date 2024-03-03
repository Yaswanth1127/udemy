#include<bits/stdc++.h>
using namespace std;


int gcd (int x, int y){
   int  a;
   a=min(x,y);
    int temp;
    for(int i=1;i<=a/2;i++){
        if(x%i==0 && y%i==0)
        temp=i;
    }
    return temp;

}
int main(){
    int x,y;
    cin>>x >> y;
    cout<<gcd(x,y);
}