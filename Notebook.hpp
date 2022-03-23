#include "Direction.hpp"
#include <string>

using namespace std;
namespace ariel{
    class Notebook
    {
    public:
        Notebook(/* args */){}
      //  ~Notebook();
        void write(unsigned int, unsigned int, unsigned int, Direction, string);
        string read(unsigned int, unsigned int, unsigned int, Direction, unsigned int);
        void erase(unsigned int, unsigned int, unsigned int, Direction, unsigned int);
        void show (unsigned int);
    };
}