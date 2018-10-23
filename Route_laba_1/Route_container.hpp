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
    
    Container(Container*);
    
    ~Container();
    
    void printPaths(Route **way);
    
    void setSize();
    
    int getSize();
    
    
    Route** getRoute();
    
    void deleteRoute(int serNumb);
    
    Container& operator +=(Route *way1);
    
    Container& operator -=(Route *way1);
};
#endif /* Route_container_hpp */
