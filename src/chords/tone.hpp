#ifndef TONE_H
#define TONE_H

#include <array>
#include <cstdint>
#include <variant>

struct Halfsteps {
    uint8_t count;

    friend auto operator==(const Halfsteps &lhs, const Halfsteps &rhs) -> bool {
	return lhs.count == rhs.count;
    }
};
 
class Whitesteps {
public:
    uint8_t count;
    static constexpr uint8_t count_max = 7;
    Whitesteps(uint8_t steps) { count = steps % count_max; };
    friend auto operator==(const Whitesteps &lhs, const Whitesteps &rhs) -> bool {
	return lhs.count == rhs.count;
    }
    friend auto operator+(const Whitesteps &lhs, const Whitesteps &rhs) -> Whitesteps {
	return Whitesteps{ (uint8_t)(lhs.count + rhs.count) };
    }
};
 
class White {
private:
    Whitesteps whitesteps;
    char name;
    Halfsteps halfsteps;
public:
    enum Type: uint8_t { c = 0, d = 1, e=2, f=3, g=4, a=5, b=6 };
    White(Type type);
    White(Whitesteps whitesteps);
    friend auto operator==(const White &lhs, const White &rhs) -> bool {
	return lhs.whitesteps == rhs.whitesteps;
    }
    friend auto operator+(const White& lhs, const Whitesteps& whitesteps) -> White {
	return White{ lhs.whitesteps + whitesteps };
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
    auto terz(Halfsteps halfsteps) -> Tone;
    friend auto operator==(const Tone& lhs, const Tone& rhs) -> bool {
	return lhs.white == rhs.white && lhs.accidental == rhs.accidental; };
};

#endif
