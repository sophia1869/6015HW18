//
//  SuperMarket.hpp
//  assignment16
//
//  Created by Hui Zhou on 4/4/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#ifndef SuperMarket_hpp
#define SuperMarket_hpp

#include <stdio.h>
#include <queue>

class SuperMarket{
public:
    SuperMarket(double arrivingRate, double maxServiceTime, int seed);
    double arrivingRate;
    double maxServiceTime;
    struct customer{
        double arrivingTime;
        double serviceTime;
        double waitingTime;
    };
    
    struct cashier{
        double completeTime;
    };
    
    struct cashierCompleteTimeCmp{
        bool operator()(const cashier&lhs, const cashier&rhs){
            return rhs.completeTime < lhs.completeTime;
            // c++ priority queue is bigger one is in front; so in normal situation,
            // pop() gives largest element. so this comparator is reversed.
        }
    };
    
    std::priority_queue<cashier, std::vector<cashier>, cashierCompleteTimeCmp> workingCashiers;
    std::vector<double> history;
    void simulation();
    void printRes();
    static bool sort_using_smaller_than(double u, double v){
        return u < v;
    }
};


#endif /* SuperMarket_hpp */
