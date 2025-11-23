// Copyright (c) 2025 by Abdelkader Benajiba

#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

// unusable
Span::Span() : size(0), data(0) {}

Span::Span(const unsigned int &N) : size(N) {
  data.reserve(N); // reserve the memory capacity but leaves the size at 0
}

Span::Span(const Span &other) {
  *this = other;  // call the asignement operator
}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->size = other.size;
    this->data.clear();     // clear the span's data then copy from the other
    this->data = other.data;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (data.size() >= size) {    // check the size befor adding the number
    throw Span::SizeNotEnoughException();
  } else {
    data.push_back(number);     // add the number to the span
  }
}

int Span::getNumAt(int i) {
  return this->data[i];
}

int Span::shortestSpan() {
  std::vector<int> tmp(this->data);
  std::sort(tmp.begin(), tmp.end());
  if (tmp.size() <= 1) {    // "If there are no numbers stored, or only one, no span can be found"
    throw Span::NoSpanFoundException();
  }
  int shortest = std::abs(tmp.at(0) - tmp.at(1));   // consider the first span is the minimun
  for (size_t i = 0; i < tmp.size() - 1; i++) {
    int diff = std::abs(tmp.at(i) - tmp.at(i + 1));
    if (diff < shortest) {
      shortest = diff;                              // if any other shortest found. uptade the min
    }
  }
  return shortest;
}

int Span::longestSpan() {
  if (data.size() <= 1) {    // "If there are no numbers stored, or only one, no span can be found"
    throw Span::NoSpanFoundException();
  }
  std::vector<int>::iterator min = std::min_element(data.begin(), data.end());  // find the minimum element in a given range
  std::vector<int>::iterator max = std::max_element(data.begin(), data.end());  // find the maximum element in a given range
  return *max - *min;   // the longest span is simply the diffrence between the max and the min number
}

const char* Span::NoSpanFoundException::what() const throw() {
  return "No Span Found. The container have less than 2 numbers";
}

const char* Span::SizeNotEnoughException::what() const throw() {
  return "Couldn't add numbers to the Span. No enough space!";
}
