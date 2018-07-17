#pragma once

#include "ActuatorBase.h"
#include "Dimmer.h"
#include "Switch.h"
#include <MySensorsToolkit/Message.h>

namespace mys_toolkit {

class DimmerActuator : public ActuatorBase
{
  Dimmer &dim_;
  Switch &sw_;
  Message dimmerMsg_;
  Message lightMsg_;
  static uint8_t fromPercentage_(uint8_t percentage);
  static uint8_t fromLevel_(uint8_t level);
  void sendCurrentLevel_();
  void firstUpdate_() override;
  void update_() override;
  void receive_(const MyMessage &message) override;

public:
  DimmerActuator(uint8_t sensorId, Dimmer &dim, Switch &sw);
};

} //mys_toolkit

