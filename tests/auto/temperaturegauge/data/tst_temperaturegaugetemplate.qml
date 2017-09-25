import QtQuick 2.2
import QtTest 1.0
import TemperatureGauge.Template 1.0 as T

TestCase {
    id: testCase
    name: "TestTemperatureGaugeTemplate"

    Component {
        id: tempGauge
        T.TemperatureGauge { }
    }

    Component {
        id: signalSpy
        SignalSpy { }
    }

    function test_value() {
        var control = tempGauge.createObject(testCase);
        verify(control);
        compare(control.value, 0);

        var valueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "valueChanged"});
        verify(valueChangedSpy.valid);
        control.value = 23;
        compare(control.value, 23);
        compare(valueChangedSpy.count, 1);

        control.value = 23;
        compare(valueChangedSpy.count, 1);
    }

    function test_displayUnit() {
        var control = tempGauge.createObject(testCase);
        verify(control);
        compare(control.displayUnit, T.TemperatureGauge.Celsius);

        var displayUnitChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayUnitChanged"});
        verify(displayUnitChangedSpy.valid);
        control.displayUnit = T.TemperatureGauge.Kelvin;
        compare(control.displayUnit, T.TemperatureGauge.Kelvin);
        compare(displayUnitChangedSpy.count, 1);

        control.displayUnit = T.TemperatureGauge.Kelvin;
        compare(displayUnitChangedSpy.count, 1);
    }
}
