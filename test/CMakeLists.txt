include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/44c03643cfbc649488a0f437cd18e05f11960d19.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
    MapperTests
    MapperTests.cpp
)

target_link_libraries(
    MapperTests
    libtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MapperTests)
