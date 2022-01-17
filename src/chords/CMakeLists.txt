target_sources(${TESTS} PRIVATE tone_test.cpp)
target_sources(${LIB} PRIVATE
  halfsteps.hpp
  white.cpp white.hpp
  tone.cpp tone.hpp)
