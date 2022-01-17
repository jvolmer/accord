#ifndef TONE_H
#define TONE_H

#include "halfsteps.hpp"
#include "white.hpp"
#include <cstdint>

class Tone {
private:
    White m_white;
    Accidental m_accidental;
public:
    Tone(White white, Accidental accidental): m_white { white }, m_accidental { accidental } {};
    Tone(White white): m_white { white }, m_accidental { Accidental::none } {};
    friend auto operator==(const Tone& lhs, const Tone& rhs) -> bool;
    auto terz(Halfsteps halfsteps) -> Tone;
};

#endif
