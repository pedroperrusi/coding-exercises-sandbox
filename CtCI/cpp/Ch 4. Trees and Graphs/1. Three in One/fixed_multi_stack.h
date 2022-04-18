#pragma once
#include <array>
#include <exception>
#include <iostream>
#include <numeric>
#include <stdexcept>

/**
 * @brief Fixed size implementation of multiple stacks
 * 
 * @tparam T : type of data to be stored
 * @tparam CAPACITY : Fixed allocated space for the stack
 * @tparam NSTACKS : Number of stacks
 */
template <typename T, std::size_t CAPACITY, std::size_t NSTACKS = 3>
class FixedMultiStack {
   public:
    FixedMultiStack() {
        _sizes.fill(0);   // only need to initialize _sizes
        _data.fill(T());  // clear any data value
        for (size_t i = 0; i < _idx_offsets.size(); i++) {
            _idx_offsets[i] = i * NSTACKS;
        }
    }

    inline void push(size_t stack_id, T data) {
        if (isFull(stack_id)) throw std::length_error("Stack is full!");
        _sizes[stack_id]++;  // expand
        auto idx = getStackIndex(stack_id);
        _data[idx] = data;
    }

    inline T pop(size_t stack_id) {
        if (_sizes[stack_id] == 0) throw std::range_error("Stack is empty!");
        auto idx = getStackIndex(stack_id);
        auto data = _data[idx];
        _data[idx] = 0;      // clear
        _sizes[stack_id]--;  //shrink
        return data;
    }

    inline T peek(size_t stack_id) {
        if (_sizes[stack_id] == 0) throw std::range_error("Stack is empty!");
        auto idx = getStackIndex(stack_id);
        return _data[idx];
    }

    inline bool isEmpty(size_t stack_id) { return _sizes[stack_id] == 0; }

    inline bool isFull(size_t stack_id) {
        return _sizes[stack_id] == CAPACITY / NSTACKS;
    }

    inline void print() {
        std::cout << "Multi stack\n"
                  << "\t of sizes: ";
        for (const auto& size : _sizes) std::cout << size << " ";
        std::cout << "\n\t and data: ";
        for (const auto& item : _data) std::cout << item << " ";
        std::cout << std::endl;
    }

   private:
    std::array<T, CAPACITY> _data;
    std::array<size_t, NSTACKS> _sizes;
    std::array<size_t, NSTACKS> _idx_offsets;

    /**
     * @brief The index of each stack element will be the sum of their sizes.
     */
   public:
    inline size_t getStackIndex(size_t stack_id) {
        if (stack_id >= NSTACKS) {
            throw std::range_error("Stack id out of range");
        }
        if (_sizes[stack_id] <= 1) return _idx_offsets[stack_id];

        return _idx_offsets[stack_id] + _sizes[stack_id] - 1;
    }
};