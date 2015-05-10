// vim: ts=4 sw=4 fenc=utf-8
#pragma once

#include <QDir>
#include <QString>
#include "ts_exception.h"
#include "state/prekeystore.h"
#include "util/keyhelper.h"

namespace TextSecure {
    class PreKeyStoreException : public TSException {
        public:
            PreKeyStoreException(QString msg);
    };

    class FilePreKeyStore : public PreKeyStore {
        private:
            QString getKeyFile(qulonglong pre_key_id);
            QString preKeyDirPath;
            QDir preKeyDir;
            QString signedPreKeyDirPath;
            QDir signedPreKeyDir;
            QDir confDir;
            KeyHelper keyHelper;

        public:
            FilePreKeyStore() {};  // Keep the compiler happy
            FilePreKeyStore(QString preKeyDir, QString signedPreKeyDir, KeyHelper keyHelper);
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

