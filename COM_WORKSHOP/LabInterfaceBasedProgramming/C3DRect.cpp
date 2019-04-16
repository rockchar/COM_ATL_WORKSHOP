#include "stdafx.h"
#include "C3DRect.h"
#include <iostream>




C3DRect::C3DRect()
{
}


C3DRect::~C3DRect()
{
}

void C3DRect::Fill(FILLTYPE fType)
{
	char * FillString[] = { "HATCH", "SOLID", "POLKADOT" };
	std::cout << "Filling the 3d rect as " << FillString[fType] << std::endl;
}

void C3DRect::Draw()
{
	std::cout << "Drawing the rectangle" << std::endl;
}

void C3DRect::Inverse()
{
	std::cout << "Rectangle Is now Inverse" << std::endl;
}

void C3DRect::Stretch(int nFactor)
{
	std::cout << "Rectangle is now stretching" << std::endl;
}