#include "subdir/Question.hpp"
#include <iostream>
#include <limits>

Question::Question(std::string prompt, std::vector<std::string> options,
                   int correctIndex)
    : prompt_(std::move(prompt)), options_(std::move(options)),
      correctIndex_(correctIndex) {}

bool Question::ask() const {
  std::cout << prompt_ << "\n";
  for (size_t i = 0; i < options_.size(); ++i) {
    std::cout << "  " << (i + 1) << ") " << options_[i] << "\n";
  }

  int choice = 0;
  while (true) {
    std::cout << "Your answer (enter the option number): ";
    if (!(std::cin >> choice)) {
      // Invalid input, clear and retry
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Please enter a number.\n";
      continue;
    }
    if (choice < 1 || static_cast<size_t>(choice) > options_.size()) {
      std::cout << "Choice out of range, try again.\n";
      continue;
    }
    break;
  }

  const bool correct = (choice - 1) == correctIndex_;
  if (correct) {
    std::cout << "Correct!\n\n";
  } else {
    std::cout << "Incorrect. Correct answer: " << (correctIndex_ + 1) << ") "
              << options_[correctIndex_] << "\n\n";
  }
  return correct;
}
