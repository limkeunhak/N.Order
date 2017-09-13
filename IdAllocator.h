/*
 * =====================================================================================
 *
 *       Filename:  IdAllocator.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/2017 10:12:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _ID_ALLOCATOR_H_
#define _ID_ALLOCATOR_H_

#include "common.h" 
#include "Graph.h"
#include "IdGenerator.h"

class Policy{
public:
    virtual int allocateId(Graph* graph) = 0;
};

class NeighborhoodPolicy: public Policy{
private:
    IdGenerator idGenerator;
    int numAlloc;
public:
    NeighborhoodPolicy(){
        this->numAlloc = 0;
    }

    virtual int allocateId(Graph* graph);

    void allocateNeighborsId(Graph* graph, int onehopVertexId);

};

class IdAllocator{
private:
    Policy* policy;

public:
    IdAllocator(Policy* policy){
        this->policy = policy;
    }

    void modifyPolicy(Policy* newPolicy){
        this->policy = newPolicy;
    }

    int allocateId(Graph* graph){
        return policy->allocateId(graph);
    }
};
#endif
