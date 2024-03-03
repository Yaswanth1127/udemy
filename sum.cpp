#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int n) {
      int sum=0;
    while (n>0) {
         sum = sum + n % 10;
         n  = n / 10;    
    }   
    return sum;  
}
int main (){
    int n;

    cin>>n;
    cout<<sum_of_digits( n);  
}
