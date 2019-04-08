//
//  SuperMarket.hpp
//  assignment16
//
//  Created by Hui Zhou on 4/4/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#ifndef SuperMarket_hpp
#define SuperMarket_hpp

#include "Store.h"
#include <stdio.h>
#include <queue>

class SuperMarket : public Store {
public:
    SuperMarket(double arrivingRate, double maxServiceTime, int seed) : Store(arrivingRate, maxServiceTime, seed) {};

    void simulation();
};


#endif /* SuperMarket_hpp */
