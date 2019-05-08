#pragma once
template <typename T>
class CSC382Graph_AdjacencyList // templated class for adjacent list graph
{
public:
	CSC382Graph_AdjacencyList()//constructor that creates a new graph thats a vector of lists on the heap
	{
		graph_adjacencylist = new vector<list<T>*>();//using template type list pointers as the vector type
	}

	~CSC382Graph_AdjacencyList()//destructor 
	{
		for (list<T>* iter : *graph_adjacencylist)// iterate through the graph vector to each list element 
		{
			if (iter != nullptr)// if the element isnt null (it exists)
			{
				delete iter;// delete it
			}
		}
		delete graph_adjacencylist;// then delete the empty graph
	}

	list<T>* AddVertex(T data)// function for adding a vertex node into the graph 
	{						//take in data of vertex as argument
							// Attempt to find
		if (IsVertex(data))// Call IsVertex function to check if data matches data of any vertex in graph
		{
			cout << "Vertex is already in the graph. Duplicate NOT added." << endl;// if it does return nullpointer
			return nullptr;
		}
		else//otherwise 
		{

			list<T>* new_vertex = new list<T>();		// Create new list to house the vertex and its edges
			new_vertex->push_back(data);				// Data is added as the first element in the list
			graph_adjacencylist->push_back(new_vertex);	// list pointer is added to the graph
			return new_vertex;
		}
	}

	bool AddEdge(list<T>* vertex, T data) //function that takes in vertex node & its data to add an edge to it
	{
		if(!IsVertex(vertex))			// Call IsVertex function & see if vertex is already in graph
		{
			cout << "Vertex specified does not exist. Cannot add edge to a non-existant vertex."
			return false;			// if its not there then you cant add an edge to it within the graph; return false
		}
		if (!IsVertex(data))		// Data must be an existing vertex or it will need to be created.
		{
			vertex->push_back(data);
			return true;
		}
		else// otherwise
		{
			list<T>* new_vertex = AddVertex(data);// create a new vertex list to add the passed data into 
			new_vertex->push_back(data);		// Add data to the vertex list as its element 
			return true;
		}
	}

	bool AddEdge(list<T>* starting_vertex, list<T>* ending_vertex) // function that adds edges to a starting & ending vertex list 
	{
		if(!IsVertex(starting_vertex) || !IsVertex(ending_vertex)) // if either the starting vertex or the ending vertex isnt in the graph
		{
			cout << "Cannot AddEdge because one of the specified vertices does not exist in the graph." << endl;
			return false;										 // return false
		}
		if (!IsEdge(starting_vertex, ending_vertex->front()))		// Prevent adding duplicate edges
		{
			starting_vertex->push_back(ending_vertex->front());		// Then put an edge between last element of starting list & first element of the other list
			return true;
		}
		return false;
	}

	bool IsVertex(T data)// function checking for vertex with data matching arument 
	{
		for (list<T>* iter : *graph_adjacencylist)// iterate through the graph vector for vertex lists
		{
						// Check the first value in the list which is the primary vertex
			if (iter->front() == data)
			{
				return true;// if so; true
			}
		}
		return false;
	}

	bool IsVertex(list<T>* vertex_to_find)// function that creates a new vertex list to represent 
	{
		for (list<T>* iter : *graph_adjacencylist)// iterate through the graph 
		{
			if (iter == vertex_to_find)			// if list pointer matches pionter of list to find 
			{		
				return true;				// return true
			}
		}
		return false;
	}

	bool IsEdge(T edge_to_find)						// function that looks for a templated edge
	{
		for (list<T>* iter : *graph_adjacencylist) // iterate through the graph vector
		{
			if (IsEdge(iter, edge_to_find))		// Call other IsEdge function to find desired edge within every vertex list 
			{
				return true;
			}
		}
		return false;
	}

	bool IsEdge(list<T>* vertex, T edge_to_find)// function that checks for edges using vertex list pointer & edge 
	{
		for (T i : *vertex)						// for every element wihtin the vertex list
		{
			// skip checking the primary vertex and only check edges
			if (vertex->front() == i)
			{
				continue;
			}
			if (i == edge_to_find)				// if current edge matches desired edge return true
			{
				return true;
			}
		}
		return false;
	}

	list<T>* FindVertex(T data)	// function that finds vertex list using its data & returns its pionter
	{
		for (list<T>* iter : *graph_adjacencylist) //use pointer to iterate through graph
		{
			if (iter->front() == data)			// if primary vertex matches desired data return its pointer
			{
				return iter;	
			}
		}
		return nullptr;
	}

	void PrintAdjacencyList()	//function to print out the contents of graph
	{
		for (list<T>* iter : *graph_adjacencylist) //itareate through graph with pointer 
		{
			for (T i : *iter) // nested for loop that checks every element in the graph list 
			{
				// skip checking the primary vertex and only check edges
				if (iter->front() == i)		// Prints the Vertex 
				{
					cout << "Vertex = " << i << "   Edges = ";
				}
				else	// Prints the Edges
				{
					cout << i << " ";
				}
			}
			cout << endl;
		}
	}

	int NumberOfEdges(T vertex_data)// function that counts the amount of edges by taking in vertex data
	{
		list<T>* vertex = FindVertex(vertex_data); // Call FindVertex function to return list pointer that contains the desired data

		if(vertex != nullptr)					// as long as the vertex you found exists
		{
			return NumberOfEdges(vertex);		// return number from calling Number of Edges function for current vertex list
		}
		return -1;
	}

	int NumberOfEdges(list<T>* vertex)// other function that takes in vertex list 
	{
		return vertex->size();		// return size of vertex list
	}

	int GraphSize()		//function that returns the number of elements within the graph
	{
		return graph_adjacencylist->size();// use vector method size() to return graph size
	}

private:
	vector<list<T>*>* graph_adjacencylist;// create vector of templated-list pointers as your graph
};