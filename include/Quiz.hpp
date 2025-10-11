#pragma once

#include <cstdint>
#include <expected>
#include <string>
#include <vector>

#include "subdir/LogStat.hpp"
#include "subdir/Question.hpp"

enum class QuizError : std::uint8_t { InvalidQuestion, NoQuestions };

class Quiz {
 public:
  Quiz(std::string title);

  auto addQuestion(const Question& q) -> void;

  auto logQuestions() const -> void;

  [[nodiscard]]
  auto run() const -> std::expected<void, QuizError>;

 private:
  std::string title;

  std::vector<Question> questions;

  template <LogStat T>
  auto logQuestion(const T) const -> void;
};
