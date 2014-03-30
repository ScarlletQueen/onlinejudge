#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
	map<UndirectedGraphNode *, UndirectedGraphNode *> nodemap;

	UndirectedGraphNode * getNode( UndirectedGraphNode *node)
	{
		if(node == NULL) return NULL;

		if(nodemap.count(node) > 0)
			return nodemap[node];
		else
			return nodemap[node] = new UndirectedGraphNode( node->label );
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		
		if( node == NULL ) return NULL;

		UndirectedGraphNode *newNode = getNode( node );	

		for( size_t i = 0; i < (node->neighbors).size(); ++i )
		{
			UndirectedGraphNode *neighbor = (node->neighbors)[i];
			if( nodemap.count(neighbor) == 0 )
			{
				UndirectedGraphNode *newNeighbor = cloneGraph(neighbor);
				
				newNode->neighbors.push_back(newNeighbor);
			}
			else
			{
				newNode->neighbors.push_back(nodemap[neighbor]);
			}
		}

		return newNode;
    }
};