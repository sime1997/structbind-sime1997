add_executable(utest utest.cpp ../src/kredit.cpp ../src/kredit.h)

set_target_properties(utest
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )


target_link_libraries(utest gtest_main)
add_test(NAME utest COMMAND utest)
