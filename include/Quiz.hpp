#pragma once

#include <string>
#include <vector>

#include "subdir/LogStat.hpp"
#include "subdir/Question.hpp"

class Quiz {
 public:
  Quiz(std::string title);
  void addQuestion(const Question& q);
  void logQuestions() const;
  void run() const;

 private:
  std::string title;
  std::vector<Question> questions;
  template <LogStat T>
  void logQuestion(const T) const;
};
