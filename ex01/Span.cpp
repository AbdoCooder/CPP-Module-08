// Copyright (c) 2025 by Abdelkader Benajiba

#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

// unusable
Span::Span() : size(0), data(0) {
  std::cout << "Span constructed" << std::endl;
}

Span::Span(const unsigned int &N) : size(N) {
  data.reserve(N); // allocates the memory capacity but leaves the size at 0
  std::cout << "Span constructed" << std::endl;
}

Span::Span(const Span &other) {
  *this = other;
  std::cout << "Span copied" << std::endl;
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->size = other.size;
    this->data.clear();
    this->data = other.data;
  }
  std::cout << "Span assigned" << std::endl;
  return *this;
}

Span::~Span() {
  this->data.clear();
  std::cout << "Span destroyed" << std::endl;
}

void Span::addNumber(int number) {
  if (data.size() >= size) {
    throw std::out_of_range("Error: Span is full");
  } else {
    data.push_back(number);
  }
}

int Span::getNumAt(int i) {
  return this->data[i];
}

int Span::shortestSpan() {
  std::vector<int> tmp(this->data);
  std::sort(tmp.begin(), tmp.end());
  if (tmp.size() <= 1) { // "If there are no numbers stored, or only one, no span can be found."
    throw std::exception();
  }
  int shortest = std::abs(tmp.at(0) - tmp.at(1));
  for (size_t i = 0; i < tmp.size() - 1; i++) {
    int diff = std::abs(tmp.at(i) - tmp.at(i + 1));
    if (diff < shortest) {
      shortest = diff;
    }
  }
  return shortest;
}

int Span::longestSpan() {
  if (data.size() <= 1) { // "If there are no numbers stored, or only one, no span can be found."
    throw std::exception();
  }
  std::vector<int>::iterator min = std::min_element(data.begin(), data.end());
  std::vector<int>::iterator max = std::max_element(data.begin(), data.end());
  return *max - *min;
}

