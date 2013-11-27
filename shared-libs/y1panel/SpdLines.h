//------------------------------------------------------------------------------
// Class: SpdLines
//------------------------------------------------------------------------------
#ifndef __SpdLines_D6B294BE_63BB_49b0_AF1B_009579C47AB2
#define __SpdLines_D6B294BE_63BB_49b0_AF1B_009579C47AB2

#include "openeaagles/basicGL/Graphic.h"

namespace Eaagles {
namespace Y1 {

//------------------------------------------------------------------------------
// Class: SpdLines
// 
// Description: Draws the lines for the airspeed graphic
// Inputs:
//      UPDATE_VALUE  -> altitude flag on or off
//------------------------------------------------------------------------------
class SpdLines : public BasicGL::Graphic
{
    DECLARE_SUBCLASS(SpdLines,BasicGL::Graphic)
    
public:
    SpdLines();
    
    // set functions
    virtual bool setIsAlt(const bool newIsAlt) { isAlt = newIsAlt; return true; }
    
    // get functions
    bool isAltSelected()    { return isAlt; }
    
    // BasicGL::Graphic interface
    virtual void drawFunc();
    
    // Basic::Component interface
    virtual bool event(const int event, Basic::Object* const obj = 0);
    
protected:
    bool setSlotIsAlt(const Basic::Number* newIsAlt);
    
private:
    // event function
    bool onEventSetIsAltSpdLines(const Basic::Number* const x);
    
    bool isAlt;     // are we drawing the altitude lines instead?
};

} // End Y1 namespace
} // End Eaagles namespace

#endif
