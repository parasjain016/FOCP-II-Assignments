#include<iostream>
#include<string>
using namespace std;

int main(){
    int L, R;
    cin >> L >> R; 
    int odd_count = ((R + 1) / 2) - (L / 2);
    
    if(odd_count % 2 == 1){
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
    
    return 0;
}