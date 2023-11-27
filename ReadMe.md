Quicksort-Project
This C++ program processes well data from a file, performs sorting based on flow rates, and outputs the results. The program consists of three main classes: 'GasWell', 'WellData', and the main application.

GasWell Class
The 'GasWell' class represents a gas well and includes methods for adding well data, sorting wells based on flow rates using the QuickSort Algorithm, and printing sorted well data.

Public Methods:

'GasWell()': Default constructor
'GasWell(const string& name)': Constructor with a specified well name
'void addWellData(const WellData& data)': Adds well data to the well
'const vector& getWellData() const': Retrieves well data
'int partition(vector& wells, int low, int high)': Partition the wells for QuickSort
'void quicksortFlowToTemp(vector& wells, int low, int high)': Sort wells based on flow rates
'void printSortedWells(const vector& wells)': Prints sorted well data

Public Members:

'string wellName': Name of the gas well
'vector WellInfo': Vector containing well data

WellData Class
The 'WellData' class represents daily data for a gas well, including flow, pressure, and temperature.

Public Methods:

'WellData()': Default constructor
'WellData(int f, int p, int temp)': Constructor with specified flow, pressure, and temperature

Public Members:

'int flow': Flow rate of the well
'int pressure': Pressure of the well
'int temperature': Temperature of the well

Main Application
The main application reads well data from a file, populates a map of gas wells, and displays the imported data. It then converts the map data to a vector, sorts the vector based on flow rates using the 'quicksortFlowToTemp' method, and prints the sorted well data.

Dependencies:

"<iostream>"
"<fstream>"
"<sstream>"
"<map>"
"GasWell.h"

Execution:

Open the "10000_random_wells.txt" for input. Process the well data and display the imported data. Sort the wells based on flow rates. Display the sorted well data.
