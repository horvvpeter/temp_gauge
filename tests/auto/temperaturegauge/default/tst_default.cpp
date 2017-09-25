#include <QtQuickTest/quicktest.h>

int main(int argc, char *argv[])
{
    QTEST_ADD_GPU_BLACKLIST_SUPPORT
    QTEST_SET_MAIN_SOURCE_PATH
    return quick_test_main(argc, argv, "tst_temperaturegauge::Default", TST_CONTROLS_DATA);
}
