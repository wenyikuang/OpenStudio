/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) Alliance for Sustainable Energy, LLC.
*  See also https://openstudio.net/license
***********************************************************************************************************************/

#include "../ReverseTranslator.hpp"
#include "../../model/DesignDay.hpp"
#include "../../model/DesignDay_Impl.hpp"
#include "../../model/ScheduleDay.hpp"
#include "../../model/ScheduleDay_Impl.hpp"
#include <utilities/idd/SizingPeriod_DesignDay_FieldEnums.hxx>
#include "../../utilities/idd/IddEnums.hpp"
#include <utilities/idd/IddEnums.hxx>
#include "../../utilities/core/Compare.hpp"

using namespace openstudio::model;

namespace openstudio {
namespace energyplus {

  OptionalModelObject ReverseTranslator::translateSizingPeriodDesignDay(const WorkspaceObject& workspaceObject) {
    if (workspaceObject.iddObject().type() != IddObjectType::SizingPeriod_DesignDay) {
      LOG(Error, "WorkspaceObject is not IddObjectType: SizingPeriod_DesignDay");
      return boost::none;
    }

    DesignDay designDay(m_model);

    // Name
    boost::optional<std::string> s = workspaceObject.getString(SizingPeriod_DesignDayFields::Name);
    if (s) {
      designDay.setName(s.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay missing required field Name");
    }

    // Month
    boost::optional<int> i = workspaceObject.getInt(SizingPeriod_DesignDayFields::Month);
    if (i) {
      designDay.setMonth(i.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Month");
    }

    // Day of Month
    i = workspaceObject.getInt(SizingPeriod_DesignDayFields::DayofMonth);
    if (i) {
      designDay.setDayOfMonth(i.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Day of Month");
    }

    // Day Type
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::DayType);
    if (s) {
      designDay.setDayType(s.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Day Type");
    }

    // Maximum Dry-Bulb Temperature
    boost::optional<double> value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::MaximumDryBulbTemperature);
    if (value) {
      designDay.setMaximumDryBulbTemperature(value.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Maximum Dry Bulb Temperature");
    }

    // Dry-Bulb Temperature Range Modifier Type
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::DryBulbTemperatureRangeModifierType);
    if (s) {
      designDay.setDryBulbTemperatureRangeModifierType(s.get());
    }
    std::string dryBulbTemperatureRangeModifierType = designDay.dryBulbTemperatureRangeModifierType();

    // Daily Dry-Bulb Temperature Range
    if (!istringEqual(dryBulbTemperatureRangeModifierType, "DifferenceSchedule")) {
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::DailyDryBulbTemperatureRange);
      if (value) {
        designDay.setDailyDryBulbTemperatureRange(value.get());
      }
    }

    // Dry-Bulb Temperature Range Modifier Schedule Name
    if (istringEqual(dryBulbTemperatureRangeModifierType, "MultiplierSchedule")
        || istringEqual(dryBulbTemperatureRangeModifierType, "DifferenceSchedule")) {
      boost::optional<WorkspaceObject> wo = workspaceObject.getTarget(SizingPeriod_DesignDayFields::DryBulbTemperatureRangeModifierDayScheduleName);
      if (wo) {
        boost::optional<ModelObject> mo = translateAndMapWorkspaceObject(wo.get());
        if (mo) {
          if (boost::optional<ScheduleDay> schedule = mo->optionalCast<ScheduleDay>()) {
            designDay.setDryBulbTemperatureRangeModifierDaySchedule(*schedule);
          }
        }
      }

      if (!designDay.dryBulbTemperatureRangeModifierDaySchedule()) {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Maximum Dry Bulb Temperature");
      }
    }

    // Humidity Condition Type
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::HumidityConditionType);
    if (s) {
      designDay.setHumidityConditionType(s.get());
    }
    std::string humidityConditionType = designDay.humidityConditionType();

    // Wetbulb or DewPoint at Maximum Dry-Bulb
    if (istringEqual(humidityConditionType, "WetBulb") || istringEqual(humidityConditionType, "DewPoint")
        || istringEqual(humidityConditionType, "WetBulbProfileMultiplierSchedule")
        || istringEqual(humidityConditionType, "WetBulbProfileDifferenceSchedule")
        || istringEqual(humidityConditionType, "WetBulbProfileDefaultMultipliers")) {
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::WetbulborDewPointatMaximumDryBulb);
      if (value) {
        // units for this field are C
        designDay.setWetBulbOrDewPointAtMaximumDryBulb(value.get());
      } else {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Wetbulb or Dew Point at Maximum Dry Bulb");
      }
    }

    // Humidity Condition Day Schedule Name
    if (istringEqual(humidityConditionType, "RelativeHumiditySchedule") || istringEqual(humidityConditionType, "WetBulbProfileMultiplierSchedule")
        || istringEqual(humidityConditionType, "WetBulbProfileDifferenceSchedule")
        || istringEqual(humidityConditionType, "RelativeHumiditySchedule")) {

      boost::optional<WorkspaceObject> wo = workspaceObject.getTarget(SizingPeriod_DesignDayFields::HumidityConditionDayScheduleName);
      if (wo) {
        boost::optional<ModelObject> mo = translateAndMapWorkspaceObject(wo.get());
        if (mo) {
          boost::optional<ScheduleDay> schedule = mo->optionalCast<ScheduleDay>();
          if (schedule) {
            designDay.setHumidityConditionDaySchedule(schedule.get());
          }
        }
      }

      if (!designDay.humidityConditionDaySchedule()) {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Humidity Condition Day Schedule Name");
      }
    }

