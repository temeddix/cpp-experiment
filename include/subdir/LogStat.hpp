#pragma once

#include <concepts>

template <typename T>
concept LogStat = requires(const T a) {
  { a.logStat() } -> std::same_as<void>;
};