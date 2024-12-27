#include "pch.h"
#include "Planet.h"

void Planet::Reset()
{
	speed = 5;
	life = 5;
	angle = 0;
	spin = 1;
	position.x = 0;
	position.y = 0;
}