    // Humidity Ratio at Maximum Dry-Bulb
    if (istringEqual(humidityConditionType, "HumidityRatio")) {
      // units for this field are kgWater/kgDryAir
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::HumidityRatioatMaximumDryBulb);
      if (value) {
        designDay.setHumidityRatioAtMaximumDryBulb(value.get());
      } else {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Humidity Ratio at Maximum Dry Bulb");
      }
    }

    // Enthalpy at Maximum Dry-Bulb
    if (istringEqual(humidityConditionType, "Enthalpy")) {
      // units for this field are J/kg
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::EnthalpyatMaximumDryBulb);
      if (value) {
        designDay.setEnthalpyAtMaximumDryBulb(value.get());
      } else {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Enthalpy at Maximum Dry Bulb");
      }
    }

    // Daily Wet-Bulb Temperature Range
    if (istringEqual(humidityConditionType, "WetbulbProfileMultiplierSchedule")
        || istringEqual(humidityConditionType, "WetBulbProfileDefaultMultipliers")) {
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::DailyWetBulbTemperatureRange);
      if (value) {
        designDay.setDailyWetBulbTemperatureRange(*value);
      } else {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Daily Wet Bulb Temperature Range");
      }
    }

    // Barometric Pressure
    value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::BarometricPressure);
    if (value) {
      designDay.setBarometricPressure(value.get());
    }

    // Site Wind Speed
    value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::WindSpeed);
    if (value) {
      designDay.setWindSpeed(value.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Site Wind Speed");
    }

    // Site Wind Direction
    value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::WindDirection);
    if (value) {
      designDay.setWindDirection(value.get());
    } else {
      LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Site Wind Direction");
    }

    // Rain Indicator
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::RainIndicator);
    if (s) {
      if (istringEqual(*s, "Yes")) {
        designDay.setRainIndicator(true);
      } else {
        designDay.setRainIndicator(false);
      }
    }

    // Snow Indicator
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::SnowIndicator);
    if (s) {
      if (istringEqual(*s, "Yes")) {
        designDay.setSnowIndicator(true);
      } else {
        designDay.setSnowIndicator(false);
      }
    }

    // Site Daylight Saving Time Status
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::DaylightSavingTimeIndicator);
    if (s) {
      if (istringEqual(*s, "Yes")) {
        designDay.setDaylightSavingTimeIndicator(true);
      } else {
        designDay.setDaylightSavingTimeIndicator(false);
      }
    }

    // Solar Model Indicator
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::SolarModelIndicator);
    if (s) {
      designDay.setSolarModelIndicator(s.get());
    }
    std::string solarModelIndicator = designDay.solarModelIndicator();

    // Beam Solar Day Schedule Name and Site Diffuse Solar Radiation Rate per Area Radiation Rate per Area Day Schedule Name
    if (istringEqual(solarModelIndicator, "Schedule")) {

      // Beam Solar Day Schedule Name
      boost::optional<WorkspaceObject> wo = workspaceObject.getTarget(SizingPeriod_DesignDayFields::BeamSolarDayScheduleName);
      if (wo) {
        boost::optional<ModelObject> mo = translateAndMapWorkspaceObject(wo.get());
        if (mo) {
          boost::optional<ScheduleDay> schedule = mo->optionalCast<ScheduleDay>();
          if (schedule) {
            designDay.setBeamSolarDaySchedule(schedule.get());
          }
        }
      }
      if (!designDay.beamSolarDaySchedule()) {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Beam Solar Day Schedule Name");
      }

      // Site Diffuse Solar Radiation Rate per Area Radiation Rate per Area Day Schedule Name
      wo = workspaceObject.getTarget(SizingPeriod_DesignDayFields::DiffuseSolarDayScheduleName);
      if (wo) {
        boost::optional<ModelObject> mo = translateAndMapWorkspaceObject(wo.get());
        if (mo) {
          boost::optional<ScheduleDay> schedule = mo->optionalCast<ScheduleDay>();
          if (schedule) {
            designDay.setDiffuseSolarDaySchedule(schedule.get());
          }
        }
      }
      if (!designDay.diffuseSolarDaySchedule()) {
        LOG(Error, "SizingPeriod:DesignDay " << designDay.name().get() << " missing required field Diffuse Solar Schedule Name");
      }
    }

    if (istringEqual(solarModelIndicator, "ASHRAETau")) {
      //  ASHRAE Clear Sky Optical Depth for Beam Irradiance (taub)
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::ASHRAEClearSkyOpticalDepthforBeamIrradiance_taub_);
      if (value) {
        designDay.setAshraeClearSkyOpticalDepthForBeamIrradiance(*value);
      }

      // ASHRAE Clear Sky Optical Depth for Diffuse Irradiance (taud)
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::ASHRAEClearSkyOpticalDepthforDiffuseIrradiance_taud_);
      if (value) {
        designDay.setAshraeClearSkyOpticalDepthForDiffuseIrradiance(*value);
      }
    }

    // Sky Clearness
    if (istringEqual(solarModelIndicator, "ASHRAEClearSky") || istringEqual(solarModelIndicator, "ZhangHuang")) {
      value = workspaceObject.getDouble(SizingPeriod_DesignDayFields::SkyClearness);
      if (value) {
        designDay.setSkyClearness(value.get());
      }
    }

    // Maximum Number Warmup Days
    i = workspaceObject.getInt(SizingPeriod_DesignDayFields::MaximumNumberWarmupDays);
    if (i) {
      designDay.setMaximumNumberWarmupDays(i.get());
    }

    // Begin Environment Reset Mode
    s = workspaceObject.getString(SizingPeriod_DesignDayFields::BeginEnvironmentResetMode);
    if (s) {
      designDay.setBeginEnvironmentResetMode(s.get());
    }

    return designDay;
  }

}  // namespace energyplus
}  // namespace openstudio
