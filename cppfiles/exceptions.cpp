#include "../headers/exceptions.h"

//--
NumericExceptions::InvalidInterval::InvalidInterval(const char* msg) {this->msg = msg;}
const char* NumericExceptions::InvalidInterval::getErrorMsg() const throw() {return this->msg;}
//--

//--
NumericExceptions::ConvergenceFailure::ConvergenceFailure(const char* msg) {this->msg = msg;}
const char* NumericExceptions::ConvergenceFailure::getErrorMsg() const throw() {return this->msg;}
//--