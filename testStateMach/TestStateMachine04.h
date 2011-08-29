//------------------------------------------------------------------------------
// Class: TestStateMachine04
//------------------------------------------------------------------------------
#ifndef __TestStateMach_TestStateMachine04_H__
#define __TestStateMach_TestStateMachine04_H__

#include "openeaagles/basic/StateMachine.h"

namespace Eaagles {
namespace TestStateMach {

//------------------------------------------------------------------------------
// Class: TestStateMachine04
//
//    Same as Test #2 plus we're testing the substate transition
//    functions: nextSubstate() and goToSubstate().
//
//------------------------------------------------------------------------------
class TestStateMachine04 : public Basic::StateMachine {
   DECLARE_SUBCLASS(TestStateMachine04,Basic::StateMachine)

public:
   enum { CALL_01 = 11, CALL_02 = 22 };

public:
   TestStateMachine04();

protected:
   // Basic::StateMachine protected interface function
   virtual void preStateProc(const LCreal dt);
   virtual void postStateProc(const LCreal dt);
   virtual unsigned short stateTable(
         const unsigned short cstate,
         const StateTableCode code,
         const LCreal dt=0
      );

private:
   // State specific functions
   void stateFunc00(const LCreal dt);
   void stateFunc02(const LCreal dt);
   void stateFunc03(const LCreal dt);
   void stateFunc05(const LCreal dt);
   void stateFunc11(const LCreal dt);
   void stateFunc12(const LCreal dt);
   void stateFunc14(const LCreal dt);
   void stateFunc15(const LCreal dt);
   void stateFunc21(const LCreal dt);
   void stateFunc22(const LCreal dt);
   void stateFunc23(const LCreal dt);
   void stateFunc99(const LCreal dt);
};

} // End TestStateMach namespace
} // End Eaagles namespace

#endif	/* __TestStateMach_TestStateMachine04_H__ */
