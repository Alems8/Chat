cmake_minimum_required(VERSION 3.16)

add_subdirectory(./lib/GoogleTest)
set(gtest_SOURCE_DIR, ./lib/GoogleTest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES runAllTests.cpp MessaggioFixture.cpp MessaggioTest.cpp Utente&ChatFixture.cpp NotificaMessaggio.cpp)
add_executable(runAllTests ${SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)