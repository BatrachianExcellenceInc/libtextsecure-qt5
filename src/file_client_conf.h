// vim: ts=4 sw=4 fenc=utf-8
#include <QDir>
#include <QObject>
#include <stdint.h>
#include "ts_exception.h"
#include "file_pre_key_store.h"
#include "util/keyhelper.h"

namespace TextSecure {
    class ClientConfException : public TSException {
        public:
            ClientConfException(QString msg);
    };

    class ClientConf : public QObject {
        Q_OBJECT
        private:
            // members
            KeyHelper keyHelper; // so the class can verify keys exist
            FilePreKeyStore preKeyStore; // to avoid subclassing libaxolot's keyhelper for this
            QString baseUrl;
            QString confDirPath;
            QDir confDir;

            QString number;
            QString password;
            quint64 registrationId;

            // consider subclassing KeyHelper to have getters for these and the store
            QByteArray signalingKey;
            IdentityKeyPair identityKeyPair;

        protected:
            // methods
            void verifyConfDir();
            void verifyNumber();
            void verifyPassword();
            void verifyRegistrationId();
            void verifySignalingKey();
            void verifyIdentityKeyPair();

        public:
            // methods
            explicit ClientConf(QString baseUrl, QString confDir, QString number, QObject *parent = 0);
            QString getBaseUrl();
            QString getNumber();
            QString getPassword();
            quint64 getRegistrationId();
            QByteArray getSignalingKey();
    };
}

