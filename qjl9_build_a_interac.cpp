#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// CLI Tool Simulator Configuration
const string TOOL_NAME = "Interactive CLI Tool Simulator";
const string VERSION = "1.0";

// Available Commands
map<string, string> commands = {
    {"help", "Display available commands"},
    {"version", "Display tool version"},
    {"quit", "Exit the tool"},
    {"calc", "Perform calculations"},
    {"list", "List available commands"}
};

// Calculation Functions
map<string, double (*)(double, double)> calcFunctions = {
    {"add", [](double a, double b) { return a + b; }},
    {"sub", [](double a, double b) { return a - b; }},
    {"mul", [](double a, double b) { return a * b; }},
    {"div", [](double a, double b) { return a / b; }}
};

int main() {
    cout << TOOL_NAME << " " << VERSION << endl;
    cout << "Type 'help' to display available commands." << endl;

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "help") {
            cout << "Available commands:" << endl;
            for (auto& command : commands) {
                cout << command.first << ": " << command.second << endl;
            }
        } else if (input == "version") {
            cout << TOOL_NAME << " " << VERSION << endl;
        } else if (input == "quit") {
            break;
        } else if (input == "calc") {
            string func;
            double a, b;
            cout << "Enter function (add, sub, mul, div): ";
            cin >> func;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            if (calcFunctions.find(func) != calcFunctions.end()) {
                cout << "Result: " << calcFunctions[func](a, b) << endl;
            } else {
                cout << "Invalid function." << endl;
            }
        } else if (input == "list") {
            cout << "Available commands:" << endl;
            for (auto& command : commands) {
                cout << command.first << ": " << command.second << endl;
            }
        } else {
            cout << "Invalid command. Type 'help' for available commands." << endl;
        }
    }

    return 0;
}