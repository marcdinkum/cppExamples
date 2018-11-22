#include <iostream>
#include <fstream>
#include <sys/stat.h>
using namespace std;


bool fileExists(const std::string& filename)
{
  // create a variable of type "struct stat"
  struct stat buffer;
  //check if file exists
  if (stat(filename.c_str(), &buffer) != -1)
  {
    return true;
  }
  return false;
}

int main (int argc, char **argv) {
  // retrieve filePath
  std::string fileName;
  if(argc > 1) {
    fileName = argv[1];
  } else fileName = "output";

  std::string fileExtension;
  if(argc > 2) {
    fileExtension = argv[1];
  } else fileExtension = "txt";

  std::string filePath = fileName + "." + fileExtension;
  std::cout << "\n" << filePath << "\n";
  // does file already exists?
  if(fileExists(filePath))
  {
    std::cout <<  "\nFile already exists, do you want to overwrite it? y / n?\n";
    std::string answer;
    std::cin >> answer;
    if(answer != "y")
    {
      std::cout <<  "\nDO NOT OVERWRITE --> EXITING NOW!\n";
      return 0;
    }
  }

  // open file
  ofstream myfile (filePath);
  if (myfile.is_open())
  {
    // write to file
    myfile << "Adding the first line to the file.";
    myfile << "Another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  // end program
  return 0;
}
