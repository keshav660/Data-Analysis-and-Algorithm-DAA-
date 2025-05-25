#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, profit;
    Item(int w, int p) : weight(w), profit(p) {}
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp);  
    double maxProfit = 0.0;

    for (auto item : items) {
        if (W >= item.weight) {  // If the full item can be taken
            maxProfit += item.profit;
            W -= item.weight;
        } else {  // Take fractional part
            maxProfit += item.profit * ((double)W / item.weight);
            break;
        }
    }
    return maxProfit;
}

// Main function to take input and run the algorithm
int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<Item> items;
    cout << "Enter weight and profit of each item:\n";
    for (int i = 0; i < n; i++) {
        int weight, profit;
        cin >> weight >> profit;
        items.push_back(Item(weight, profit));
    }

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum profit: " << fixed << setprecision(2) << maxProfit << endl;
    return 0;
}
