/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) Alliance for Sustainable Energy, LLC.
*  See also https://openstudio.net/license
***********************************************************************************************************************/

#include "LuminaireDefinition.hpp"
#include "LuminaireDefinition_Impl.hpp"

#include <utilities/idd/OS_Luminaire_Definition_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>

#include "../utilities/math/FloatCompare.hpp"
#include "../utilities/core/Compare.hpp"
#include "../utilities/core/Assert.hpp"

namespace openstudio {
namespace model {

  namespace detail {

    LuminaireDefinition_Impl::LuminaireDefinition_Impl(const IdfObject& idfObject, Model_Impl* model, bool keepHandle)
      : SpaceLoadDefinition_Impl(idfObject, model, keepHandle) {
      OS_ASSERT(idfObject.iddObject().type() == LuminaireDefinition::iddObjectType());
    }

    LuminaireDefinition_Impl::LuminaireDefinition_Impl(const openstudio::detail::WorkspaceObject_Impl& other, Model_Impl* model, bool keepHandle)
      : SpaceLoadDefinition_Impl(other, model, keepHandle) {
      OS_ASSERT(other.iddObject().type() == LuminaireDefinition::iddObjectType());
    }

    LuminaireDefinition_Impl::LuminaireDefinition_Impl(const LuminaireDefinition_Impl& other, Model_Impl* model, bool keepHandle)
      : SpaceLoadDefinition_Impl(other, model, keepHandle) {}

    const std::vector<std::string>& LuminaireDefinition_Impl::outputVariableNames() const {
      static const std::vector<std::string> result;
      return result;
    }

    IddObjectType LuminaireDefinition_Impl::iddObjectType() const {
      return LuminaireDefinition::iddObjectType();
    }

    double LuminaireDefinition_Impl::lightingPower() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::LightingPower, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isLightingPowerDefaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::LightingPower);
    }

