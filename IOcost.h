
#include "Graph.h"
#include "common.h"

class IOCostCalculator{
    private:
        vector<VertexId>* vec;
        long sum;

    public:
        void set(vector<VertexId>* neighborList){
            vec = neighborList;
            sum = 0;
            for(vector<VertexId>::iterator start = vec->begin(); start<vec->end(); start++){
                sum += *start;
            }
        }
        double calcMean(){
            return sum/vec->size();
        }

        double calcVar(vector<VertexId>* target){
            cout << "calcVar" << endl;
            if(vec->size() == 0)
                return 0;

            double avg = calcMean();
            double total = 0;
            for(vector<VertexId>::iterator start = vec->begin(); start < vec->end(); start++){
                total += pow(avg - *start, 2);
            }
            return total/vec->size();
        }
        double calcStd(vector<VertexId>* target){
            return sqrt(calcVar(target));
        }

        double getIOcost(Graph* graph){
            cout << "getIOcost" << endl;
		    double total = 0 ;
            int id = 0;
            while(id < graph->getMaxVertexId() +1){
                if(graph->getVertices()[id].getId() != -1)
                    total += calcStd(graph->getVertices()[id].getOutNeighbors());
            }
            return total / (double)graph->getMaxVertexId();
        }

};
