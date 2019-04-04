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

SuperMarket::SuperMarket(double arrivingRate, double maxServiceTime, int seed){
    this->arrivingRate = arrivingRate;
    this->maxServiceTime = maxServiceTime;
    std::srand(seed);
    for (int i = 0; i < 6; i++){
        cashier c= {0};
        c.completeTime = 0;
        this->workingCashiers.push(c);
    }
};

void SuperMarket::simulation(){
    double period = 60/this->arrivingRate;
    int i = 0;
    while( i*period <= 12*60*60){
        
        customer c = {0};
        c.arrivingTime = rand()%60 + i*period;
        c.serviceTime = rand()%((unsigned int)this->maxServiceTime*60+1);
        
        //        std::cout<<"arriving at: "<<c.arrivingTime<<" "<<"service time: "<<c.serviceTime<<std::endl;
        
        double nearestCompleteTime = this->workingCashiers.top().completeTime;
        
        cashier cashierUpdated = {0};
        if (nearestCompleteTime <= c.arrivingTime){
            cashierUpdated.completeTime = c.arrivingTime + c.serviceTime;
            c.waitingTime = 0;
        }else{
            cashierUpdated.completeTime = nearestCompleteTime + c.serviceTime;
            c.waitingTime = nearestCompleteTime - c.arrivingTime;
            //            std::cout<< "total service time: "<<c.waitingTime<<std::endl;
        }
        if (cashierUpdated.completeTime <= 12*60*60){
            this->workingCashiers.pop();
            this->workingCashiers.push(cashierUpdated);
            this->history.push_back(c.serviceTime+c.waitingTime);
            //            std::cout<< "total service time: "<<c.waitingTime<<std::endl;
        }
        i++;
    }
}

void SuperMarket::printRes(){
    
    std::sort(this->history.begin(), this->history.end(), sort_using_smaller_than);
    
    std::cout<<"SuperMarket service times in minutes: 10th %ile "<< this->history[this->history.size()*0.1] << ", 50th %ile "<< this->history[this->history.size()*0.5] <<", 90th %ile "<< this->history[this->history.size()*0.9] <<std::endl;
    
}
