#include <vector>
#include <inttypes.h>

template<typename T1,typename T2>
class Buffer{
    public:
    Buffer(){};
    void push(T1 input){
        img.push_back(input);
    }
    void push(T1 input_1,T2* input_2 ){
        img.push_back(input_1);
        odom=input_2;
    }
    void push(T1 input_1,T1 input_2){
        img.push_back(input_1);
        img.push_back(input_2);
    }
    void push(T1 input_1,T1 input_2,T2* input_3 ){
        img.push_back(input_1);
        img.push_back(input_2);
        odom=input_3;
    }
    std::vector<T1>* read(){
        return &img;
    }
    T2* read_odom(){
        return odom;
    }
    int64_t time(){
        return t;
    }
    std::pair<std::size_t,int64_t> config(){
        return std::pair<std::size_t,int64_t>(img.size(),t);
    }
    private:
    std::vector<T1> img;
    T2* odom=nullptr;
    int64_t t=0;
};
