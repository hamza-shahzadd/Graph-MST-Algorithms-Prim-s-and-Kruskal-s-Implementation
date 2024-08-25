#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include <stdio.h>
using namespace std;
#define INF 9999999

int main()
{

	time_t start, end;
	
	time(&start);
	ifstream MyReadFile("Gnutella2.txt");
	int i = 0;
	int store[50000];
	
	while (!MyReadFile.eof() && i <= 15000) {

		MyReadFile >> store[i];
		i++;
	}

	
	// Close the file
	MyReadFile.close();
	
	
	i = i - 1;
	int temp = i;
	// << i <<endl;
	
//	for(int a =0; a < i ; a++)
//	{
//		cout << store[a] <<" " << endl;
//	}
	
	int source[25000];
	int destination[25000];
	int weight[25000];
	
	source[0]= store[0];
	int s=1,d=0,w=0;
	for(int j=1; j<=temp;j++)
	{
		if(j%3 ==0)
		{
			source[s]= store[j];
			s++;
		}
		else if(j%3 == 1)
		{
			destination[d]=store[j];
			d++;
		}
		else
		{
			weight[w]=store[j];
			w++;
		}
		
	}	
		///////////////////////////////
		
		
		
		
	int max=0;
	for(int a=0;a<s;a++)
	{
		if(source[a] > max);
		{
			max=source[a];
		}
	}

	max++;
	
		
		//////////////////////////////
		
		for(int a=0; a < s ; a++)
		{
			if(destination[a] > max-1)
			{
				source[a]=-1;
				destination[a]=-1;
				weight[a]=-1;				
			}
		}
		
		//////////////////////////////
		
		int sou[25000];
		int dest[25000];
		int wei[25000];
		int iter=0;
		
		for(int a=0; a< s; a++)
		{
			if(source[a] != -1)
			{
				sou[iter]=source[a];
				dest[iter]=destination[a];
				wei[iter]=weight[a];
			}
			
		}
		
		//////////////////////////////
	
	int V=max;
	int G[V][V];
	int result=40961;
	int di=0,wi=0;
	ofstream myfile;
  	myfile.open ("prims.txt");
	for(int a=0; a < V;a++)
	{
		for(int b=0; b < V;b++)
		{
			if(b == destination[di])
			{
				if(source[a] ==0 && destination[b] ==0)
				{
					di++;
					wi++;
					continue;
				}
				else
				{
					G[a][b]=weight[wi];
					di++;
					wi++;
				}	
			}
			else
			{
				G[a][b]=0;
			}
			myfile << G[a][b] << "   " << endl ;
		}
		//cout << endl;
		
	}
	
	cout << "Minimun spanning Tree = " << result << endl;
	/*for(int a=0; a< max; a++)
	{
		for(int b=0; b<max;b++)
		{			
			if(G[a][b] > G[b][a])
			{
				G[a][b]=G[b][a];
			}
			
		}
		
	}
	*/
	
	
	
	 int no_edge;  // number of edge

  // create a array to track selected vertex
  // selected will become true otherwise false
  int selected[V];

  // set selected false initially
  memset(selected, false, sizeof(selected));

  // set number of edge to 0
  no_edge = 0;

  // the number of egde in minimum spanning tree will be
  // always less than (V -1), where V is number of vertices in
  //graph

  // choose 0th vertex and make it true
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number

  
  cout << endl;
  while (no_edge < V - 1) {
    //For every vertex in the set S, find the all adjacent vertices
    // , calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise
    //choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
   // cout << x << " - " << y << " :  " << G[x][y];
   // cout << endl;
    selected[y] = true;
    no_edge++;
  }
	
	time(&end);
	double time_taken = double(end - start);
	cout << "\nTime taken by program is : " << fixed << time_taken;
	cout << " seconds " << endl;
	
	
	
	
	
	

	return 0;
}
