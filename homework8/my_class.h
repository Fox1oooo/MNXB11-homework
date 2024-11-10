#ifndef __MY__CLASS__H__
#define __MY__CLASS__H__

#include <TObject.h> 
#include <iostream>
#include <cmath>


class momentum: public TObject {
    public:
        Int_t px, py, pz;
        momentum(); 
        momentum(Int_t px, Int_t py, Int_t pz);

        virtual ~momentum();

        Int_t Magnitude() const;

    private:
        
        ClassDef(momentum, 1); // your_class
    };



#endif // __MY__CLASS__H__