#pragma once

#include "subdir/Clone.hpp"
#include <string>
#include <vector>

class Question : Clone<Question> {
public:
  Question(std::string prompt, std::vector<std::string> options,
           int correctIndex);

  // Ask the question on stdout, read an answer from stdin, return true if
  // correct
  bool ask() const;

  Question clone() const override {
    return Question{
        this->prompt,
        this->options,
        this->correctIndex,
    };
  }

private:
  std::string prompt;
  std::vector<std::string> options;
  int correctIndex;
};
