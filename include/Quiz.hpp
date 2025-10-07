#pragma once

#include "Question.hpp"
#include <string>
#include <vector>

class Quiz {
public:
  Quiz(std::string title = "Simple CLI Quiz");
  void addQuestion(const Question &q);
  void run();

private:
  std::string title_;
  std::vector<Question> questions_;
};
