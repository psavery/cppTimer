/* Written by Patrick S. Avery -- 2015
 *
 * This is just a basic timer whose makefile is generated with CMake.
 * It prints wall-time to 6 decimal places and
 * cpu-time to 2 decimal places
 */

#include <chrono>
#include <cstdio>
#include <iostream>

void timedFunction();
void timeIt(void (*timedFunction)());

int main(int argc, char* argv[])
{
  timeIt(timedFunction);
  // Add timeIt() with different functions to be called here
}

// Add functions to be called here

void timedFunction()
{
  for (size_t i = 0; i < 100000; i++) std::cout << i << "\n";
  // Or insert a single timed function call here
}

void timeIt(void (*timedFunction)())
{
  auto start_cpu = clock();
  auto start_wall = std::chrono::high_resolution_clock::now();

  (*timedFunction)();

  auto cpuTime = (clock() - start_cpu) / (double) CLOCKS_PER_SEC;
  auto wallTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start_wall).count() * 0.000000001;

  printf("wallTime is %.6f\n", wallTime);
  printf("cpuTime is %.2f\n", cpuTime);;
}

