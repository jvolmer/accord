#include "tone.hpp"


White::White(Type type) : White{ Whitesteps{type} } {};

White::White(Whitesteps steps): whitesteps{ steps } {
    switch (steps.count) {
    case Type::c :
	name = 'c'; halfsteps = Halfsteps{0};
	break;
    case Type::d :
	name = 'd'; halfsteps = Halfsteps{2};
	break;
    case Type::e :
	name = 'e'; halfsteps = Halfsteps{4};
	break;
    case Type::f :
	name = 'f'; halfsteps = Halfsteps{5};
	break;
    case Type::g :
	name = 'g'; halfsteps = Halfsteps{7};
	break;
    case Type::a :
	name = 'a'; halfsteps = Halfsteps{9};
	break;
    case Type::b :
	name = 'b'; halfsteps = Halfsteps{11};
	break;
    } 
}

auto Tone::terz(Halfsteps halfsteps) -> Tone {
    return Tone{
	white + 2,
	Accidental::none
    };
}
