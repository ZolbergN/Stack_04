#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
    T * array_; 
    size_t array_size_;
    size_t count_ = 0;
public:
   
    Stack() noexcept: array_size_(size_t(10)),
        array_(new T[10]) { //Конструктор для стека по умолчанию
    };
   
    Stack(size_t st) noexcept: array_size_(st),
        array_(new T[st]) { //Конструктор для стека с параметром
    };
    
    Stack(const Stack& s) noexcept{
        delete[] array_;
        array_size_ = s.array_size_;
        count_ = s.count_;
        array_ = new T[s.array_size_];
        for(size_t i = 0; i < s.count_; ++i) {
          array_[i] = s.array_[i];
        }
    };
   
    Stack(Stack&& s) noexcept{
      array_size_ = s.array_size_;
      count_ = s.count_;
      array_ = s.array_;
      s.array_size_ = 0;
      s.count_ = 0;
      s.array_ = nullptr;
    };
   
    Stack<T>& operator=(const Stack& s) noexcept{
      if(this != &s) {
        delete[] array_;
        array_size_ = s.array_size_;
        count_ = s.count_;
        array_ = new T[s.array_size_];
        for(size_t i = 0; i < s.count_; ++i) {
          array_[i] = s.array_[i];
        }
      }
      return *this;
    };
    
    Stack<T>& operator=(Stack&& s) noexcept{
      if(this != &s) {
        array_size_ = s.array_size_;
        count_ = s.count_;
        array_ = s.array_;
        s.array_size_ = 0;
        s.count_ = 0;
        s.array_ = nullptr;
      }
      return *this;
    };

    T& operator [](int pos) noexcept {
        return array_[pos];
    };
    //Метод count
    size_t count() const noexcept{
        return count_;
    };

    void push(T const &value) noexcept{
        if (count_ == array_size_) {
            T* new_array_ = new T[2*array_size_];
            for (int i = 0; i < array_size_; ++i) {
                new_array_[i] = array_[i]; 
            }
            delete[] array_; 
            array_ = new_array_; 
        }
        array_[count_] = value; 
        ++count_; 
    };

    T top() const noexcept{
      return array_[count_];
    }

    void pop() noexcept{
        if (count_ == 0) {
            throw runtime_error("---Stack is empty---");
        }
        --count_;
    };

    bool empty() const noexcept{
        if(count() == 0) return true;
        return false;
    };
  
    ~Stack<T>() noexcept{
        delete[] array_;
    };
};


#endif
