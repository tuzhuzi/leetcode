#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPairs(vector<int>& nums, int target, vector<vector<int>>& ret) {
    int left = 0;
    int right = nums.size() - 1;
    sort(nums.begin(), nums.end());
    cout<<left<<", "<<right<<endl;
    while (left < right) {
        cout<<left<<","<<right<<endl;
        if (nums[left] + nums[right] > target) {
            right--;
            continue;
        } else if (nums[left] + nums[right] < target){
            left++;
            continue;
        }
        if (nums[left] != nums[right]) {
            int leftCount = 1;
            int rightCount = 1;
            while (left < right && nums[left + 1] == nums[left]) {
                left++;
                leftCount++;
            }
            while (left < right && nums[right - 1] == nums[right]) {
                right--;
                rightCount++;
            }
            for (int i = 0; i < leftCount*rightCount; i++) {
                ret.push_back(vector<int>{nums[left], nums[right]});
            }
            left++;
            right--;
        } else {
             cout<<"find pair"<<nums[left]<<","<<nums[right]<<endl;
            int diff = right - left;
            int count = 0;
            while (diff >= 1) {
                count += diff;
                diff--;
            }
            while (count > 0) {
                ret.push_back(vector<int>{nums[left], nums[right]});
                count--;
            }
            break;
        }
    }
}

int main() {
    vector<int> input{1, 2, 5, 2, -1, 3, 1, 2};
    vector<vector<int>> ret;
    findPairs(input, 4, ret);
    for (auto vec : ret) {
        cout<<vec[0]<<", "<<vec[1]<<endl;
    }
    return 0;
}