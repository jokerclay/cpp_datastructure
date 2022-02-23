// Implementation of quick sort

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

// --------------------------
// quick sort implementation
// --------------------------
void quick_sort(std::vector<int> &v,  begin, int end) {
   // wreite the implementation here
   print(v);

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
  std::cout << "The random numbers are: " << std::endl;
  print(values);


  // Sort the vector
  quick_sort(values,values.begin(),values.end() );

  std::cout << std::endl;
  // Print ending values
  std::cout << "The numbers after sorted are:" << std::endl;
  print(values);

  return 0;
}


