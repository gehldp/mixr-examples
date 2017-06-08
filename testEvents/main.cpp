//----------------------------------------------------------------
// Test Component send command, using different parameters
//----------------------------------------------------------------
#include "mxrp/base/Pair.hpp"
#include "mxrp/base/edl_parser.hpp"
#include "mxrp/base/Timers.hpp"

#include <GL/glut.h>

// factories
#include "mxrp/graphics/factory.hpp"
#include "mxrp/base/factory.hpp"
#include "mxrp/gui/glut/factory.hpp"

#include "Display.hpp"
#include "ObjectHandler.hpp"

#include <string>
#include <cstdlib>

// frame rate
const unsigned int frameRate = 20;

Display* display = nullptr;

// timerFunc()
void timerFunc(int)
{
   const double dt = 1.0 / static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   mxrp::base::Timer::updateTimers(static_cast<double>(dt));
   mxrp::graphics::Graphic::flashTimer(static_cast<double>(dt));
   display->tcFrame(static_cast<double>(dt));
}

// our class factory
mxrp::base::Object* factory(const std::string& name)
{
   mxrp::base::Object* obj = nullptr;

   if ( name == Display::getFactoryName() ) {
      obj = new Display();
   }
   else if ( name == ObjectHandler::getFactoryName() ) {
      obj = new ObjectHandler();
   }
   else {
      if (obj == nullptr) obj = mxrp::graphics::factory(name);
      if (obj == nullptr) obj = mxrp::glut::factory(name);
      if (obj == nullptr) obj = mxrp::base::factory(name);
   }

   return obj;
}

// display builder
Display* builder(const std::string& filename)
{
   // read configuration file
   unsigned int num_errors = 0;
   mxrp::base::Object* obj = mxrp::base::edl_parser(filename, factory, &num_errors);
   if (num_errors > 0) {
      std::cerr << "File: " << filename << ", number of errors: " << num_errors << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // test to see if an object was created
   if (obj == nullptr) {
      std::cerr << "Invalid configuration file, no objects defined!" << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // do we have a base::Pair, if so, point to object in Pair, not Pair itself
   const auto pair = dynamic_cast<mxrp::base::Pair*>(obj);
   if (pair != nullptr) {
      obj = pair->object();
      obj->ref();
      pair->unref();
   }

   // try to cast to proper object, and check
   const auto display = dynamic_cast<Display*>(obj);
   if (display == nullptr) {
      std::cerr << "Invalid configuration file!" << std::endl;
      std::exit(EXIT_FAILURE);
   }
   return display;
}

int main(int argc, char* argv[])
{
   glutInit(&argc, argv);

   // default configuration filename
   std::string configFilename = "test.edl";

   display = builder(configFilename);

   // create a display window
   display->createWindow();

   // set timer
   const double dt = 1.0 / static_cast<double>(frameRate);
   const auto millis = static_cast<unsigned int>(dt * 1000);
   glutTimerFunc(millis, timerFunc, 1);

   // main loop
   glutMainLoop();

   return 0;
}
