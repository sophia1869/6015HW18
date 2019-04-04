//
//  Bank.hpp
//  assignment16
//
//  Created by Hui Zhou on 4/3/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include <stdio.h>
#include <queue>

class Bank{
public:
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
    double arrivingRate;
    double maxServiceTime;
    Bank(double arrivingRate, double maxServiceTime, int seed);
    void simulation();
    void printRes();
    
    static bool sort_using_smaller_than(double u, double v){
        return u < v;
    }
    
};


#endif /* Bank_hpp */
