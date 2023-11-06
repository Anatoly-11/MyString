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
  // ����� ������ ����������� � �������� ������� 
  class MYSTRING_DLL MyString {
    int cmp(const MyString &) const noexcept;
    int cmp(const char *) const noexcept;
    friend   int cmp(const char *str, const MyString &s) noexcept;

  public:

    // �������� �������� c����b � ������� ���������� c MyString
    friend MYSTRING_DLL  MyString operator+(const char *_cstr, const MyString &str) noexcept;

    // �������� �������� ������a c MyString
    friend MYSTRING_DLL  MyString operator+(const char chr, const MyString &str) noexcept;

    // �������� ��������� ������� � ������� ���������� � MyString
    friend MYSTRING_DLL  bool operator==(const char *_cs, const MyString &s) noexcept;

    // �������� ����������� ������� � ������� ���������� � MyString
    friend MYSTRING_DLL  bool operator!=(const char *_cs, const MyString &s) noexcept;

    // �������� > � �.�.
    friend MYSTRING_DLL bool operator>(const char *_s, const MyString &s ) noexcept;

    friend MYSTRING_DLL  bool operator<(const char *_s, const MyString &s) noexcept;

    friend MYSTRING_DLL  bool operator>=(const char *_s, const MyString &s) noexcept;

    friend MYSTRING_DLL  bool operator<=(const char *_s, const MyString &s) noexcept;

    // ����������� �� ���������
    MyString() noexcept;

    // ����������� c ��������������� �����
    MyString(const size_t _n) noexcept;

    // ����������
    ~MyString() noexcept;

    // ����������� �� �������
    MyString(const char *) noexcept;

    // ����������� �����
    MyString(const MyString &) noexcept;

    // ����������� ����������
    MyString(MyString &&) noexcept;

    // ��������� ������ ������ � ������� ����������
    const char *c_str() const noexcept;

    // ��������� ������ ������
    const size_t size() const noexcept;

    // ��������� ������� ������
    const size_t capacity() const noexcept;

    // ������ �� ������
    bool empt�() const noexcept;

    // ��������� ������� ��� ������ ������
    void shink_to_fit() noexcept;

    // ��������������� ����� � ������ � ������������ ������������ �����. 
    void reserve(const size_t _n) noexcept;

    // �������� ������
    void truncate(const size_t _n) noexcept;

    // �������� ������
    void reverse() noexcept;

    // �������� ��������� �� ������� ������� � ������� ����������
    bool operator==(const char *) const noexcept;

    // �������� ����������� �����
    bool operator!=(const MyString &) const noexcept;

    // �������� ����������� �� ������� ������� � ������� ����������
    bool operator!=(const char*) const noexcept;

    // �������� ��������� �����
    bool operator==(const MyString &) const noexcept;

    // �������� > � �.�.
    bool operator>(const MyString &) const noexcept;

    bool operator<(const MyString &) const noexcept;

    bool operator>=(const MyString &) const noexcept;

    bool operator<=(const MyString &) const noexcept;

    bool operator>(const char *_s) const noexcept;

    bool operator<(const char *_s) const noexcept;

    bool operator>=(const char *_s) const noexcept;

    bool operator<=(const char *_s) const noexcept;

    // �������� ���������� �����
    MyString &operator=(const MyString &) noexcept;

    // �������� ����������� �����
    MyString &operator=(MyString &&) noexcept;

    // �������� ���������� �� ������� ������� � ������� ����������
    MyString &operator=(const char *) noexcept;

    // �������� �������� �� �������
    MyString operator+(const MyString &) noexcept;

    // �������� �������� �� ������� ������� � ������� ����������
    MyString operator+(const char *) noexcept;

    // �������� �������� � ��������
    MyString operator+(const char) noexcept;

    // �������� ������� � �������� ������ �� ������� ��� ������ � ������
    char &operator[](const size_t) noexcept;

    // �������� ������� � �������� ������ �� ������� ������ ��� ������ 
    char operator[](const size_t) const noexcept;

  private:
    // �� ����������� �������!!!
    size_t _capacity;
    size_t _size;
    char *_str;
  };

  MYSTRING_DLL  MyString operator+(const char *_cstr, const MyString &str) noexcept;

  MYSTRING_DLL  MyString operator+(const char chr, const MyString &str) noexcept;
}
#endif // !_MYSTRING_H_
//---------------------------------------------------------------------------------------------------------------------------------

