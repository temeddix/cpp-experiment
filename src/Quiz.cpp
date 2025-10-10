#include "Quiz.hpp"

#include <iostream>

#include "subdir/LogStat.hpp"

Quiz::Quiz(std::string title) : title(std::move(title)) {}

void Quiz::addQuestion(const Question& q) { questions.push_back(q); }

void Quiz::run() const {
  std::cout << "=== " << title << " ===\n\n";
  int score = {0};
  for (size_t i = {0}; i < questions.size(); ++i) {
    std::cout << "Question " << (i + 1) << "/" << questions.size() << ":\n";
    if (questions[i].ask()) ++score;
  }
  std::cout << "Quiz finished. Score: " << score << "/" << questions.size()
            << "\n";
}

void Quiz::logQuestions() const {
  std::cout << "Logging questions:\n";
  for (const auto& q : questions) {
    this->logQuestion(q);
  }
}

template <LogStat T>
void Quiz::logQuestion(const T q) const {
  q.logStat();
}