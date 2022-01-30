#ifndef HALFSTEPS_H
#define HALFSTEPS_H 

#include <cstdint>
#include <optional>
#include <string>

struct Halfsteps {
    int count;
    friend auto operator==(const Halfsteps& lhs, const Halfsteps& rhs) -> bool;
    friend auto operator+(const Halfsteps& lhs, const Halfsteps& rhs) -> Halfsteps;
    friend auto operator-(const Halfsteps& lhs, const Halfsteps& rhs) -> Halfsteps;
};

class Accidental {
private:
    std::string m_name;
    Halfsteps m_steps;
    Accidental(std::string name, Halfsteps steps);
    enum Steps: int {of_double_flat=-2, of_flat=-1, of_none=0, of_sharp=1, of_double_sharp=2};
public:
    static auto of(Halfsteps halfsteps) -> std::optional<Accidental>;
    static auto double_flat() -> Accidental { return Accidental{ "--", Halfsteps{Steps::of_double_flat} }; }
    static auto flat() -> Accidental { return Accidental{ "-", Halfsteps{Steps::of_flat} }; };
    static auto none() -> Accidental { return Accidental{ "", Halfsteps{Steps::of_none} }; };
    static auto sharp() -> Accidental { return Accidental{ "+", Halfsteps{Steps::of_sharp} }; };
    static auto double_sharp() -> Accidental { return Accidental{ "++", Halfsteps{Steps::of_double_sharp} }; };
    auto halfsteps() -> Halfsteps { return m_steps; };
    friend auto operator==(const Accidental& lhs, const Accidental& rhs) -> bool;
};

#endif
