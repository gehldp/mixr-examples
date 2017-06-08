
#ifndef __DspRadar_H__
#define __DspRadar_H__

#include "mxrp/graphics/Graphic.hpp"
#include <array>

namespace mxrp {
namespace base { class PairStream; }
namespace models { class Radar; }
}

//------------------------------------------------------------------------------
// Class: DspRadar
// Description: Simple Realbeam B-Scan RADAR.  Displays the real-beam signal,
//              with color coded doppler shift, and overlayed with tracks.
// Factory name: DspRadar
//------------------------------------------------------------------------------
class DspRadar : public mxrp::graphics::Graphic
{
   DECLARE_SUBCLASS(DspRadar, mxrp::graphics::Graphic)

public:
   DspRadar();

   const mxrp::models::Radar* getRadar()             { return radar; }
   const mxrp::models::Radar* getRadar() const       { return radar; }
   bool setRadar(mxrp::models::Radar* const s)       { radar = s; return true; }

   virtual void drawFunc() override;

   virtual void updateData(const double dt = 0.0) override;

private:
    static const int MAX_TRKS = 50;

    const mxrp::models::Radar* radar {};  // The test RADAR sensor
    SendData azSD;
    SendData elSD;

    // Tracks
    unsigned int nTracks {};                       // Number of tracks
    int ntsTrk {-1};                               // Index of the 'next-to-shoot' track
    std::array<double, MAX_TRKS> trkRng {};        // Track's range                    (meters)
    std::array<double, MAX_TRKS> trkAz {};         // Track's relative azimuth
    std::array<double, MAX_TRKS> trkVel {};        // Track's velocity                 (m/s)
    std::array<double, MAX_TRKS> trkRelGndTrk {};  // Track's relative ground track (to nearest 45 deg)
};

#endif
