#include <bear/Audio/File.hpp>
#include <bear/Audio/Output.hpp>
#include <iostream>
#include <cmath>

using namespace bear;
using namespace std;
using namespace unit;

int main(int argc, const char * argv[]) {
  auto& output = audio::Output::getDefaultOutput();

  output.onOutput = [&](auto outputs, size_t channelCount, size_t frameCount)
  {
    const auto sampleRate = output.getSampleRate();
    // Iterate over the frames
    // ouputs is ordered in channels, then samples.
    // In this example we first take a frame (all channels at the same moment) then iterate over the channels
    for (auto frame = 0; frame < frameCount; ++frame)
    {
      // Generate the new output sample
      static double phase = 0;
      auto sample = sin(phase);

      // Increase the phase for next round
      phase += 220 / sampleRate * 2 * M_PI;
      if (phase >= 2 * M_PI)
        phase -= 2 * M_PI;

      // Iterate over the channels
      for (auto channel = 0; channel < channelCount; ++channel)
        outputs[channel][frame] = sample * 0.4;
    }
  };

  output.start();

  bool running = true;
  while (running)
  {
      switch (cin.get())
      {
          case 'q': running = false; break;
      }
  }

  // Stop the output stream
  output.stop();

  return 0;
}