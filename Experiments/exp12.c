#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expectedSum = n * (n + 1) / 2; // Sum of numbers from 0 to n
    int actualSum = 0;

    // Calculate the actual sum of elements in the array
    for (int num : nums) {
        actualSum += num;
    }

    // The missing number is the difference
    return expectedSum - actualSum;
}

int main() {
    vector<int> nums1 = {3, 0, 1};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    cout << "Missing number in [3,0,1]: " << missingNumber(nums1) << endl;
    cout << "Missing number in [0,1]: " << missingNumber(nums2) << endl;
    cout << "Missing number in [9,6,4,2,3,5,7,0,1]: " << missingNumber(nums3) << endl;

    return 0;
}
