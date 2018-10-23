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
#include "Route_search.hpp"
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
        free(path);
    }
}

Container::Container(Container*){
    cout<<endl<<"constructor copying Container class"<<endl;
    this->size = size;
    this->path = path;
}

void Container::setSize(){
    cout<<endl<<"Enter size of array Container class"<<endl;
    cin>>size;
}

int Container::getSize(){return size;}

Route** Container::getRoute(){return path;}

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

Container& Container::operator +=(Route *way1){
    Route **newPath = new Route*[size+1];
    for(int i=0;i<size;i++){
        newPath[i]=path[i];
    }
    newPath[size]=way1;
    if(size!=0){
        delete [] path;
    }
    size++;
    path=newPath;
    if(size>1){
        routeSorting(path, size);
    }
    printPaths(path);
    return *this;
}

Container& Container::operator -=(Route *way1){
    try{
        if(size<=0){
            throw 404;
        }
    }
    catch(int error){
        cout<<endl<<"Sorry, you can't delete element from empty array"<<endl;
        return *this;
    }
    bool isWay=false;
    for(int i=0;i<size;i++){
        int id=path[i][0].getRouteId();
        string firstRoute=path[i][0].getinitialStop();
        string secondRoute=path[i][0].getendingStop();
        if((id==way1[0].getRouteId())&&(firstRoute==way1[0].getinitialStop())&&(secondRoute==way1[0].getendingStop())){
            try{
                if(size==1){
                    throw 405;
                }
            }
            catch(int error){
                size--;
                delete [] path;
                path=nullptr;
                return *this;
            }
            deleteRoute(i);
            isWay=true;
            printPaths(path);
            return *this;
        }
    }
        if(!isWay){
            cout<<endl<<"Sorry, there is no your Route"<<endl;
        }
    return *this;
}

void Container::printPaths(Route **way){
    cout<<endl<<"Base of Routes:"<<endl;
    for(int i=0;i<size;i++){
        way[i][0].printRoute();
    }
}





