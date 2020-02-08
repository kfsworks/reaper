# ./env-prepare.sh
rm -rf ./build/ && mkdir -p build/default include src

export CC=/usr/bin/clang && export CXX=/usr/bin/clang++ && cd build/default  && cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -GNinja ../..
