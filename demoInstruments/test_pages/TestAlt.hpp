
#ifndef __TestAlt_H__
#define __TestAlt_H__

#include "mixr/graphics/Page.hpp"

//------------------------------------------------------------------------------
// Class: TestAlt
//
// Description: Tests our altitude tape instrument
//------------------------------------------------------------------------------
class TestAlt : public mixr::graphics::Page
{
   DECLARE_SUBCLASS(TestAlt, mixr::graphics::Page)

public:
    TestAlt();

    virtual void updateData(const double dt = 0) override;

private:
    double alt {};             // our altitude (feet)
    SendData altSD;
    double  altRate {500.0};   // rate which are going (up or down)
    SendData altROSD;
};

#endif
