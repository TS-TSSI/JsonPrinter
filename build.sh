mkdir -p $PREFIX/intermediate/jsoncpp
cmake -S thirdparty/jsoncpp-1.9.6 -B $PREFIX/intermediate/jsoncpp
make -C $PREFIX/intermediate/jsoncpp
mkdir -p $PREFIX/intermediate/lib
cp $PREFIX/intermediate/jsoncpp/lib/libjsoncpp.a $PREFIX/intermediate/lib/
mkdir -p $PREFIX/bin
$CXX -o $PREFIX/bin/jsonprinter -std=c++17 -I thirdparty/jsoncpp-1.9.6/include/ -L$PREFIX/intermediate/lib main.cpp -ljsoncpp
rm -r $PREFIX/intermediate