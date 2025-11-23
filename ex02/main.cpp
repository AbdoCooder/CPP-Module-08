// Copyright (c) 2025 by Abdelkader Benajiba

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main() {
  {
    MutantStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    MutantStack<int>::iterator it = st.begin();
    while (it != st.end()) {
      std::cout << *it++ << std::endl;
    }
  }
  std::cout << "========" << std::endl;
  {
    std::list<int> st;
    st.push_back(1);
    st.push_back(2);
    st.push_back(3);
    std::list<int>::iterator it = st.begin();
    while (it != st.end()) {
      std::cout << *it++ << std::endl;
    }
  }
  return 0;
}
