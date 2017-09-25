#include <QtQuickTest/quicktest.h>
#include <QtQuickControls2/qquickstyle.h>

int main(int argc, char *argv[])
{
    QTEST_ADD_GPU_BLACKLIST_SUPPORT
    QTEST_SET_MAIN_SOURCE_PATH
    QQuickStyle::setStyle("Alternative");
    return quick_test_main(argc, argv, "tst_temperaturegauge::Alternative", TST_CONTROLS_DATA);
}
