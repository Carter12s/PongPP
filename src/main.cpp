#define ELPP_NO_DEFAULT_LOG_FILE
#define ELPP_STL_LOGGING

#include<iostream>
#include <easylogging++.h>

INITIALIZE_EASYLOGGINGPP

int main(){
    el::Configurations conf("../logging.conf");
    el::Loggers::reconfigureAllLoggers(conf);
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    LOG(ERROR) << "Hello World" << std::endl;
	std::cout << "Hello World" << std::endl;
}
