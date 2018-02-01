#include "saw.h"

//Constructors and destructor
Saw::Saw(double samplerate) : Saw(samplerate, 0, 0) {}

Saw::Saw(double samplerate, double frequency) :
  Saw(samplerate, frequency, 0) {}

Saw::Saw(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

Saw::~Saw() {}

//override calculate method
//this method contains the sample calculation
void Saw::calculate()
{
  //TODO - clean up static values
  //TODO - use more proper names
  static double wrappedPhase = 0;
  static double tempSample = 0;
  static const double phaseIncrement = frequency / samplerate;
  static double tempX = 0;

  wrappedPhase = phase + 0.5;
  if(tempPhase > 1) wrappedPhase -= 1;

  tempSample = wrappedPhase * 2 - 1;

  if(wrappedPhase < phaseIncrement) {
    tempX = wrappedPhase / phaseIncrement;
    tempX = tempX + tempX - tempX * tempX - 1.0;)
  } else if (wrappedPhase > 1.0 - phaseIncrement) {
    tempX = (wrappedPhase - 1.0) / increment;
    tempX = tempX * tempX + tempX + tempX + 1.0;
  } else {
    tempX = 0;
  }
  sample = tempSample - tempX;

}

void Saw::wrap() {

}
