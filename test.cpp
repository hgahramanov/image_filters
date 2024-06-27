#include "greyscale.h"

template <typename T> 
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) { 
    os << "[";
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << " "; 
    }
    os << "]" << std::endl << std::endl;
    return os; 
}

int main(){
   GreyScale pic(10, 10);
   GreyScale pic2(10, 10);
   pic = 5;
   pic2 = 9;
   pic+=pic2;
   std::cout<<(pic).pixels<<std::endl;
   pic.linTrans(0, 2);
   std::cout<<(pic).pixels<<std::endl;
   pic.resize(3, 3);
   std::cout<<(pic).pixels<<std::endl;
   pic+=3;
   std::cout<<(pic).pixels<<std::endl;
   pic.resize(10, 10);
   std::cout<<pic(0, 9)<<"\n";
   std::cout<<pic(1, 0)<<"\n";
   return 0;

}
