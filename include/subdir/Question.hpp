#pragma once

#include <expected>
#include <string>
#include <vector>

enum class QuestionError : std::uint8_t {
  InvalidOptionIndex,
  EmptyOptions,
  EmptyPrompt
};

class Question {
 public:
  // Constructor that validates inputs and can be used directly
  Question(std::string prompt, std::vector<std::string> options,
           int correctIndex);

  // Ask the question on stdout, read an answer from stdin,
  // return expected with result or error
  [[nodiscard]]
  auto ask() const -> std::expected<bool, QuestionError>;

  auto logStat() const -> void;

 private:
  std::string prompt;

  std::vector<std::string> options;

  int correctIndex;
};
