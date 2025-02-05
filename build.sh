# Create a target folder for JsonCpp and build
mkdir -p $PREFIX/intermediate/jsoncpp
cmake -S thirdparty/jsoncpp-1.9.6 -B $PREFIX/intermediate/jsoncpp
make -C $PREFIX/intermediate/jsoncpp
mkdir -p $PREFIX/intermediate/lib
# Copy static library (since we'll be linking statically) to input libs folder we'll look in when building our binaries
cp $PREFIX/intermediate/jsoncpp/lib/libjsoncpp.a $PREFIX/intermediate/lib/
# Build executable utility
mkdir -p $PREFIX/bin
$CXX -o $PREFIX/bin/jsonprinter -std=c++17 -I thirdparty/jsoncpp-1.9.6/include/ -L$PREFIX/intermediate/lib main.cpp -ljsoncpp
# Build as library
mkdir -p $PREFIX/lib
$CXX -o $PREFIX/lib/libjsonprinter.so -shared -fPIC -std=c++17 -I thirdparty/jsoncpp-1.9.6/include/ -L$PREFIX/intermediate/lib -D BUILD_LIBRARY=1 main.cpp -ljsoncpp
rm -r $PREFIX/intermediate