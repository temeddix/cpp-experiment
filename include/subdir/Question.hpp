#pragma once

#include <string>
#include <vector>

class Question {
 public:
  Question(std::string prompt, std::vector<std::string> options,
           int correctIndex);

  // Ask the question on stdout, read an answer from stdin, return true if
  // correct
  bool ask() const;

  void logStat() const;

 private:
  std::string prompt;
  std::vector<std::string> options;
  int correctIndex;
};
