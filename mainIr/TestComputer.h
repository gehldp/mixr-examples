//------------------------------------------------------------------------------
// Class: TestComputer
//
// Description:
//    Onboard computer for IrMissile, provides basic functionality
//    Controls a TrackManager, IrSensor, & IrSeeker.
//    Updates gimbal to point at predicted az/el of strongest signal in IFOV
//    Provides these methods in public i/f mainly for IrMissile
//       haveTgt()   true if computer/seeker currently tracking a target
//
//------------------------------------------------------------------------------
#ifndef __oe_example_TestComputer_H__
#define __oe_example_TestComputer_H__

#include "openeaagles/simulation/OnboardComputer.h"

namespace oe {
namespace example {

class TestComputer : public simulation::OnboardComputer
{
    DECLARE_SUBCLASS(TestComputer, simulation::OnboardComputer)

public:
   TestComputer();
   bool haveTgt() const { return haveTarget; }

   virtual void updateShootList(const bool step = false) override;      // Updates the shoot list

   virtual void updateTC(const double dt = 0.0) override;

   virtual void reset() override;

protected:
   // process() subfunction, tells computer if we are tracking a target or not
   virtual bool processIr();

   virtual void process(const double dt) override;

private:
   bool uncaged;      // flag that indicates whether gimbal is free to track target
   bool haveTarget;   // flag indicating if we have a target track
};

} // End example namespace
} // End oe namespace

#endif


