#ifndef DEFAULT
#define DEFAULT

#include <string>
#include <iostream>
using namespace std;

/**
 * @brief This is the abstract class of the IO streams in this program.
 * 
 */
class DefaultIO {
    public:
    /**
     * @brief this is the read (input) func.
     * 
     * @return string (the string that inputed).
     */
        virtual string read() = 0;
        
        /**
         * @brief this is the write (output) func.
         * 
         * @param str (the string to wrtie).
         */
        virtual void write(string str) = 0;
};


#endif // DEFAULT