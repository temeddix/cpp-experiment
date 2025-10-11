#include "Quiz.hpp"

#include <iostream>

#include "subdir/LogStat.hpp"

Quiz::Quiz(std::string title) : title(std::move(title)) {}

auto Quiz::addQuestion(const Question& question) -> void {
  questions.push_back(question);
}

auto Quiz::run() const -> std::expected<void, QuizError> {
  if (questions.empty()) {
    return std::unexpected{QuizError::NoQuestions};
  }

  std::cout << "=== " << title << " ===\n\n";
  int score = {0};
  for (size_t i = {0}; i < questions.size(); ++i) {
    std::cout << "Question " << (i + 1) << "/" << questions.size() << ":\n";

    auto result = questions[i].ask();
    if (!result) {
      std::cout << "Error asking question: " << static_cast<int>(result.error())
                << "\n";
      continue;
    }

    if (result.value()) {
      ++score;
    }
  }
  std::cout << "Quiz finished. Score: " << score << "/" << questions.size()
            << "\n";
  return {};  // Success
}

auto Quiz::logQuestions() const -> void {
  std::cout << "Would you like to see the answer sheet? (y/n): ";
  char choice = '\0';
  std::cin >> choice;

  if (choice != 'y' && choice != 'Y') {
    return;
  }

  std::cout << "Logging questions:\n";
  for (const auto& question : questions) {
    this->logQuestion(question);
  }
}

template <LogStat T>
auto Quiz::logQuestion(const T& question) const -> void {
  question.logStat();
}