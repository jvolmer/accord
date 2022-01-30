#include "halfsteps.hpp"
#include <optional>

Accidental::Accidental(std::string name, Halfsteps steps) :
    m_name { std::move(name) },
    m_steps { steps } {}

auto Accidental::of(Halfsteps halfsteps) -> std::optional<Accidental> {
    switch (halfsteps.count) {
    case Steps::of_double_flat : return Accidental{ "--", halfsteps }; 
    case Steps::of_flat : return Accidental{ "-", halfsteps };
    case Steps::of_none : return Accidental::none();
    case Steps::of_sharp : return Accidental{ "+", halfsteps };
    case Steps::of_double_sharp : return Accidental{ "++", halfsteps };
    default: return {};
    }
}

auto operator==(const Accidental& lhs, const Accidental& rhs) -> bool {
    return lhs.m_steps == rhs.m_steps;
}
