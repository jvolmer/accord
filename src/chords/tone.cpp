#include "tone.hpp"

White::White(Type type) {
    switch(type) {
    case Type::c :
	name = 'c'; halftone = 0;
	break;
    case Type::d :
	name = 'd'; halftone = 2;
	break;
    case Type::e :
	name = 'e'; halftone = 4;
	break;
    case Type::f :
	name = 'f'; halftone = 5;
	break;
    case Type::g :
	name = 'g'; halftone = 7;
	break;
    case Type::a :
	name = 'a'; halftone = 9;
	break;
    case Type::b :
	name = 'b'; halftone = 11;
	break;
    }
}

auto Tone::terz(int halftone) -> Tone {
    return Tone{White::e};
}
