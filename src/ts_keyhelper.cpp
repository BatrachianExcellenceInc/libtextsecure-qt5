// vim: ts=4 sw=4 fenc=utf-8
#include "ts_keyhelper.h"

using namespace TextSecure;

QByteArray TSKeyHelper::generateSignalingKey() {
    return getRandomBytes(52);
}

