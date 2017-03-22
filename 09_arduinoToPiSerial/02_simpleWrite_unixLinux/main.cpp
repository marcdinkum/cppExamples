#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <thread>

//NOTE ****  ONLY WORKS ON UNIX / LINUX ****

//size of the buffer we use to write the serial data
static constexpr int writeBufferSize = 1;
//create write buffer with the data we want to send
//int writeBuffer[] = {65};
char writeBuffer[] = { 'A' };


//size of the buffer we use to read the serial data
static constexpr int readBufferSize = 2;
//create char buffer to use to read the serial values
//retrieve from -128 up to 127, or use unsigned char -> 0 : 255
char readBuffer[readBufferSize];
//create int buffer to hold int values (transform char to int)
int sensorVal[readBufferSize];

//set serial port
const char* devicename = "/dev/cu.usbmodem1411";
/*
 * pointer to file, on UNIX / LINUX we can read serial data from a port as if
 * port is a file.
 */
FILE *fileWrite = nullptr;
FILE *fileRead = nullptr;

//while running == true -> program continues
static bool running = true;
std::mutex mtx;
/*
 * serial write data function
 */
void writeData() {
  //Opening device file
  fileWrite = fopen(devicename, "wb");
  //check if succesfull
  if(fileWrite==NULL)
  { //if there is no serial port
    printf("Unable to open device %s\n",devicename);
    exit(1);
  }//if
  int number = -127;
  int loop = 0;
  int numLoops = 4;
  while(running) {
    //change the number we are writing
    number++;
    if(number >= 128) {
      loop++;
      std::cout << "\n ****************** loop: " << loop <<" \n";
      if(loop >= numLoops) {
        mtx.lock();
        running = false;
        mtx.unlock();
        break;
      }
      number = -127;
    } // end if (number >= 128)
    std::cout << "write: " << number << "\n";
    //store number as char
    writeBuffer[0] = number;
    //write buffer
    fwrite (writeBuffer, sizeof(char), writeBufferSize, fileWrite);
    usleep(10000);
  }
  std::cout << "\nAt end write data function\n" ;
  fclose(fileWrite);
  fileWrite = nullptr;
}

/*
 * serial read data function
 */
void readData() {
  //Opening device file
  fileRead = fopen(devicename, "r");
  //check if succesfull
  if(fileRead==NULL)
  { //if there is no serial port
    printf("Unable to open device %s\n",devicename);
    exit(1);
  }//if

  while(running) {
    std::cout << "read\n";
    fread(&readBuffer,1, readBufferSize, fileRead);
    std::cout << std::endl;
    //fill buffer with serial data
    for(int i = 0; i < readBufferSize; i++){
      sensorVal[i] = readBuffer[i];
      std::cout << sensorVal[i] << ", ";
    }//end for
  }//end while
  std::cout << "\nAt end read data function\n";
  fclose(fileRead);
  fileRead = nullptr;
}

int main()
{
  // spawn new threads that calls writeData and readData
  std::thread writeSerialThread(writeData);
  std::thread readSerialThread(readData);
  //start while loop to receive keyboard input -> q -> quit program
  while(running) {
    switch (std::cin.get())
    {
      case 'q':
      std::cout << "\n******* input contains q ******** \n";
      mtx.lock();
      running = false;
      mtx.unlock();
      break;
    }
  }
  std::cout << "\n *** quited running while loop main thread";
  if(writeSerialThread.joinable()) writeSerialThread.join();
  if(readSerialThread.joinable()) readSerialThread.join();
  //end programm
  return 0;
}
