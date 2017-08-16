
#ifndef __Rng_H__
#define __Rng_H__

#include "mixr/base/Object.hpp"

#include <random>

//------------------------------------------------------------------------------
// Class: Rng
// Description: Generates random numbers
//------------------------------------------------------------------------------
class Rng : public mixr::base::Object
{
   DECLARE_SUBCLASS(Rng, mixr::base::Object)

public:
   Rng();

   unsigned num();
   unsigned min() const   { return engine.min(); }
   unsigned max() const   { return engine.max(); }

   void setSeed(const unsigned int);

private:
   // mersenne twister algoithm used to produce random integer
   // values, uniformly distributed from [min(), max()] 
   std::mt19937 engine;
   std::uniform_int_distribution<> dist;
};

#endif
