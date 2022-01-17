#include "tone.hpp"

auto Tone::terz(Halfsteps halfsteps) -> Tone {
    return Tone{
	m_white + Whitesteps{2},
	Accidental::none
    };
}

auto operator==(const Tone& lhs, const Tone& rhs) -> bool {
    return lhs.m_white == rhs.m_white && lhs.m_accidental == rhs.m_accidental;
};
