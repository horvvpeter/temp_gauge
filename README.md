# TemperatureGauge

TemperatureGauge is a small QML gauge based on QtQuickControls 2. It can show temperature in the units of Celsius or Kelvin in two styles.

## Installation
### Requirements
- Qt 5.9
- qmake
- g++

### Installation steps
- The easiest way to install is to run the build.sh script from the root directory of the project

```sh
$ git clone git@github.com:horvvpeter/temp_gauge.git
$ cd temp_gauge
$ ./build.sh
```

## Documentation
The documentation can be found in build/doc/html after running the build.sh.
If you want to create only the documentation follow the steps below:

```sh
$ cd doc
$ qmake
$ make temperaturegauge_docs
```
