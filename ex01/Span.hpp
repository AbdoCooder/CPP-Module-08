// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <exception>

class Span {
  public:
    // A constructer that takes the fixed size of the size (Span is not resizable)
    Span(const unsigned int &N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    // add a number at the end of the span
    void  addNumber(int);
    // get a number from a specific position
    int   getNumAt(int);
    // calculate the shortest dist between the span's numbers
    int   shortestSpan();
    // calculate the longest dist between the span's numbers
    int   longestSpan();

    // add a range of numbers from other container at once
    template<typename T>                      // Used template to accept all type of containers
    void addRange(T begin, T end) {
      int dist = std::distance(begin, end);   // count how many numbers to add
      if ((data.size() + dist) > size) {      // make sure the Span's size capable of holder the range
        throw Span::SizeNotEnoughException(); // Throw a custom exception if the size is not enough
      }
      data.insert(data.end(), begin, end);    // insert the range from begin to end at the end of the Span
    }

    class NoSpanFoundException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

    class SizeNotEnoughException : public std::exception {
      public:
        virtual const char* what() const throw();
    };

  private:
    Span();                   // no need for the default (exist for the OCF)
    unsigned int      size;   // The max size of the span
    std::vector<int>  data;   // The container that hold the span's numbers
};

#endif //  SPAN_HPP
