set(LIB ${CMAKE_PROJECT_NAME}_lib)
set(MAIN ${CMAKE_PROJECT_NAME}_main)
set(TESTS ${CMAKE_PROJECT_NAME}_tests)

add_library(${LIB} EXCLUDE_FROM_ALL STATIC "")
# add_executable(${MAIN} main.cpp)
target_compile_options(${LIB} PUBLIC -fstrict-enums)

add_executable(${TESTS} EXCLUDE_FROM_ALL main_test.cpp)
find_package(GTest REQUIRED)
target_link_libraries(${TESTS} PRIVATE ${LIB} GTest::GTest)

add_custom_target(test COMMAND ${TESTS}
  COMMENT "Execute tests")

add_subdirectory(chords)
