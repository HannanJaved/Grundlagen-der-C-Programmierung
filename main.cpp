#include <iostream>

#include "vector.hpp"

using Vec3 = Math::Vector<float, 3>;

void test(bool expr, const std::string &failmessage, bool &fail)
{
    if (!(expr))
    {
        std::cerr << failmessage.c_str() << std::endl;
        fail = true;
    }
}

int main()
{

    bool fail = false;
    {

        // Todo: test the functionality of your vector.
        // Test all written functions.
        // Return 0 if everything works, 1 if not.
        Vec3 a;
        for (unsigned int i = 0; i < a.SIZE; ++i)
        {
            test(a[i] == 0, "Default constructor should initialize with zero.", fail);
        }

        //read access
        {
            Vec3 a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = rand();
            }
            Vec3 b(a);
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(a[i] == b[i], "Copy construction failed.", fail);
            }
        }

        {
            Vec3 a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = i;
            }
            Vec3 b(a);
            Vec3 x = b + a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(x[i] == b[i] + a[i], "Operation+ failed", fail);
            }
        }

        {
            Vec3 a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = i;
            }
            Vec3 x = -a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(x[i] == -a[i], "unary Operation- failed.", fail);
            }
        }

        {
            Vec3 a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = i;
            }
            Vec3 b(a);
            Vec3 x = b - a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(x[i] == b[i] - a[i], "Operation- failed.", fail);
            }
        }

        {
            Vec3 a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                a[i] = i;
            }
            Vec3 b = a * 5.f;
            Vec3 x = 5.f * a;
            for (unsigned int i = 0; i < a.SIZE; ++i)
            {
                test(x[i] == b[i] && a[i] * 5 == x[i] && a[i] * 5 == b[i], "Operation* failed.", fail);
            }
        }

        if (fail)
        {
            std::cerr << "\n ------- Test run failed! :( ------- \n";
            return 1;
        }
        else
        {
            std::cerr << "\n ------- All tests passed! :) ------- \n";
            return 0;
        }
    }
}

//bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Hannan Mahadik, Moayad Okal.