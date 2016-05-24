
#ifndef __oe_example_InstrumentPanel_H__
#define __oe_example_InstrumentPanel_H__

#include "openeaagles/gui/glut/GlutDisplay.h"
#include "openeaagles/simulation/Player.h"

namespace oe {

namespace simulation { class Player; class Simulation; class Station; }

namespace example {

class DedDisplay;
class MfdDisplay;

//------------------------------------------------------------------------------
// Class:  InstrumentPanel
//
// Description: Sim3 Main Instrument Panel
//
// Events: (all keyboard events)
//   'r' or 'R'   -- Reset simulation
//   'f' or 'F'   -- Toggle simulation freeze
//   '+'          -- Ownship step (to next local air vehicle)
//------------------------------------------------------------------------------
class InstrumentPanel : public glut::GlutDisplay
{
   DECLARE_SUBCLASS(InstrumentPanel, glut::GlutDisplay)

public:
   InstrumentPanel();

   simulation::Player* getOwnship();
   simulation::Simulation* getSimulation();
   simulation::Station* getStation();

   virtual bool event(const int event, base::Object* const obj = nullptr) override;
   virtual void updateData(const double dt = 0.0) override;

protected:
   // Key event handlers
   bool onResetKey();
   bool onFreezeKey();
   bool onStepOwnshipKey();

private:
   base::safe_ptr<simulation::Station> myStation;

   // ALT Stuff
   double altitude;            // our current altitude
   SendData altitudeSD;

   // VVI Stuff
   osg::Vec3 vvi;              // velocity vector
   SendData vviSD;
   double pastVvi;             // our past vvi value (to create a linear filter)

   // AOA Stuff
   double aoa;                 // angle of attack
   SendData aoaSD;
   SendData aoaDigSD;          // angle of attack (digital)

   // HSI Stuff - sends this to our Sim3Hsi class
   double heading;             // our heading (in degrees)
   SendData headingSD;
   double bpAngle;             // our bearing pointer angle (degrees)
   SendData bpAngleSD;
   double dme;                 // dme (miles)
   SendData dmeSD;


   // CAS Stuff
   double airSpeed;            // our air speed (in knots)
   SendData airSpeedSD;

   // G Stuff
   double gForce;              // g's we are pulling
   SendData gForceSD;
   SendData gForce2SD;         // this is for the analog meter

   // ADI
   double pitch;               // pitch (degrees)
   SendData pitchSD;
   double roll;                // roll (degrees)
   SendData rollSD;
   double slip;                // slip (degrees)
   SendData slipSD;

   // Mach
   double mach;                // mach number
   SendData machSD;

   // G
   double gload;               // G
   SendData gloadSD;
};

}
}

#endif

