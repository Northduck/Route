//
//  Route_swap.cpp
//  Route_laba_1
//
//  Created by администратор on 13.10.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Route_swap.hpp"
#include "Route.hpp"
#include <iostream>
void routeSwap(Route &path1, Route &path2){
    Route swapPath;
    swapPath=path1;
    path1=path2;
    path2=swapPath;
}
