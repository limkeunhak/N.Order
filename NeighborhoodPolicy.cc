/*
 * =====================================================================================
 *
 *       Filename:  NeighborhoodPolicy.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/03/2017 03:39:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "IdAllocator.h" 

int NeighborhoodPolicy::allocateId(Graph* graph){
    int vid = 0;
    long maxId = graph->getMaxVertexId();
    while(vid < maxId +1){
        Vertex* sourceVertex = graph->getVertex(vid);
        if(sourceVertex->getId() == NOT_ALLOCATED){
            vid++;
            continue;
        }

        if(sourceVertex->getNewId() == NOT_ALLOCATED){
            sourceVertex->setNewId(this->idGenerator.createNewId());
        }

        vector<VertexId>::iterator it = sourceVertex->getOutNeighbors()->begin();
        while(it != sourceVertex->getOutNeighbors()->end()){
            allocateNeighborsId(graph,*it);
            it++;
        }
        vid++;
    }
}

void NeighborhoodPolicy::allocateNeighborsId(Graph* graph, int onehopVertexId){
    Vertex* onehopVertex = graph->getVertex(onehopVertexId);
    if(onehopVertex->isOrdered()){
        return;
    }

    if(onehopVertex->getNewId() == NOT_ALLOCATED){
        onehopVertex->setNewId(this->idGenerator.createNewId());
    }

    vector<VertexId>::iterator it = onehopVertex->getOutNeighbors()->begin();
    while(it != onehopVertex->getOutNeighbors()->end()){
        if(graph->getVertex(*it)->getNewId() == NOT_ALLOCATED){
            graph->getVertex(*it)->setNewId(this->idGenerator.createNewId());
            it++;
            continue;
        }
        it++;
    }
    onehopVertex->setIsOrdered();
}

