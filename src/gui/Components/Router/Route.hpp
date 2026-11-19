#pragma once 
#include <unordered_map>
#include<string>
#include <FL/Fl_Group.H>
#include<iostream>
class Router{
    private:
     static inline std::unordered_map<std::string,Fl_Group*> routes;
    public:
     static inline Fl_Group* curView=nullptr;
    public:
     static inline void addRoute(const std::string& path,Fl_Group * group){
        group->hide();
        routes[path]=group;
     }
     static inline void navigate(const std::string & path){
        for(const auto & [name,route]: routes){
            if(name==path){
                curView->hide();
                route->show();
                curView=route;
            }
        }
        std::cout<<"Route not found"<<std::endl;
     }
};