#ifndef WHITE_H
#define WHITE_H

#include "halfsteps.hpp"
#include <cstdint>

class Whitesteps {
private:
    uint8_t m_count;
    static constexpr uint8_t count_max = 7;
public:
    Whitesteps(uint8_t steps) { m_count = steps % count_max; };
    auto count() -> uint8_t { return m_count; };
    friend auto operator==(const Whitesteps &lhs, const Whitesteps &rhs) -> bool;
    friend auto operator+(const Whitesteps &lhs, const Whitesteps &rhs) -> Whitesteps;
};

class White {
private:
    Whitesteps m_whitesteps;
    char m_name;
    Halfsteps m_halfsteps;
public:
    enum Type: uint8_t { c=0, d=1, e=2, f=3, g=4, a=5, b=6 };
    White(Type type) : White{ Whitesteps{type} } {};
    White(Whitesteps whitesteps);
    friend auto operator==(const White &lhs, const White &rhs) -> bool;
    friend auto operator+(const White& lhs, const Whitesteps& whitesteps) -> White;
};

#endif
