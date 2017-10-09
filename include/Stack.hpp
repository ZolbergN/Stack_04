#ifndef STACK_HPP
#define STACK_HPP

#include <iostream> 
#include <string> 
#include <stdexcept> 

using namespace std;

template <typename T>
class Stack {
private:
	T* array_;
	size_t array_size_;
	size_t count_;
public:
	Stack() noexcept : array_size_(8), array_(new T[array_size_]), count_(0) {}
	Stack(size_t max_el) noexcept : array_size_(max_el), array_(new T[max_el]), count_(0) {}

	Stack(const Stack& s) noexcept {
		if (this != &s) {
			delete[] array_;
			array_size_ = s.array_size_;
			count_ = s.count_;
			array_ = new T[s.array_size_];
			for (size_t i = 0; i < s.array_size_; ++i) {
				array_[i] = s.array_[i];
			}
		}
	}

	Stack(Stack&& s) noexcept : array_size_(s.array_size_), count_(s.count_), array_(s.array_) {

		s.array_size_ = 0;
		s.count_ = 0;
		s.array_ = nullptr;
	}

	Stack<T>& operator=(const Stack& s) noexcept{
      		if(this == &s) return *this;
      		else {
        		delete[] array_;
        		array_size_ = s.array_size_;
        		count_ = s.count_;
        		array_ = new T[s.array_size_];
        		for(size_t i = 0; i < s.array_size_; ++i) {
         	 array_[i] = s.array_[i];
        	}
        	return *this;
      }
    }
  
    	Stack<T>& operator=(Stack&& s) noexcept{
      		array_size_ = s.array_size_;
      		count_ = s.count_;
      		array_ = s.array_;
      		s.array_size_ = 0;
      		s.count_ = 0;
      		s.array_ = nullptr;
      		return *this;
    }
	size_t count() const noexcept {
		return count_;
	}

	bool empty() const noexcept {
		if (count() == 0) return true;
		return false;
	}

	void push(T const &value) noexcept {
		if (count_ == array_size_) {
			T* array_size2_ = new T[2 * array_size_];
			for (int i = 0; i != array_size_; ++i) {
				array_size2_[i] = array_[i];
			}
			array_size_ *= 2;
			delete[] array_;
			array_ = array_size2_;
		}
		array_[count_++] = value;
	}

	T& top() const noexcept {
		return array_[count_];
	}

	void pop() noexcept {
		if (count_ == 0) domain_error{ "ERROR —- STACK EMPTY" };
	--count_;
	}

	~Stack() noexcept {
		delete[] array_;
	}

	T& operator[](int ij) noexcept {
		return array_[ij];
	}
};



#endif
