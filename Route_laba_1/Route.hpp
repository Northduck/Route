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
    
    Route(const Route*);
    
    ~Route();
    
    int getRouteId();
    
    void setRoudeId();
    
    string getinitialStop();
    
    void setinitialStop();
    
    string getendingStop();
    
    void setendingStop();
    
    void printRoute();
    
    void setDefault();
    
    Route* operator = (Route &way);
};
#endif /* Route_hpp */
