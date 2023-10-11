#include "immstring.hpp"
#include <iostream>

// Functions from <cstring> may be used to ease working with
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>
#include <stdio.h>

namespace Util
{

  // NOTE: Compiler errors related to this constructor provide hints to
  //        where else you need to use `const`.
  ImmutableString::ImmutableString(ImmutableString *const other)
      : m_size{other->size()}, // Order of initialization is important here!
        m_data{new char[m_size + 1]}
  {
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other->c_str(), m_size + 1, m_data);
  }

  ImmutableString::ImmutableString(const char *src)
      : m_size{(int)strlen(src)},
        m_data{new char[m_size + 1]}
  {
    std::copy_n(src, m_size + 1, m_data);
  }

  ImmutableString ImmutableString::concat(ImmutableString other) const
  {
    char *y = (char *)malloc(other.m_size + this->m_size);
    strcat(y, this->c_str());
    strcat(y, other.c_str());
    ImmutableString output{y};
    delete[] y;
    return output;
  }

  ImmutableString::ImmutableString(char *buf, int len)
      : m_size{len},
        m_data{new char[len]}
  {
    strcpy(m_data, buf);
  }

  char *ImmutableString::c_str() const
  {
    return m_data;
  }

  int ImmutableString::size() const
  {
    return m_size;
  }

    ImmutableString::~ImmutableString()
  {
  }

} // Util