
# third-party library
include(BuildCatch2)
include(BuildBench)

set(libs ${PROJ})

# ----------------------------- test -----------------------------
set(TEST_NAME ${PROJ}-test)

file(GLOB TEST_SRC_LIST test_*.cpp)
add_executable(${TEST_NAME} ${TEST_SRC_LIST})
target_link_libraries(${TEST_NAME} PRIVATE Catch2 ${libs})

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

# ----------------------------- bench -----------------------------
set(BENCH_NAME ${PROJ}-bench)
file(GLOB BENCH_SRC_LIST bench_*.cpp)
add_executable(${BENCH_NAME} ${BENCH_SRC_LIST})
target_link_libraries(${BENCH_NAME} PRIVATE benchmark ${libs})
