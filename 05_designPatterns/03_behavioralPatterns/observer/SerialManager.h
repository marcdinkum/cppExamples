#include <iostream>
#include "Subject.h"
#include "EffectValuesSubject.h"

#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

struct EffectValues{
  float delayDryWet = 0.0f;
  float delayTimeMS = 0;
  float delayAmp = 0.0f;
};

class SerialManager : public EffectValuesSubject{
public:
  void demoValuesChanged();
  float getValues(EffectValueTypes effectValueType);

private:
  EffectValues _effectValues;
};

#endif
