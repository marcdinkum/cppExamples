#include <iostream>
#include <thread>
#include "jack_module.h"

#include "sine.h"
#include "saw.h"
#include "square.h"

/*
 * This example plays the sine, saw and square oscillators
 *
 * ------ HANDS-ON TIPS ------
 * TODO - add HANDS-ON tips
 * ---------------------------
 */


int main(int argc,char **argv)
{
  //create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  //create a Sine instance
  Square square(jack.getSamplerate(), 220, 0);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&square](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes)
  {
    //loop through frames, retrieve sample of sine per frame
    for(int i = 0; i < nframes; i++) {
      //TODO check type of jack_default_audio_sample_t, double? or float?
      outBuf[i] = square.getSample();
      square.tick();
    }

    return 0;
  };


  //
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
