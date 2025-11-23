// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <
  typename T,
  typename Container = std::deque<T>
>
class MutantStack : public std::stack<T, Container> {
 public:
  typedef typename Container::iterator iterator;
  typedef typename Container::const_iterator const_iterator;
  typedef typename Container::reverse_iterator reverse_iterator;

  MutantStack(): std::stack<T, Container>() {}

  MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}

  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) {
      std::stack<T, Container>::operator=(other);
    }
    return *this;
  }

  ~MutantStack() {}

  iterator begin() {
    return this->c.begin();
  }
  const_iterator cbegin() const {
    return this->c.cbegin();
  }
  reverse_iterator rbegin() const {
    return this->c.rbegin();
  }
  iterator end() {
    return this->c.end();
  }
  const_iterator cend() const {
    return this->c.cend();
  }
  reverse_iterator rend() const {
    return this->c.rend();
  }
};

#endif //  MUTANTSTACK_HPP
