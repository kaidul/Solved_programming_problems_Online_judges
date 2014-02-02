// Unsolved
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {8, 5, 6, 1};

  std::sort (myints,myints+4);

  do {
      if(myints[3] != 1 && myints[3] != 5)
        std::cout << myints[0] << myints[1] << myints[2] << myints[3] <<'\n';
  } while ( std::next_permutation(myints, myints+4) );

  //std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
