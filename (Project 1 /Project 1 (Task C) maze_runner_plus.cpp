//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 29, 2022
//Project 1 Task C

#include <iostream>
#include <string>
using namespace std;
int main()
{
        int maze[6][6] = 
        {
            1,0,1,1,1,1,
            1,0,0,0,1,1,
            1,0,1,0,0,1,
            1,0,1,0,1,1,
            1,0,0,0,0,0,
            1,1,1,1,1,1
        };

        string x;
        int row = 0;
        int col = 1;
        int end_row = 4;
        int end_col = 5;

        while(cin >> x){
		string arr[x.size()];
            for (int i = 0; i < x.size(); i++) 
            {
                    arr[i] = x[i];
            }
            for (string i: arr) 
            {
                if(i == ";") 
                {
                    if (row == end_row && col == end_col) 
                    {
					    cout << "You got out of the maze." << endl;
                    }
			        else 
			        {
					    cout << "You are stuck in the maze." << endl;
				    }
				row = 0;
				col = 1;
			}	       
			if(i == "R" && maze[row][col + 1] != 1) 
			{
                col++;
            }
            else if(i == "L" && maze[row][col - 1] != 1) 
            {
                col--;
            }
            else if(i == "U" && maze[row - 1][col] != 1)
            {
                row--;
            }
            else if(i == "D" && maze[row + 1][col] != 1) 
            {
                row++;
            }
			else 
			{
				row = row;
				col = col;
			}
        }
    }
}
