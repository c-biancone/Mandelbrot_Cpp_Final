# Gigabrot


<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url] -->
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/c-biancone/Mandelbrot_Cpp_Final">
    <img src="output/test_5000.png" alt="Logo" width="800" height="800" caption="Sample Output">
  </a>

  <h3 align="center">Gigabrot_C++</h3>

<!-- DESCRIPTION -->
  <p align="left">
    This is a C++ implementation of my original Gigabrot project, put into this repo for ease of submission. Its goal is to take in user-specified parameters and efficiently produce a PPM image render of the Mandelbrot set with stripe-average colorization and a pseudo-neumorphic normal mapping effect. This project also demonstrates various fundamental aspects of coding using the C++ language. Sample output image shown above.
    <br />
    <a href="#usage"><strong>Jump to Usage»</strong></a>
    <br />
    <br />
    <!-- <a href="https://github.com/github_username/repo_name">View Demo</a> -->
    ·
    <a href="https://github.com/c-biancone/Mandelbrot_Cpp_Final/issues">Report Bug / Request Feature</a>
    ·
  </p>
</p>

<!-- TABLE OF CONTENTS
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About the project</a>
      <ul>
        <li><a href="#built-with">Built with</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements-and-references">Acknowledgements and References</a></li>
  </ol>
</details> -->

## About The Project
The <a href="https://en.wikipedia.org/wiki/Mandelbrot_set">Mandelbrot set</a> is a set of complex numbers named for <a href="https://en.wikipedia.org/wiki/Benoit_Mandelbrot">Benoit B. Mandelbrot</a> for which the function f<sub>c</sub>(z) = z<sup>2</sup> + c does not exist when z is iterated from 0. The implications of this set of numbers range far and wide in the world of mathematics, and it is often a subject of interest in computing due to its many notable properties and ease of computing. It is also widely known for its aesthetic appeal as a fractal and the many coloring techniques that can be implemented.

The stripe average colorization method implemented here, described in Jussi Härkönen's "On fractal coloring techniques", is an extension of the Triangle Inequality Average method and highlights various features of the fractal. It is combined here with a normal vector map calculated to simulate the soft, shadowy nature of <a href="https://uxdesign.cc/neumorphism-in-user-interfaces-b47cef3bf3a6"> modern neumorphic UI design</a>.

A key aspect of the set's applications in computing is that the iteration is *embarrassingly parallel*, meaning it can be easily separated into parallel tasks. Thus, the creation of the thread pool in this project. This pool uses only C++ provide libraries and uses an unlocked work queue to allow for job-stealing, inspired by <a href="https://www.youtube.com/watch?v=zULU6Hhp42w&t=3635s">Sean Parent's talk</a>.

### Note:
Parallelization of the main Mandelbrot code has not been implemented. The vector used to cache each row of the set to be written to the PPM file stream output throws a wrench in the "embarrassingly parallel" mix and I did not have time to fully debug the corrupted image output. While I removed that part of the code from my `main()`, I have included the test program I used to verify that the thread pool and its exception handling are in fact working.

#### Built With:

* CLion
* Cygwin



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps:

### Prerequisites

* C++17
* CMake 3.21

To view the output `.ppm` files and convert to `.png`:
* [Netpbm Viewer](http://paulcuth.me.uk/netpbm-viewer/)


### Cloning

1. Clone the repo into the desired directory
   ```sh
   git clone https://github.com/c-biancone/Mandelbrot_Cpp_Final.git
   ```
2. Open the directory from within CLion and build


<!-- USAGE EXAMPLES -->
## Usage

1. In CLion, hit the play button to build and run the code. In the terminal, enter the image resolution when prompted. This value is automatically checked and copied so that the image is square for this implementation. Enter the desired filename when prompted.

2. Once the code has finished running, the output can be found within the `output` directory. A 1280 x 1280 image is generated in ~2.5s on my laptop, and scales as expected according to image size.

3. Drag and drop this file into [Netpbm Viewer](http://paulcuth.me.uk/netpbm-viewer/).

4. If this file is to your liking, download the `.png` file.

##### Test Thread Pool:
5. Find `CMakeLists.txt` and switch the comment under "executables" from `src/ThreadPoolTest.cpp` to `src/main.cpp`.

6. Build and run code as before. This main function will generate a random number of exceptions thrown from within the threads of the thread pool. Run repeatedly to get different output.


<!-- CONTACT -->
## Contact

Chris Biancone - [email](chris.biancone@gmail.com)

Project Link: [https://github.com/pinecone19/Gigabrot](https://github.com/c-biancone/Mandelbrot_Cpp_Final)

### Demonstrated C++ Fundamentals
#### For Reference
* Class Inheritance
  * 3-level hierarchy
  * Is-a and Has-a relationship
  * Polymorphism
    * [pure] virtual functions
    * Abstract classes
    * Downcasting
* Operator Overloading
  * Copy constructor
  * Assignment and stream insertion operators
* Data Structures
  * (Unbounded) queue
  * Vector
* Exception handling
  * Try/catch
  * Throw/rethrow
* C++ STL
* Custom Templated Classes
* File Procesing
* String Stream Processing


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/github_username/repo.svg?style=for-the-badge
[contributors-url]: https://github.com/github_username/repo/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/github_username/repo.svg?style=for-the-badge
[forks-url]: https://github.com/github_username/repo/network/members
[stars-shield]: https://img.shields.io/github/stars/github_username/repo.svg?style=for-the-badge
[stars-url]: https://github.com/github_username/repo/stargazers
[issues-shield]: https://img.shields.io/github/issues/github_username/repo.svg?style=for-the-badge
[issues-url]: https://github.com/github_username/repo/issues
[license-shield]: https://img.shields.io/github/license/github_username/repo.svg?style=for-the-badge
[license-url]: https://github.com/github_username/repo/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/chris-biancone
