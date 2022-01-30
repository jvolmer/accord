target_sources(${TESTS} PRIVATE tone_test.cpp)
target_sources(${LIB} PRIVATE
  halfsteps.cpp
  halfsteps.hpp
  white.cpp white.hpp
  tone.cpp tone.hpp)
