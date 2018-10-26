//
//  Route_container.cpp
//  Route_laba_1
//
//  Created by администратор on 13.10.2018.
//  Copyright © 2018 Denisov Daniil. All rights reserved.
//

#include "Route_container.hpp"
#include "Route.hpp"
#include "Route_sorting.hpp"
Container::Container(){
    cout<<endl<<"default constructor Container class"<<endl;
    path=nullptr;
    size=0;
}

Container::Container(int capacity){
    cout<<endl<<"constructor with parameter Container class"<<endl;
    size=capacity;
    path=new Route*[size];
    for (int i=0;i<size;i++)
        path[i]=new Route;
    routeSorting(path, size);
}

Container::~Container(){
    cout<<endl<<"destructor Container class"<<endl;
    if(size!=0){
        size=0;
        delete [] path;
    }
}

Container::Container(Container &C){
    cout<<endl<<"constructor copying Container class"<<endl;
    this->size = C.size;
    this->path = C.path;
}

int Container::getSize(){return size;}

Route** Container::getRoute(){return path;}

void Container::routeSearch(Container &subC,int wantedPath){
for(int i=0; i<size; ++i){
    if(wantedPath==path[i][0].getRouteId()){
        subC+=path[i];
    }
}
}
void Container::deleteRoute(int serNumb){
    size--;
    Route **newPath = new Route*[size];
    int j=0;
    for(int i=0;i<size;i++){
        if(i==serNumb){
            j++;
        }
        newPath[i]=path[j];
        j++;
    }
    delete [] path;
    path=newPath;
}

Container& Container::operator +=(Route *way){
    Route **newPath = new Route*[size+1];
    for(int i=0;i<size;i++){
        newPath[i]=path[i];
    }
    newPath[size]=way;
    if(size!=0){
        delete [] path;
    }
    size++;
    path=newPath;
    if(size>1){
        routeSorting(path, size);
    }
    return *this;
}

Container& Container::operator -=(Route *way){
    for(int i=0;i<size;i++){
        if(path[i][0]==way[0]){
                if(size==1){
                    size--;
                    delete [] path;
                    path=nullptr;
                    return *this;
                }
            deleteRoute(i);
            return *this;
        }
    }
    cout<<endl<<"Sorry, there is no your Route"<<endl;
    return *this;
}

void Container::printPaths(){
    if(size!=0){
        cout<<endl<<"Routes:"<<endl;
        for(int i=0;i<size;i++){
            path[i][0].printRoute();
        }
    }
    else{
        cout<<endl<<"There is no Route with your number or there is no Routes at all"<<endl;
    }
}





