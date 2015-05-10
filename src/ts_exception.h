// vim: ts=4 sw=4 fenc=utf-8
#pragma once

#include <QString>
#include <exception>

namespace TextSecure {
    class TSException : public std::exception {
        protected:
            QString msg;
        public:
            TSException(QString msg);
            virtual const char* what() const throw();
            ~TSException() throw();
    };
}

