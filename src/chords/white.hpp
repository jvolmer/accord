#ifndef WHITE_H
#define WHITE_H

#include "halfsteps.hpp"
#include <cstdint>

class Whitecount {
public:
    enum Count: unsigned int { c=0, d=1, e=2, f=3, g=4, a=5, b=6 };
    Whitecount(unsigned int steps) { m_count = static_cast<Count>(steps % 7); };
    auto get() -> Count { return m_count; };
    friend auto operator==(const Whitecount &lhs, const Whitecount &rhs) -> bool;
    friend auto operator+(const Whitecount &lhs, int add) -> Whitecount;
private:
    Count m_count;
};

class White {
private:
    Whitecount m_whitecount;
    char m_name;
    Halfsteps m_halfsteps;
    White(Whitecount whitesteps, char name, Halfsteps halfsteps);
public:
    static auto of(Whitecount whitesteps) -> White;
    static auto c() -> White { return White{Whitecount::c, 'c', Halfsteps{0}}; };
    static auto d() -> White { return White{Whitecount::d, 'd', Halfsteps{2}}; }
    static auto e() -> White { return White{Whitecount::e, 'e', Halfsteps{4}}; }
    static auto f() -> White { return White{Whitecount::f, 'f', Halfsteps{5}}; }
    static auto g() -> White { return White{Whitecount::g, 'g', Halfsteps{7}}; }
    static auto a() -> White { return White{Whitecount::a, 'a', Halfsteps{9}}; }
    static auto b() -> White { return White{Whitecount::b, 'b', Halfsteps{11}}; }
    auto halfsteps() -> Halfsteps { return m_halfsteps; };
    friend auto operator==(const White &lhs, const White &rhs) -> bool;
    friend auto operator+(const White& lhs, int add) -> White;
};

#endif
