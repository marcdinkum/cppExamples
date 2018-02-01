#ifndef _H_SIMPLE_SYNTH_
#define _H_SIMPLE_SYNTH_
#include "sine.h"

class SimpleSynth {
public:
  //constructor
  SimpleSynth(double samplerate);
  SimpleSynth(double samplerate, float midiPitch);
  //prevent the default constructor to be generated
  SimpleSynth() = delete;
  //destructor
  ~SimpleSynth();

  //set the pitch
  void setMidiPitch(float midiPitch);
  float getMidiPitch();
  //return the current sample
  double getSample();
  void tick();

private:
  void setFrequency(float frequency);
  float mtof(float midiPitch);

  float midiPitch;
  double samplerate;
  Sine sine;
};

#endif
