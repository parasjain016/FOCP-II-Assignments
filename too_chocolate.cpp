#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int> arr){
    sort(arr.begin(), arr.end(), greater<int>());
    
    set<int> alexSeen, bobSeen;
    int alex = 0, bob = 0;
    int turn = 0;
    
    for(int i = 0; i < n; i++){
        if(turn == 0){
            if(alexSeen.count(arr[i])){
                continue;
            }
            alexSeen.insert(arr[i]);
            alex += arr[i];
            turn = 1;
        } else {
            if(bobSeen.count(arr[i])){
                continue;
            }
            bobSeen.insert(arr[i]);
            bob += arr[i];
            turn = 0;
        }
    }
    
    if(alex > bob) return "Alex";
    else return "Bob";
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        cout << solve(n, arr) << endl;
    }
    
    return 0;
}