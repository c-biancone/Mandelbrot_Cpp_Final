#include "PPM.h"
#include "Colorization.h"
#include "Mandelbrot.h"
#include "ThreadPool.h"

#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int width;
  int height;

  // set up input handling to prevent creation of image with distortion for
  // given default Mandelbrot parameters
  bool invalidInput = true;
  while (invalidInput)
  {
    cout << "Enter square image size in pixels:\n";
    string line;
    getline(cin, line);
    istringstream is(line);

    char dummy;
    if (!(is >> width) || (is >> ws && is.get(dummy)) || width <= 0)
    {
      cout << "Invalid input. Try again:\n";
    } else {
      invalidInput = false;
    }
  }
  height = width;


  // handle invalid filename inputs
  string fileName;
  bool invalidChar = true;
  while (invalidChar)
  {
    cout << "Enter output file name in the form 'name.ppm':\n";
    cin >> fileName;
    for (const char c : fileName)
    {
      if (!isalnum(c) && !ispunct(c))
      {
        cout << "Invalid character found. Try again:\n";
        break;
      } else {
        invalidChar = false;
        break;
      }
    }
  }

  auto begin = chrono::steady_clock::now();

  // set up image stream for writing
  PPM pgm(fileName, width, height);
  // PPM pgm(width, height); // for testing
  if (!pgm.init_stream())
  {
    cout << "Could not open ofstream for image\n";
    return -1;
  }
  pgm.write_header();

  // set up container for image row data
  vector<unsigned char> row{}; // array needs compile-time const length
  bool ppmTrue = (pgm.get_magic() == "P6\n");
  if (ppmTrue)
  {
    // if rgb need 3x row length
    row.resize(width * 3);  // avoid constant resizing by allocating up front
  } else {
    row.resize(width);
  }

  cout << "Rendering row by row:\n";

  // using basic constructor since I only want this image
  // call member functions here to set specific parameters
  Mandelbrot gigabrot(width, height);
  cout << gigabrot;

  // unsigned int numThreads = thread::hardware_concurrency();
  // cout << "numThreads: " << numThreads << "\n";

  for (size_t pY = 0; pY < height; pY++)
  {
    for (size_t pX = 0; pX < width; pX++)
    {
      gigabrot.current_pixel(pX, pY);
      gigabrot.get_c();
      gigabrot.iterate();

      if (ppmTrue) {
        size_t subPixel = 3 * pX;
        row[subPixel + 2] = row[subPixel + 1] = row[subPixel] =
            gigabrot.colorize_bw();
      } else {
        row[pX] = gigabrot.colorize_bw();
      }

      gigabrot.reset();
    }
    {
      // implemented due to possibility of having huge image, keep memory usage low
      // might be causing the issues with parallelization, ruining the embarrassingly parallel
      // aspect of the Mandelbrot set
      pgm.write_row(row);
    }
  }

  pgm.close();

  auto end = chrono::steady_clock::now();
  cout << "Time elapsed: "
       << static_cast<float>(chrono::duration_cast<chrono::milliseconds>
           (end - begin).count()) / 1000.F
       << " sec\n";

  return 0;
}