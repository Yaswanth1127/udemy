#include<iostream>
using namespace std;
int factorial(int n){
    int ans=1;
    int i;
for(int i = 1; i<=n; i++){
    ans=ans * i;

}

return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
}