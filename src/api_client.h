// vim: ts=4 sw=4 fenc=utf-8
#include <QNetworkReply>
#include <QObject>
#include <QUrl>
#include "ts_exception.h"
#include "file_client_conf.h"


namespace TextSecure {
    class ApiException : public TSException {
        public:
            ApiException(QString msg);
    };

    class ApiResponse : public QObject {
        Q_OBJECT
        public:
            // members
            int resCode;
            QString resBody;

            // methods
            explicit ApiResponse(QObject *parent = 0, int resCode=0, QString resBody="(empty)");
            void validate();
            ~ApiResponse();
    };

    class ApiClient : public QObject {
        Q_OBJECT
        public:
            explicit ApiClient(ClientConf *conf, QObject *parent = 0);
            ~ApiClient();
        protected:
            // members
            QNetworkAccessManager mgr;
            ClientConf *conf;
            static const int apiVersion = 1;

            // methods
            void checkInstallation();
            QUrl genPath(QString);
            void getResponse(QUrl);
            void putResponse(QUrl, QString, QString);
            void handleNetworkResponse(QNetworkReply *);
            void handleResponse(ApiResponse *);
            void printSslErrors(QList<QSslError>);
        public slots:
            void getVerificationCode(QString);
            void confirmVerificationCode(QString);
    };
}

