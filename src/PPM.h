#ifndef C___PPM_H
#define C___PPM_H

#include <fstream>
#include <cstring>
#include <sstream>
#include <array>
#include <vector>
#include <iostream>

class PPM
{
 public:

  /**
   * Default parametrized constructor
   * contains output directory and file name
   * @param width
   * @param height
   */
  PPM(int width, int height);

  /**
   * Minimal parametrized constructor
   * Only needs file name, contains output directory
   * @param fileName
   * @param width
   * @param height
   */
  PPM(const std::string& fileName, int width, int height);

  /**
   * Copy constructor
   * @param oldPPM - dereferenced old object
   */
  PPM(const PPM& oldPPM);

  /**
   * Sets output directory destination
   * @param fileNameIn
   */
  void set_outputDirectory(const std::string& outputDirectoryIn);

  /**
   * Overloaded assignment operator used to override output directory and file name
   * @param fileNameIn
   * @return
   */
  PPM& operator=(std::string fileNameIn);

  /**
   * Initialize ofstream
   * @return
   */
  bool init_stream();

  /**
   * Print row of pixels to PPM file - templated for size of array
   * @tparam N - std::array size
   * @param row - std::array of pixels
   */
  //template<size_t N>
  void write_row(const std::vector<unsigned char> &row)
  {
    image.write((char const *) row.data(), row.size());
  }

  /**
   * Print entire 2D array to PPM file
   */
   void write_array(const unsigned char &img)
   {
     for (size_t y; y = 0; )
   }

  /**
   * Print header data to PPM file
   */
  void write_header();

  /**
   * Set magic number
   */
  void set_magic(std::string magicIn);

  /**
   * Get magic number
   */
  std::string get_magic();

  /**
   * Set width of PPM image
   * @param widthIn
   */
  void set_width(int widthIn);

  /**
   * Set height of PPM image
   * @param heightIn
   */
  void set_height(int heightIn);

  /**
   * Set custom comment for PPM image
   * @param commentIn
   */
  void set_comment(std::string commentIn);

  /**
   * Close ofstream for image
   */
  void close();


 private:

  /**
   * Determines type of PPM
   */
  std::string magic = "";

  const std::string pixMaxVal = "255\n";

  int width;

  int subPixel;

  int height;

  std::string comment;

  /**
   * Contains full header info
   */
  std::stringstream header;

  std::string outputDirectory;

  std::string fileName;

  std::ofstream image;
};

#endif //C___PPM_H