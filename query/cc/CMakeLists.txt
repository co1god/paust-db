add_library(query_cc OBJECT query.cc query.h data_group_container.cc data_group_container.h)
target_compile_features(query_cc PUBLIC cxx_std_17)
target_include_directories(query_cc PUBLIC ${OpenFST_INCLUDE_DIRS})
target_link_libraries(query_cc PUBLIC ${OpenFST_LIBRARIES})

if (WITH_TESTS)
    add_executable(query_test query_test.cc)
    target_link_libraries(query_test PRIVATE query_cc GTest::gmock_main)
endif ()