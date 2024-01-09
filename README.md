# toy_calculator
The toy project as a proof of concept for having front end React and back end C++

The instructions to having this running in Windows is as followed:
1. Clone this repo
2. Use chocolatey to install openssl:
choco install openssl
4. Clone restbed recursively and place it inside calculator_back-end folder:
git clone --recursive https://github.com/corvusoft/restbed.git
5. Copy all the files in Program Files/OpenSSL-Win64/ into restbed/dependency/openssl
6. Make a build folder at calculator_back-end. cd into it. Then open a terminal and start build the back-end (together with restbed):
cmake -G "Visual Studio 16 2019" -DBUILD_EXAMPLES=NO -DBUILD_TESTS=NO .. \
cmake --build . --target ALL_BUILD --config Release
8. Go to calculator_front-end and build the react app
9. Start front end:
npm start
10. Open another terminal and go to calculator_back-end/build/Release. Start back end with:
./CalculatorAPI.exe
11. Play with the calculator
