#pragma once

#include <concepts>

template <typename T>
concept LogStat = requires(const T obj) {
  { obj.logStat() } -> std::same_as<void>;
};