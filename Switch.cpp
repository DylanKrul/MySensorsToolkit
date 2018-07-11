#include "Switch.h"

namespace mys_toolkit {

Switch::Switch(bool activeLow = false)
  : activeLow_(activeLow)
{
}

bool Switch::update()
{
  bool state = doUpdate_();
  return activeLow_ ? !state : state;
}

} //mys_toolkit
