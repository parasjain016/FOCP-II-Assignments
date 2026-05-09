#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Bank {
private:
    unordered_map<string, long long> accounts;

public:
    // CREATE X Y
    bool create(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) {
            accounts[X] = Y;
            return true;
        } else {
            accounts[X] += Y;
            return false;
        }
    }

    // DEBIT X Y
    bool debit(string X, long long Y) {
        if (accounts.find(X) == accounts.end() || accounts[X] < Y) {
            return false;
        }

        accounts[X] -= Y;
        return true;
    }

    // CREDIT X Y
    bool credit(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) {
            return false;
        }

        accounts[X] += Y;
        return true;
    }

    // BALANCE X
    long long balance(string X) {
        if (accounts.find(X) == accounts.end()) {
            return -1;
        }

        return accounts[X];
    }
};

int main() {
    int Q;
    cin >> Q;
    cin.ignore();

    Bank bank;

    for (int i = 0; i < Q; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        string queryType, X;
        long long Y;

        ss >> queryType;

        if (queryType == "CREATE") {
            ss >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        }

        else if (queryType == "DEBIT") {
            ss >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        }

        else if (queryType == "CREDIT") {
            ss >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        }

        else if (queryType == "BALANCE") {
            ss >> X;
            cout << bank.balance(X) << endl;
        }
    }

    return 0;
}
