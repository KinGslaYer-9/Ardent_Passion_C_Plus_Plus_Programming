#include <cstring>
#include "CarInline.h"

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, sizeof(gamerID), ID);
	fuelGauage = fuel;
	curSpeed = 0;
}

void Car::Accel()
{
	if (fuelGauage <= 0)
		return;
	else
		fuelGauage -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}