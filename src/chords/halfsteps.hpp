#ifndef HALFSTEPS_H
#define HALFSTEPS_H 

#include <cstdint>
#include <optional>
#include <string>

struct Halfsteps {
    int count;
    friend auto operator==(const Halfsteps &lhs, const Halfsteps &rhs) -> bool {
	return lhs.count == rhs.count;
    }
};

class Accidental {
private:
    std::string m_name;
    Halfsteps m_steps;
    Accidental(std::string name, Halfsteps steps);
    enum Steps: int {of_double_flat=-2, of_flat=-1, of_none=0, of_sharp=1, of_double_sharp=2};
public:
    static auto of(Halfsteps halfsteps) -> std::optional<Accidental>;
    static auto none() -> Accidental { return Accidental{ "", Halfsteps{Steps::of_none} }; };
    friend auto operator==(const Accidental& lhs, const Accidental& rhs) -> bool;
};

#endif
