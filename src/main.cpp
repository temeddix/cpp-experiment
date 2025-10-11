#include <iostream>
#include <vector>

#include "Quiz.hpp"
#include "subdir/Question.hpp"

auto main() -> int {
  Quiz quiz{"C++ OOP CLI Quiz"};

  quiz.addQuestion(Question{
      "What is the output type of std::string::size() in C++11 and later?",
      {"int", "std::size_t", "long", "unsigned int"},
      1});
  quiz.addQuestion(Question{"Which keyword introduces a lambda in C++?",
                            {"func", "lambda", "[]", "->"},
                            2});
  quiz.addQuestion(Question{"Which standard introduced std::optional?",
                            {"C++11", "C++14", "C++17", "C++20"},
                            2});

  quiz.logQuestions();

  auto run_result = quiz.run();
  if (!run_result) {
    std::cout << "Failed to run quiz: " << static_cast<int>(run_result.error())
              << "\n";
    return 1;
  }

  std::cin.ignore();  // consume leftover newline
  std::cin.get();     // wait for user input

  return 0;
}
