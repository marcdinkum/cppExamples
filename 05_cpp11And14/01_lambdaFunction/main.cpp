/*
 * TODO - add explenation + HANDSON TIPS
 */
#include <iostream>
#include <vector>


//function used to iterate over vector with for_each function
void myfunction (int i) {
  std::cout << ' ' << i;
}

int main() {
  //create and fill vector
  std::vector<int> myVector;
  for(int i = 0; i < 10; i++) {
    myVector.push_back(i);
  }

  //use for_each, which applies function fn to each of the elements in the range [first,last]
  //old-style -> as third parameter pass a predefined function
  std::cout << "\nIterate over vector<int> myVector with for_each, using a " <<
               "predefined function: \n";
  for_each(begin(myVector), end(myVector), myfunction);

  //use a lambda function
  std::cout << "\nIterate over vector<int> myVector with for_each, using a " <<
               "lambda function: \n";
  for_each(begin(myVector), end(myVector), [](int i){
    std::cout << '_' << i;
  });

  //end program
  std::cout << std::endl;
  return 0;
}
