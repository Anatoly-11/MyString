#include "MyString.h"
#include <cstring>
#include <utility>
//---------------------------------------------------------------------------------------------------------------------------------
namespace MyString {
  static size_t AlignedSize(size_t x, size_t align = 4) { // Функция дял получения выравненного значения
    // на заданую границу
    if(!x) return align;
    if(x != 0 && (x & (x - 1)) == 0 && x >= align) return x; // состоит из 1 бита и больше выравнивания
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    size_t r = (x - (x >> 1)) << 1;
    if(r & (align - 1))
      r = align;
    return r;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString() noexcept : _str(nullptr), _size(0), _capacity(0) {
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString(const size_t _n) noexcept : _capacity(AlignedSize(_n)), _size(0), _str(new char[_capacity]) {
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString(const MyString &str) noexcept : _capacity(AlignedSize(str._size + 1)), _size(str._size),
    _str(new char[_capacity]) {
    memcpy(this->_str, str._str, str._size + 1);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString(MyString &&str) noexcept : _capacity(str._capacity), _size(str._size), _str(str._str) {
    str._str = nullptr;
    str._size = str._capacity = 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString::MyString(char *&&s, const size_t _cap) noexcept  {
    if(s == nullptr || *s == 0) {
      _str = nullptr;  _size = _capacity = 0;
      return;
    }
    _size = strlen(s);
    _capacity = _cap >  _size + 1 ? _cap : _size + 1;
    _str = s; s = nullptr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString::MyString(const char *str) noexcept : MyString()  {
    size_t len = str == nullptr ? 0 : strlen(str);
    if(!len) return;
    _size = len;
    _capacity = AlignedSize(len + 1);
    _str = new char[_capacity];
    memcpy(_str, str, len + 1);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  int MyString::cmp(const MyString &str) const noexcept {
    return cmp(str._str);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  int MyString::cmp(const char *str) const noexcept {
    size_t len = str ? strlen(str) : 0;
    int diff = static_cast<int>(_size - len);
    return !diff ? strcmp(_str, str) : diff;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString :: ~MyString() noexcept {
    delete[] _str;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  const char * MyString::c_str() const noexcept {
    return _str;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  const size_t MyString::size() const noexcept {
    return _size;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString::emptу() const noexcept {
    return _str == nullptr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  const size_t MyString::capacity() const noexcept {
    return _capacity;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  void MyString::shink_to_fit() noexcept {
    _capacity = AlignedSize(_size + 1);
    char *ss = new char[_capacity];
    memcpy(ss, _str, (_size + 1) * sizeof(char));
    delete[] _str;
    _str = ss;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  void MyString::reserve(const size_t _n) noexcept {
    if(_capacity == _n) return; // неча резервировать!
    if(_n == 0) {
      delete[] _str;
      _str = nullptr;
      _size = _capacity = 0;
      return;
    }
    size_t len = AlignedSize(_n), sz = _size < len - 1 ? _size : len - 1; // Если помещается, то обрезать не надо!!!
    if(len == _capacity) return; // тоже неча резервировать!
    char *ss = new char[len];
    if(sz > 0) {
      memcpy(ss, _str, sz * sizeof(char));
      ss[sz] = '\0';
    }
    _size = sz;
    _capacity = len;
    delete[] _str;
    _str = ss;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  void MyString::truncate(const size_t _n) noexcept {
    if(_n < _size) {
      _str[_n] = '\0';
      _size = _n;
      if(_capacity > (_n << 2)  + 1) { // Если ёмкость больше чем для записи ещё 3-х таких же строк то слишком много,
        // уменьшаем ёмкость
        shink_to_fit();
      }
    }
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  void MyString::reverse() noexcept {
    for(size_t i = 0, j = _size - 1; i < j; ++i, --j) {
      _str[i] ^= _str[j];
      _str[j] ^= _str[i];
      _str[i] ^= _str[j];
    }
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator == (const MyString &str) const noexcept {
    return *this == str._str;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator == (const char *str) const noexcept {
    return !cmp(str);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator != (const MyString &other) const noexcept {
    return !(*this == other);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator != (const char *str) const noexcept {
    return !(*this == str);
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator>(const MyString &_s) const noexcept {
    return cmp(_s._str) > 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator<(const MyString &_s) const noexcept {
    return cmp(_s._str) < 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator>=(const MyString &_s) const noexcept {
    return cmp(_s._str) >= 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator<=(const MyString &_s) const noexcept {
    return cmp(_s._str) <= 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator>(const char *_s) const noexcept {
    return cmp(_s) > 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator<(const char *_s) const noexcept {
    return cmp(_s) < 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator>=(const char *_s) const noexcept {
    return cmp(_s) >= 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  bool MyString :: operator<=(const char *_s) const noexcept {
    return cmp(_s) <= 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString &MyString :: operator = (const MyString &str) noexcept {
    if(this != &str)
      *this = str._str;
    return *this;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString &MyString :: operator = (const char *str) noexcept {
    const size_t len = str ? strlen(str) : 0;
    if(!len)
      return *this;
    if(_capacity <= len) {
      _capacity = AlignedSize(len + 1);
      _str = new char[_capacity];
    }
    memcpy(_str, str, len + 1);
    _size = len;
    return *this;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  char &MyString :: operator [](const size_t ind) noexcept {
    return _str[ind];
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  char MyString :: operator [](const size_t ind) const noexcept {
    return _str[ind];
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString &MyString :: operator = (MyString &&str) noexcept {
    if(this == &str)
      return *this;
    delete[] _str;
    _str = str._str;
    _size = str._size;
    _capacity = str._capacity;
    str._str = nullptr;
    str._size = 0;
    str._capacity = 0;
    return *this;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString MyString :: operator+(const MyString &str) noexcept {
    if(str.emptу()) return MyString(*this);
    MyString newStr(_size + str._size + 1);
    memcpy(newStr._str, _str, _size);
    memcpy(newStr._str + _size, str._str, str._size + 1);
    newStr._size = _size + str._size;
    return newStr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString MyString :: operator+(const char *str) noexcept {
    const size_t len = str == nullptr ? 0 : strlen(str);
    if(!len) return MyString(*this);
    MyString newStr(_size + len + 1);
    memcpy(newStr._str, _str, _size);
    memcpy(newStr._str + _size, str, len + 1);
    newStr._size = _size + len;
    return newStr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MyString MyString :: operator + (const char chr) noexcept {
    if(chr == '\0') return MyString(*this); // Добвление нулевого окончаняи ничего не даёт...
    MyString newStr(_size + 2);
    memcpy(newStr._str, _str, _size);
    newStr._str[_size] = chr;
    newStr._str[_size + 1] = '\0';
    newStr._size = _size + 1;
    return newStr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  MyString operator+(const char *_cstr, const MyString &str) noexcept {
    const size_t len = str == nullptr ? 0 : strlen(_cstr);
    if(!len) return MyString(str);
    if(str.emptу()) return MyString(_cstr);
    MyString newStr(str._size + len + 1);
    memcpy(newStr._str, _cstr, len);
    memcpy(newStr._str + len, str._str, str._size + 1);
    newStr._size = str._size + len;
    return newStr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  MyString operator+(const char chr, const MyString &str) noexcept {
    if(chr == '\0')
      return MyString(""); // добавление нулевого окончания спереди эквивалентно пустой строке независмио
    // от того что дальше
    MyString newStr(str._size + 2);
    newStr._str[0] = chr;
    if(str._size > 0) memcpy(newStr._str + 1, str._str, str._size);
    newStr._str[str._size + 1] = '\0';
    newStr._size = str._size + 1;
    return newStr;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  int cmp(const char *str,  const MyString &s) noexcept {
    size_t len = str ? strlen(str) : 0;
    int diff = static_cast<int>(len - s._size);
    return !diff ? strcmp(str,  s._str) : diff;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  bool operator==(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) == 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  bool operator!=(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) != 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL bool operator>(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) > 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  bool operator<(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) < 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  bool operator>=(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) >= 0;
  }
  //-------------------------------------------------------------------------------------------------------------------------------
  MYSTRING_DLL  bool operator<=(const char *_cs, const MyString &s) noexcept {
    return cmp(_cs, s) <= 0;
  }
}
//---------------------------------------------------------------------------------------------------------------------------------