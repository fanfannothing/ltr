# lets list tests' binaries
# it reflect the LTR_lib structure

SET(TOSTRING_TEST ${Source_Path}/ltr/data/tostring_unittest.cc)

SET(INDICES_TEST ${Source_Path}/ltr/data/indices_unittest.cc)

SET(NUMERICAL_TEST ${Source_Path}/ltr/data/numerical_unittest.cc)

SET(SAVE_PREDICTION_TEST ${Source_Path}/ltr/data/save_predictions_unittest.cc)

SET(LIST_TO_ALL_PAIRS_CONVERTER_TEST ${Source_Path}/ltr/data/list_to_all_pairs_converter_unittest.cc)

SET(LTR_OBJECT_TEST ${Source_Path}/ltr/data/object_unittest.cc)

SET(LTR_FEATURE_INFO_TEST ${Source_Path}/ltr/data/feature_info_unittest.cc)

SET(LTR_OBJECT_LIST_TEST ${Source_Path}/ltr/data/object_list_unittest.cc)

SET(LTR_DATA_TEST ${Source_Path}/ltr/data/data_set_unittest.cc
				  ${Source_Path}/ltr/data/serialization_unittest.cc)

SET(LTR_IO_UILITY_TEST ${Source_Path}/ltr/data/utility/io_utility_unittest.cc)

SET(LTR_DECISION_TREE_TEST ${Source_Path}/ltr/learners/decision_tree/decision_tree_unittest.cc)

SET(LTR_FEATURE_CONVERTERS_TEST ${Source_Path}/ltr/feature_converters/feature_converters_unittest.cc
                                ${Source_Path}/ltr/feature_converters/feature_converters_learner_unittest.cc)

SET(LTR_DATA_PREPROCESSORS_TEST ${Source_Path}/ltr/data_preprocessors/data_preprocessors_unittest.cc)

SET(LTR_LEARNERS_TEST ${Source_Path}/ltr/learners/learners_unittest.cc
					  ${Source_Path}/ltr/learners/linear_learner/linear_learner_unittest.cc)

SET(LTR_MEASURES_TEST ${Source_Path}/ltr/measures/measure_unittest.cc
                      ${Source_Path}/ltr/measures/listwise_measures_unittest.cc
                      ${Source_Path}/ltr/measures/pointwise_measures_unittest.cc
                      ${Source_Path}/ltr/measures/pairwise_measures_unittest.cc)

SET(LTR_SCORERS_TEST ${Source_Path}/ltr/scorers/fake_scorer_unittest.cc
                     ${Source_Path}/ltr/scorers/one_feature_scorer_unittest.cc
					 ${Source_Path}/ltr/scorers/linear_scorer_unittest.cc
					 ${Source_Path}/ltr/scorers/linear_composition_scorer_unittest.cc
                     ${Source_Path}/ltr/scorers/gp_scorer_unittest.cc)

SET(LTR_INTERFACES_TEST ${Source_Path}/ltr/interfaces/reporter_unittest.cc
                        ${Source_Path}/ltr/interfaces/aliaser_unittest.cc
                        ${Source_Path}/ltr/interfaces/parameterized_unittest.cc)

SET(LTR_PARAMETERS_CONTAINER_TEST ${Source_Path}/ltr/parameters_container/parameters_container_unittest.cc)

SET(LTR_CROSSVALIDATION ${Source_Path}/ltr/crossvalidation/splitter_unittest.h
                        ${Source_Path}/ltr/crossvalidation/k_fold_simple_splitter_unittest.cc
                        ${Source_Path}/ltr/crossvalidation/leave_one_out_splitter_unittest.cc
                        ${Source_Path}/ltr/crossvalidation/tk_fold_simple_splitter_unittest.cc
                        ${Source_Path}/ltr/crossvalidation/validation_result_unittest.cc
                        ${Source_Path}/ltr/crossvalidation/crossvalidation_unittest.cc)
                        
SET(LTR_LINEAR_COMPOSITION ${Source_Path}/ltr/learners/linear_composition/linear_composition_unittest.cc)



SOURCE_GROUP(interfaces FILES ${LTR_INTERFACES_TEST})
SOURCE_GROUP(parameters_container FILES ${LTR_PARAMETERS_CONTAINER_TEST})
SOURCE_GROUP(scorers FILES ${LTR_SCORERS_TEST})
SOURCE_GROUP(measures FILES ${LTR_MEASURES_TEST})
SOURCE_GROUP(crossvalidation FILES ${LTR_CROSSVALIDATION})
SOURCE_GROUP(data_preprocessors FILES ${LTR_DATA_PREPROCESSORS_TEST})
SOURCE_GROUP(linear_composition FILES ${LTR_LINEAR_COMPOSITION})
SOURCE_GROUP(feature_converters FILES ${LTR_FEATURE_CONVERTERS_TEST})
SOURCE_GROUP(learners FILES ${LTR_LEARNERS_TEST})

# lets list all LTR_TEST's source binaries
SET(LTR_TEST ${TOSTRING_TEST} ${INDICES_TEST} ${NUMERICAL_TEST} ${SAVE_PREDICTION_TEST} ${LIST_TO_ALL_PAIRS_CONVERTER_TEST} ${LTR_OBJECT_TEST} ${LTR_OBJECT_LIST_TEST} 
			 ${LTR_FEATURE_INFO_TEST} ${LTR_DATA_TEST} ${LTR_LEARNERS_TEST} ${LTR_SCORERS_TEST} ${LTR_FEATURE_CONVERTERS_TEST} 
			 ${LTR_IO_UILITY_TEST} ${LTR_INTERFACES_TEST} ${LTR_PARAMETERS_CONTAINER_TEST} ${LTR_CROSSVALIDATION} ${LTR_DECISION_TREE_TEST}
             ${LTR_DATA_PREPROCESSORS_TEST} ${LTR_MEASURES_TEST} ${LTR_LINEAR_COMPOSITION})
SET(LTR_TEST_H)
SET(LTR_TEST_ALL ${LTR_TEST} ${LTR_TEST_H} ${gtest_SOURCE_DIR}/src/gtest_main.cc)
