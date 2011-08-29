//------------------------------------------------------------------------------
// Class:	TestCompass
// Base class:	Basic::Object > BasicGL::Graphic > BasicGL::Page -> TestCompass
//
// Description: This page will test the CompassRose
//------------------------------------------------------------------------------
#ifndef	__TestCompass_H__1C58872E_6D31_47e0_A66E_CA1C6B80EF7C
#define __TestCompass_H__1C58872E_6D31_47e0_A66E_CA1C6B80EF7C

#include "openeaagles/basicGL/Page.h"

namespace Eaagles {
namespace Mainz2 {

class TestCompass : public BasicGL::Page {
   DECLARE_SUBCLASS(TestCompass,BasicGL::Page)

public:
    TestCompass();
   
    // Basic::Component interface
    virtual void updateData(const LCreal dt = 0);
    virtual bool event(const int event, Basic::Object* const obj = 0);
    
    static const int MAX_TRACKS = 8;
    static const int MAX_AIRPORTS = 8;
    static const int MAX_NAV_AIDS = 8;
   
private:
    bool onToggleRangeTestCompass();
    bool onToggleCenteredTestCompass();
    bool onToggleViews();

    LCreal heading;             // our gauge position (inches)
    SendData headingSD;
    SendData headingCRSD;       // compass rose send data
    SendData headingBRGSD;      // our bearing's heading value
    SendData isCenteredCRSD;    // compass rose is centered flag
    SendData isCenteredBRGSD;   // bearing is centered flag
    LCreal  headingRate;        // rate which are going (up or down)
    LCreal bearing;             // goes to our bearing pointer
    SendData bearingBRGSD;
    SendData bearingROSD;
    LCreal bearingRate;
    SendData headingROSD;       // our heading readout
    LCreal range;               // our range
    SendData rangeSD;
    SendData rangeROSD;

    bool centered;
    SendData centeredSD;
    struct mySymbols {
        double     x;       // X position or latitude
        double     y;       // Y position or longitude
        LCreal     hdg;     // heading (degs)
        int       type;     // numeric type (for looking up in slottable)
        char     id[8];     // name of the airport (up to 8 characters)
    };

    // air track stuff
    mySymbols myTracks[MAX_TRACKS];     // holds our track data 
    bool tracksLoaded;                  // tracks have been loaded

    // airport stuff
    mySymbols myAP[MAX_AIRPORTS];       // holds our airport data 
    bool airportsLoaded;                // airports have been loaded

    // navaid stuff
    mySymbols myNA[MAX_NAV_AIDS];       // holds our navaid data 
    bool navAidsLoaded;                 // navaids have been loaded
};

} // end of Mainz2 namespace
} // end of Eaagles namespace

#endif	/* __TestCompass_H__1C58872E_6D31_47e0_A66E_CA1C6B80EF7C */

