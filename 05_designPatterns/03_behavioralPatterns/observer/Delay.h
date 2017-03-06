#include "Effect.h"
#include "Subject.h"

#ifndef DELAY_H
#define DELAY_H

#define MAXDELAYSAMPLES  44100
class Delay : public Effect {
public:
  void process(/*float* buffer, int numFrames*/);
  //override Observer update method
  void update(Subject* subject);

  //set the delay time in miliseconds
  void setDelayTimeMS(float delayTimeMS);
private:
  static float constexpr maxDelayTimeMS = MAXDELAYSAMPLES / SAMPLERATE * 1000.0;
  //TODO remove MAXDELAYSAMPLES, use constexpr instead
  //static int constexpr maxDelaySamples = 44100;
  float delayBuffer[MAXDELAYSAMPLES];
  int delayInSamples;
};

#endif
