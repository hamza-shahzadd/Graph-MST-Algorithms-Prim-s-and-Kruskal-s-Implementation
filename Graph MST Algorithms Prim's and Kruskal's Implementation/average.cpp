#include<iostream>
#include<fstream>
#include<string>
#include<cstring> 
#include <ctime>
#include <bits/stdc++.h>
using namespace std;


int main()
{
	time_t start, end;
	
	time(&start);
	ios_base::sync_with_stdio(false);
	ifstream MyReadFile("p2p-Gnutella08.txt");
	int i = 0;
	int store[50000];
	
	while (!MyReadFile.eof() ) {

		MyReadFile >> store[i];
		i++;
	}
	
	MyReadFile.close();
	int edges = i/2;
	
	int source[50000];
	int destination[50000];
	
	int s=0,d=0;
	
	ofstream myfile;
  	myfile.open ("AvgDegree.txt");
  	source[0]=store[0];
  	myfile << "  " << source[0] << "		";
  	
  	
  	
	for(int j=1; j<i;j++)
	{
		if(j%2 ==0)
		{
			source[s]= store[j];
			myfile << "  " << source[s] << "		" ;
			s++;
		}
		else
		{
			destination[d]=store[j];
			myfile << destination[d] << endl;
			d++;
		}
		
	}
	
	
	s--;
	d--;
	
	int max1=0;
	for(int j=0; j< s ; j++)
	{
		if(source[j]> max1)
		{
			max1=source[j];
		}
		
	}
	
	int max2=0;
	for(int j=0; j< d ; j++)
	{
		if(destination[j]> max2)
			{
				max2=destination[j];
			}
	}	
	
		

	float nodes;
	if( max1 > max2)
	{
		nodes=max1;
	}
	else
	{
		nodes=max2;
	}
	
	float avgDegree;
	avgDegree= edges/nodes;
	
	cout << "Average Degree = " << avgDegree <<  endl;
	
	myfile << "\n\n\nTotal Nodes = " << nodes << endl;
	myfile << "Total edges = " << edges << endl;
	myfile << "Average Degree = " << avgDegree << endl;
	myfile.close();
	
	time(&end);
	// Calculating total time taken by the program.
	double time_taken = double(end - start);
	cout << "\nTime taken by program is : " << fixed << time_taken;
	cout << " sec " << endl;
	

	return 0;
}
