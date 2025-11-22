// main.cpp
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main() {
  // --- PART 1: Subject Example ---
  std::cout << "--- Subject Example ---" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest: " << sp.longestSpan() << std::endl;

  // --- PART 2: The 10,000 Numbers Test ---
  std::cout << "\n--- 10,000 Numbers Test ---" << std::endl;
  try {
    std::vector<int> random_numbers;
    
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; ++i) {
      random_numbers.push_back(std::rand());
    }

    Span bigSpan(10000);
    bigSpan.addRange(random_numbers.begin(), random_numbers.end());

    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

  } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
  }
  return 0;
}
