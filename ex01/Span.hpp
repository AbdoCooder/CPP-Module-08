// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <exception>

class Span {
  public:
    Span(const unsigned int &N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void  addNumber(int);
    int   getNumAt(int);
    int   shortestSpan();
    int   longestSpan();

    template<typename T>
    void addRange(T begin, T end) {
      int dist = std::distance(begin, end);
      if (data.size() + dist > size) {
        throw std::exception();
      }
      data.insert(data.end(), begin, end);
    }

  private:
    Span();
    unsigned int      size;
    std::vector<int>  data;
};

#endif //  SPAN_HPP
