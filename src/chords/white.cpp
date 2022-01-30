#include "halfsteps.hpp"
#include "white.hpp"

auto operator==(const Whitecount &lhs, const Whitecount &rhs) -> bool {
    return lhs.m_count == rhs.m_count;
}

auto operator+(const Whitecount &lhs, int add) -> Whitecount {
    return Whitecount{ lhs.m_count + add };
}

White::White(Whitecount whitecount, char name, Halfsteps halfsteps) :
    m_whitecount { whitecount },
    m_name { name },
    m_halfsteps { halfsteps } {}

auto White::of(Whitecount count) -> White {
    switch (count.get()) {
    case Whitecount::c : return White::c();
    case Whitecount::d : return White::d();
    case Whitecount::e : return White::e();
    case Whitecount::f : return White::f();
    case Whitecount::g : return White::g();
    case Whitecount::a : return White::a();
    case Whitecount::b : return White::b();
    } 
}

auto operator==(const White &lhs, const White &rhs) -> bool {
    return lhs.m_whitecount == rhs.m_whitecount;
}

auto operator+(const White& lhs, int add) -> White {
    return White::of( Whitecount{lhs.m_whitecount + add} );
}