    double LuminaireDefinition_Impl::fractionRadiant() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::FractionRadiant, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isFractionRadiantDefaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::FractionRadiant);
    }

    double LuminaireDefinition_Impl::fractionVisible() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::FractionVisible, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isFractionVisibleDefaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::FractionVisible);
    }

    double LuminaireDefinition_Impl::returnAirFraction() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::ReturnAirFraction, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isReturnAirFractionDefaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::ReturnAirFraction);
    }

    bool LuminaireDefinition_Impl::returnAirFractionCalculatedfromPlenumTemperature() const {
      boost::optional<std::string> value = getString(OS_Luminaire_DefinitionFields::ReturnAirFractionCalculatedfromPlenumTemperature, true);
      OS_ASSERT(value);
      return openstudio::istringEqual(value.get(), "Yes");
    }

    bool LuminaireDefinition_Impl::isReturnAirFractionCalculatedfromPlenumTemperatureDefaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::ReturnAirFractionCalculatedfromPlenumTemperature);
    }

    double LuminaireDefinition_Impl::returnAirFractionFunctionofPlenumTemperatureCoefficient1() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient1, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isReturnAirFractionFunctionofPlenumTemperatureCoefficient1Defaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient1);
    }

    double LuminaireDefinition_Impl::returnAirFractionFunctionofPlenumTemperatureCoefficient2() const {
      boost::optional<double> value = getDouble(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient2, true);
      OS_ASSERT(value);
      return value.get();
    }

    bool LuminaireDefinition_Impl::isReturnAirFractionFunctionofPlenumTemperatureCoefficient2Defaulted() const {
      return isEmpty(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient2);
    }

    bool LuminaireDefinition_Impl::setLightingPower(double lightingPower) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::LightingPower, lightingPower);
      return result;
    }

    void LuminaireDefinition_Impl::resetLightingPower() {
      bool result = setString(OS_Luminaire_DefinitionFields::LightingPower, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setFractionRadiant(double fractionRadiant) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::FractionRadiant, fractionRadiant);
      return result;
    }

    void LuminaireDefinition_Impl::resetFractionRadiant() {
      bool result = setString(OS_Luminaire_DefinitionFields::FractionRadiant, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setFractionVisible(double fractionVisible) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::FractionVisible, fractionVisible);
      return result;
    }

    void LuminaireDefinition_Impl::resetFractionVisible() {
      bool result = setString(OS_Luminaire_DefinitionFields::FractionVisible, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setReturnAirFraction(double returnAirFraction) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::ReturnAirFraction, returnAirFraction);
      return result;
    }

    void LuminaireDefinition_Impl::resetReturnAirFraction() {
      bool result = setString(OS_Luminaire_DefinitionFields::ReturnAirFraction, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setReturnAirFractionCalculatedfromPlenumTemperature(bool returnAirFractionCalculatedfromPlenumTemperature) {
      bool result = false;
      if (returnAirFractionCalculatedfromPlenumTemperature) {
        result = setString(OS_Luminaire_DefinitionFields::ReturnAirFractionCalculatedfromPlenumTemperature, "Yes");
      } else {
        result = setString(OS_Luminaire_DefinitionFields::ReturnAirFractionCalculatedfromPlenumTemperature, "No");
      }
      OS_ASSERT(result);
      return result;
    }

    void LuminaireDefinition_Impl::resetReturnAirFractionCalculatedfromPlenumTemperature() {
      bool result = setString(OS_Luminaire_DefinitionFields::ReturnAirFractionCalculatedfromPlenumTemperature, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setReturnAirFractionFunctionofPlenumTemperatureCoefficient1(
      double returnAirFractionFunctionofPlenumTemperatureCoefficient1) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient1,
                              returnAirFractionFunctionofPlenumTemperatureCoefficient1);
      return result;
    }

    void LuminaireDefinition_Impl::resetReturnAirFractionFunctionofPlenumTemperatureCoefficient1() {
      bool result = setString(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient1, "");
      OS_ASSERT(result);
    }

    bool LuminaireDefinition_Impl::setReturnAirFractionFunctionofPlenumTemperatureCoefficient2(
      double returnAirFractionFunctionofPlenumTemperatureCoefficient2) {
      bool result = setDouble(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient2,
                              returnAirFractionFunctionofPlenumTemperatureCoefficient2);
      return result;
    }

    void LuminaireDefinition_Impl::resetReturnAirFractionFunctionofPlenumTemperatureCoefficient2() {
      bool result = setString(OS_Luminaire_DefinitionFields::ReturnAirFractionFunctionofPlenumTemperatureCoefficient2, "");
      OS_ASSERT(result);
    }

  }  // namespace detail

  LuminaireDefinition::LuminaireDefinition(const Model& model) : SpaceLoadDefinition(LuminaireDefinition::iddObjectType(), model) {
    OS_ASSERT(getImpl<detail::LuminaireDefinition_Impl>());
  }

  IddObjectType LuminaireDefinition::iddObjectType() {
    IddObjectType result(IddObjectType::OS_Luminaire_Definition);
    return result;
  }

  double LuminaireDefinition::lightingPower() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->lightingPower();
  }

  bool LuminaireDefinition::isLightingPowerDefaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isLightingPowerDefaulted();
  }

  double LuminaireDefinition::fractionRadiant() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->fractionRadiant();
  }

  bool LuminaireDefinition::isFractionRadiantDefaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isFractionRadiantDefaulted();
  }

  double LuminaireDefinition::fractionVisible() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->fractionVisible();
  }

  bool LuminaireDefinition::isFractionVisibleDefaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isFractionVisibleDefaulted();
  }

  double LuminaireDefinition::returnAirFraction() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->returnAirFraction();
  }

  bool LuminaireDefinition::isReturnAirFractionDefaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isReturnAirFractionDefaulted();
  }

  bool LuminaireDefinition::returnAirFractionCalculatedfromPlenumTemperature() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->returnAirFractionCalculatedfromPlenumTemperature();
  }

  bool LuminaireDefinition::isReturnAirFractionCalculatedfromPlenumTemperatureDefaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isReturnAirFractionCalculatedfromPlenumTemperatureDefaulted();
  }

  double LuminaireDefinition::returnAirFractionFunctionofPlenumTemperatureCoefficient1() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->returnAirFractionFunctionofPlenumTemperatureCoefficient1();
  }

  bool LuminaireDefinition::isReturnAirFractionFunctionofPlenumTemperatureCoefficient1Defaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isReturnAirFractionFunctionofPlenumTemperatureCoefficient1Defaulted();
  }

  double LuminaireDefinition::returnAirFractionFunctionofPlenumTemperatureCoefficient2() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->returnAirFractionFunctionofPlenumTemperatureCoefficient2();
  }

  bool LuminaireDefinition::isReturnAirFractionFunctionofPlenumTemperatureCoefficient2Defaulted() const {
    return getImpl<detail::LuminaireDefinition_Impl>()->isReturnAirFractionFunctionofPlenumTemperatureCoefficient2Defaulted();
  }

  bool LuminaireDefinition::setLightingPower(double lightingPower) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setLightingPower(lightingPower);
  }

  void LuminaireDefinition::resetLightingPower() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetLightingPower();
  }

  bool LuminaireDefinition::setFractionRadiant(double fractionRadiant) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setFractionRadiant(fractionRadiant);
  }

  void LuminaireDefinition::resetFractionRadiant() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetFractionRadiant();
  }

  bool LuminaireDefinition::setFractionVisible(double fractionVisible) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setFractionVisible(fractionVisible);
  }

  void LuminaireDefinition::resetFractionVisible() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetFractionVisible();
  }

  bool LuminaireDefinition::setReturnAirFraction(double returnAirFraction) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setReturnAirFraction(returnAirFraction);
  }

  void LuminaireDefinition::resetReturnAirFraction() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetReturnAirFraction();
  }

  bool LuminaireDefinition::setReturnAirFractionCalculatedfromPlenumTemperature(bool returnAirFractionCalculatedfromPlenumTemperature) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setReturnAirFractionCalculatedfromPlenumTemperature(
      returnAirFractionCalculatedfromPlenumTemperature);
  }

  void LuminaireDefinition::resetReturnAirFractionCalculatedfromPlenumTemperature() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetReturnAirFractionCalculatedfromPlenumTemperature();
  }

  bool LuminaireDefinition::setReturnAirFractionFunctionofPlenumTemperatureCoefficient1(
    double returnAirFractionFunctionofPlenumTemperatureCoefficient1) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setReturnAirFractionFunctionofPlenumTemperatureCoefficient1(
      returnAirFractionFunctionofPlenumTemperatureCoefficient1);
  }

  void LuminaireDefinition::resetReturnAirFractionFunctionofPlenumTemperatureCoefficient1() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetReturnAirFractionFunctionofPlenumTemperatureCoefficient1();
  }

  bool LuminaireDefinition::setReturnAirFractionFunctionofPlenumTemperatureCoefficient2(
    double returnAirFractionFunctionofPlenumTemperatureCoefficient2) {
    return getImpl<detail::LuminaireDefinition_Impl>()->setReturnAirFractionFunctionofPlenumTemperatureCoefficient2(
      returnAirFractionFunctionofPlenumTemperatureCoefficient2);
  }

  void LuminaireDefinition::resetReturnAirFractionFunctionofPlenumTemperatureCoefficient2() {
    getImpl<detail::LuminaireDefinition_Impl>()->resetReturnAirFractionFunctionofPlenumTemperatureCoefficient2();
  }

  /// @cond
  LuminaireDefinition::LuminaireDefinition(std::shared_ptr<detail::LuminaireDefinition_Impl> impl) : SpaceLoadDefinition(std::move(impl)) {}
  /// @endcond

}  // namespace model
}  // namespace openstudio
