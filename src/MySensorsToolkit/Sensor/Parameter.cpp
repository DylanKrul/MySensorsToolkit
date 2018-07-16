#include "Parameter.h"

namespace mys_toolkit {

void ParameterBase::present_()
{
  ::present(sensorId_, sensorType_);
}
ParameterBase::ParameterBase(uint8_t sensorId, uint8_t type, uint8_t sensorType)
  : msg_(sensorId+100, type), sensorId_(sensorId+100), sensorType_(sensorType)
{
  parameterPoition_ = globalParameterPosition_;
  if (parametersCount_ < MAX_PARAMETERS)
    parameters_[parametersCount_++] = this;
}

static void ParameterBase::present()
{
  for (size_t i=0; i<parametersCount_; i++)
    parameters_[i]->present_();
}

static void ParameterBase::receive(const MyMessage &message)
{
  for (size_t i=0; i<parametersCount_; i++) {
    if (parameters_[i]->sensorId_ == message.sensor) {
      if (message.isAck()) {
        return;
      }
      if (parameters_[i]->msg_.type == message.type) {
        if (message.getCommand() == C_REQ) {
          ::send(parameters_[i]->msg_);
        }
        else if (message.getCommand() == C_SET) {
          parameters_[i]->set_(message);
        }
      }
    }
  }
}

uint8_t ParameterBase::parametersCount_ = 0;
ParameterBase* ParameterBase::parameters_[];
uint8_t ParameterBase::globalParameterPosition_ = 0;

} //mys_toolkit
