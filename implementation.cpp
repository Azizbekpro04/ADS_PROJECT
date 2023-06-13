#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums) {
    vector<int> duplicates;
    vector<int> count(nums.size() + 1, 0);
    
    for (int num : nums) {
        count[num]++;
        if (count[num] > 1) {
            duplicates.push_back(num);
        }
    }
    
    return duplicates;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);
    
    cout << "Duplicate elements: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
