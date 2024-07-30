#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> queue;
  deque<int> maxValueQueue;
  vector<int> output;
  for (int num : nums) {
    queue.push_back(num);
    while (!maxValueQueue.empty() && maxValueQueue.back() < num) {
      maxValueQueue.pop_back();
    }
    maxValueQueue.push_back(num);
    if (queue.size() > k) {
      int front = queue.front();
      queue.pop_front();
      if (!maxValueQueue.empty() && maxValueQueue.front() == front) {
        maxValueQueue.pop_front();
      }
    }
    if (queue.size() == k) {
      output.push_back(maxValueQueue.front());
    }
  }
  return output;
}

int main(int argc, char const* argv[]) {
  vector<int> input({9, 10, 9, -7, -4, -8, 2, -6});
  vector<int> output = maxSlidingWindow(input, 5);
  for (int num : output) {
    printf("%d ", num);
  }
  return 0;
}
