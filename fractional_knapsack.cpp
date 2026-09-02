// Write a program to solve the Fractional Knapsack problem using the
// Greedy approach.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Solves fractional knapsack greedily by value/weight ratio.
// Returns the maximum value obtainable for the given capacity.
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by value/weight ratio in descending order
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        double ratioA = (double)a.value / a.weight;
        double ratioB = (double)b.value / b.weight;
        return ratioA > ratioB;
    });

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (remainingCapacity <= 0) break;

        if (item.weight <= remainingCapacity) {
            // Take the whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
            cout << "Took whole item (weight=" << item.weight
                 << ", value=" << item.value << ")" << endl;
        } else {
            // Take a fraction of the item
            double fraction = (double)remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            cout << "Took " << fraction * 100 << "% of item (weight="
                 << item.weight << ", value=" << item.value << ")" << endl;
            remainingCapacity = 0;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {10, 60},  // weight, value
        {20, 100},
        {30, 120}
    };
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in knapsack (capacity " << capacity << "): "
         << maxValue << endl;

    return 0;
}

/*
Sample Output:

student@labs:~/dsa$ g++ -std=c++17 -o fractional_knapsack fractional_knapsack.cpp && ./fractional_knapsack
Took whole item (weight=10, value=60)
Took whole item (weight=20, value=100)
Took 66.6667% of item (weight=30, value=120)
Maximum value in knapsack (capacity 50): 240
*/
