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
  //TODO - use saw function
  //NOTE sin() method is not the most efficient way to calculate the saw value
  sample = sin(phase * PI_2 );
}
