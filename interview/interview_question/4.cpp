#include <map>
#include <set>
#include <list>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
 * Complete the function below.
 */
struct Point
{
    int x;
    int y;
};
// An Data Structure for queue used in BFS
struct queueNode
{
    Point pt;
    int dist;
};

bool isValid(int row, int col, int maze_size)
{
    return (row >= 0) && (row < maze_size) &&
           (col >= 0) && (col < maze_size);
}

// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

//A function to compute the shortest path between any two points in the maze
int BFS(vector < vector < int > > maze, Point start, Point dest, int maze_size)
{
    if ( !maze[start.x][start.y] || !maze[dest.x][dest.y])
        return INT_MAX;

    bool visited[maze_size][maze_size];
    memset(visited, false, sizeof visited);

    visited[start.x][start.y] = true;

    // Create a queue for BFS
    queue<queueNode> q;

    // distance of source cell is 0
    queueNode s = {start, 0};
    q.push(s);  // Enqueue source cell

    // Do a BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;

        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col, maze_size) && maze[row][col] &&
                    !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                    curr.dist + 1
                };
                q.push(Adjcell);
            }
        }
    }
    return INT_MAX;
}


//We generate all possible permutations of cheese location sequences as the number of cheeses are small.
//And then we iteratively call above method for each route:
//start -> cheese1->cheese2->...->end
//Then we consider return the minimum path
vector<Point> cheese_locations(vector < vector < int > > maze)
{
    vector<Point> cheese_loc;
    for (int i=0; i<maze.size(); i++)
    {
        for (int j=0; j<maze[i].size() ; j++)
            if (maze[i][j]==2)
            {
                Point pt;
                pt.x = i;
                pt.y = j;
                cheese_loc.push_back(pt);
            }
    }
    return cheese_loc;
}


int minMoves(vector < vector < int > > maze, int x, int y)
{
//    cheese_loc = cheese_locations(maze);
//    vector<int> routes_len;
//    do
//    {
//        //compute the distance for each path
//    }
//    while (next_permutation(cheese_loc));
    Point start;
    Point dest;
    start.x = 0;
    start.y = 0;
    dest.x = x;
    dest.y = y;
    int res = BFS(maze,start, dest, maze.size());
    if (res = INT_MAX) res = -1;
    return res;

}


int minMoves(vector < vector < int > > maze, int x, int y)
{
//    Point start;
//    Point dest;
//    start.x = 0;
//    start.y = 0;
//    dest.x = x;
//    dest.y = y;
//    vector<Point> cheese_loc = cheese_locations(maze);
//    int res = INT_MAX;
//    int distance = 0;
//    do
//    {
//        //compute the distance for each path
//        cheese_loc.insert ( cheese_loc.begin(), start );
//        cheese_loc.insert ( cheese_loc.end(), dest );
//        for (vector<Point>::iterator it =cheese_loc.begin(); it<cheese_loc.end(); ++it )
//        {
//            distance += BFS(maze,*it, *(it+1), maze.size());
//        }
//        res = min (res, distance);
//    }
//    while (next_permutation(cheese_loc.begin(),cheese_loc.end()));
////    int res = BFS(maze,start, dest, maze.size());
//    if (res = INT_MAX) res = -1;
//    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;

    int _maze_rows = 0;
    int _maze_cols = 0;
    cin >> _maze_rows >> _maze_cols;
    vector< vector < int > > _maze(_maze_rows);
    for(int _maze_i=0; _maze_i<_maze_rows; _maze_i++)
    {
        for(int _maze_j=0; _maze_j<_maze_cols; _maze_j++)
        {
            int _maze_tmp;
            cin >> _maze_tmp;
            _maze[_maze_i].push_back(_maze_tmp);
        }
    }

    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    int _y;
    cin >> _y;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = minMoves(_maze, _x, _y);
    fout << res << endl;

    fout.close();
    return 0;
}
