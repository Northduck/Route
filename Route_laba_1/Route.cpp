#include "Route.hpp"
#include <string>
#include <iostream>
using namespace std;
Route::Route(){
    cout<<"default constructor";
    setRoudeId();
    setinitialStop();
    setendingStop();
}

Route::Route(int ID, string initial, string ending): routeId(ID), initialStop(initial), endingStop(ending){
    cout<<endl<<"constructor with parameter"<<endl;
}

Route::Route(const Route*){
    cout<<endl<<"constructor copying"<<endl;
    this->routeId = routeId;
    this->initialStop = initialStop;
    this->endingStop = endingStop;
}

Route::~Route(){
    cout<<endl<<"destructor"<<endl;
    routeId=0;
    initialStop="";
    endingStop="";
}

int Route::getRouteId(){return routeId;}

void Route::setRoudeId(){
    int id=0;
    cout<<"Enter route ID"<<endl;
    cin>>id;
    routeId=id;
}

string Route::getinitialStop(){return initialStop;}

void Route::setinitialStop(){
    cout<<"Enter initial stop"<<endl;
    cin>>initialStop;
}

string Route::getendingStop(){return endingStop;}

void Route::setendingStop(){
    cout<<"Enter ending stop"<<endl;
    cin>>endingStop;
}

void Route::printRoute(){
    cout<<getRouteId()<<endl;
    cout<<getinitialStop()<<endl;
    cout<<getendingStop()<<endl;
}

Route& Route::operator = (Route &way1){
    this->routeId=way1.routeId;
    this->initialStop=way1.initialStop;
    this->endingStop=way1.endingStop;
    return *this;
}

