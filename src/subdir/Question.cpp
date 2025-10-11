#include "subdir/Question.hpp"

#include <iostream>
#include <limits>

Question::Question(std::string prompt, std::vector<std::string> options,
                   int correctIndex)
    : prompt(std::move(prompt)),
      options(std::move(options)),
      correctIndex(correctIndex) {}

auto Question::ask() const -> std::expected<bool, QuestionError> {
  std::cout << prompt << "\n";
  for (size_t i = {0}; i < options.size(); ++i) {
    std::cout << "  " << (i + 1) << ") " << options[i] << "\n";
  }

  int choice = {0};
  while (true) {
    std::cout << "Your answer (enter the option number): ";
    if (!(std::cin >> choice)) {
      // Invalid input, clear and retry
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please enter a number.\n";
      continue;
    }
    if (choice < 1 || static_cast<size_t>(choice) > options.size()) {
      std::cout << "Choice out of range, try again.\n";
      continue;
    }
    break;
  }

  const bool correct = {(choice - 1) == correctIndex};
  if (correct) {
    std::cout << "Correct!\n\n";
  } else {
    std::cout << "Incorrect. Correct answer: " << (correctIndex + 1) << ") "
              << options[correctIndex] << "\n\n";
  }

  return correct;
}

auto Question::logStat() const -> void {
  std::cout << "Question: " << prompt << "\n";
  std::cout << "Number of options: " << options.size() << "\n";
  std::cout << "Correct option index: " << correctIndex << "\n";
}