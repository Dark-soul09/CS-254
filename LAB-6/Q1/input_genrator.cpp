#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
using namespace std;
#define lmt 17
#define NOV 20
 
using namespace std;
 
// A function to check for the cycle, on addition of a new edge in the random graph.
bool CheckAcyclic(int edge[][2], int ed, bool check[], int v)
{
	int i;
	bool value;
	// If the current vertex is visited already, then the graph contains cycle.
	if(check[v] == true)
	{
		return false;
	}
	else
	{
		check[v] = true;
		// For each vertex, go for all the vertex connected to it.
		for(i = ed; i >= 0; i--)
		{
			if(edge[i][0] == v)
			{
				return CheckAcyclic(edge, ed, check, edge[i][1]);
			}
		}
	}
	// In case, if the path ends then reassign the vertexes visited in that path to false again.
	check[v] = false;
 
	if(i == 0)
		return true;
}
 
// A function to generate random graph.
void GenerateRandGraphs(int e,int n)
{
	int i, j, edge[e][2], count;
 
	bool check[21];
 
	// Build a connection between two random vertex.
	i = 0;
	while(i < e)
	{
		edge[i][0] = rand()%n+1;
		edge[i][1] = rand()%n+1;
 
		for(j = 1; j <= n; j++)check[j] = false;
 
		if(CheckAcyclic(edge, i, check, edge[i][0]) == true)
			i++;
	}

    for(j = 0; j < e; j++)
    {
        cout<<edge[j][0]<<" "<<edge[j][1]<<"\n";
    }
}
int main()
{
    freopen("test_cases_Q1.txt","w",stdout);
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = rand()%lmt;
	cout<<tt<<"\n";
	while (tt--)
	{
        
        int n = rand()%NOV, m = rand()%NOV;
        cout<<n<<" "<<m<<"\n";
        GenerateRandGraphs(m,n);
        cout<<"\n\n\n";
	}   
}