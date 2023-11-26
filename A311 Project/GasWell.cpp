#include "GasWell.h"

GasWell::GasWell()
{
}

GasWell::GasWell(const string& name)
{
    this->wellName = name;
}

void GasWell::addWellData(const WellData& data)
{
    WellInfo.push_back(data);
}

const vector<WellData>& GasWell::getWellData() const
{
    return WellInfo;
}

// Finds the partition of the data by calling the bool function compareByFlow to determine the 
// where the current element is placed
int GasWell::partition(vector<GasWell>& wells, int low, int high)
{
    const GasWell& pivot = wells[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (compareByFlow(wells[j], pivot)) {
            ++i;
            swap(wells[i], wells[j]);
        }
    }
    swap(wells[i + 1], wells[high]);
    return i + 1;
};

// Uses a recursive call to sort the flow rates of the wells with QuickSort
void GasWell::quicksortFlow(vector<GasWell>& wells, int low, int high)
{
    if (low < high) {
        int pivot = partition(wells, low, high);
        quicksortFlow(wells, low, pivot - 1);
        quicksortFlow(wells, pivot + 1, high);
    }
}
 
// Prints the well list sorted by the flow rates as well as the name of the well and the 
// average temperature of the well. 
void GasWell::printSortedWells(const vector<GasWell>& wells)
{
    for (const auto& well : wells) {
        int sumFlow = 0, sumTemp = 0;
        for (const auto& dailyData : well.WellInfo) {
            sumFlow += dailyData.flow;
            sumTemp += dailyData.temperature;
        }
        double averageFlow = sumFlow / static_cast<double>(well.WellInfo.size());
        double averageTemp = sumTemp / static_cast<double>(well.WellInfo.size());

        cout << "Well: " << well.wellName << ", Average Flow Rate: " << averageFlow << ", Temperature: " << averageTemp << endl;
    }
}

// Uses bool function to calculate the average daily flow rate of a well and 
// compares that to the next well to return a true/false well a flowing less then well b
bool compareByFlow(const GasWell& a, const GasWell& b)
{
    int sumFlowA = 0;
    int sumFlowB = 0;
    for (const auto& dailyData : a.WellInfo) {
        sumFlowA += dailyData.flow;

    }
    for (const auto& dailyData : b.WellInfo) {
        sumFlowB += dailyData.flow;

    }
    double averageFlowA = sumFlowA / static_cast<double>(a.WellInfo.size());
    double averageFlowB = sumFlowB / static_cast<double>(b.WellInfo.size());

    return ( averageFlowA < averageFlowB );

}
