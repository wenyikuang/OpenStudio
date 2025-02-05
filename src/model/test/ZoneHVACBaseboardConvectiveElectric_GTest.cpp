/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) Alliance for Sustainable Energy, LLC.
*  See also https://openstudio.net/license
***********************************************************************************************************************/

#include <gtest/gtest.h>
#include "ModelFixture.hpp"
#include "../ZoneHVACBaseboardConvectiveElectric.hpp"
#include "../ZoneHVACBaseboardConvectiveElectric_Impl.hpp"
#include "../ScheduleConstant.hpp"
#include "../ScheduleConstant_Impl.hpp"
#include "../ThermalZone.hpp"
#include "../ThermalZone_Impl.hpp"

using namespace openstudio;
using namespace openstudio::model;

TEST_F(ModelFixture, ZoneHVACBaseboardConvectiveElectric_Test) {
  Model model;

  // test constructor
  ZoneHVACBaseboardConvectiveElectric zoneHVACBBConv(model);

  // test set and get availibility schedule
  ScheduleConstant sched1(model);
  sched1.setValue(1.0);
  EXPECT_TRUE(zoneHVACBBConv.setAvailabilitySchedule(sched1));
  EXPECT_EQ(zoneHVACBBConv.availabilitySchedule(), sched1);

  // test add thermal zone
  // check if it has a thermal zone, should return no thermal zone
  EXPECT_FALSE(zoneHVACBBConv.thermalZone());
  // add to a thermal zone, check to see that it should have a thermal zone
  ThermalZone thermalZone1(model);
  zoneHVACBBConv.addToThermalZone(thermalZone1);
  boost::optional<ThermalZone> test_ThermalZone = zoneHVACBBConv.thermalZone();
  EXPECT_EQ(*test_ThermalZone, thermalZone1);

  //test remove a thermal zone
  //check to see it should have a thermal zone
  EXPECT_TRUE(zoneHVACBBConv.thermalZone());
  // remove the thermal zone
  zoneHVACBBConv.removeFromThermalZone();
  // check to see if it doesn't have a thermal zone
  EXPECT_FALSE(zoneHVACBBConv.thermalZone());
}
