#ifndef TONE_H
#define TONE_H

#include <array>
#include <cstdint>
#include <variant>

class White {
private:
    char name;
    uint8_t halftone;
public:
    enum Type {c, d, e, f, g, a, b};
    White(Type name);
    friend bool operator== (const White& lhs, const White& rhs) {
	return lhs.name == rhs.name && lhs.halftone == rhs.halftone;
    }
};

// possibly a map: -2: HalftoneDifference -> 'bb' ???
enum class Accidental {double_flat=-2, flat=-1, none=0, sharp=1, double_sharp=2};

class Tone {
private:
    White white;
    Accidental accidental;
public:
    Tone(White white, Accidental accidental): white { white }, accidental { accidental } {};
    Tone(White white): white { white }, accidental { Accidental::none } {};
    auto terz(int halftone) -> Tone;
    friend bool operator== (const Tone& lhs, const Tone& rhs) {
	return lhs.white == rhs.white && lhs.accidental == rhs.accidental; };
};

#endif
