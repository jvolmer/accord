#include "halfsteps.hpp"
#include "white.hpp"

auto operator==(const Whitesteps &lhs, const Whitesteps &rhs) -> bool {
    return lhs.m_count == rhs.m_count;
}

auto operator+(const Whitesteps &lhs, const Whitesteps &rhs) -> Whitesteps {
    return Whitesteps{ (uint8_t)(lhs.m_count + rhs.m_count) };
}

White::White(Whitesteps steps): m_whitesteps{ steps } {
    switch (steps.count()) {
    case Type::c :
	m_name = 'c'; m_halfsteps = Halfsteps{0};
	break;
    case Type::d :
	m_name = 'd'; m_halfsteps = Halfsteps{2};
	break;
    case Type::e :
	m_name = 'e'; m_halfsteps = Halfsteps{4};
	break;
    case Type::f :
	m_name = 'f'; m_halfsteps = Halfsteps{5};
	break;
    case Type::g :
	m_name = 'g'; m_halfsteps = Halfsteps{7};
	break;
    case Type::a :
	m_name = 'a'; m_halfsteps = Halfsteps{9};
	break;
    case Type::b :
	m_name = 'b'; m_halfsteps = Halfsteps{11};
	break;
    } 
}

auto operator==(const White &lhs, const White &rhs) -> bool {
    return lhs.m_whitesteps == rhs.m_whitesteps;
}
auto operator+(const White& lhs, const Whitesteps& whitesteps) -> White {
    return White{ lhs.m_whitesteps + whitesteps };
}
