#pragma once

#include "subdir/Question.hpp"
#include <string>
#include <vector>

class Quiz {
public:
  Quiz(std::string title);
  void addQuestion(const Question &q);
  void run() const;

private:
  std::string title_;
  std::vector<Question> questions_;
};
