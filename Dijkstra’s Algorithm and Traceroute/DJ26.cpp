//C++ Program for Dijkstra Algorithm
#include<iostream>
using namespace std;

int graph[50][50];
int minfunc (int x, int y); //Minimum Function Defined inorder to fine Minimum Distance between Edges

int
Dijkstra (int v) // Dijkstra Algorithm implementation
{

  int vtx[v + 1];

  for (int i = 0; i < v + 1; i++)
    {
      vtx[i] = 0;
    }

  int vtx_visit[v + 1];
  int short_path[v];

  int c = 1; //count variable
  int min = 999; //max value
  int temp = 0;

  cout << "\nStep\t"; // Table is printed accordingly
  for (int i = 2; i <= v; i++)
    {
      cout << "V = " << i <<"\t";
    }
  cout <<
    "N\n----------------------------------------------------------------------------------";


  //Initializations
  cout << "\n0\t";
  vtx_visit[1] = 1;
  c = 2;

  vtx[1] = 1;
  int D[v + 1][v + 1];
  int P[v + 1][v + 1];
  for (int i = 2; i <= v; i++)
    {
      D[1][i - 1] = graph[1][i];

      P[1][i - 1] = 1;
      cout << D[1][i - 1] << "," << P[1][i - 1] << "\t"; //values are printed from graph
      if (D[1][i - 1] < min)
	{
	  min = D[1][i - 1];
	  temp = i;
	}
    }
  cout << vtx_visit[1] << "\t";
  vtx[temp] = 1;
  short_path[temp] = min;
  cout << "\n";


  for (int itn = 2; itn <= v; itn++)
    {

      cout << itn - 1 << "\t";

      vtx_visit[c] = temp;
      c++;

      min = 999;

      for (int dpvtx = 1; dpvtx < v; dpvtx++)  
	{

	  if (vtx[dpvtx + 1] == 0)
	    {

	      D[itn][dpvtx] =
		minfunc (D[itn - 1][dpvtx],
		       D[itn - 1][vtx_visit[c - 1] - 1] +
		       graph[vtx_visit[c - 1]][dpvtx + 1]); //Formula

	      if (minfunc
		  (D[itn - 1][dpvtx],
		   D[itn - 1][vtx_visit[c - 1] - 1] +
		   graph[vtx_visit[c - 1]][dpvtx + 1]) ==
		  D[itn - 1][dpvtx])
		{
		  P[itn][dpvtx] = P[itn - 1][dpvtx];
		}
	      else
		{
		  P[itn][dpvtx] = vtx_visit[c - 1];

		}


	      if (D[itn][dpvtx] < min)
		{
		  min = D[itn][dpvtx];
		  temp = dpvtx + 1;
		}

	      cout  << D[itn][dpvtx] << "," <<
		P[itn][dpvtx] << "\t";

	    }
	  else
	    {
	      cout << "----\t"; //When particular vertex is selected print blank
	    }

	}
      for (int m = 1; m <= c - 1; m++)
	cout << vtx_visit[m] << ",";
      if (min != 999)
	{
	  short_path[temp] = min;
	}
      cout << "\n";
      vtx[temp] = 1;
    }

  for (int i = 2; i <= v; i++)
    {
      cout << "Shortest path from vertex 1 to\t" << i  << "\tis\t" <<
	short_path[i] << "\n";
    }
}

int
minfunc (int x, int y) //Minimum Function
{
  int min;
  if (x <= y)
    {
      min = x;
    }

  else
    min = y;

  return min;
}

int
graph_input (int v) //Graph is used to store info
{

  cout << "Enter the Adjacency Matrix : \n";
  for (int i = 1; i <= v; i++)
    {
      for (int j = 1; j <= v; j++)
	{
	  cout << "Enter value between\t" << i << "\tand\t" << j << ":\t";
	  cin >> graph[i][j];
	}
    }
  Dijkstra (v);
  return 0;
}

int
main ()
{
  int v;
  cout << "Enter No. of Vertices : "; //Enter Total Number of vertices
  cin >> v;
  int graph[v + 1][v + 1];
  graph_input (v);

}




