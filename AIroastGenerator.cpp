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

    // Checking empty input
    if(name.empty()) {
        cout << "Name cannot be empty!" << endl;
        return 0;
    }

    // Roast templates
    vector<string> roasts = {
        name + "'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be " + name + ".",
        name + " doesn't debug code — they negotiate with bugs.",
        name + " writes code so confusing that even AI asks for clarification.",
        "If procrastination were an Olympic sport, " + name + " would win gold.",
        name + "'s WiFi signal is stronger than their coding logic.",
        name + " debugs by staring at the screen until the bug feels guilty.",
        "Even a calculator gets nervous when " + name + " starts coding.",
        name + "'s code has more twists than a Bollywood movie.",
        "When " + name + " says 'Trust me, it works,' everyone gets scared."
    };

    // Random number generation
    srand(time(0));

    int randomIndex = rand() % roasts.size();

    // Display roast
    cout << "\n🔥 Roast Generator 🔥" << endl;
    cout << roasts[randomIndex] << endl;

    return 0;
}
