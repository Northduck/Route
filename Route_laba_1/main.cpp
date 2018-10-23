#include <iostream>
#include "Route.hpp"
#include "Route_container.hpp"
#include "Route_search.hpp"
#include "Route_sorting.hpp"
using namespace std;
int main() {
    int el=0;
    int routeCapacity=0;
    cout<<"How much routes do you want to enter?"<<endl;
    cin>>routeCapacity;
    Container c(routeCapacity);
    c.printPaths(c.getRoute());
    cout<<"1 is for searching the route; 2 is for += or --; 3 is for print routes"<<endl;
    cin>>el;
    while(el!=0){
        switch (el){
            case 1:{
                routeSearch(c.getRoute(), c.getSize());
                break;
            }
            case 2:{
                int op;
                Route *way1=new Route;
                cout<<"1 is for +=; 2 is for --"<<endl;
                cin>>op;
                switch (op){
                    case 1:{
                        c+=way1;
                        break;
                    }
                    case 2:{
                        c-=way1;
                        break;
                    }
                }
                delete way1;
                break;
            }
            case 3:{
                c.printPaths(c.getRoute());
                break;
            }
        }
        
        cout<<"1 is for searching the route; 2 is for += or --; 3 is for print routes"<<endl;
        cin>>el;
    }
    return 0;
}
