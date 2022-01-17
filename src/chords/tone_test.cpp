#include "tone.hpp"
#include <gtest/gtest.h>

class Interval : public::testing::TestWithParam<std::tuple<int, Tone>> {};

// TEST_P(Interval, Terz_from_C) {
//     auto [halftone, expected_tone] = Interval::GetParam();
//     EXPECT_EQ(
// 	(Tone{White{White::c}}.terz(halftone)),
// 	(expected_tone)); 
// }

// INSTANTIATE_TEST_CASE_P(
//     Tone,
//     Interval,
//     ::testing::Values(
// 	std::make_tuple(3, Tone{White{White::e}})));

TEST(Tone, Terz_from_C_by_4_halftones_is_E) {
    EXPECT_EQ(
	(Tone{White{White::c}}.terz(Halfsteps{4})),
	(Tone{White{White::e}})); 
};
	
TEST(Tone, Terz_from_F_by_4_halftones_is_A) {
    EXPECT_EQ(
	(Tone{White{White::f}}.terz(Halfsteps{4})),
	(Tone{White{White::a}}));
};

// TEST(Tone, Terz_from_C_by_3_halftones_is_E_flat) {
//     EXPECT_EQ(
// 	(Tone{White{White::c}}.terz(3)),
// 	(Tone{White{White::e}, Accidental::flat})); 
// };
	
