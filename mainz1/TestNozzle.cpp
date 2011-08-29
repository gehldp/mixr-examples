#include "TestNozzle.h"

namespace Eaagles {
namespace Mainz1 {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TestNozzle,"TestNozzle")
EMPTY_SERIALIZER(TestNozzle)

//------------------------------------------------------------------------------
// Constructor(s)
//------------------------------------------------------------------------------
TestNozzle::TestNozzle()
{
    STANDARD_CONSTRUCTOR()
    nozPos = 0;
    nozPosSD.empty();
    nozRate = 5;
    nozPosROSD.empty();
}


//------------------------------------------------------------------------------
// copyData()
//------------------------------------------------------------------------------
void TestNozzle::copyData(const TestNozzle& org, const bool)
{
    BaseClass::copyData(org);
    nozPos = org.nozPos;
    nozPosSD.empty();
    nozRate = org.nozRate;
    nozPosROSD.empty();
}

EMPTY_DELETEDATA(TestNozzle)


//------------------------------------------------------------------------------
// updateData() -- update non time-critical stuff here
//------------------------------------------------------------------------------
void TestNozzle::updateData(const LCreal dt)
{
    BaseClass::updateData(dt);
    
    nozPos += (nozRate * dt);
    if (nozPos > 100) {
        nozPos = 100;
        nozRate = -nozRate;
    }
    if (nozPos < 0) {
        nozPos = 0;
        nozRate = -nozRate;
    }

    // send the data down                        
    send("noz", UPDATE_INSTRUMENTS, nozPos, nozPosSD);
    send("nozRO", UPDATE_VALUE, nozPos, nozPosROSD);
}

} // end of Mainz1 namespace
} // end of Eaagles namespace
