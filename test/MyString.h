#pragma once
#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#ifdef MYSTRING_EXPORTS
#define MYSTRING_DLL __declspec(dllexport)
#else 
#define MYSTRING_DLL __declspec(dllimport)
#endif 
//---------------------------------------------------------------------------------------------------------------------------------
namespace MyString {
  // Класс строки реализующий её основные функции 
  class MYSTRING_DLL MyString {
    int cmp(const MyString &) const noexcept;
    int cmp(const char *) const noexcept;
    friend   int cmp(const char *str, const MyString &s) noexcept;

  public:

    // Оператор сложения cтрокb с нулевым окончанием c MyString
    friend MYSTRING_DLL  MyString operator+(const char *_cstr, const MyString &str) noexcept;

    // Оператор сложения символa c MyString
    friend MYSTRING_DLL  MyString operator+(const char chr, const MyString &str) noexcept;

    // Оператор равенства строкой с нулевым окончанием с MyString
    friend MYSTRING_DLL  bool operator==(const char *_cs, const MyString &s) noexcept;

    // Оператор неравенства строкой с нулевым окончанием с MyString
    friend MYSTRING_DLL  bool operator!=(const char *_cs, const MyString &s) noexcept;

    // Оператор > и т.д.
    friend MYSTRING_DLL bool operator>(const char *_s, const MyString &s ) noexcept;

    friend MYSTRING_DLL  bool operator<(const char *_s, const MyString &s) noexcept;

    friend MYSTRING_DLL  bool operator>=(const char *_s, const MyString &s) noexcept;

    friend MYSTRING_DLL  bool operator<=(const char *_s, const MyString &s) noexcept;

    // Конструктор по умолчанию
    MyString() noexcept;

    // Конструктор c резервированеим места
    MyString(const size_t _n) noexcept;

    // Деструктор
    ~MyString() noexcept;

    // Конструктор со строкой
    MyString(const char *) noexcept;

    // Конструктор копии
    MyString(const MyString &) noexcept;

    // Конструктор пермещения
    MyString(MyString &&) noexcept;

    // Получение буфера строки с нулевым окончанием
    const char *c_str() const noexcept;

    // Получение длинны строки
    const size_t size() const noexcept;

    // Получение ёмкости строки
    const size_t capacity() const noexcept;

    // пустая ли строка
    bool emptу() const noexcept;

    // подогнать ёмкость под размер строки
    void shink_to_fit() noexcept;

    // Зарезервировать место в строке с перемещением помещающейся части. 
    void reserve(const size_t _n) noexcept;

    // Обрезать строку
    void truncate(const size_t _n) noexcept;

    // обратить строку
    void reverse() noexcept;

    // Оператор равенства со внешней строкой с нулевым окончанием
    bool operator==(const char *) const noexcept;

    // Оператор неравенства строк
    bool operator!=(const MyString &) const noexcept;

    // Оператор неравенства со внешней строкой с нулевым окончанием
    bool operator!=(const char*) const noexcept;

    // Оператор равенства строк
    bool operator==(const MyString &) const noexcept;

    // Оператор > и т.д.
    bool operator>(const MyString &) const noexcept;

    bool operator<(const MyString &) const noexcept;

    bool operator>=(const MyString &) const noexcept;

    bool operator<=(const MyString &) const noexcept;

    bool operator>(const char *_s) const noexcept;

    bool operator<(const char *_s) const noexcept;

    bool operator>=(const char *_s) const noexcept;

    bool operator<=(const char *_s) const noexcept;

    // Оператор присвоения копии
    MyString &operator=(const MyString &) noexcept;

    // Оператор перемещения копии
    MyString &operator=(MyString &&) noexcept;

    // Оператор присвоения со внешней строкой с нулевым окончанием
    MyString &operator=(const char *) noexcept;

    // Оператор сложения со строкой
    MyString operator+(const MyString &) noexcept;

    // Оператор сложения со внешней строкой с нулевым окончанием
    MyString operator+(const char *) noexcept;

    // Оператор сложения с символом
    MyString operator+(const char) noexcept;

    // Оператор доступа к символоу строки по индексу для чтения и записи
    char &operator[](const size_t) noexcept;

    // Оператор доступа к символоу строки по индексу только для чтения 
    char operator[](const size_t) const noexcept;

  private:
    // Не перставлять местами!!!
    size_t _capacity;
    size_t _size;
    char *_str;
  };

  MYSTRING_DLL  MyString operator+(const char *_cstr, const MyString &str) noexcept;

  MYSTRING_DLL  MyString operator+(const char chr, const MyString &str) noexcept;
}
#endif // !_MYSTRING_H_
//---------------------------------------------------------------------------------------------------------------------------------

