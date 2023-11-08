
// libraries for data structures
#include <map>
#include <vector>
#include <array>
#include <algorithm>

// other generic libraries
#include <iostream>

using namespace std;

void mcst_kruskal(map<int, array<int, 2>> weightmap, int no_of_nodes){
    
    int edges_in_mcst = no_of_nodes - 1;
    vector<int> weights; // This will store weights only

    map<int, array<int, 2>> mcst_weightmap; 
    // To store minimum cost spanning tree

    for(const auto& wgt: weightmap){
        weights.push_back(wgt.first);
        // wgt.first is key, wgt.second is value
    }

    // sort weights
    std::sort(weights.begin(), weights.end());

    map<int, bool> connected;
    for(int i = 0; i < no_of_nodes; i++){
        connected[i] = false;
    }
    // This will note which nodes have been connected in
    // minimum cost spanning tree

    /*** APPLY KRUSKAL'S ALGORITHM ***/
    for(int wgt: weights){
        // weights are sorted
        if(!connected[weightmap[wgt][0]] || !connected[weightmap[wgt][1]]){
            // If both nodes are connected already, adding a new edge
            // will make a cycle so we skip such edges

            connected[weightmap[wgt][0]] = true;
            connected[weightmap[wgt][1]] = true;
            // Mark both nodes as connected

            mcst_weightmap[wgt] = {weightmap[wgt][0], weightmap[wgt][1]};
            // Add the edge in weightmap of mcst

            edges_in_mcst--;
            if(edges_in_mcst == 0){
                break;
            }
        }
    }

    /*** print ***/
    cout << "Weightmap for minimum cost spanning tree: \n";
    for(const auto& wgt: mcst_weightmap){
        cout << wgt.first << ": " << wgt.second[0] << " " << wgt.second[1] << "\n";
    }

}

int main(){

    /* 
    
    A new type of data structure will be used to represent undirected
    graphs. This new data structure is given the name 'weightmap'

    Weightmap is represented as key value pairs, where 
    key is weight and value is an array of length 2, 
    representing nodes which they connect

    for Eg, If node 1 and node 3 are connected with an edge of
    weight 7, in weightmap will represent it as

    graph[7] = {1, 3};

    This new data structure will greatly simplify calculations
    in kruskal's algorithm

    Nodes will be labeled 0, 1, 2 etc
    
    */

    /* Get the graph */

    map<int, array<int, 2>> graph;

    // Declare your graph here

    graph[3] = {0, 1};
    graph[2] = {0, 2};
    graph[5] = {0, 3};

    graph[4] = {1, 3};
    graph[7] = {1, 4};

    graph[6] = {2, 4};

    graph[8] = {3, 4};

    int no_of_nodes = 5;

    mcst_kruskal(graph, no_of_nodes);

}



