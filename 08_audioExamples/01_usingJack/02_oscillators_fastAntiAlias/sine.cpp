#include "sine.h"

//Constructors and destructor
Sine::Sine(double samplerate) : Sine(samplerate, 0, 0) {}

Sine::Sine(double samplerate, double frequency) :
  Sine(samplerate, frequency, 0) {}

Sine::Sine(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

Sine::~Sine() {}

//override calculate method
//this method contains the sample calculation
void Sine::calculate()
{
  //std::cout << "\n";
  //translate phase to -PI..PI
  static double tempPhase = 0;
  tempPhase = (phase - 0.5) * PI_2;
  //std::cout << phase;
  if (tempPhase < 0)
    sample =  1.27323954 * tempPhase + .405284735 * tempPhase * tempPhase;
  else
    sample = 1.27323954 * tempPhase - 0.405284735 * tempPhase * tempPhase;
}
