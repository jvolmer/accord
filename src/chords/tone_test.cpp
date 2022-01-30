#include "tone.hpp"
#include "white.hpp"
#include <gtest/gtest.h>

// class Interval : public::testing::TestWithParam<std::tuple<int, Tone>> {};

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

TEST(Terz_of_different_halfsteps, Terz_from_C_by_1_halftone_does_not_exist) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{1})),
	std::nullopt); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_2_halftones_is_E_double_flat) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{2})),
	(Tone{White::e(), Accidental::double_flat()})); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_3_halftones_is_E_flat) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{3})),
	(Tone{White::e(), Accidental::flat()})); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_4_halftones_is_E) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{4})),
	(Tone::of(White::e()))); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_5_halftones_is_E_sharp) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{5})),
	(Tone{White::e(), Accidental::sharp()})); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_6_halftones_is_E_double_sharp) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{6})),
	(Tone{White::e(), Accidental::double_sharp()})); 
};
	
TEST(Terz_of_different_halfsteps, Terz_from_C_by_7_halftone_does_not_exist) {
    EXPECT_EQ(
	(Tone::of(White::c()).terz(Halfsteps{7})),
	std::nullopt); 
};
	

TEST(Terz_from_different_Tones, Terz_from_F_by_4_halftones_is_A) {
    EXPECT_EQ(
	(Tone::of(White::f()).terz(Halfsteps{4})),
	(Tone::of(White::a())));
};

TEST(Terz_from_different_Tones, Terz_from_F_sharp_by_4_halftones_is_A_sharp) {
    EXPECT_EQ(
	(Tone{White::f(), Accidental::sharp()}.terz(Halfsteps{4})),
	(Tone{White::a(), Accidental::sharp()}));
};

TEST(Terz_from_different_Tones, Terz_from_C_sharp_by_4_halftones_is_E_sharp) {
    EXPECT_EQ(
	(Tone{White::c(), Accidental::sharp()}.terz(Halfsteps{4})),
	(Tone{White::e(), Accidental::sharp()}));
};

TEST(Terz_from_different_Tones, Terz_from_E_flat_by_5_halftones_is_G_sharp) {
    EXPECT_EQ(
	(Tone{White::e(), Accidental::flat()}.terz(Halfsteps{5})),
	(Tone{White::g(), Accidental::sharp()}));
};

