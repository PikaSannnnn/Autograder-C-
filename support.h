#include <vector>
#include <iostream>
using std::cout;
using std::endl;

namespace sprt {
    std::vector<int> merge(std::vector<int> x, const std::vector<int> y) {
        for (size_t i = 0; i < y.size(); i++) {
            x.push_back(y[i]);
        }
        
        return x;
    }
    std::vector<int> Sort(std::vector<int> x) {
        if (x.size() <= 1) return x;
        
        int mid = x.size() / 2;
        std::vector<int> left;
        std::vector<int> right;

        for (size_t i = 0; i < x.size(); i++) {
            if (i < mid) {
                left.push_back(x[i]);
            }
            else {
                right.push_back(x[i]);
            }
        }


        left = Sort(left);
        right = Sort(right);

        size_t i = 0, j = 0;
        std::vector<int> merged;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                merged.push_back(left[i]);
                i++;
            }
            else {
                merged.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            merged.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            merged.push_back(right[j]);
            j++;
        }

        return merged;
    }
}