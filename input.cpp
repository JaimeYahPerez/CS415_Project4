
#include "input.hpp"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

KnapsackInput readInput(int prefix) {

    if (prefix < 0) {
        throw runtime_error("Invalid file prefix.");
    }

    // Generate the file prefix: p00, p01, ... p10
    ostringstream name;
    name << "p" << setfill('0') << setw(2) << prefix;

    string base = name.str();

    // Input files are stored in the data directory
    string capacityFile = "data/" + base + "_c.txt";
    string weightFile = "data/" + base + "_w.txt";
    string valueFile = "data/" + base + "_v.txt";

    ifstream cFile(capacityFile);
    ifstream wFile(weightFile);
    ifstream vFile(valueFile);

    if (!cFile || !wFile || !vFile) {
        throw runtime_error("Unable to open input files for " + base);
    }

    KnapsackInput input;

    // Read the capacity
    if (!(cFile >> input.capacity) || input.capacity < 0) {
        throw runtime_error("Invalid knapsack capacity.");
    }

    // Read weights
    vector<int> weights;
    int weight;

    while (wFile >> weight) {
        if (weight <= 0) {
            throw runtime_error("Weights must be positive.");
        }
        weights.push_back(weight);
    }

    // Read values
    vector<long long> values;
    long long value;

    while (vFile >> value) {
        if (value < 0) {
            throw runtime_error("Values must be nonnegative.");
        }
        values.push_back(value);
    }

    // Check for malformed file content
    if (!wFile.eof() || !vFile.eof()) {
        throw runtime_error("Invalid weight or value data.");
    }

    // Each item must have both a weight and a value
    if (weights.size() != values.size()) {
        throw runtime_error("Weight and value counts do not match.");
    }

    // Construct item records (1-based indexing)
    for (size_t i = 0; i < weights.size(); i++) {
        Item item;

        item.index = static_cast<int>(i) + 1;
        item.weight = weights[i];
        item.value = values[i];

        input.items.push_back(item);
    }

    return input;
}