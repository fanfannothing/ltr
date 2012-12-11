// Copyright 2012 Yandex

#ifndef LTR_UTILITY_RANDOM_NUMBER_GENERATOR_H_
#define LTR_UTILITY_RANDOM_NUMBER_GENERATOR_H_

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>

#include <algorithm>

using std::swap;

using boost::random::mt19937;
using boost::random::uniform_int_distribution;
using boost::random::uniform_real_distribution;

namespace ltr {
namespace utility {
class Randomizer {
 public:
  Randomizer() {
    generator_.seed(0);
  }

  double doubleRand(double min_value, double max_value) {
    uniform_real_distribution<> distribution(min_value, max_value);
    return distribution(generator_);
  }

  int rand(int max_value = 2147483647) {
    uniform_int_distribution<> distribution(0, max_value - 1);
    return distribution(generator_);
  };

  void setSeed(int seed) {
    generator_.seed(seed);
  };

  int operator()(int max_value = 2147483647) {
    return rand(max_value);
  }

 private:
  mt19937 generator_;
} static randomizer;
};
};
#endif  // LTR_UTILITY_RANDOM_NUMBER_GENERATOR_H_
