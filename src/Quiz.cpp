#include "Quiz.hpp"
#include <iostream>

Quiz::Quiz(std::string title) : title_(std::move(title)) {}

void Quiz::addQuestion(const Question &q) { questions_.push_back(q); }

void Quiz::run() {
  std::cout << "=== " << title_ << " ===\n\n";
  int score = {0};
  for (size_t i = {0}; i < questions_.size(); ++i) {
    std::cout << "Question " << (i + 1) << "/" << questions_.size() << ":\n";
    if (questions_[i].ask())
      ++score;
  }
  std::cout << "Quiz finished. Score: " << score << "/" << questions_.size()
            << "\n";
}
