/* Written by Patrick S. Avery -- 2015
 *
 * This is just a basic timer compiled with CMake.
 * It prints wall-time to about 4 decimal places and
 * cpu-time to about 2 decimal places
 */

#include <chrono>
#include <iostream>

void timedFunction()
{
  // Insert timed function call here
}

int main(int argc, char* argv[])
{
  auto start_cpu = clock();
  auto start_wall = std::chrono::high_resolution_clock::now();

  timedFunction();

  auto cpuTime = (clock() - start_cpu) / (double) CLOCKS_PER_SEC;
  auto wallTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start_wall).count() * 0.000000001;

  std::cout << "wallTime is " << wallTime << "\n";
  std::cout << "cpuTime is " << cpuTime << "\n";
}
