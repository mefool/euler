/* Project Euler - Problem 26
  Reciproval cycles

  p026.exe
  g++ p026.cpp -o p026.exe
  
  Comments/Issues:
  > 

*/
#include <iostream>
#include <vector>

#define LIMIT 1000

int cycle_lenght(int d){
  if (d == 0)
    return 0;

  int pos = 1;
  int div = 1;
  
  std::vector<int> last_pos(d,0);

  for(;;){
    int r = div % d;
    if (r == 0)
      return 0;
    if (last_pos[r] != 0)
      return pos - last_pos[r];
    last_pos[r] = pos;
    pos++;
    div = r*10;
  }
}

int main(int argc, char *argv[]) {
  int max = 0, i_max = 0;
  for (int i = 0; i < LIMIT; i++){
    int lenght = cycle_lenght(i);
    if (lenght > max){
      max = lenght;
      i_max = i;
    }
  }
  std::cout << "Number with the maximum length: " << i_max << " (" << max << ")" << std::endl;
  return 0;
	 
}
