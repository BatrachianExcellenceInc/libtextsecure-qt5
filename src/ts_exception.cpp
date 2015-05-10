// vim: ts=4 sw=4 fenc=utf-8
#include <QString>
#include "ts_exception.h"

using namespace TextSecure;

TSException::TSException(QString msg) {
    this->msg = msg;
}

const char* TSException::what() const throw() {
    return this->msg.toStdString().c_str();
}

TSException::~TSException() throw() {
}

