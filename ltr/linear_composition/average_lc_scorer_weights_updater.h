// Copyright 2011 Yandex

#ifndef LTR_LINEAR_COMPOSITION_AVERAGE_LC_SCORER_WEIGHTS_UPDATER_H_
#define LTR_LINEAR_COMPOSITION_AVERAGE_LC_SCORER_WEIGHTS_UPDATER_H_

#include <boost/shared_ptr.hpp>

#include "ltr/measures/measure.h"
#include "ltr/data/data_set.h"
#include "ltr/scorers/linear_composition_scorer.h"
#include "ltr/scorers/utility/scorer_utility.h"
#include "ltr/utility/numerical.h"
#include "ltr/scorers/scorer.h"

using std::exp;
using std::log;

using ltr::Measure;
using ltr::DataSet;
using ltr::LinearCompositionScorer;
using ltr::utility::MarkDataSet;
using ltr::utility::DoubleEps;
using ltr::Scorer;

namespace ltr {
namespace lc {
  template <class TElement>
  class AverageLCScorerWeightsUpdater {
  public:
    typedef boost::shared_ptr<AverageLCScorerWeightsUpdater> Ptr;

    explicit AverageLCScorerWeightsUpdater() {}

    void updateWeights(const DataSet<TElement>& data,
        LinearCompositionScorer* lin_scorer) const;

    void setMeasure(typename Measure<TElement>::Ptr in_measure) {
      measure_ = in_measure;
    }
  protected:
    typename Measure<TElement>::Ptr measure_;
  };

  // template realizations
  template <class TElement>
  void AverageLCScorerWeightsUpdater<TElement>::updateWeights(
      const DataSet<TElement>& data,
      LinearCompositionScorer* lin_scorer) const {
    double weight = 1.0 / lin_scorer->size();
    for (int i = 0; i < lin_scorer->size(); ++i) {
      lin_scorer->at(i).weight = weight;
    }
  }
};
};

#endif  // LTR_LINEAR_COMPOSITION_AVERAGE_LC_SCORER_WEIGHTS_UPDATER_H_
