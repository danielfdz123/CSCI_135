//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//September 22, 2022
//Project 1 Task B

#include <iostream>
#include <string>
using namespace std;

int endY(int startY, char letter), endX(int startX, char letter);
void success(int goalX, int pickX, int goalY, int pickY);  
bool valid(int pickX, int pickY, int maze[6][6]); 
int maze[6][6] = {
    1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1
};

int main(){
    int pickX = 1;
    int pickY = 0;
    int goalX = 5;
    int goalY = 4;
    char s;
    
    while (cin >> s) 
    {
        if (valid(endX(pickX, s),endY(pickY, s),maze))
        {
            pickY = endY(pickY, s);
            pickX = endX(pickX, s);
        }
    }
    success(goalX,pickX,goalY,pickY); 
    return 0;
}

int endX(int startX, char alphabet){

    if(alphabet != ' ')
    {
        if (alphabet == 'R')
        {
            startX += 1;
        }
        else if (alphabet == 'L')
        {
            startX -= 1;
        }
    }
    return startX; 
}

int endY(int startY, char yea)
{
    if (yea != ' ')
    {
        if (yea  == 'D')
        {
            startY += 1;
        }
        else if (yea == 'U')
        {
            startY -= 1;
        }
    }
    return startY;
}
void success(int goalX, int pX, int goalY, int pY){
    if(goalX == pX && goalY == pY)
    {
        cout << "You got out of the maze.\n";
    }
    else
    {
        cout << "You are stuck in the maze.\n";
    }
}
bool valid(int pX, int pY, int maze[6][6])
{
    return maze[pY][pX]==0;
}