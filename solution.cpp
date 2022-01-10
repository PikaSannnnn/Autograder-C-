// Read the README.md for more information on how to compile/run here
// Write ALL your code below
#include <iostream>
#include "support.h"

using namespace std;

vector<int> Merge(vector<int> x, vector<int> y) {
    return sprt::merge(x, y);
}

void Print(double x) {
    cout << x << endl;
}
void Print(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
// Leave smain()'s parameters empty unless instructed.
// You will get an error if there's supposed to be parameters
int smain() {    // This is not the actual main(), but pretend it is
    vector<int> x;
    vector<int> y;
    int num_entries = 0;

    cout << "Enter num entries in data set 1: ";
    cin >> num_entries;
    cout << "Enter your data set: ";
    for (int i = 0; i < num_entries; i++) {
        int num = 0;
        cin >> num;
        x.push_back(num);
    }

    cout << "Enter num entries in data set 2: ";
    cin >> num_entries;
    cout << "Enter your data set: ";
    for (int i = 0; i < num_entries; i++) {
        int num = 0;
        cin >> num;
        y.push_back(num);
    }
    
    vector<int> merged;
    vector<int> sorted;
    string choice = "";
    cin >> choice;
    while(choice != "exit") {
        if (choice == "mean") {
            if (merged.empty()) {
                cout << "No Merged Data Set" << endl;
            }
            else {
                int sum = 0;
                for (int i = 0; i < merged.size(); i++) {
                    sum += merged[i];
                }
                
                Print(static_cast<double> (sum)/ merged.size());
            }
        }
        else if (choice == "median") {
            if (merged.empty()) {
                cout << "No Merged Data Set" << endl;
            }
            else {
                double median;
                if (sorted.empty()) {
                    sorted = sprt::Sort(merged); 
                }
                
                if (sorted.size() % 2 == 0) {    // even # elements
                    int sum = sorted[sorted.size() / 2] + sorted[sorted.size() / 2 - 1];
                    median = sum / 2.0;
                }
                else {
                    median = sorted[sorted.size() / 2];
                }
    
                Print(median);
            }
        }
        else if (choice == "range") {
            if (merged.empty()) {
                cout << "No Merged Data Set" << endl;
            }
            else {
                if (sorted.empty()) {
                    sorted = sprt::Sort(merged); 
                }
                
                Print(sorted[sorted.size() - 1] - sorted[0]);
            }
        }
        else if (choice == "print") {
            if (merged.empty()) {
                cout << "No Merged Data Set" << endl;
            }
            else {
                Print(merged);
            }
        }
        else if (choice == "merge") {
            if (merged.empty()) {
                merged = Merge(x, y);
            }
            if (merged.empty()) {
                cout << "No Merged Data Set" << endl;
            }
            else {
                Print(merged);
            }
        }

        cin >> choice;
    }

    cout << "Bye!" << endl;
    
    return 0;
}

// Uncomment this if you wish to test your code manually
// Make sure to use g++ solution.cpp instead
// int main() {    // edit this line however you need to
//     // smain();    // edit this line however you need to
// }