// GraphTutorial.cpp : Creates a directed, unweighted graph.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iostream>
#include "CSC382Graph_NodeBased.h"
#include "CSC382Graph_AdjacencyList.h"

using namespace std;

bool Testing_NodeBased()
{
	CSC382Graph_NodeBased<int>* default = new CSC382Graph_NodeBased<int>;
	cout << "\nA graph and vertex have just been created. Lets see if their default constructors works!" << endl;

	// Test CSC382Graph_NodeBased Constructor(s)
	if (default->Size() == 0)
	{
		cout << "\nYay!There's nothing in this Graph! The default constructor works!" << endl;
		return true;
	}
	else { cout << "\nWhoops! This constructor is broken" << endl; return false; }
	
}

bool Testing_AdjacencyList()
{
	// Test CSC382Graph_AdjacencyList Constructor(s)

	// Test functions of the CSC382Graph_AdjacencyList class

	// Test creating lots of nodes and edges
	
	return false;
}

bool Test_Vertex_Constrct()
{
	CSC382Graph_Vertex<char>* first = new  CSC382Graph_Vertex<char>;
	if (first->GetData() == 0)
	{
		cout << "\nYay!There's nothing in this Vertex! The default constructor works!" << endl;
		return true;
	}
	else { cout << "\nWhoops! This constructor is broken" << endl; return false; }
}


void Test_Graph()// Test creating lots of nodes and edges
{
	int I = 1 ;	//creating data for all 20 vertices
	int II = 2;
	int III = 3;
	int IV = 4;
	int V = 5;
	int VI = 6;
	int VII = 7;
	int VIII = 8;
	int IX = 9;
	int X = 10;
	int XI = 11;
	int XII = 12;
	int XIII = 13;
	int XIV = 14;
	int XV = 15;
	int XVI = 16;
	int XVII = 17;
	int XVIII = 18;
	int XIX = 19;
	int XX = 20;


	CSC382Graph_NodeBased<int>* default = new CSC382Graph_NodeBased<int>;// my new graph
	// creating all 20 vertices
	CSC382Graph_Vertex<int>* first = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* two = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* three = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* four = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* five = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* six = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* seven = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* eight = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* nine = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* ten = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* eleven = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* twelve = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* thirteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* fourteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* fifteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* sixteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* seventeen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* eightteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* nineteen = new CSC382Graph_Vertex<int>;
	CSC382Graph_Vertex<int>* twenty = new CSC382Graph_Vertex<int>;

	cout << "\n\nCreating vertices using the SetData() method... " << endl;
	first->SetData(I);	//using SetData function to add data into their respective vertex
	two->SetData(II);
	three->SetData(III);
	four->SetData(IV);
	five->SetData(V);
	six->SetData(VI);
	seven->SetData(VII);
	eight->SetData(VIII);
	nine->SetData(IX);
	ten->SetData(X);
	eleven->SetData(XI);
	twelve->SetData(XII);
	thirteen->SetData(XIII);
	fourteen->SetData(XIV);
	fifteen->SetData(XV);
	sixteen->SetData(XVI);
	seventeen->SetData(XVII);
	eightteen->SetData(XVIII);
	nineteen->SetData(XIX);
	twenty->SetData(XX);
	
	//creating the first path set
	first->AddEdge(two);
	first->AddEdge(three);
	first->AddEdge(four);
	first->AddEdge(five);
	cout << "\n\nHere's the first set of vertex paths: " << endl;
	first->Display_V();
	

	//creating the 2nd set of paths
	six->AddEdge(seven);
	six->AddEdge(eight);
	six->AddEdge(nine);
	six->AddEdge(ten);

	cout << "\n\nHere's the second set of vertex paths: " << endl;
	six->Display_V();

	//creating the 3rd set of paths
	eleven->AddEdge(twelve);
	eleven->AddEdge(thirteen);
	eleven->AddEdge(fourteen);
	eleven->AddEdge(fifteen);
	
	cout << "\n\nHere's the third set of vertex paths: " << endl;
	eleven->Display_V();

	//creating the 4th set of paths
	sixteen->AddEdge(seventeen);
	sixteen->AddEdge(eightteen);
	sixteen->AddEdge(nineteen);
	sixteen->AddEdge(twenty);

	cout << "\n\nHere's the fourth set of vertex paths: " << endl;
	sixteen->Display_V();

	//add vertex paths to graph
	default->Insert(first);
	default->Insert(six);
	default->Insert(eleven);
	default->Insert(sixteen);
	
	//Show the user the graph
	cout << "\n\n\nHere's the entire graph with all vertices" << endl;
	default->Display();

	cout << "\n\n\nRemoving vertex 6 and its paths using RemoveVertex() function...." << endl;
	default->RemoveVertex(VI);
	cout<< "\nThe new Graph...\n" << endl;
	default->Display();

	cout << "\n\n\nRemoving edge from Vertex 1 to Vertex 5 using RemoveEdge() function...." << endl;
	default->RemoveEdge(first, five);
	default->Display();
}

int main()
{
	Testing_NodeBased();//test node graph constructor
	Test_Vertex_Constrct();//test node graph vertex constructor
	Test_Graph();//test graph & its functions
	system("pause");
    return 0;
}

