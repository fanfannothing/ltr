// Copyright 2011 Yandex

#include <algorithm>
#include <stdexcept>
#include <cmath>

#include "ltr/measures/gmrr.h"
#include "ltr/data/object_list.h"
#include "ltr/measures/utils/measure_utility.h"

using std::sort;
using std::logic_error;
using std::pow;
using ltr::utility::PredictedAndActualLabels;
using ltr::utility::ExtractLabels;
using ltr::utility::PredictedDecreasingActualIncreasing;
using ltr::ObjectList;


namespace ltr {
  double GMRR::GMRRFormula(double label) const {
    return (pow(2.0, label) - 1)
      / pow(2.0, this->getDoubleParameter("MAX_LABEL"));
  }

  double GMRR::get_measure(const ObjectList& objects) const {
    vector<PredictedAndActualLabels> labels = ExtractLabels(objects);
    sort(labels.begin(), labels.end(), PredictedDecreasingActualIncreasing);

    size_t n = this->getIntParameter("NUMBER_OF_OBJECTS_TO_CONSIDER");
    if ((n == 0) || (n > labels.size())) {
      n = labels.size();
    }

    double p_look = 1.0, p_relevance = 0.0, result = 0.0;
    int pos = 1;
    for (int labels_index = 0; labels_index < n; ++labels_index, ++pos) {
      if (labels[labels_index].actual < 0) {
        // todo: log here!
        // throw logic_error(alias() + " some actual object label < 0");
        labels[labels_index].actual = 0;
      }
      if (labels[labels_index].actual
          > this->getDoubleParameter("MAX_LABEL")) {
        // todo: log here!
        // throw logic_error(alias() + " some actual object label > MAX_LABEL");
        labels[labels_index].actual = this->getDoubleParameter("MAX_LABEL");
      }
      p_relevance = GMRRFormula(labels[labels_index].actual);
      result += (1.0 / pos) * p_look * p_relevance;
      p_look *= (1 - p_relevance);
    }
    return result;
  }
};
