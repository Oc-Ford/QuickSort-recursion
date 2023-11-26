/*
/   Uses a quickSort recursion algorithem modified to work on multidimensional data
/   Reads in a file of data, imports the data into a multidimential array
/  
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "GasWell.h"
using namespace std;

int main() {

    map<string, GasWell> wellMap;

    ifstream inputFile("10000_random_wells.txt"); // Open file

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string wellName;
            int time, flow, pressure, temp;


            if (iss >> wellName >> time >> flow >> pressure >> temp) // Declares the order of the data in each line in the file. 
            {
                if (wellMap.find(wellName) == wellMap.end())  // Populates the map with the wellName and processeding data.
                {
                    GasWell newWell(wellName);
                    wellMap[wellName] = newWell;
                }
                wellMap[wellName].addWellData(WellData(flow, pressure, temp));
            }
        }
        inputFile.close(); // Close file
    }
    else 
    {
        cout << "Unable to open file!" << std::endl;
        return 1;
    }


    // Displays the imported data
    for (const auto& well : wellMap) 
    {
        cout << "Well: " << well.second.wellName << " Data";
        for (const auto& data : well.second.getWellData())
        {
            cout << "Flow: " << data.flow << ", Pressure: " << data.pressure << ", Temperature: " << data.temperature << endl;
        }
        cout << std::endl;
    }

    // Puts the data of the map into a vector
    vector<GasWell> sortedWells;
    for (auto& well : wellMap) {
        sortedWells.push_back(well.second);
    }

    // Calls the quicksortFlow function to sort the list of wells by flow rate. 
    GasWell().quicksortFlow(sortedWells, 0, sortedWells.size() - 1);

    // Displays the sorted list
    cout << "Sorted Well Data Based on Flow Rate and Temperature:\n";
    GasWell().printSortedWells(sortedWells);

    return 0;
}
