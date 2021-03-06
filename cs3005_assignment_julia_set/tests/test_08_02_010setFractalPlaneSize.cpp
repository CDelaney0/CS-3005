#include "image_menu.h"
#include "image_menu.h" // Did you #ifndef your file?

#include "gtest/gtest.h"
#include <fstream>

class JuliaSetSetFractalPlaneSizeTest : public ::testing::Test {
protected:

  virtual void SetUp( ) {
    mExpectedOutput = "";
    mInputStream.str( "" );
    mOutputStream.str( "" );
  }

  virtual void TearDown( ) {
  }

  /* data members */
  std::string mExpectedOutput;
  std::stringstream mInputStream;
  std::stringstream mOutputStream;
  JuliaSet js;
};



TEST_F( JuliaSetSetFractalPlaneSizeTest, setsPlaneSize ) {

  /* Setup */
  js.setPlaneSize( -1.9, 1.8, -1.7, 1.6 );
  mInputStream.str( "1.1 -1.2 -1.3 1.4" );
  mExpectedOutput = "Min X? Max X? Min Y? Max Y? ";

  /* Stimulus */
  setFractalPlaneSize( mInputStream, mOutputStream, js );
  const JuliaSet& js_const = js;

  /* Comparison */
  EXPECT_EQ( mExpectedOutput, mOutputStream.str( ) );
  EXPECT_EQ( -1.2, js_const.getMinX( ) );
  EXPECT_EQ(  1.1, js_const.getMaxX( ) );
  EXPECT_EQ( -1.3, js_const.getMinY( ) );
  EXPECT_EQ(  1.4, js_const.getMaxY( ) );

  /* Tear-down */
  // Done automatically
}


TEST_F( JuliaSetSetFractalPlaneSizeTest, setsPlaneSize2 ) {

  /* Setup */
  js.setPlaneSize( -1.9, 1.8, -1.7, 1.6 );
  mInputStream.str( "-1.1 1.2 1.3 -1.4" );
  mExpectedOutput = "Min X? Max X? Min Y? Max Y? ";

  /* Stimulus */
  setFractalPlaneSize( mInputStream, mOutputStream, js );
  const JuliaSet& js_const = js;

  /* Comparison */
  EXPECT_EQ( mExpectedOutput, mOutputStream.str( ) );
  EXPECT_EQ( -1.1, js_const.getMinX( ) );
  EXPECT_EQ(  1.2, js_const.getMaxX( ) );
  EXPECT_EQ( -1.4, js_const.getMinY( ) );
  EXPECT_EQ(  1.3, js_const.getMaxY( ) );

  /* Tear-down */
  // Done automatically
}
