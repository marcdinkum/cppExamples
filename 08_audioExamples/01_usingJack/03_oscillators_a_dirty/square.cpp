#include "square.h"

#define OUTPUT_SQUAREWAVE 0

//Constructors and destructor
Square::Square(double samplerate) : Square(samplerate, 0, 0) {}

Square::Square(double samplerate, double frequency) :
  Square(samplerate, frequency, 0) {}

Square::Square(double samplerate, double frequency, double phase) :
  Oscillator (samplerate, frequency, phase) {}

Square::~Square() {}

//override calculate method
//this method contains the sample calculation
void Square::calculate()
{
  //NOTE - creating a pure square wave -> ALIASING ISSUES!!!
  sample = phase < 0.5 ? 1 : -1;
  //write output squarewave to console
  #if OUTPUT_SQUAREWAVE
    static int i = 0;
    if(i < 1000) std::cout << "\n" << i << "\t" << sample;
    i++;
  #endif
}
