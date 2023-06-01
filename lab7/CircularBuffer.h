#ifndef LAB1_CIRCULARBUFFER_H
#define LAB1_CIRCULARBUFFER_H

#include "iterator"
#include "algorithm"

template<typename T>
class CircularBuffer {
public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T* ptr_;
    public:
        explicit iterator(T *ptr = nullptr) : ptr_(ptr) {}
        ~iterator() = default;
        T &operator*() const {
            return *(ptr_);
        }
        T *operator->() const {
            return ptr_;
        }
        T &operator[](const int n) {
            return ptr_[n];
        }
        iterator &operator++() {
            ++ptr_;
            return *this;
        }
        iterator operator++(T) {
            iterator tmp(*this);
            ++ptr_;
            return tmp;
        }
        iterator &operator--() {
            --ptr_;
            return *this;
        }
        iterator operator--(T) {
            iterator tmp(*this);
            --ptr_;
            return tmp;
        }
        iterator &operator+=(int n) {
            ptr_ += n;
            return *this;
        }
        iterator &operator-=(int n) {
            ptr_ -= n;
            return *this;
        }
        iterator operator+(int n) {
            ptr_ = ptr_ + n;
            return *this;
        }
        iterator operator-(int n) {
            ptr_ = ptr_ - n;
            return *this;
        }
        auto operator-(const iterator &it) {
            return ptr_ - it.ptr_;
        }
        bool operator<(const iterator &it) {
            return ptr_ < it.ptr_;
        }
        bool operator>(const iterator &it) {
            return ptr_ > it.ptr_;
        }
        bool operator<=(const iterator &it) {
            return ptr_ <= it.ptr_;
        }
        bool operator>=(const iterator &it) {
            return ptr_ >= it.ptr_; }
        bool operator==(const iterator &it) {
            return ptr_ == it.ptr_; }
        bool operator!=(const iterator &it) {
            return ptr_ != it.ptr_;
        }
    };
public:
    explicit CircularBuffer(size_t capacity) {
        capacity_ = capacity;
        data_ = new T[capacity_];
    }

    CircularBuffer(const CircularBuffer& cir_buf) : size_(cir_buf.size_), capacity_(cir_buf.capacity_), data_(cir_buf.data_) {}

    ~CircularBuffer() {
        delete[] data_;
    }

    // capacity, size
    size_t capacity() const {
        return this->capacity_;
    }

    size_t size() const {
        return this->size_;
    }

    bool is_empty() const {
        return size_ == 0;
    }

    bool is_full() const {
        return size_ == capacity_;
    }

    T operator[](size_t ind) {
        return data_[ind % capacity_];
    }

    T &front() const {
        return data_[0];
    }

    T &back() const {
        return data_[size_ - 1];
    }

    // iterators
    iterator begin() const {
        return iterator(data_);
    }
    iterator end() const {
        return iterator(data_ + size_);
    }


    // pushes
    void push_f(T value) {
        if (!is_full()) { // size < capacity
            for (size_t i = size_; i >= 1; i--) {
                data_[i] = data_[i - 1];
            }
            data_[0] = value;
            size_++;
        } else { // capacity == size
            for (size_t i = size_ - 1; i >= 1; i--) {
                data_[i] = data_[i - 1];
            }
            data_[0] = value;
        }
    }
    void push_b(T value) {
        if (!is_full()) {
            data_[size_] = value;
            size_++;
        } else {
            for (size_t i = 1; i < capacity_; i++)
                data_[i - 1] = data_[i];
            data_[capacity_ - 1] = value;
        }
    }

    // pops
    void pop_f() {
        for (size_t i = 0; i < size_ - 1; i++)
            data_[i] = data_[i + 1];
        size_--;
    }
    void pop_b() {
        if (!is_empty()) {
            size_--;
        }
    }

    // insert
    void insert(size_t ind, T value) { // using index
        data_[ind % size_] = value;
    }

    void insert(iterator it, T value) { // using iterator
        *(begin() + (it - begin()) % size_) = value;
    }

    // remove
    void remove(size_t ind) {
        ind %= size_;
        for (size_t i = ind + 1; i < size_; i++)
            data_[i - 1] = data_[i];
        size_--;
    }

    // resize
    void resize(size_t new_cap) {
        T* new_d = new T[new_cap];
        size_ = std::min(size_, new_cap);
        for (size_t i = 0; i < size_; i++)
            new_d[i] = data_[i];
        delete data_;
        data_ = new_d;
        capacity_ = new_cap;
    }
private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
};

#endif
