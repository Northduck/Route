//
//  Route_search.cpp
//  Route_laba_1
//
//  Created by администратор on 13.10.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Route_search.hpp"
#include <iostream>
#include <string>
#include "Route.hpp"
using namespace std;
void routeSearch(Route *array, int pathSize){
    bool isPath=false;
    int path;
    cout<<endl<<"Which Route do you want to find?"<<endl;
    cin>>path;
    for(int i=0; i<pathSize; ++i){
        if(path==array[i].getRouteId()){
            cout<<endl<<"There is the Route with your stop"<<endl;
            array[i].printRoute();
            isPath=true;
        }
    }
    if(!isPath){
        cout<<endl<<"There is no entered Route"<<endl;
    }

}
