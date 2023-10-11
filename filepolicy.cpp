#include <fstream>

#include "filepolicy.hpp"

FilePolicy::FilePolicy(const char *fname)
{
    myFile.open(fname, std::ios_base::app);
    myFile << "Opened file \n";
}

FilePolicy::~FilePolicy()
{
    if (myFile.is_open())
    {
        myFile << std::endl
               << std::endl;

        myFile.close();
    }
}

void FilePolicy::write(const std::string &message)
{
    myFile << message;
}

//bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Hannan Mahadik, Moayad Okal