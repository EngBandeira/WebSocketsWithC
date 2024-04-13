#include <iostream>
struct a
{
    int *point;
    int batataa(int k){
        std::cout << k << '\n';
    }
    a(int size){
        point = (int*)malloc(size*sizeof(int));
    }
    ~a(){
        free(point);
    }
};
