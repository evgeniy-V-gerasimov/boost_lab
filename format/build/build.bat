cmake -D BOOST_ROOT="c:/mingw/boost32/" -D BOOST_INCLUDEDIR="c:/mingw/boost32/include/boost-1_64/" -D BOOST_LIBRARYDIR="c:/mingw/boost32/lib/" -G"MinGW Makefiles" ..
cmake --build . -- VERBOSE=1
