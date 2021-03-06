// Copyright 2011 Yandex

#ifndef LTR_MEASURES_ABS_ERROR_H_
#define LTR_MEASURES_ABS_ERROR_H_

#include <cmath>
#include <string>

#include "ltr/utility/numerical.h"
#include "ltr/measures/measure.h"
#include "ltr/data/object.h"

using std::fabs;
using std::string;
using ltr::Object;
using ltr::utility::Inf;

namespace ltr {
/**
 * Absolute error pointwise measure
 */
class AbsError : public PointwiseMeasure {
 public:
  explicit AbsError() {}

  explicit AbsError(const ParametersContainer& parameters) {
    // DO NOTHING
  }

  double worst() const {
    return Inf;
  }
  double best() const {
    return 0.0;
  }

  string toString() const {
    return "Absolute error measure";
  }

 private:
  double get_measure(const Object& element) const {
    return fabs(element.actual_label() -
                element.predicted_label());
  }
  virtual string getDefaultAlias() const {return "AbsError";}
};
};
#endif  // LTR_MEASURES_ABS_ERROR_H_
