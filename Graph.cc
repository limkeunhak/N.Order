/*
 * =====================================================================================
 *
 *       Filename:  Graph.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/13/2017 02:52:19 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Keunhak Lim 
 *   Organization:  NECSST Lan. and co-work with BDSA Lab.
 *
 * =====================================================================================
 */

#include"common.h"
#include"Graph.h"

void Graph::addEdge(VertexId source, VertexId dest){
    this->vertices[source].setId(source);
    this->vertices[dest].setId(dest);
    this->vertices[source].addOutNeighbor(dest);
}

int Graph::graphLoading(){
    if(this->graphName == NULL){
        cout << "There is no graph" << endl;
        return 1;
    }

    ifstream infile;
    infile.open(this->graphName, ios::in);

    if(!infile.is_open()){
        return 1;
    }

    cout << "Graph name: " << this->graphName << endl;

    char source[100];
    char dest[100];
    struct timespec start, end;

    /*
     * Start graph loading
     */
    if(clock_gettime(CLOCK_MONOTONIC, &start) == -1){
        cout << "time measuring error" << endl;
    }
    unsigned int count = 0;
    int maxId = -1;
    while(infile >> source >> dest){
        if(atoi(source) > maxId){
            maxId = atoi(source);
            if(atoi(dest) > maxId){
                maxId = atoi(dest);
            }
        }

        addEdge(atoi(source), atoi(dest));
        count++;
    }

    if(clock_gettime(CLOCK_MONOTONIC, &end) == -1){
        cout << "time measuring error" << endl;
    }
    this->numEdges = count - 1UL;
    this->maxVertexId = maxId;;
    cout << "Max Vertex Id: " << this->maxVertexId << endl;
    cout << "Num edges: " << this->numEdges << endl;
    cout << "Loading time: " << end.tv_sec - start.tv_sec << "Sec" << endl;
    infile.close();

    return 0;
}

void Graph::printGraph(){

   int id = 0;
   ofstream graphOutput("output");
   cout << "Output reordered graph...\n";
    // output
    while(id < getMaxVertexId()+1){
        vector<VertexId>::iterator it = this->vertices[id].getOutNeighbors()->begin();
        while(it != this->vertices[id].getOutNeighbors()->end()){
            graphOutput << this->vertices[id].getNewId() << " " << this->vertices[*it].getNewId();
            graphOutput << endl;
            it++;
        }
        id++;
    }
    cout << "Complete neighborhood order" << endl;;
    graphOutput.close();
}

void Graph::printExistingGraph(){

   int id = 0;
   ofstream graphOutput("output");
   cout << "Output reordered graph...\n";
    // output
    while(id < getMaxVertexId()+1){
        vector<VertexId>::iterator it = this->vertices[id].getOutNeighbors()->begin();
        while(it != this->vertices[id].getOutNeighbors()->end()){
            graphOutput << this->vertices[id].getId() << " " << this->vertices[*it].getId();
            graphOutput << endl;
            it++;
        }
        id++;
    }
    cout << "Complete neighborhood order" << endl;;
    graphOutput.close();
}

void Graph::printNewId(){
   int cnt = 0;
    cout << "-----Print id mapping table-----" << endl;
  while(cnt < getMaxVertexId()+1){
      cout<< this->vertices[cnt].getId() << " " << this->vertices[cnt].getNewId() << endl;
      cnt++;
  }
}

void Graph::createOutput(){

}

