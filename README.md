# toy_calculator
The toy project as a proof of concept for having front end React and back end C++

The instructions to having this running in Windows is as followed:
1. Clone this repo
2. Use chocolatey to install openssl:
choco install openssl
4. Clone restbed recursively and place it inside toy_calculator/calculator_back-end folder:
git clone --recursive https://github.com/corvusoft/restbed.git
5. Copy all the files in Program Files/OpenSSL-Win64/ into restbed/dependency/openssl (replace the file in destination). 
6. Go into restbed/cmake folder. The file Findopenssl need to be changed. Copy the Findopenssl file that is provided in the current folder into the cloned restbed.
7. Make a build folder at calculator_back-end. cd into it. Then open a terminal and start build the back-end (together with restbed):
mkdir build \
cd build \
cmake -G "Visual Studio 16 2019" -DBUILD_EXAMPLES=NO -DBUILD_TESTS=NO .. \
cmake --build . --target ALL_BUILD --config Release
9. Go to toy_calculator/calculator_front-end and build the react app:\
npm install
11. Start front end:
npm start
12. Open another terminal and go to calculator_back-end/build/Release. Start back end with:
./CalculatorAPI.exe
13. Play with the calculator
