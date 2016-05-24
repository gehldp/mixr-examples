//------------------------------------------------------------------------------
// Class: Table
//------------------------------------------------------------------------------
#ifndef __oe_test_Table_H__
#define __oe_test_Table_H__

#include "openeaagles/graphics/Field.h"

namespace oe {
   namespace base { class Number; class PairStream; }

namespace test {

//------------------------------------------------------------------------------
// Class: Table
// Description: Manages a table
//
// Factory name: Table
// Slots:
//    rows     <Number>     ! Number of rows (default: 1)
//    spacing  <Number>     ! Spacing between rows (default: 1)
//    columns  <PairStream> ! Column descriptions: list of items in each row
//------------------------------------------------------------------------------
class Table : public graphics::Field
{
   DECLARE_SUBCLASS(Table,graphics::Field)

public:
   Table();

   virtual const base::PairStream* getColumns() const;
   virtual unsigned int getNumberOfRows() const;

   // Slot functions
   virtual bool setSlotRows(base::Number* const);
   virtual bool setSlotSpacing(base::Number* const);
   virtual bool setSlotColumns(base::PairStream* const);

   virtual int line() const override;
   virtual int line(const int ll) override;
   virtual int column() const override;
   virtual int column(const int cc) override;

   virtual void reset() override;

private:
   void initData();
   void build();        // Builds the table into our components
   void position();     // Positions the table

   unsigned int  rows;     // Number of rows in table
   unsigned int  spacing;  // Spacing between rows (default: 1)
   const base::PairStream* columns;  // columns items
};

}
}

#endif

