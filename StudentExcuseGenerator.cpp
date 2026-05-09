#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string name;

    // Taking user input
    cout << "Enter your name: ";
    getline(cin, name);

    // Check if input is empty
    if(name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Excuse templates
    vector<string> excuses = {
        name + " couldn't finish the assignment because the laptop battery died unexpectedly.",
        name + " tried completing the homework, but the Wi-Fi suddenly stopped working.",
        name + " was about to submit the assignment when the file mysteriously disappeared.",
        name + " couldn't study because the computer started updating for hours.",
        "Just when " + name + " started the assignment, the keyboard stopped working.",
        name + " lost track of time while fixing a technical issue on the laptop.",
        name + " accidentally deleted the assignment while organizing files.",
        name + " couldn't complete the work because the internet kept disconnecting.",
        name + " was ready with the homework, but the system crashed unexpectedly.",
        name + " spent hours solving one bug and forgot about the assignment deadline."
    };

    // Random function setup
    srand(time(0));

    // Random index
    int randomIndex = rand() % excuses.size();

    // Display excuse
    cout << "\nGenerated Excuse:\n";
    cout << excuses[randomIndex] << endl;

    return 0;
}
