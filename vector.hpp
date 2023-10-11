#pragma once

#include <cstdint>

/* Implement a generic mathematical Vector.
 * todo: * add template parameters
 *       * implement the required operators
 *       * test all functions
 *       * keep it const correct
 */
namespace Math
{

    // The vector should have both a generic numeric type(T) and a number of dimensions(N).
    // The data can be stored in an array of type T and size N.
    template <typename T, unsigned int N>
    class Vector
    {
    public:
        Vector()
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = 0;
            }
        }

        Vector(Vector<T, N> const &v)
        {
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = v[i];
            }
        }

        // Todo: Implement an operator[] overload for reading!
        T operator[](unsigned int const pos) const
        {
#ifdef DEBUG
            if (pos >= SIZE)
            {
                throw std::out_of_range("Index out of bounds.");
            }
#endif
            return data[pos];
        }

        // Todo: Implement an operator[] overload for read/write access!
        T &operator[](unsigned int const pos)
        {
#ifdef DEBUG
            if (pos >= SIZE)
            {
                throw std::out_of_range("Index out of bounds.");
            }
#endif
            return data[pos];
        }
        // Todo: Implement a unary operator- overload that returns a copy with all components negated.
        Vector<T, N> operator-()
        {
            Vector<T, N> res;
            for (unsigned int i = 0; i < N; i++)
            {
                res[i] = -data[i];
            }
            return res;
        }
        // Todo: Implement an operator+ overload that takes a vector of same type and size.
        Vector<T, N> operator+(Vector<T, N> const &v)
        {
            Vector<T, N> res;
            for (unsigned int i = 0; i < N; i++)
            {
                res[i] = data[i] + v[i];
            }
            return res;
        }
        // Todo: Implement an operator- overload that takes a vector of same type and size.
        Vector<T, N> operator-(Vector<T, N> const &v)
        {
            Vector<T, N> res;
            for (unsigned int i = 0; i < N; i++)
            {
                res[i] = data[i] - v[i];
            }
            return res;
        }
        enum MetaInfo
        {
            SIZE = N
        };
        // Todo: Implement an operator* overload that takes a vector from the left and a scalar from the right side.
        // Returns a vector.
        Vector<T, N> operator*(T const &v)
        {
            Vector<T, N> res;
            for (unsigned int i = 0; i < N; i++)
            {
                res[i] = data[i] * v;
            }
            return res;
        }

        friend Vector<T, N> operator*(const T &x, Vector<T, N> const &v)
        {
            Vector<T, N> res;
            for (unsigned int i = 0; i < N; i++)
            {
                res[i] = x * v[i];
            }
            return res;
        }

    private:
        T data[N];
    };
    // Todo: Implement a operator* overload that takes a vector from the right and a scalar from the left side.
    // Returns a vector.
}


//bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Hannan Mahadik, Moayad Okal.