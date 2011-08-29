
#include "openeaagles/basic/Pair.h"
#include "openeaagles/basic/Timers.h"
#include "openeaagles/basic/Parser.h"
#include "openeaagles/basicGL/basicGLFF.h"
#include "openeaagles/basic/basicFF.h"

#include "openeaagles/gui/glut/GlutDisplay.h"
#include "openeaagles/gui/glut/glutFF.h"
#include <GL/glut.h>

#include "Worm.h"

namespace Example07 {

// Description (input) File -- After being processed by the C preprocessor
const char* inputFileName = "file0.edl";

// Frame Rate
const int frameRate = 20;

// System descriptions
static class Eaagles::Glut::GlutDisplay* sys = 0;

// timerFunc() -- Time critical stuff)
static void timerFunc(int)
{
    double dt = 1.0/double(frameRate);

    unsigned int millis = (unsigned int)(dt * 1000);
    glutTimerFunc(millis, timerFunc, 1);

    Eaagles::Basic::Timer::updateTimers((float)dt);
    Eaagles::BasicGL::Graphic::flashTimer((Eaagles::LCreal)dt);
    sys->tcFrame((Eaagles::LCreal)dt);
}

// Test Form Function
static Eaagles::Basic::Object* exampleFormFunc(const char* const formname)
{
  Eaagles::Basic::Object* newform = 0;

  if ( strcmp(formname, Worm::getFormName()) == 0 ) {
    newform = new Worm;
  }
   
  // Default to base classes
  if (newform == 0) newform = Eaagles::Glut::glutFormFunc(formname);
  if (newform == 0) newform = Eaagles::BasicGL::basicGLFormFunc(formname);
  if (newform == 0) newform = Eaagles::Basic::basicFormFunc(formname);
  return newform;
}

// readTest() -- function to the read description files
static void readTest()
{
  // Read the description file
  int errors = 0;
  Eaagles::Basic::Object* q1 = lcParser(inputFileName, exampleFormFunc, &errors);
  if (errors > 0) {
    std::cerr << "Errors in reading file: " << errors << std::endl;
    exit(1);
  }

  // Set 'sys' to our basic description object.
  sys = 0;
  if (q1 != 0) {

    // When we were given a Pair, get the pointer to its object.
    Eaagles::Basic::Pair* pp = dynamic_cast<Eaagles::Basic::Pair*>(q1);
    if (pp != 0) {
      q1 = pp->object();
    }

    // What we should have here is the description object and
    // it should be of type 'TestDisplay'.
    sys = dynamic_cast<Eaagles::Glut::GlutDisplay*>(q1);
  }

  // Make sure we did get a valid object (we must have one!)
  if (sys == 0) {
    std::cout << "Invalid description file!" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int exec(int argc, char* argv[])
{
  glutInit(&argc, argv);

  // parse and read input file
  readTest();

  // create a display window
  sys->createWindow();

  // set timer
  double dt = 1.0/double(frameRate);
  unsigned int millis = (unsigned int)(dt * 1000);
  glutTimerFunc(millis, timerFunc, 1);

  // main loop
  glutMainLoop();
  return 0;
}

} // namespace Example07

//-----------------------------------------------------------------------------
// main() -- Main routine
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  Example07::exec(argc, argv);
}

