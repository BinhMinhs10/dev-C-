#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>
 
#define X first
#define Y second
#define ii pair<int, int>
 
using namespace std;
 
/*matrix[i][j] == 0, nghia la vat can*/
 
int m, n;
vector<vector<int> > matrix, path;
 
void ReadFile(void);
void FordBellman(ii start, ii end);
 
int main()
{
    ReadFile();
    FordBellman(make_pair(0, 0), make_pair(2, 1));
    return 0;
}
 
void ReadFile(void)
{
    fstream f;
    f.open("Matrix.INP", ios::in);
 
    f>>m>>n;
 
    matrix.resize(m, vector<int>(n, 0));
    path.resize(m, vector<int>(n, 0));
 
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            f>>matrix[i][j];
        }
    }
 
    f.close();
}
 
void PrintTraversal(vector<vector<ii > > &trace, ii start, ii end)
{
    if(start != end)
    {
        PrintTraversal(trace, start, trace[end.X][end.Y]);
    }
    else
    {
        path[end.X][end.Y] = 1;
        return;
    }
 
    path[end.X][end.Y] = 1;
}
 
void FordBellman(ii start, ii end)
{
    const int INFINITE = INT_MAX;
    int row, col;
    vector<vector<ii > > trace(m, vector<ii >(n));
    vector<vector<int> > dist(m, vector<int>(n, INFINITE));
    ii u, v;
 
    queue<ii > queu;
    vector<vector<bool> > inqueue(m, vector<bool>(n, false));
 
    dist[start.X][start.Y] = matrix[start.X][start.Y];
    queu.push(start);
 
    vector<ii > move = {make_pair(0, -1), make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1)};
 
    while(queu.size() != 0)
    {
        u = queu.front();
        queu.pop();
        inqueue[u.X][u.Y] = false;
 
        for(int i = 0; i < 4; i++)
        {
            row = u.X + move[i].X;
            col = u.Y + move[i].Y;
 
            if(row < 0 || row >= m || col < 0 || col >= n)
            {
                continue;
            }
 
            if(dist[row][col] > dist[u.X][u.Y] + matrix[row][col])
            {
                dist[row][col] = dist[u.X][u.Y] + matrix[row][col];
                trace[row][col] = u;
 
                if(inqueue[row][col] == false)
                {
                    inqueue[row][col] = true;
                    queu.push(make_pair(row, col));
                }
            }
        }
    }
 
    if(dist[end.X][end.Y] == INFINITE)
    {
        cout<<"No path."<<endl;
    }
    else
    {
        cout<<"min cost = "<<dist[end.X][end.Y]<<endl;
        PrintTraversal(trace, start, end);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
