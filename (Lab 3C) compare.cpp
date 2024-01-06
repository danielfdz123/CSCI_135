//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 26, 2022
//Lab 3C

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail())
    {
        cerr<<"File cannot be opened for reading.";
        exit(1);
    }

    string start_date, end_date;    
    cout << "Enter starting date: ";
    cin >> start_date;
    cout <<  "Enter ending date: ";
    cin >> end_date;

    string junk;
    getline (fin, junk);

    string date; 
    float eastSt, eastEl, westSt, westEl;
    bool gi = false;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');
        if(date == start_date)
        {
            gi = true;
        }
        if(gi == true)
        {
            if (eastEl > westEl)
            {
                cout << date <<" East"<<endl;
            }
            if (westEl > eastEl) 
            {
                cout << date << " West"<<endl;
            }
            if (eastEl == westEl)
            {
                cout << date << " Equal"<<endl;
            }
        }
        if(end_date == date)
        {
        fin.close();
        }
    }
}