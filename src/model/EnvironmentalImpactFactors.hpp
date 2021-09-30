/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) 2008-2021, Alliance for Sustainable Energy, LLC, and other contributors. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
*  following conditions are met:
*
*  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*  disclaimer.
*
*  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
*  disclaimer in the documentation and/or other materials provided with the distribution.
*
*  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
*  derived from this software without specific prior written permission from the respective party.
*
*  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
*  may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
*  written permission from Alliance for Sustainable Energy, LLC.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#ifndef MODEL_ENVIRONMENTALIMPACTFACTORS_HPP
#define MODEL_ENVIRONMENTALIMPACTFACTORS_HPP

#include <model/ModelAPI.hpp>
#include "ModelObject.hpp"

namespace openstudio {

namespace model {

  namespace detail {

    class EnvironmentalImpactFactors_Impl;

  }  // namespace detail

  /** EnvironmentalImpactFactors is a ModelObject that wraps the OpenStudio IDD object 'OS:EnvironmentalImpactFactors'. */
  class MODEL_API EnvironmentalImpactFactors : public ModelObject
  {
   public:
    /** @name Constructors and Destructors */
    //@{

    virtual ~EnvironmentalImpactFactors() {}

    //@}

    static IddObjectType iddObjectType();

    /** @name Getters */
    //@{

    double districtHeatingEfficiency() const;

    double districtCoolingCOP() const;

    double steamConversionEfficiency() const;

    double totalCarbonEquivalentEmissionFactorFromN2O() const;

    double totalCarbonEquivalentEmissionFactorFromCH4() const;

    double totalCarbonEquivalentEmissionFactorFromCO2() const;

    //@}
    /** @name Setters */
    //@{

    bool setDistrictHeatingEfficiency(double districtHeatingEfficiency);

    bool setDistrictCoolingCOP(double districtCoolingCOP);

    bool setSteamConversionEfficiency(double steamConversionEfficiency);

    bool setTotalCarbonEquivalentEmissionFactorFromN2O(double totalCarbonEquivalentEmissionFactorFromN2O);

    bool setTotalCarbonEquivalentEmissionFactorFromCH4(double totalCarbonEquivalentEmissionFactorFromCH4);

    bool setTotalCarbonEquivalentEmissionFactorFromCO2(double totalCarbonEquivalentEmissionFactorFromCO2);

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
    /// @cond
    typedef detail::EnvironmentalImpactFactors_Impl ImplType;

    explicit EnvironmentalImpactFactors(std::shared_ptr<detail::EnvironmentalImpactFactors_Impl> impl);

    friend class detail::EnvironmentalImpactFactors_Impl;
    friend class Model;
    friend class IdfObject;
    friend class openstudio::detail::IdfObject_Impl;
    explicit EnvironmentalImpactFactors(Model& model);

    /// @endcond
   private:
    REGISTER_LOGGER("openstudio.model.EnvironmentalImpactFactors");
  };

  /** \relates EnvironmentalImpactFactors*/
  typedef boost::optional<EnvironmentalImpactFactors> OptionalEnvironmentalImpactFactors;

  /** \relates EnvironmentalImpactFactors*/
  typedef std::vector<EnvironmentalImpactFactors> EnvironmentalImpactFactorsVector;

}  // namespace model
}  // namespace openstudio

#endif  // MODEL_ENVIRONMENTALIMPACTFACTORS_HPP