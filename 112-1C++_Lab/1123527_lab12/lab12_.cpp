#include<iostream>
using namespace std;
void readMaze(char maze[][10],int row,int column,int &startx,int &starty)
{
    for(int i = 0; i < row; i++)
    {
        for(int k = 0; k < column; k++)
        {
            if(maze[i][k] == 'S')
            {
                startx = i;
                starty = k;
            }
        }
    }
}
int findPath(char maze[][10],int row,int column,int startx,int starty,int &targetx,int &targety)
{
    for(int k = 0; k < row; k++)
    {
        for(int j = 0; j < column; j++)
        {
            if(maze[k][j] == 'T')
            {
                targetx = k;
                targety = j;
            }
        }
    }
    enum direction{right, front, left, back};
    direction dir = front;
    int currX = startx;
    int currY = starty;
    int path = 0;
    if(maze[currX][currY + 1] == '0' )
    {
        currY++;
        dir = right;
        path++;
    }
    else if(maze[currX - 1][currY] == '0' )
    {
        currX--;
        dir = front;
        path++;
    }
    else if(maze[currX][currY - 1] == '0' )
    {
        currY--;
        dir = left;
        path++;
    }
    else if(maze[currX + 1][currY] == '0')
    {
        currX++;
        dir = back;
        path++;
    }

    while(currX >=0 && currX < row && currY >=0 && currY < column && maze[currX][currY] != 'T' && maze[currX][currY] != 'S')
    {
        switch(dir)
        {
            case front:
               if(maze[currX][currY + 1] == '0' || maze[currX][currY + 1] == 'T' || maze[currX][currY + 1] == 'S')
               {
                currY++;
                dir = right;
               }
                else if(maze[currX - 1][currY] == '0' || maze[currX - 1][currY] == 'T' || maze[currX - 1][currY] == 'S')
                {
                    currX--;
                    dir = front;
                }
                else if(maze[currX][currY - 1] == '0' || maze[currX][currY - 1] == 'T' || maze[currX][currY - 1] == 'S')
                {
                    currY--;
                    dir = left;
                }
                else if(maze[currX + 1][currY] == '0' || maze[currX + 1][currY] == 'T' || maze[currX + 1][currY] == 'S')
                {
                    currX++;
                    dir = back;
                }
                path++;
                break;
             case right:
                 if(maze[currX + 1][currY] == '0' || maze[currX + 1][currY] == 'T' || maze[currX + 1][currY] == 'S')
                 {
                    currX++;
                    dir = back;
                 }
                 else if(maze[currX][currY + 1] == '0' || maze[currX][currY + 1] == 'T' || maze[currX][currY + 1] == 'S')
                 {
                    currY++;
                    dir = right;
                 }
                 else if(maze[currX - 1][currY] == '0' || maze[currX - 1][currY] == 'T' ||  maze[currX - 1][currY] == 'S')
                 {
                    currX--;
                    dir = front;
                 }
                 else if(maze[currX][currY - 1] == '0' || maze[currX][currY - 1] == 'T' || maze[currX][currY - 1] == 'S')
                 {
                    currY--;
                    dir = left;
                 }
                 path++;
                 break;
              case left:
                 if(maze[currX - 1][currY] == '0' || maze[currX - 1][currY] == 'T' || maze[currX - 1][currY] == 'S')
                 {
                    currX--;
                    dir = front;
                 }
                 else if(maze[currX][currY - 1] == '0' || maze[currX][currY - 1] == 'T' || maze[currX][currY - 1] == 'S')
                 {
                    currY--;
                    dir = left;
                 }
                 else if(maze[currX + 1][currY] == '0' || maze[currX + 1][currY] == 'T' || maze[currX + 1][currY] == 'S')
                 {
                    currX++;
                    dir = back;
                 }
                 else if(maze[currX][currY + 1] == '0' || maze[currX][currY + 1] == 'T' || maze[currX][currY + 1] == 'S')
                 {
                    currY++;
                    dir = right;
                 }
                 path++;
                 break;
             case back:
                if(maze[currX][currY - 1] == '0' || maze[currX][currY - 1] == 'T' || maze[currX][currY - 1] == 'S')
                {
                    currY--;
                    dir = left;
                }
                else if(maze[currX + 1][currY] == '0' || maze[currX + 1][currY] == 'T' || maze[currX + 1][currY] == 'S')
                {
                    currX++;
                    dir = back;
                }
                else if(maze[currX][currY + 1] == '0' || maze[currX][currY + 1] == 'T' || maze[currX][currY + 1] == 'S')
                {
                    currY++;
                    dir = right;
                }
                else if(maze[currX - 1][currY] == '0' || maze[currX - 1][currY] == 'T' || maze[currX - 1][currY] == 'S')
                {
                    currX--;
                    dir = front;
                }
                path++;
                break;
            default:
              break;
        }
    }
    if(maze[currX][currY] == 'S')
    {
        targetx = startx;
        targety = starty;
    }
    return path;
}

int main()
{
 int numTest;
 char maze[10][10];
 cin >> numTest;
 for(int i = 0; i < numTest; i++)
 {
  int column;
  int row;
  int numOfMove;
  int startX;
  int startY;
  int targetX;
  int targetY;
  cin >> row >> column;
  for(int n = 0; n < row; n++)
  {
    for(int m = 0; m < column; m++)
    {
        cin >>maze[n][m];
    }
  }
  readMaze(maze,row,column,startX,startY);
  numOfMove = findPath(maze,row,column,startX,startY,targetX,targetY);
  cout << "Source coordinates:(" << startX + 1 << ","<< startY + 1 <<"). Target coordinates:(" << targetX + 1 << "," << targetY + 1
  << "),Distance traveled:" << numOfMove << endl;
  }

 }