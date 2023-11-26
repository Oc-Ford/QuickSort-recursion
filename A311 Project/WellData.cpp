#include "WellData.h"

WellData::WellData()
{
	flow = 0;
	pressure = 0;
	temperature = 0;
}

WellData::WellData(int f, int p, int temp)
{
	this->flow = f;
	this->pressure = p;
	this->temperature = temp;
}
