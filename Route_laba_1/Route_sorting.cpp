//
//  Route_sorting.cpp
//  Route_laba_1
//
//  Created by администратор on 13.10.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Route_sorting.hpp"
#include "Route.hpp"
#include <iostream>
#include "Route_swap.hpp"
Route& routeSorting(Route *array, int arrSize) {
    int iPath=0, minPath=0;
    for (int i = 0; i < arrSize - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arrSize; j++) {
            iPath=array[j].getRouteId();
            minPath=array[min].getRouteId();
            if (iPath<minPath){
                min = j;
            }
        }
        
        if (min != i) {
            routeSwap(array[i], array[min]);
            min = i;
        }
    }
    return *array;
}
