#include "../include/Question.hpp"
#include "../include/Quiz.hpp"

int main() {
  Quiz quiz("C++17 OOP CLI Quiz");

  quiz.addQuestion(Question(
      "What is the output type of std::string::size() in C++11 and later?",
      {"int", "std::size_t", "long", "unsigned int"}, 1));

  quiz.addQuestion(Question("Which keyword introduces a lambda in C++?",
                            {"func", "lambda", "[]", "->"}, 2));

  quiz.addQuestion(Question("Which standard introduced std::optional?",
                            {"C++11", "C++14", "C++17", "C++20"}, 2));

  quiz.run();
  return 0;
}
