#include<iostream>
#include<cmath>
using namespace std;
int power(int x,int y){
    int ans;
    ans=1;
    ans=pow(x,y);
    return ans;
}

int main(){
    int x,y;
    cin>>x >> y;
    cout<<power(x,y);

}


