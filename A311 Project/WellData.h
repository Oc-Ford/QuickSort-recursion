#pragma once

class WellData
{

public:

    WellData();
    WellData(int f, int p, int temp);

    int flow;
    int pressure;
    int temperature;

};

