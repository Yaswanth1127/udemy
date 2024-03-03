#include<iostream>
using namespace std;
int  factorial(int n){
int ans=1;
int i;
for(int i = 1; i<=n; i++){
    ans=ans * i;

}

return ans;
}
int bincoff(int N, int R){
    int ans = factorial(N)/ (factorial(N-R) * factorial(R));
    return ans;

}



int main(){
    int N,R;
    cin>>N>>R;
    cout<< bincoff(N,R) <<endl;

}