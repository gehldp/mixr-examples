
#ifndef __Table_H__
#define __Table_H__

#include "mixr/graphics/readouts/AbstractField.hpp"

namespace mixr {
namespace base { class Number; class PairStream; }
}

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
class Table : public mixr::graphics::AbstractField
{
   DECLARE_SUBCLASS(Table, mixr::graphics::AbstractField)

public:
   Table();

   virtual const mixr::base::PairStream* getColumns() const;
   virtual unsigned int getNumberOfRows() const;

   virtual int line() const override;
   virtual int line(const int ll) override;
   virtual int column() const override;
   virtual int column(const int cc) override;

   virtual void reset() override;

private:
   static const unsigned int DEFAULT_ROW     = 1;
   static const unsigned int DEFAULT_SPACING = 1;

   void build();        // Builds the table into our components
   void position();     // Positions the table

   unsigned int rows {DEFAULT_ROW};         // Number of rows in table
   unsigned int spacing {DEFAULT_SPACING};  // Spacing between rows (default: 1)
   const mixr::base::PairStream* columns {};  // columns items

private:
   // slot table helper methods
   bool setSlotRows(mixr::base::Number* const);
   bool setSlotSpacing(mixr::base::Number* const);
   bool setSlotColumns(mixr::base::PairStream* const);
};

#endif
