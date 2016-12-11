#include <iostream>
#include <cmath>

class Signal {
public:
  //use default value for freq parameter
  Signal(float freq = 0);
  virtual ~Signal();

  virtual void process(float* const* const outputs, size_t channelCount, size_t frameCount, int sampleRate) = 0;

  void setFreq(float freq);
  float getFreq();

private:
  float freq;
  double phase;
};
