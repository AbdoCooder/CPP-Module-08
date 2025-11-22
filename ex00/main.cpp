// Copyright (c) 2025 by Abdelkader Benajiba

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
  std::vector<int> vec;
  vec.push_back(2);
  vec.push_back(6);
  vec.push_back(1);
  vec.push_back(5);
  vec.push_back(4);
  vec.push_back(3);
  try {
    std::vector<int>::iterator it = easyfind(vec, 1);
    while (it != vec.end()) {
      std::cout << *it << std::endl;
      it++;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
