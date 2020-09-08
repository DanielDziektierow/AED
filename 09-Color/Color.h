#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <cstdint>

using namespace std;

//Structs
using Colores= std::array <uint8_t,MAX_COLOR>;

struct Color{
	Colores col;
};

//const
const unsigned MAX_COLOR=3;
const Color ROJO={255,0,0};
const Color AZUL={0,0,255};
const Color AMARILLO={255,255,0};
const Color VERDE={0,255,0};
const Color NARANJA={255,170,0};
const Color VIOLETA={140,0,255};
const Color NEGRO={0,0,0};
const Color BLANCO={255,255,255};




