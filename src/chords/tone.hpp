#ifndef TONE_H
#define TONE_H

#include "halfsteps.hpp"
#include "white.hpp"
#include <cstdint>
#include <optional>

class Tone {
private:
    White m_white;
    Accidental m_accidental;
    auto halfsteps() -> Halfsteps { return m_white.halfsteps() + m_accidental.halfsteps(); }; 
    auto halfsteps_up(White white) -> Halfsteps { return white.halfsteps() - halfsteps(); };
public:
    Tone(White white, Accidental accidental): m_white { white }, m_accidental { accidental } {};
    static auto of(White white) -> Tone { return Tone{ white, Accidental::none() }; };
    friend auto operator==(const Tone& lhs, const Tone& rhs) -> bool;
    auto terz(Halfsteps halfsteps) -> std::optional<Tone>;
};

#endif
