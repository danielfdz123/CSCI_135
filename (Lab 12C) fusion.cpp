//Daniel Andres Fernandez
//daniel.fernandez16@Myhunter.cuny.edu
//December 12, 2022
//Lab 12C

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
    for(int i = 0; i < vegeta.size(); i++)
    {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

int main() 
{
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};
    gogeta(v1, v2);
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
}
    