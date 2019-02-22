add_executable(
    unit_tests
    tokenizer.cpp
    )
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(
    unit_tests
    gtest_main
    libsphinx
    dl 
    z
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/gtest/unit_tests
  )
