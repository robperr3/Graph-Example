#pragma once

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>


using namespace std;

template <typename T>  //a templated vertex class for the node-style graph
class CSC382Graph_Vertex
{
private:
	T data;// data for the vertex
	list<CSC382Graph_Vertex<T>*>* connected_vertices;//the vertex will really be a list reperesenting one possible path within the graph
public:												//with each element of the list being a vertex for this one specific path (not all the vertices in the graph!)
	CSC382Graph_Vertex()//default Vertex constructor, meaning an empty list of vertices
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();// new vertex list created on the heap
		data = NULL;//there's only this data and nothing else so this is a non-weighted graph
	}

	CSC382Graph_Vertex(T node_data)//creating a vertex object with data being passed into it
	{
		connected_vertices = new list<CSC382Graph_Vertex<T>*>();// vertex list being put into the heap again
		data = node_data;//data to be stored into vertex object
	}

	~CSC382Graph_Vertex()//vertex deconstructor
	{
		delete connected_vertices;
	}


	void AddEdge(CSC382Graph_Vertex<T>* vertex_connection)//fucntion to connect a vertex to another one  within the vertex list 
	{
		if (vertex_connection != this)//if this edge (connection) doesnt already exist 
		{
			connected_vertices->push_back(vertex_connection);//then create this new edge
		}
	}


	bool VertexConnected(CSC382Graph_Vertex<T>* vertex_to_find)//this function causes lists fo vertices to be accesabnle to each pother
	{															//so this would make the graph directed
		for(CSC382Graph_Vertex<T>* i : *connected_vertices)
		{//if the vertex list youre trying to find is connected 
			if(i == vertex_to_find)
			{//then its accessible to the vertex youre currently looking at
				return true;
			}
		}
		return false;
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* edge_to_remove)//function to delete an edge of 2 vertices
	{
		if (edge_to_remove != nullptr)//if the edge youre trying to remove exists 
		{
			connected_vertices->remove(edge_to_remove);//then get rid of it
		}
	}


	T GetData()//function returns the data of the current vertex
	{
		return data;
	}


	void SetData(T data_param)//function sets data passed in as data of current vertex
	{
		data = data_param;
	}

	void Display_V()
	{
		cout << "\nVertex: "<< this->data << "\n     " << endl;
		for (CSC382Graph_Vertex<T>* iter: *connected_vertices)
		{
			
			if (iter->GetData() != NULL)
			{
				
				cout << "\nConnected Vertex: " << iter->GetData() << endl;

			}
		}
	}
};


template <typename T>
class CSC382Graph_NodeBased//templated Graph class 
{
private:
	list<CSC382Graph_Vertex<T>*>* graph;//the graph is basically a list of the vertex lists

public:
	CSC382Graph_NodeBased()//constructor that creates an empty graph 
	{
		graph = new list<CSC382Graph_Vertex<T>*>;// new graph created on the heap
	}


	CSC382Graph_NodeBased(CSC382Graph_Vertex<T>* initial_vertex)//constructor that creates a new graph (list) made up of vertices
	{
		graph = new list<CSC382Graph_Vertex<T>*>;//new graph created on the heap
		Insert(initial_vertex);// vertex(which is really a list in itself) is added to the graph list 
	}


	~CSC382Graph_NodeBased()//graph destructor
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)//make an iterator to go through the graph
		{
			if (iter != nullptr && iter != NULL)// as long as the iterator isnt null
			{
				delete iter;// delete the vertex in the graph
			}
		}
		delete graph; // then delete the graph
	}


	CSC382Graph_Vertex<T>* Insert(CSC382Graph_Vertex<T>* vertex)// function that inserts a vertex node in to the graph
	{// take in the passed vertex list and push it into the graph list
		graph->push_back(vertex);
		return vertex;//return the inserted vertex
	}


	CSC382Graph_Vertex<T>* Insert(T data)// function that inserts the data into the vertex node
	{
		CSC382Graph_Vertex<T>* new_node = new CSC382Graph_Vertex<T>(data);//create a new vertex on the heap based with the data that was passed into the funttion 
		return Insert(new_node);//use the other insert function to insert this new vertex into the graph & return the new vertex
	}


	void RemoveVertex(T data)// remove a vertex from the graph using its data
	{
		CSC382Graph_Vertex<T>* vertex_to_remove = FindVertex(data);// Call the find function to return the desired vertex via its data 
		RemoveVertex(vertex_to_remove);// Call the other Remove function to delete the vertex from the graph
	}


	void RemoveVertex(CSC382Graph_Vertex<T>* vertex_to_remove)// Function that takes in a pointer to a vertex node & deletes it
	{
		graph->remove(vertex_to_remove);// take passed in vertex node via pionter and delete using list remove method on graph
	}


	void AddEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)// function that takes in 2 vertice pointers as arguments to make an edge between them
	{
		start_vertex->AddEdge(end_vertex);// take the start vertex & recursively call AddEdge function with ending vertex
	}


	void RemoveEdge(CSC382Graph_Vertex<T>* start_vertex, CSC382Graph_Vertex<T>* end_vertex)// function for removing an edge between 2 vertices
	{//take in 2 pointers for your starting & ending vertices
		start_vertex->RemoveEdge(end_vertex);//recursively call RemoveEdge function from starting vertex on ending vertex
	}


	bool IsEdge(CSC382Graph_Vertex<T>* vertex_to_search_in, CSC382Graph_Vertex<T>* edge_to_check_for)// function that sees if an edge actually exists
	{//take in pointers for vertex to search in & desired vertex 
		return vertex_to_search_in->VertexConnected(edge_to_check_for);// Call the VertexConnected function on the vertex youre searching in
	}//with the desired vertex as the argument and return true if its there


	CSC382Graph_Vertex<T>* FindVertex(T data_to_find)// function takes in data as an arguemnt and searches for the associated vertex pointer
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)// iterate through the vertices of the graph 
		{
			if (iter->GetData() == data_to_find)// if the data of a vertex is the same as the data youre looking for
			{
				return iter;// return that vertex pointer
			}
		}
		return nullptr;// otherwise return nullpointer
	}


	CSC382Graph_Vertex<T>* FindVertex(CSC382Graph_Vertex<T>* node_to_find)// function taking in pionter to vertex your looking for & finds it
	{
		for(CSC382Graph_Vertex<T>* iter : *graph)// iterate through all vertex pionters in graph
		{
			if(iter == node_to_find)// if pointer of vertex matches pointer of desired vertex
			{
				return iter;// return that pointer
			}
		}
		return nullptr;// if not return nullpointer
	}


	int Size()// function that tells you how many vertex nodes are in the graph
	{
		return graph->size();// use list size method to obtain amount of elements (vertex nodes) are in the graph & return it
	}

	void Display()
	{
		for (CSC382Graph_Vertex<T>* iter : *graph)
		{
			
				if (iter->GetData() != NULL)
				{
					iter->Display_V();
				}
			
		}
	}

};
