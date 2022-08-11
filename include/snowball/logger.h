
#include <string>
#include "colors.h"

#ifndef __SNOWBALL_LOGGER_H_
#define __SNOWBALL_LOGGER_H_

#define VSNPRINTF_BUFF_SIZE 8192


namespace snowball {

    class Logger {

        public:
        static void log     (std::string message);
        static void rlog    (std::string message);
        static void elog    (std::string message);

        static void info    (std::string message);
        static void help    (std::string message);
        static void error   (std::string message);
        static void warning (std::string message);
        static void verbose (std::string message);
        static void success (std::string message);

        // status messages
        static void reset_status();
        static void compiling (std::string message);

        static std::string progress(float progress = 0);
        static std::string format(const char* p_format, ...);

    };
}

#endif // __SNOWBALL_LOGGER_H_
