#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;              

    while (t--) {
        int n;
        cin >> n;

        int count = 0;     

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * j == n && gcd(i, j) == 1) {
                    count++;
                }
            }
        }

        cout << count << endl;   
    }

    return 0;
}

