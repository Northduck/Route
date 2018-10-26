#include "Route.hpp"
#include <string>
#include <iostream>
using namespace std;
Route::Route(){
    cout<<endl<<"default constructor Route class"<<endl;
    setRoudeId();
    setinitialStop();
    setendingStop();
}

Route::Route(int ID, string initial, string ending): routeId(ID), initialStop(initial), endingStop(ending){
    cout<<endl<<"constructor with parameter Route class"<<endl;
}

Route::Route(Route &way){
    cout<<endl<<"constructor copying Route class"<<endl;
    this->routeId = way.routeId;
    this->initialStop = way.initialStop;
    this->endingStop = way.endingStop;
}

Route::~Route(){
    cout<<endl<<"destructor Route class"<<endl;
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
    cout<<endl<<"Id of the route is: "<<getRouteId()<<endl;
    cout<<endl<<"Initial stop of the route is: "<<getinitialStop()<<endl;
    cout<<endl<<"Ending stop of the route is: "<<getendingStop()<<endl<<endl;
}

Route& Route::operator = (Route &way){
    this->routeId = way.routeId;
    this->initialStop = way.initialStop;
    this->endingStop = way.endingStop;
    return *this;
}
bool Route::operator ==(const Route &way){
    return this->routeId==way.routeId && this->initialStop==way.initialStop && this->endingStop==way.endingStop;
}
