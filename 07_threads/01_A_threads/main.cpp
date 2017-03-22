#include <iostream>
#include <thread>


/*
 * example functions that will run on the serialIO thread
 */
void readSerialInput() {
  std::cout << "\nreadSerialInput\n";
}
bool readingSerialInput = true;
void serialIO()
{
  while(readingSerialInput) {
    readSerialInput();
  }
}

/*
 * example functions that will run on the audio thread
 */
void audioCallback ( /* outputbuffer, numframes, sampleRate etc.*/ )
{
  std::cout << "\naudioCallbacl\n";
}
static bool audioIsRunning = true;
void audio()
{
  while(audioIsRunning) {
    audioCallback();
  }
}

int main()
{
  // spawn new thread that calls serialIO()
  std::thread serialThread (serialIO);
   // spawn new thread that calls audio()
  std::thread audioThread (audio);

  std::cout << "main, foo and bar now execute concurrently...\n";


 bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q':
          std::cout << "\n******* input contains q ******** \n";
          audioIsRunning = false;
          readingSerialInput = false;
          running = false;
          break;
      }
  }

  /*
   * aThread.join() returns when the thread execution has completed
   * this means the programm pauses here until this call is finished
   */
  serialThread.join();
  audioThread.join();

  std::cout << "serialThread and audioThread completed.\n";

  return 0;
}
