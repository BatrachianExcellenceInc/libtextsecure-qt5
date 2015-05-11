// vim: ts=4 sw=4 fenc=utf-8
#pragma once

#include <QDir>
#include <QString>
#include "ts_pre_key_store.h"
#include "ts_keyhelper.h"

namespace TextSecure {
    class FilePreKeyStore : public PreKeyStore {
        private:
            QString getKeyFile(qulonglong pre_key_id);
            QString preKeyDirPath;
            QDir preKeyDir;
            QString signedPreKeyDirPath;
            QDir signedPreKeyDir;
            QDir confDir;
            TSKeyHelper keyHelper;

        public:
            FilePreKeyStore() {};  // Keep the compiler happy
            FilePreKeyStore(QString preKeyDir, QString signedPreKeyDir, TSKeyHelper keyHelper);
            void verifyPreKeyDir();
            void verifySignedPreKeyDir();
            void verifyPreKeys();
            void verifyLastResortPreKey();

            PreKeyRecord loadPreKey(qulonglong preKeyId);
            void storePreKey(qulonglong preKeyId, const PreKeyRecord &record);
            bool containsPreKey(qulonglong preKeyId);
            void removePreKey(qulonglong preKeyId);
            int countPreKeys();

            void setNextPreKeyId(qulonglong id);
            qulonglong getNextPreKeyId();
    };
}

