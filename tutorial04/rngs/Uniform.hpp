
#ifndef __Uniform_H__
#define __Uniform_H__

#include "AbstractRng.hpp"

namespace mixr {
namespace base { class Number; }
}

class Uniform: public AbstractRng
{
  DECLARE_SUBCLASS(Uniform, AbstractRng)

public:
  Uniform();

  virtual unsigned num() override;
  
  bool setMin(const double x)       { min = x; return true; }
  double getMin() const             { return min; }

  bool setMax(const double x)       { max = x; return true; }
  double getMax() const             { return max; }

private:
  double min {};
  double max {};

  bool setSlotMin(const mixr::base::Number* const);
  bool setSlotMax(const mixr::base::Number* const);
};

#endif
