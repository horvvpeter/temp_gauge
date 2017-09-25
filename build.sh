rm -rf /home/peti/Qt/5.9/gcc_64/qml/TemperatureGauge
rm -rf build
mkdir build
cd build
qmake ..
make -j4
make install
make check
