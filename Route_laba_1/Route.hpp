#ifndef Route_hpp
#define Route_hpp
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Route{
private:
    int routeId=0;
    string initialStop=" ";
    string endingStop=" ";
public:
    Route();
    
    Route(int ID, string initial, string ending);
    
    Route(Route &way);
    
    ~Route();
    
    int getRouteId();
    
    void setRoudeId();
    
    string getinitialStop();
    
    void setinitialStop();
    
    string getendingStop();
    
    void setendingStop();
    
    void printRoute();
    
    Route& operator = (Route &way);
    
    bool operator ==(const Route &way);
};
#endif /* Route_hpp */
