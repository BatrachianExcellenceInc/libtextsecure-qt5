// vim: ts=4 sw=4 fenc=utf-8
#pragma once
#include <QByteArray>
#include "util/keyhelper.h"

namespace TextSecure {
    class TSKeyHelper : public KeyHelper {
        public:
            QByteArray generateSignalingKey();
    };
}

