#ifndef HALFSTEPS_H
#define HALFSTEPS_H 

#include <cstdint>

struct Halfsteps {
    uint8_t count;

    friend auto operator==(const Halfsteps &lhs, const Halfsteps &rhs) -> bool {
	return lhs.count == rhs.count;
    }
};

// possibly a map: -2: HalftoneDifference -> 'bb' ???
enum class Accidental {double_flat=-2, flat=-1, none=0, sharp=1, double_sharp=2};

#endif
