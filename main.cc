/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/2017 10:54:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "common.h"
#include "IdAllocator.h"
#include "IOcost.h"


int main(int argc, char* argv[]){

    char* graphfile = argv[1];
    Graph* graph = new Graph(graphfile);
    graph->graphLoading();

    IdAllocator* alloc;
    NeighborhoodPolicy* policy = new NeighborhoodPolicy();

    alloc = new IdAllocator(policy);

    struct timespec start, end;
    if(clock_gettime(CLOCK_MONOTONIC, &start) == -1){
        cout << "time measuring error" << endl;
    }
    alloc->allocateId(graph);
     if(clock_gettime(CLOCK_MONOTONIC, &end) == -1){
        cout << "time measuring error" << endl;
    }
      cout << "Ordering time: " << end.tv_sec - start.tv_sec << "sec" << endl;

    graph->printGraph();
    

    return 0;
}
