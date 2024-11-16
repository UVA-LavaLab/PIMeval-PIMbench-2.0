// File: pimPerfEnergyAquabolt.h
// PIMeval Simulator - Performance Energy Models
// Copyright (c) 2024 University of Virginia
// This file is licensed under the MIT License.
// See the LICENSE file in the root of this repository for more details.

#ifndef LAVA_PIM_PERF_ENERGY_AQUABOLT_H
#define LAVA_PIM_PERF_ENERGY_AQUABOLT_H

#include "libpimeval.h"                // for PimDeviceEnum, PimDataType
#include "pimParamsDram.h"             // for pimParamsDram
#include "pimCmd.h"                    // for PimCmdEnum
#include "pimResMgr.h"                 // for pimObjInfo
#include "pimPerfEnergyBase.h"         // for pimPerfEnergyBase


//! @class  pimPerfEnergyAquabolt
//! @brief  PIM performance energy model for aquabolt PIM family
class pimPerfEnergyAquabolt : public pimPerfEnergyBase
{
public:
  pimPerfEnergyAquabolt(const pimPerfEnergyModelParams& params) : pimPerfEnergyBase(params) {}
  virtual ~pimPerfEnergyAquabolt() {}

  virtual pimeval::perfEnergy getPerfEnergyForFunc1(PimCmdEnum cmdType, const pimObjInfo& obj) const override;
  virtual pimeval::perfEnergy getPerfEnergyForFunc2(PimCmdEnum cmdType, const pimObjInfo& obj) const override;
  virtual pimeval::perfEnergy getPerfEnergyForRedSum(PimCmdEnum cmdType, const pimObjInfo& obj, unsigned numPass) const override;
  virtual pimeval::perfEnergy getPerfEnergyForBroadcast(PimCmdEnum cmdType, const pimObjInfo& obj) const override;
  virtual pimeval::perfEnergy getPerfEnergyForRotate(PimCmdEnum cmdType, const pimObjInfo& obj) const override;

protected:
  double m_coreLatency = 0.000003; // ms; 300 MHz. Reference: Aquabolt paper
  unsigned m_coreWidth = 16;
  unsigned m_numCore = 16;
  // Following values are taken from fulcrum paper as BLIMP paper does not model energy
  double m_coreArithmeticEnergy = 0.0000000004992329586; // mJ
  double m_coreLogicalEnergy = 0.0000000001467846411; // mJ
};

#endif

