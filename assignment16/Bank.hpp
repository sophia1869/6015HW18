//
//  Bank.hpp
//  assignment16
//
//  Created by Hui Zhou on 4/3/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp

#include "Store.h"
#include <stdio.h>
#include <queue>

class Bank : public Store {
public:
    Bank(double arrivingRate, double maxServiceTime, int seed) : Store(arrivingRate, maxServiceTime, seed){};
    void simulation();
};


#endif /* Bank_hpp */
