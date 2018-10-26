//
//  Route_container.hpp
//  Route_laba_1
//
//  Created by администратор on 13.10.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#ifndef Route_container_hpp
#define Route_container_hpp

#include <stdio.h>
#include <iostream>
#include "Route.hpp"
class Container{
    private:
        int size;
        Route **path=nullptr;
    public:
    Container();
    
    Container(int capacity);
    
    Container(Container &C);
    
    ~Container();
    
    void printPaths();
    
    int getSize();
    
    Route** getRoute();
    
    void routeSearch(Container &subC,int path);
    
    void deleteRoute(int serNumb);
    
    Container& operator +=(Route *way);
    
    Container& operator -=(Route *way);
    
};
#endif /* Route_container_hpp */
