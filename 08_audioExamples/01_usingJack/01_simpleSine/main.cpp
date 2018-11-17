#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"

#define PI_2 6.28318530717959



int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;
  //assign a function to the JackModule::onProces
  jack.onProcess = [](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes, double samplerate) {

    static double phase = 0;
    static double amplitude = 0.5;
    static double frequency = 880;

    for(int i = 0; i < nframes; i++) {
      outBuf[i] = amplitude * sin(phase * PI_2 );
      phase += frequency / samplerate;
    }

    return 0;
  };

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q':
            running = false;
            break;
      }
  }

  //end the program
  return 0;
} // main()