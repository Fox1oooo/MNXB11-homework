#include "my_class.h"
#include <iostream>
#include <cmath>

ClassImp(my_class)

momentum::momentum() : px(0), py(0), pz(0){}


momentum::momentum(Int_t x_value, Int_t y_value, Int_t z_value)
    : px(x_value), py(y_value), pz(z_value){   
}

// destructor 
momentum::~momentum(){
// right now i'm empty
}

Int_t momentum::Magnitude() const{
    return std::sqrt(px*px + py*py + pz*pz);
}

