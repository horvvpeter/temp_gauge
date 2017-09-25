import QtQuick 2.2
import QtTest 1.0
import TemperatureGauge.Template 1.0 as T

TestCase {
    id: testCase
    name: "TestTemperatureGaugeTemplate"
    property int defaultValue: 0
    property int defaultMinValue: -50
    property int defaultMaxValue: 50
    property double celsiusToKelvin: 274.15

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
        compare(control.value, defaultValue);
        compare(control.displayValue, defaultValue);

        var valueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "valueChanged"});
        var displayValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayValueChanged"});
        verify(valueChangedSpy.valid);
        verify(displayValueChangedSpy.valid);

        // test change
        control.value = 23;
        compare(control.value, 23);
        compare(control.displayValue, 23);
        compare(valueChangedSpy.count, 1);
        compare(displayValueChangedSpy.count, 1);

        // test no change
        control.value = 23;
        compare(valueChangedSpy.count, 1);
    }

    function test_minMaxValue() {
        var control = tempGauge.createObject(testCase);
        verify(control);
        compare(control.minValue, defaultMinValue);
        compare(control.displayMinValue, defaultMinValue);
        compare(control.maxValue, defaultMaxValue);
        compare(control.displayMaxValue, defaultMaxValue);

        var minValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "minValueChanged"});
        var displayMinValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayMinValueChanged"});
        var maxValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "maxValueChanged"});
        var displayMaxValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayMaxValueChanged"});
        verify(minValueChangedSpy.valid);
        verify(displayMinValueChangedSpy.valid);
        verify(maxValueChangedSpy.valid);
        verify(displayMaxValueChangedSpy.valid);

        // test change
        control.minValue = -20;
        compare(control.minValue, -20);
        compare(control.displayMinValue, -20);
        compare(minValueChangedSpy.count, 1);
        compare(displayMinValueChangedSpy.count, 1);

        control.maxValue = 20;
        compare(control.maxValue, 20);
        compare(control.displayMaxValue, 20);
        compare(maxValueChangedSpy.count, 1);
        compare(displayMaxValueChangedSpy.count, 1);

        // test no change
        control.minValue = -20;
        control.maxValue = 20;
        control.minValue = 40;
        control.maxValue = -30;
        compare(control.minValue, -20);
        compare(control.maxValue, 20);
        compare(minValueChangedSpy.count, 1);
        compare(maxValueChangedSpy.count, 1);
    }

    function test_displayUnit() {
        var control = tempGauge.createObject(testCase);
        verify(control);
        compare(control.displayUnit, T.TemperatureGauge.Celsius);
        compare(control.value, defaultValue);
        compare(control.displayValue, defaultValue);
        compare(control.displayMinValue, defaultMinValue);
        compare(control.displayMaxValue, testCase.defaultMaxValue);

        var displayUnitChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayUnitChanged"});
        var displayValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayValueChanged"});
        var displayMinValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayMinValueChanged"});
        var displayMaxValueChangedSpy = signalSpy.createObject(control, {target: control, signalName: "displayMaxValueChanged"});
        verify(displayUnitChangedSpy.valid);
        verify(displayValueChangedSpy.valid);
        verify(displayMinValueChangedSpy.valid);
        verify(displayMaxValueChangedSpy.valid);

        // test change
        control.displayUnit = T.TemperatureGauge.Kelvin;
        compare(control.displayUnit, T.TemperatureGauge.Kelvin);
        compare(control.displayValue, celsiusToKelvin);
        compare(control.displayMinValue, celsiusToKelvin + testCase.defaultMinValue);
        compare(control.displayMaxValue, celsiusToKelvin + testCase.defaultMaxValue);

        compare(displayUnitChangedSpy.count, 1);
        compare(displayValueChangedSpy.count, 1);
        compare(displayMinValueChangedSpy.count, 1);
        compare(displayMaxValueChangedSpy.count, 1);

        // test no change
        control.displayUnit = T.TemperatureGauge.Kelvin;
        compare(displayUnitChangedSpy.count, 1);
    }
}
