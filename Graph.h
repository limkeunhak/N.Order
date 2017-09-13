/*
* =====================================================================================
*
*       Filename:  Graph.h
*
*    Description:  
*
*        Version:  1.0
*        Created:  06/13/2017 06:40:34 PM
*       Revision:  none
*       Compiler:  g++
*
*         Author:  Keunhak Lim
*   Organization:  NECSST Lab. and co-work with BDSA Lab.
*
* =====================================================================================
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include"common.h"

#define NOT_ALLOCATED -1
#define ALLOCATED 0


using namespace std;

typedef int VertexId;

class Vertex{
private:
    VertexId id;
    VertexId newId;
    vector<VertexId> outNeighbors;
    bool flagIsOrdered;

public:
    Vertex(){
        this->id = NOT_ALLOCATED;
        this->newId = NOT_ALLOCATED;
        this->flagIsOrdered = false;
    }

    VertexId getId() const {
        return this->id;
    }

    VertexId getNewId() const {
        return this->newId;
    }

    void setId(VertexId id){
        this->id = id;
    }

    void setNewId(VertexId id){
        if(this->newId == ALLOCATED){
            return;
        }
        this->newId = id;
    }

    void setIsOrdered(){
        this->flagIsOrdered = true;
    }

    bool isOrdered(){
        return this->flagIsOrdered;
    }

    vector<VertexId>* getOutNeighbors(){
        return &this->outNeighbors;
    }

    void addOutNeighbor(VertexId neighborId){
        outNeighbors.push_back(neighborId);
    }

    int getDegree(){
        return outNeighbors.size();
    }
};

class Graph{
private:
    Vertex* vertices;
    const char* graphName;
    unsigned int numEdges;
    int maxVertexId;
    int numVertices;

public:

    Graph(char* graphName){
        vertices = new Vertex[70000000];
        this->graphName = graphName;
    }
    ~Graph(){
        delete vertices;
    }

    Vertex* getVertex(VertexId id){
        return &vertices[id];
    }

    int getMaxVertexId() const{
        return maxVertexId;
    }

    int getNumEdges() const {
        return numEdges;
    }

    int getNumVertices() const {
        return numVertices;
    }

    Vertex* getVertices() {
        return vertices;
    }

    void addEdge(VertexId source, VertexId dest);

    int graphLoading();

    int graphLoading(char* graphName){
        this->graphName = graphName;
        graphLoading();
    }

    void printGraph();

    void printExistingGraph();

    void printNewId();

    void createOutput();

};

#endif
