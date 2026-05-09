#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MovieTicket {
private:
    // movieID -> set of customerIDs
    unordered_map<int, unordered_set<int>> bookings;

    // Total slots for each movie
    static const int MAX_SLOTS = 100;

public:

    // BOOK X Y
    bool book(int customerID, int movieID) {

        // Check if already booked
        if (bookings[movieID].count(customerID)) {
            return false;
        }

        // Check if movie is sold out
        if (bookings[movieID].size() >= MAX_SLOTS) {
            return false;
        }

        // Book ticket
        bookings[movieID].insert(customerID);
        return true;
    }

    // CANCEL X Y
    bool cancel(int customerID, int movieID) {

        // Check if booking exists
        if (!bookings[movieID].count(customerID)) {
            return false;
        }

        // Cancel booking
        bookings[movieID].erase(customerID);
        return true;
    }

    // IS_BOOKED X Y
    bool isBooked(int customerID, int movieID) {

        return bookings[movieID].count(customerID);
    }

    // AVAILABLE_TICKETS Y
    int availableTickets(int movieID) {

        return MAX_SLOTS - bookings[movieID].size();
    }
};

int main() {

    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {

        string query;
        cin >> query;

        if (query == "BOOK") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.book(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "CANCEL") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "IS_BOOKED") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "AVAILABLE_TICKETS") {

            int Y;
            cin >> Y;

            cout << mt.availableTickets(Y) << endl;
        }
    }

    return 0;
}
