//
//  main.cpp
//  assignment16
//
//  Created by Hui Zhou on 4/3/19.
//  Copyright © 2019 Hui Zhou. All rights reserved.
//

#include <iostream>
#include "Bank.hpp"
#include "SuperMarket.hpp"
#include <string>

//clang++ -std=c++17 main.cpp Bank.cpp SuperMarket.cpp -o a

int main(int argc, const char * argv[]) {
    Bank bank = Bank(std::stod(argv[1]),std::stod(argv[2]),std::stoi(argv[3]));
    bank.simulation();
    bank.printRes();
    
    SuperMarket supermarket = SuperMarket(std::stod(argv[1]),std::stod(argv[2]),std::stoi(argv[3]));
    supermarket.simulation();
    supermarket.printRes();
}
