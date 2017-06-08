
#include "factory.hpp"

#include "mxrp/base/Object.hpp"

#include "TestDisplay.hpp"
#include "TestIoHandler.hpp"
#include "SimStation.hpp"

#include "xrecorder/factory.hpp"
#include "xpanel/factory.hpp"

#include "mxrp/base/factory.hpp"
#include "mxrp/graphics/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"
#include "mxrp/interop/dis/factory.hpp"
#include "mxrp/instruments/factory.hpp"
#include "mxrp/iodevice/factory.hpp"
#include "mxrp/otw/factory.hpp"
#include "mxrp/recorder/factory.hpp"
#include "mxrp/models/factory.hpp"
#include "mxrp/simulation/factory.hpp"

#include <string>

mxrp::base::Object* factory(const std::string& name)
{
    mxrp::base::Object* obj = nullptr;

    if ( name == SimStation::getFactoryName() ) {
        obj = new SimStation();
    }
    else if ( name == TestDisplay::getFactoryName() ) {
        obj = new TestDisplay();
    }
    else if ( name == TestIoHandler::getFactoryName() ) {
        obj = new TestIoHandler();
    }

    // Example libraries
    if (obj == nullptr) obj = mxrp::xrecorder::factory(name);
    if (obj == nullptr) obj = mxrp::xpanel::factory(name);

    // MXRP packages
    if (obj == nullptr) obj = mxrp::simulation::factory(name);
    if (obj == nullptr) obj = mxrp::instruments::factory(name);
    if (obj == nullptr) obj = mxrp::iodevice::factory(name);
    if (obj == nullptr) obj = mxrp::instruments::factory(name);
    if (obj == nullptr) obj = mxrp::recorder::factory(name);
    if (obj == nullptr) obj = mxrp::models::factory(name);
    if (obj == nullptr) obj = mxrp::otw::factory(name);
    if (obj == nullptr) obj = mxrp::dis::factory(name);
    if (obj == nullptr) obj = mxrp::graphics::factory(name);
    if (obj == nullptr) obj = mxrp::glut::factory(name);
    if (obj == nullptr) obj = mxrp::base::factory(name);

    return obj;
}
