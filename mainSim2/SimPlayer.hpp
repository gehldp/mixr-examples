
#ifndef __SimPlayer_H__
#define __SimPlayer_H__

#include "mxrp/models/player/AirVehicle.hpp"

//------------------------------------------------------------------------------
// Class: SimPlayer
//
// Description: Simulation player
//------------------------------------------------------------------------------
class SimPlayer : public mxrp::models::Aircraft
{
    DECLARE_SUBCLASS(SimPlayer, mxrp::models::Aircraft)

public:
    SimPlayer();

    virtual void reset() override;
};

#endif
