#pragma once

#include <expected>
#include <string>
#include <vector>

#include "subdir/LogStat.hpp"
#include "subdir/Question.hpp"

enum class QuizError { InvalidQuestion, NoQuestions };

class Quiz {
 public:
  Quiz(std::string title);
  void addQuestion(const Question& q);
  void logQuestions() const;
  std::expected<void, QuizError> run() const;

 private:
  std::string title;
  std::vector<Question> questions;
  template <LogStat T>
  void logQuestion(const T) const;
};
