#pragma once

#include "subdir/Into.hpp"
#include <string>
#include <vector>

class Question : Into<int> {
public:
  Question(std::string prompt, std::vector<std::string> options,
           int correctIndex);

  // Ask the question on stdout, read an answer from stdin, return true if
  // correct
  bool ask() const;

  int into() && override { return this->correctIndex; }

private:
  std::string prompt;
  std::vector<std::string> options;
  int correctIndex;
};
