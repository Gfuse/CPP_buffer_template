#include "buffer.hpp"
#include <iostream>
#include <string>
#include <uchar.h>

int main(){
    Buffer<std::pair<u_char*,u_char*>,double> buffer[10];
    for(uint i=0;i<10;++i){
        u_char * depth = (u_char *)calloc(static_cast<std::size_t>(10*10 * 2), sizeof(u_char));
        u_char * left = (u_char *)calloc(static_cast<std::size_t>(10*10* 3), sizeof(u_char));
        buffer[i].push(std::pair<u_char*,u_char*>(depth,left));
    }
    for(uint i=0;i<10;++i){
        std::cerr<<buffer[i].config().first<<' '<<buffer[i].config().second<<'\n';
        for(auto n:*buffer[i].read())free(n.first);
        buffer[i].read()->clear();
        std::cerr<<buffer[i].config().first<<' '<<buffer[i].config().second<<'\n';
    }
    for(uint i=0;i<10;++i){
        u_char * depth = (u_char *)calloc(static_cast<std::size_t>(10*10 * 2), sizeof(u_char));
        u_char * left = (u_char *)calloc(static_cast<std::size_t>(10*10* 3), sizeof(u_char));
        u_char * depth1 = (u_char *)calloc(static_cast<std::size_t>(10*10 * 2), sizeof(u_char));
        u_char * left1 = (u_char *)calloc(static_cast<std::size_t>(10*10* 3), sizeof(u_char));
        double* newOdom = (double *)calloc(static_cast<std::size_t>(7), sizeof(double));
        buffer[i].push(std::pair<u_char*,u_char*>(depth,left),std::pair<u_char*,u_char*>(depth1,left1),newOdom);
    }
    std::cerr<<"--------------------"<<'\n';
    for(uint i=0;i<10;++i){
        std::cerr<<buffer[i].config().first<<' '<<buffer[i].config().second<<'\n';
        for(auto n:*buffer[i].read()){
            free(n.first);
            free(n.second);
        }
        free(buffer[i].read_odom());
        buffer[i].read()->clear();
        std::cerr<<buffer[i].config().first<<' '<<buffer[i].config().second<<'\n';
    }
}
