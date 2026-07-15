#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <tuple>


template<typename T>
void PrintIterator(T begin , T end) {
    std::cout << "the value of this iterator is : ";
    for (auto it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PrintContainer(const Container& container) {
    std::cout << "the elements of this container is : ";
    for (const auto& el : container) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


// 万能打印器：递归打印 tuple
template<typename Tuple, size_t... Is>
void print_tuple_impl(const Tuple& t, std::index_sequence<Is...>) {
    ((std::cout << std::get<Is>(t) << " "), ...);
}


template<typename... Args>
void print_tuple(const std::tuple<Args...>& t) {
    print_tuple_impl(t, std::index_sequence_for<Args...>{});
}

// -------- 模板打印函数 --------
template<typename T>
void print_all(const T& obj) {
    print_tuple(obj.tie());
}


template<typename T>
void cout__(const T& info) {
    std::cout << "info" << " :  "; 
    std::cout << info <<std::endl; 
}

template<typename T>
void cline__(const T& info) {
    std::cout << info <<std::endl; 
}