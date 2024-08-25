#include <ctime>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include<fstream>
#include<string>
#include<cstring>
#include <stdio.h>
using namespace std;
#define edge pair<int, int>


class Graph {
   private:
  
  vector<pair<int, edge> > G;  // graph
  vector<pair<int, edge> > T;  // mst
  
  int *parent;
  int *p;
  bool choice;
  int V;  // number of vertices/nodes in graph
 
 public:
 
  Graph(int V)  // Parameterized constructor
  {
  parent = new int[V];   // 
  
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}

void AddWeightedEdge(int s, int d, int w) 
{
  G.push_back(make_pair(w, edge(s, d)));
}

int find_set(int i) {
  // If i is the parent of itself
  if (i == parent[i])
    return i;
  else
    // so we recursively call Find on its parent
    return find_set(parent[i]);
}

void union_set(int s, int d) {
  parent[s] = parent[d];
}


void kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
 int sel=7;
  int rep=0;
  for(int ab=0; ab <sel; ab++)
  {
  	rep++;
  }
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}

void print()
 {
	
	ofstream myfile;
  	myfile.open ("kruskal.txt");	
	
	int total=0;
  myfile << "Edge    :   "
     << " Weight" << endl;
  for (int i = 0; i < T.size(); i++) {
    myfile << T[i].second.first << "    -    " << T[i].second.second << "     :     "
       << T[i].first << endl;
       
       total=total+T[i].first;
       
  }
  
  cout << "Minimun spanning tree= " << total << endl;
  myfile << "Minimun spanning tree " << total << endl;
  
}

};



//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


int main()
{


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
	
	//////////////////////////////////////////////
	
	int max=0;
	for(int a=0;a<s;a++)
	{
		if(source[a] > max);
		{
			max=source[a];
		}
	}

	
	max++;
	
	
	
	for(int a =0; a < d; a++)
	{
		if(destination[a] > (max-1))
		{
			source[a]=0;
			destination[a]=0;
			weight[a]=0;
		}
	}

	//////////////////////////////////////////////
	
	
	
	////////////////////////////////////////////
	
/*	for(int a =0; a <s; a++ )
	{
		cout << source[a] << "       ";
		cout << destination[a] << "       ";
		cout << weight[a] << endl;
	}
*/	


	time_t start, end;
	
	time(&start);
	
	Graph g(max);
  	for(int a=0; a < s ; a++)
  	{
  		if(source[a] != 0 && destination[a] !=0)
  		{
  			g.AddWeightedEdge(source[a],destination[a], weight[a]);
  		}
  		if((source[a] == 0 && destination[a] !=0) || (source[a] != 0 && destination[a] ==0) )
  		{
  			g.AddWeightedEdge(source[a],destination[a], weight[a]);
  		}
  	}
  	g.kruskal();
  	g.print();
  	
  	time(&end);
	// Calculating total time taken by the program.
	double time_taken = double(end - start);
	cout << "\nTime taken by program is : " << fixed << time_taken;
	cout << " sec " << endl;
	
	return 0;	
}	
