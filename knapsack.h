#pragma once

#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>

struct Item {
    int index;
    int weight;
    long long value;
};

struct KnapsackInput {
    int capacity;
    std::vector<Item> items;
};

struct KnapsackResult {
    long long bestValue = 0;
    std::vector<int> selectedItems;
    long long basicOps = 0;
    long long spaceTaken = 0;
};

#endif
