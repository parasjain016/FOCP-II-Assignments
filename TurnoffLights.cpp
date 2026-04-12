#include <iostream>
#include <string>
using namespace std;

bool TurnOff(string &bulbs, int N, int K, int X) {
    int operations = 0;

    for (int i = 0; i < N; i++) {
        if (bulbs[i] == '1') {
            operations++;
            i += X - 1; 
        }
    }

    return operations <= K;
}

int main() {
    int N, K;
    cin >> N >> K;

    string bulbs;
    cin >> bulbs;

    int low = 1, high = N, answer = N;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (TurnOff(bulbs, N, K, mid)) {
            answer = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    cout << answer << endl;

    return 0;
}
