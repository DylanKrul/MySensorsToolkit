#ifndef DHTSensor_h
#define DHTSensor_h

#include "SensorBase.h"
#include "SensorValue.h"
#include <DHT.h>

namespace mys_toolkit {

class DHTSensor: public SensorBase
{
  DHT dhtSensor_;
  uint8_t dataPin_;
  SensorValue<float> humidity_;
  SensorValue<float> temperature_;
  void begin_() override;
  unsigned long preUpdate_() override;
  unsigned long update_() override;

public:
  DHTSensor(uint8_t humSensorId, uint8_t tempSensorId, uint8_t dataPin, float humTreshold = 0, float tempTreshold = 0);
};

} //mys_toolkit

#endif //DHTSensor_h
