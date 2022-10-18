#include<iostream>
#include<vector>
#include<string>
#include <sstream>


using namespace std;

void addEdge(vector <pair<int, int> > adj[], int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void printGraph(vector<pair<int,int> > adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

int main(){

	int processors,tasks;
	cout<<"Enter no. of processors: \n";
	cin>>processors;
	
	cout<<"\nEnter total no. of subtasks: \n";
	cin>>tasks;
	
	cout<<"\nEnter directed graph representation for each subtask with transtion delay at end\n";
	cout<<"For example: 0 1 10 implies edge from node 0 to 1 with transition delay 10\n\n";
	
	vector<pair<int,int>> adj[tasks];
	string query="";
	while(query!="Quit"){
		cout<<"\nEnter a transition ('Quit' to stop): ";
		getline(cin,query);

		vector<int> queries;
		istringstream is(query);
		int n;
		while(is >> n){
			queries.push_back(n);
		}
		if(queries.size()>3 || queries.size()<2 ){
			cout<<"Invalid Input Try Again\n";
			continue;
		}
		int delay;
		(queries.size()==3?delay=queries[2]:delay=0);

		addEdge(adj,queries[0],queries[1],delay);
	}
	
	printGraph(adj,tasks);
	
	int clockrates[processors];
	for(int i=0;i<processors;i++){
		cout<<"\nEnter clockrate of processor "<< i+1<<" in GHz :";
		cin>>clockrates[i];
	}
	
	int traversal;
	cout<<"\nEnter data structure : \n";
	cout<<" 1) BFS\n 2) DFS\n 3) Level Order Traversal\n 4) Min Heap\n";
	cout<<" 5) Max Heap\n 6) Topological Sort\n";
	cin>>traversal;
	
	switch(traversal){
		case 1:
			cout<<"BFS";
			break;
		case 2:
			cout<<"DFS";
			break;
		case 3:
			cout<<"Level Order Traversal";
			break;
		case 4:
			cout<<"Min Heap";
			break;
		case 5:
			cout<<"Max Heap";
			break;
		case 6:
			cout<<"Topological Sort";
			break;
		default:
			cout<<"Invalid Input";
			break;
		}
	return 0;
	}
	
