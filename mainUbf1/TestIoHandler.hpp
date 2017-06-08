
#ifndef __TestIoHandler_H__
#define __TestIoHandler_H__

#include "mxrp/base/io/IoHandler.hpp"

//------------------------------------------------------------------------------
// Class: TestIoHandler
//
// Description:  Handles the flow of I/O data to and from the
//               stick and throttle hardware
//------------------------------------------------------------------------------
class TestIoHandler : public mxrp::base::IoHandler
{
   DECLARE_SUBCLASS(TestIoHandler, mxrp::base::IoHandler)

public:
   TestIoHandler();

   virtual void inputDevices(const double dt) override;

protected:
   virtual void clear() override;

private:
   bool rstSw1 {};
   bool frzSw1 {};
   bool wpnReloadSw1 {};

   bool wpnRelSw1 {};
   bool trgSw1 {};
   bool tgtStepSw1 {};
   bool tgtDesSw1 {};
   bool rtn2SrchSw1 {};

   bool autopilotSw1 {};
   bool incStptSw1 {};
   bool decStptSw1 {};
};

#endif
