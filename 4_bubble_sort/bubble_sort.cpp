// Implementation of bubble sort

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Bubble sort implementations
void sort(std::vector<int> &values) {
  // For each position in the vector (descending)
  for (int target = values.size() - 1; target > 0; target--) {
    // For each element in the unsorted sub-array
    for (int current = 0; current < target; current++) {
      // Compare the current element to the next
      auto next = current + 1;
      if (values[current] > values[next])
        // Swap the larger element upward
        std::swap(values[current], values[next]);
    }
  }
}

// Helper function to print the vector contents
void print(const std::vector<int> &values) {
  for (auto v : values) std::cout << v << ' ';
  std::cout << '\n';
}

int main() {
  // Number of elements to sort
  int N = 16;

  // Create our random number generator
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 100);

  // Create vector of input elements
  std::vector<int> values;
  values.reserve(N);
  for (int i = 0; i < N; i++) values.push_back(dist(rng));

  // Print out starting values
  print(values);

  // Sort the vector
  sort(values);

  // Print ending values
  print(values);

  return 0;
}


/* 总结：
 * 冒泡排序：
 * 依次，两个两个比较，小的在前，大的在后，
 * 最大的换到最后
 * 剩下的，再从 0 开始，大的慢慢到最后
 *
 * */
