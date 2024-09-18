#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                          int capacity) {
  sort(buses.begin(), buses.end());
  sort(passengers.begin(), passengers.end());

  int busIndex = 0;
  int passengersIndex = 0;
  int count = 0;
  while (busIndex < buses.size() && passengersIndex < passengers.size()) {
    int curBusTime = buses[busIndex++];
    count = 0;
    while (count < capacity && passengersIndex < passengers.size() &&
           passengers[passengersIndex] <= curBusTime) {
      passengersIndex++;
      count++;
    }
  }
  // 车没坐满， 跟着最后一辆车就行
  int arriveTime;
  if (busIndex < buses.size() || count < capacity) {
    arriveTime = buses[buses.size() - 1];
  } else {
    // 车坐满了，要跟在最后一个人之前才行
    arriveTime = passengers[passengersIndex - 1];
  }
  // 避免和乘客的时间重合，有重合就提前
  for (int i = passengersIndex - 1; i >= 0; i--) {
    if (passengers[i] != arriveTime) {
      break;
    }
    arriveTime--;
  }
  return arriveTime;
}

int main(int argc, char const* argv[]) {
  vector<int> buses{10, 20, 30};
  vector<int> passengers{19, 13, 26, 4, 25, 11, 21};
  printf("%d", latestTimeCatchTheBus(buses, passengers, 2));
  return 0;
}
