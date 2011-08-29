//------------------------------------------------------------------------------
// Class:	Pfd
// Base class:	... -> BasicGL::Page -> Pfd
//
// Description:	Tests the pfd.
//------------------------------------------------------------------------------
#ifndef	__Pfd_H_37E8E713_43E9_4103_88DB_787151FC0E13
#define __Pfd_H_37E8E713_43E9_4103_88DB_787151FC0E13

#include "openeaagles/basicGL/Page.h"
#include "openeaagles/basic/units/Angles.h"

namespace Eaagles {
namespace Mainy1 {

class Pfd : public BasicGL::Page {
   DECLARE_SUBCLASS(Pfd,BasicGL::Page)

public:
    Pfd();  

    enum { NCHAR_NAV1_ID = 3, NCHAR_NAV2_ID = 5 };
      
    // set functions
    virtual bool setPitchDeg(const LCreal newP);        // Sets pitch angle (degs) 
    virtual bool setPitchRad(const LCreal newP);        // Sets pitch angle (rads)
    virtual bool setRollDeg(const LCreal newR);         // Sets roll angle (degs)
    virtual bool setRollRad(const LCreal newR);         // Sets roll angle (rads)
    virtual bool setTrueHeading(const LCreal newTH);    // Sets true heading angle (degs)
    virtual bool setCmdHdg(const LCreal newCH);         // Sets commanded heading (degs)
    virtual bool setAirSpeedKts(const LCreal newAS);    // Sets airspeed (kts)
    virtual bool setCmdAirSpdKts(const LCreal newCAS);  // Sets commanded airspeed (kts)
    virtual bool setAltitudeFt(const LCreal newA);      // Sets pressure altitude (ft)
    virtual bool setCmdAltFt(const LCreal newCA);       // Sets comanded altitude (ft)
    virtual bool setGlideslope(const LCreal newGS);     // Sets glide slope deviation (dots)
    virtual bool setLatDev(const LCreal newLD);         // Sets localizer deviation (dots)
    virtual bool setVVI(const LCreal newVVI);           // Sets vertical velocity (ft/min)
    virtual bool setSideSlip(const LCreal newSS);       // Sets side slip (degs)
    virtual bool setFltDirBankDeg(const LCreal newFDB); // Sets flight directory commanded bank (deg)
    virtual bool setFltDirPitchDeg(const LCreal newFDP);// Sets flight director commanded pitch (deg)
    virtual bool setFltDirBankRad(const LCreal newFDB); // Sets flight directory commanded bank (rad)
    virtual bool setFltDirPitchRad(const LCreal newFDP);// Sets flight director commanded pitch (rad)
    virtual bool setBaroPress(const LCreal newBOP);     // Sets baro pressure (inches)
    virtual bool setRefLat(const double newRL);         // reference latitude 
    virtual bool setRefLon(const double newRL);         // reference longitude 
    virtual bool setRange(const LCreal newR);           // range 
    virtual bool setGLoad(const LCreal newLoad);        // our g load
    virtual bool setMach(const LCreal x);               // machine speed    

    // get functions
    LCreal getPitchDeg()            { return pitch; }
    LCreal getPitchRad()            { return (LCreal)(pitch * Basic::Angle::D2RCC); }
    LCreal getRollDeg()             { return roll; }
    LCreal getRollRad()             { return (LCreal)(roll * Basic::Angle::D2RCC); }
    LCreal getTrueHdg()             { return trueHdg; }
    LCreal getCmdHdg()              { return cmdHdg; }
    LCreal getAirSpdKts()           { return airSpd; }
    LCreal getCmdAirSpdKts()        { return cmdSpd; }
    LCreal getAltFeet()             { return alt; }
    LCreal getCmdAltFeet()          { return cmdAlt; }
    LCreal getGlideSlope()          { return gSlope; }
    LCreal getLatDev()              { return latDev; }
    LCreal getVVI()                 { return vvi; }
    LCreal getSideSlip()            { return slip; }
    LCreal getFltDirBankDeg()       { return fDirBank; }
    LCreal getFltDirBankRad()       { return (LCreal)(fDirBank * Basic::Angle::R2DCC); }
    LCreal getFltDirPitchDeg()      { return fDirPitch; }
    LCreal getFltDirPitchRad()      { return (LCreal)(fDirPitch * Basic::Angle::R2DCC); }
    LCreal getBaroPressure()        { return baro; }
    double getRefLat()              { return refLat; }
    double getRefLon()              { return refLon; }
    LCreal getRange()               { return range; }
    LCreal getGLoad()               { return gLoad; }
    LCreal getMach()                { return mach; }
    
    
    // Component interface
    virtual void updateData(const LCreal dt = 0.0);

private:
    // pitch and roll
    LCreal pitch;           // Pitch angle (degs)
    SendData pitchSD;
    SendData hdgPitchSD;    // heading pitch for the heading tape
    LCreal roll;            // Roll angle (degs)
    SendData rollSD;
    
    // bank angle
    SendData baSD;
    SendData bascaleSD;
    
    // heading and nav stuff
    LCreal trueHdg;         // True heanding (degs)
    SendData tHdgSD;

    LCreal cmdHdg;          // commanded heading (heading bug)
    SendData cmdHdgROSD;
    
    // airspeed
    LCreal airSpd;          // Kts
    SendData airSpdTpSD;    // for the airspeed tape
    SendData onesSD;        // for the readout ones tape
    SendData spdRstSD;      // rest of the speed data

    // altitude
    LCreal alt;
    SendData alt1SD;
    SendData alt2SD;
    SendData alt3SD;
    SendData altTpSD;       // for the airspeed tape
    SendData altTensSD;
    SendData altSelectSD;   // to select the justification
    SendData altSD;         // for the actual altitude

    // side slip
    LCreal slip;             // Side slip angle (degs)
    SendData slipSD;

    // glideslope (in dots)
    LCreal gSlope;
    SendData gSlopeSD;

    // Lateral dev
    LCreal latDev;
    SendData latDevSD;

    // commanded speed
    LCreal cmdSpd;          // kts
    SendData aBugSD;
    SendData diffSD;

    // commanded alt
    LCreal cmdAlt;
    SendData altBugSD;
    SendData altDiffSD;

    // vvi
    LCreal vvi;         // ft/min
    SendData vviSD;
    SendData vviROSD;

    // flight director stuff (in inches)
    LCreal fDirBank;
    SendData fDirBankSD;
    LCreal fDirPitch;
    SendData fDirPitchSD;

    // barometric pressure
    LCreal baro;
    SendData baroSD;

    // Hsi send data
    SendData trueHdgSD;
    SendData hdgTapeSD;
    SendData cmdHdgSD;
   
    double refLat;
    double refLon;
    LCreal range;

    // Gs
    LCreal gLoad;
    // Mach
    LCreal mach;    //// meter altitude
    SendData mAltSD;
    SendData cmdMAltSD;

    // ghost horizon
    SendData pitchGhostSD;

};

}; // end of Mainy1 namespace
}; //end of Eaagles namespace

#endif  /* __Pfd_H_37E8E713_43E9_4103_88DB_787151FC0E13 */
