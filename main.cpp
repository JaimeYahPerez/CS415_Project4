
#include <iostream>
#include <string>
#include "input.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Usage: ./p3 <prefix>" << endl;
        return 1;
    }

    try {
        // Convert command-line argument to integer
        size_t parsed = 0;
        string argument = argv[1];
        int prefix = stoi(argument, &parsed);

        if (parsed != argument.size()) {
            throw invalid_argument("Invalid prefix.");
        }

        // Load problem data
        KnapsackInput input = readInput(prefix);

        cout << "Knapsack capacity = "
            << input.capacity << endl;

        cout << "Total number of items = "
            << input.items.size() << endl;

        cout << "\nItems:\n";

        for (const Item& item : input.items) {
            cout << "Item " << item.index
                << ": Weight = " << item.weight
                << ", Value = " << item.value
                << endl;
        }

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}