#include <iostream>
#include "Observer.h"
#include "EffectValuesSubject.h"

#ifndef EFFECT_H
#define EFFECT_H

#define SAMPLERATE 512

class Effect : public Observer{
public:
  virtual ~Effect(){}
  virtual void process(/*float* buffer, int numFrames*/) = 0;
  //NOTE: example code - drywet and amp should be private!
  float dryWet = 0.0f;
  float amp = 1.0f;
protected:
  Effect(){}
};

#endif
