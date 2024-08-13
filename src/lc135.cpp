#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
  vector<int> candies(ratings.size(), 1);
  for (int i = 1; i <= ratings.size(); i++) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = max(candies[i], candies[i - 1] + 1);
    }
  }
  for (int i = ratings.size() - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i + 1]) {
      candies[i] = max(candies[i], candies[i + 1] + 1);
    }
  }
  return accumulate(candies.begin(), candies.end(), 0);
}

int main(int argc, char const* argv[]) {
  vector<int> input{5, 3, 7, 3};
  printf("%d", candy(input));
  return 0;
}
