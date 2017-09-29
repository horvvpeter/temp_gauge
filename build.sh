rm -rf build
mkdir build
cd build
qmake ..
make -j4
make install
make check
cd doc
make temperaturegauge_docs
