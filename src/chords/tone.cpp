#include "tone.hpp"
#include <optional>

auto Tone::terz(Halfsteps terz_halfsteps) -> std::optional<Tone> {
    auto new_white = m_white + 2;
    auto missing_halfsteps = (terz_halfsteps - this->halfsteps_up(new_white)).in_octave();
    auto needed_accidental = Accidental::of(missing_halfsteps);

    if (!needed_accidental) {
	return {};
    }
    
    return Tone{
	new_white,
	*needed_accidental
    };
}

auto operator==(const Tone& lhs, const Tone& rhs) -> bool {
    return lhs.m_white == rhs.m_white && lhs.m_accidental == rhs.m_accidental;
}
