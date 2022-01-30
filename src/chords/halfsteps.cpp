#include "halfsteps.hpp"
#include <optional>

auto operator==(const Halfsteps& lhs, const Halfsteps& rhs) -> bool {
    return lhs.count == rhs.count;
}

auto operator+(const Halfsteps& lhs, const Halfsteps& rhs) -> Halfsteps {
    return Halfsteps{lhs.count + rhs.count};
}

auto operator-(const Halfsteps& lhs, const Halfsteps& rhs) -> Halfsteps {
    return Halfsteps{lhs.count - rhs.count};
}

Accidental::Accidental(std::string name, Halfsteps steps) :
    m_name { std::move(name) },
    m_steps { steps } {}

auto Accidental::of(Halfsteps halfsteps) -> std::optional<Accidental> {
    switch (halfsteps.count) {
    case Steps::of_double_flat : return Accidental::double_flat(); 
    case Steps::of_flat : return Accidental::flat(); 
    case Steps::of_none : return Accidental::none();
    case Steps::of_sharp : return Accidental::sharp(); 
    case Steps::of_double_sharp : return Accidental::double_sharp();
    default: return {};
    }
}

auto operator==(const Accidental& lhs, const Accidental& rhs) -> bool {
    return lhs.m_steps == rhs.m_steps;
}
