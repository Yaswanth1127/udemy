#include<iostream>
using namespace std;
void playmusic(){
    cout <<" playing music ";
}

void sayhi(string name){
    cout<<"hi"+ name <<endl;

}
string sayhello(string name){
    return "hello"+ name;
}

int main(){

    playmusic();
    sayhi("yaswanth");
    cout<< sayhello("coding minutes")<< endl;

    return 0;

}