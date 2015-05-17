#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"

/*****************************************
 * UW User ID:  t7wei
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 *  the provided code.
 *****************************************/

// include whatever classes you want

class Weighted_graph {
	private:
		// your implementation here
		static const double INF;
		//number of edges and vertices in graph
		int edges;
		int vertices;

		//adjacency matrix and arrays to store distances, visited, and degrees
		double **matrix;
		double *distancearray;
		int *visitedarray;
		int *degreearray;

	public:
		Weighted_graph( int = 50 );
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double distance( int, int ) const;

		void insert( int, int, double );

};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

// Your implementation here

Weighted_graph::Weighted_graph( int n ){

	//if n is negative or 0, set number of vertices as 1
	if(n <= 0)
		n = 1;
	//create new 2-d array called matrix
	matrix = new double * [n];
	for(int i = 0; i < n; i++)
		//create a new array within each index of the array
		matrix[i] = new double[n];
	//set each entry in adjacency matrix to INF and set values on diagonal to 0
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			matrix[i][j] = INF;
		matrix[i][i] = 0;
	}

	//create new distancearray and set all values in it to INF
	distancearray = new double[n];
	for(int i = 0; i < n; i++)
		distancearray[i] = INF;
	//create new visitedarray and set all values in it to 0 (false)
	visitedarray = new int[n];
	for(int i = 0; i < n; i++)
		visitedarray[i] = 0;
	//create new degreearray and set all values in it to 0
	degreearray = new int[n];
	for(int i = 0; i < n; i++)
		degreearray[i] = 0;

	//set number of vertices as n
	vertices = n;
	//set number of edges to 0
	edges = 0;
}

Weighted_graph::~Weighted_graph(){

	//for all the arrays within the array, delete them
    for(int i = 0; i < vertices; i++)     
	{
		delete[] matrix[i];
	}
	//delete the array that stores all the other arrays
	delete[] matrix;

	//delete distancearray, visitedarray, and degreearray
	delete[] distancearray;
	delete[] visitedarray;
	delete[] degreearray;
}

int Weighted_graph::degree( int n ) const {

	//if n does not correspond to existing vertex, throw illegal argument exception
	if(n >= vertices || n < 0)
		throw illegal_argument();
	//return degree of vertex n
	return degreearray[n];
}

int Weighted_graph::edge_count() const {

	//return number of edges in graph
	return edges;
}

double Weighted_graph::adjacent( int m, int n ) const {

	//if m or n does not correspond to existing vertices throw illegal argument exception
	if(m >= vertices || n >= vertices || m < 0 || n < 0)
		throw illegal_argument();
	//if there is no edge connecting m and n return 0
	if(matrix[m][n] == INF && matrix[n][m] == INF)
		return 0.0;
	//otherwise return weight of edge between m and n
	else
		return matrix[m][n];
}

double Weighted_graph::distance( int m, int n ) const {

	//if m or n does not correspond with existing vertices throw illegal argument exception
	if(m >= vertices || n >= vertices || m < 0 || n < 0)
		throw illegal_argument();
	//if vertex m or n has no edges connecting to it throw illegal argument exception
	if(degree(m) == 0 || degree(n) == 0)
		throw illegal_argument();
	//if m is the same vertex as n, return 0 distance
	if(m == n)
		return 0.0;

	//initialization of distance array to all infinity
	for(int i = 0; i < vertices; i++)
		distancearray[i] = INF;
	//initialization of visited array to all 0
	for(int i = 0; i < vertices; i++)
		visitedarray[i] = 0;

	//initialize visited all variable (0 is false, 1 is true)
	int visitedall = 0;

	//set node m to visited
	visitedarray[m] = 1;
	//set distance from m to m to 0
	distancearray[m] = 0.0;
	//set minimumdistanceindex to m
	int mindistanceindex = m;
	
	//Dijkstra's Algorithm
	while(visitedall == 0)
	{
		//relaxation loop to check all adjacent vertices
		for(int i = 0; i < vertices; i++)
		{
			
			//if distance from current node to adjacent node is not 0 or INF, and the sum of the distance from current node to adjacent node and the distance of the current node is less than the distance between 
			if(matrix[mindistanceindex][i] != 0 && matrix[mindistanceindex][i] != INF && matrix[mindistanceindex][i] + distancearray[mindistanceindex] < distancearray[i])
			{
				//update distancearray with new shortest distance
				distancearray[i] = matrix[i][mindistanceindex] + distancearray[mindistanceindex];
			}
			//set visitedarray to visited
			visitedarray[mindistanceindex] = 1;
		}
		
		//set mindistance to infinity to check for actual mindistance in distancearray
		double mindistance = INF;
		//check for mindistance and update mindistance and mindistanceindex
		for(int i = 0; i < vertices; i++)
		{
			if(distancearray[i] <= mindistance && visitedarray[i] == 0)
			{
				//set mindistance to min distance in distancearray
				mindistance = distancearray[i];
				//set mindistanceindex to the index of the min distance
				mindistanceindex = i;
			}
		}
		
		//reset visitedall variable to 1
		visitedall = 1;
		//check if all vertices have been visited by multiplying each element in visitedarray. if one of them is 0 (unvisited), result of visitedall will be 0
		for(int i = 0; i < vertices; i++)
		{
			visitedall = visitedall * visitedarray[i];
		}
	}
	//return shortest distance of node n from m
	return distancearray[n];
}

void Weighted_graph::insert( int m, int n, double w ) {

	//if weight is negative or 0 throw illegal argument exception
	if(w <= 0)
		throw illegal_argument();
	//if trying to insert an edge between the same node, throw illegal argument exception
	if(m == n)
		throw illegal_argument();
	//if m or n is greater than total number of vertices, throw illegal argument exception
	if(m >= vertices || n >= vertices)
		throw illegal_argument();
	//if current edge between m and n is infinity increase number of edges by 1 and increase degrees of m and n by 1
	if(matrix[m][n] == INF)
	{
		edges++;
		degreearray[m] += 1;
		degreearray[n] += 1;
	}
	//set corresponding entries in adjacency matrix to w
	matrix[m][n] = w;
	matrix[n][m] = w;
}

#endif
