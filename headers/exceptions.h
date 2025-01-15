#ifndef EXCEPTIONS_H
#define EXCEPTIONS

namespace NumericExceptions{
    class InvalidInterval{
        private:
            const char* msg;

        public:
            InvalidInterval(const char* msg);

            const char* getErrorMsg() const throw();
    };

    class ConvergenceFailure{
        private:
            const char* msg;

        public:
            ConvergenceFailure(const char* msg);

            const char* getErrorMsg() const throw();
    };
};

#endif