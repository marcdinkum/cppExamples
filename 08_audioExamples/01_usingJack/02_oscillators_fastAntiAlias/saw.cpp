#include "saw.h"
#define PLOT_SAW 0

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

  //* 5 -> alters the smoothing.
  //TODO -> research aliasing with and without this factor
  static const double phaseIncrement = frequency / samplerate * 5.0;
  static double tempX = 0;

  wrappedPhase = phase + 0.5;
  if(wrappedPhase > 1) wrappedPhase -= 1;

  tempSample = wrappedPhase * 2 - 1;

  if(wrappedPhase < phaseIncrement) {
    tempX = wrappedPhase / phaseIncrement;
    tempX = tempX + tempX - tempX * tempX - 1.0;
  } else if (wrappedPhase > 1.0 - phaseIncrement) {
    tempX = (wrappedPhase - 1.0) / phaseIncrement;
    tempX = tempX + tempX + tempX * tempX + 1.0;
  } else {
    tempX = 0;
  }
  sample = tempSample - tempX;
#if PLOT_SAW
  static int i = 0;
  if(i < 1000) std::cout << "\n" << i << "\t" << tempSample - tempX;
  i++;
#endif
}
