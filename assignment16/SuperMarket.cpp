//
//  SuperMarket.cpp
//  assignment16
//
//  Created by Hui Zhou on 4/4/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#include "SuperMarket.hpp"

#include <queue>
#include <iostream>

void SuperMarket::simulation() {
    double period = 60 / this->arrivingRate;
    int i = 0;
    while (i * period <= MAX_SIM_LENGTH) {

        customer c = {0};
        c.arrivingTime = rand() % 60 + i * period;
        c.serviceTime = rand() % ((unsigned int) this->maxServiceTime * 60 + 1);

        //        std::cout<<"arriving at: "<<c.arrivingTime<<" "<<"service time: "<<c.serviceTime<<std::endl;

        double nearestCompleteTime = this->workingCashiers.top().completeTime;

        cashier cashierUpdated = {0};
        if (nearestCompleteTime <= c.arrivingTime) {
            cashierUpdated.completeTime = c.arrivingTime + c.serviceTime;
            c.waitingTime = 0;
        } else {
            cashierUpdated.completeTime = nearestCompleteTime + c.serviceTime;
            c.waitingTime = nearestCompleteTime - c.arrivingTime;
            //            std::cout<< "total service time: "<<c.waitingTime<<std::endl;
        }
        if (cashierUpdated.completeTime <= MAX_SIM_LENGTH) {
            this->workingCashiers.pop();
            this->workingCashiers.push(cashierUpdated);
            this->history.push_back(c.serviceTime + c.waitingTime);
            //            std::cout<< "total service time: "<<c.waitingTime<<std::endl;
        }
        i++;
    }
}