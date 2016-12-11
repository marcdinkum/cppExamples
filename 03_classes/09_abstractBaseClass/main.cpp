#include <bear/Audio/File.hpp>
#include <bear/Audio/Output.hpp>
#include "Sine.h"
/*
 * TODO - add explenation + HANDSON TIPS
 */

using namespace bear;
using namespace unit;

int main() {
  //create a Signal object
  Sine mySine(220);

  //retrieve bear default audio output object
  auto& output = audio::Output::getDefaultOutput();

  //create onOutput function using labmda function (see \05_cpp11And14\01_lambdaFunction)
  output.onOutput = [&](auto outputs, size_t channelCount, size_t frameCount)
  {
    const auto sampleRate = output.getSampleRate();

    mySine.process(outputs, channelCount, frameCount, sampleRate);
  };

  output.start();

  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q': running = false; break;
      }
  }

  // Stop the output stream
  output.stop();

  return 0;
}
