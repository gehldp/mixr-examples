#include "TestRpmDial.h"

namespace Eaagles {
namespace Mainz2 {

IMPLEMENT_EMPTY_SLOTTABLE_SUBCLASS(TestRpmDial,"TestRpmDial")
EMPTY_SERIALIZER(TestRpmDial)

//------------------------------------------------------------------------------
// Constructor(s)
//------------------------------------------------------------------------------
TestRpmDial::TestRpmDial()
{
    STANDARD_CONSTRUCTOR()
    rpm = 0;
    rpmRate = 10;
    rpmSD.empty();
    rpmROSD.empty();
}


//------------------------------------------------------------------------------
// copyData()
//------------------------------------------------------------------------------
void TestRpmDial::copyData(const TestRpmDial& org, const bool)
{
    BaseClass::copyData(org);
    rpm = org.rpm;
    rpmRate = org.rpmRate;
    rpmSD.empty();
    rpmROSD.empty();
}

EMPTY_DELETEDATA(TestRpmDial)


//------------------------------------------------------------------------------
// updateData() -- update non time-critical stuff here
//------------------------------------------------------------------------------
void TestRpmDial::updateData(const LCreal dt)
{
    BaseClass::updateData(dt);
    
    rpm += (rpmRate * dt);
    if (rpm > 110) {
        rpm = 110;
        rpmRate = -rpmRate;
    }
    if (rpm < 0) {
        rpm = 0;
        rpmRate = -rpmRate;
    }
                        
    send("rpm", UPDATE_INSTRUMENTS, rpm, rpmSD);
    send("rpmRO", UPDATE_VALUE, rpm, rpmROSD);
}

} // end of Mainz2 namespace
} // end of Eaagles namespace
