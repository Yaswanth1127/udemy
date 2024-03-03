#include<bits/stdc++.h>
using namespace std;

double getArea(string shape, double dimension1, double dimension2)
    { 
        double area;
        area=1;
        
        if(shape=="square"){
        area=dimension1*dimension1;
        return area;

       }
       
       
       if(shape=="rectangle"){
        area=dimension1*dimension2;
        return area;
       }
       if(shape=="triangle"){
        area=(dimension1*dimension2)/2;
        return area;
       }
       if(shape=="circle"){
        area=3.14*dimension1;
        return area;
       }
       return 0;

     }
    


    int main(){
        double dimension1,dimension2;
        string shape;
        cin>> dimension1 >> dimension2 ;
        getline(cin,shape);
        cout<<getArea(shape, dimension1, dimension2);

    }