/*===========================================================================*/
/**
 * @file main.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Add a description here
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - @todo Update list of other applicable standards
 *
 */
/*==========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <cstdint>
#include <vector>
#include <thread>
#include <chrono>
#include "katas.h"
#include "parser.h"
#include "encrypt.h"
#include "singleton.h"
#include "logger.h"
#include "logger_sink_stdout.h"
#include "factory.h"
#include "server.h"
#include "filters.h"
#include <iomanip>
#include <sstream>
#include <openssl/evp.h>

#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"
#include <mutex>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
#define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define NumElems(arr) (sizeof(arr) / sizeof((arr)[0]))

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
extern "C"
{
}

/*===========================================================================*
 * Simple C++ Objects - Polymorphism Example
 *===========================================================================*/
class Animal
{
    private:
    std::string name;

    public:

    Animal(std::string name)
    : name(name)
    {
            std::cout << "=== Object Created ===" << std::endl;
    }

    virtual void shape()
    {
        std::cout << "=== Animal Shape ===" << std::endl;
    }

    virtual void sound() final
    {
        std::cout << "=== Animal Sound ===" << std::endl;
    }

    ~Animal()
    {
            std::cout << "=== Object Destroyed ===" << std::endl;
    }
};

class Cat : public Animal
{
    public:
    Cat(std::string name) : Animal(name) {}

    void shape() override final
    {
        std::cout << "=== Cat Shape ===" << std::endl;
    }
};

class Dog : public Animal
{
    public:
    Dog(std::string name) : Animal(name) {}

    void shape() override
    {
        std::cout << "=== Dog Shape ===" << std::endl;
    }
};

class Grandanes : public Dog
{
    public:
    Grandanes(std::string name) : Dog(name) {}

    void shape() override
    {
        std::cout << "=== Grandanes Shape ===" << std::endl;
    }
};

void test_polymorphism()
{
    Animal* pAnimal;

    Cat cat1 = Cat("Whiskers");
    Dog dog1 = Dog("Buddy");
    Grandanes grandanes1 = Grandanes("Max");

    pAnimal = &cat1;
    pAnimal->shape();

    pAnimal = &dog1;
    pAnimal->shape();

    pAnimal = &grandanes1;
    pAnimal->shape();

    cat1.shape();
    dog1.shape();
    grandanes1.shape();

    cat1.sound();
    dog1.sound();
    grandanes1.sound();
}

/*===========================================================================*
 * Templates Example
 *===========================================================================*/
class Shape
{
    public:
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape
{
    private:
    double width;
    double height;

    public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double perimeter() const override
    {
        return 2 * (width + height);
    }
};
class Circle : public Shape
{
    private:
    double radius;

    public:
    Circle(double r) : radius(r) {}

    double perimeter() const override
    {
        return 2 * 3.14159265358979323846 * radius;
    }
};

template <typename T>
void print_perimeter (T shape)
{
    std::cout << "Perimeter: " << shape.perimeter() << std::endl;
}

void test_template_shapes()
{
    Rectangle rect(3.0, 4.0);
    Circle circ(5.0);

    print_perimeter(rect);
    print_perimeter(circ);
}

/*===========================================================================*
 * Singleton Example
 *===========================================================================*/
void test_singleton()
{
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    std::cout << "s1 address: " << &s1 << std::endl;
    std::cout << "s2 address: " << &s2 << std::endl;
}

/*===========================================================================*
 * Smart Pointers Example
 *===========================================================================*/
void test_smart_pointers()
{
    std::unique_ptr<int> smart_p = std::make_unique<int>(30);
    std::cout << "*smart_p = " << *smart_p << std::endl;

    auto shared_smart_p = std::make_shared<int>(40);
    std::shared_ptr<int> shared_smart_p_copy = shared_smart_p;
    std::cout << "*shared_smart_p = " << *shared_smart_p << std::endl;
    std::cout << "*shared_smart_p_copy = " << *shared_smart_p_copy << std::endl;
    *shared_smart_p = 20;
    std::cout << "*shared_smart_p = " << *shared_smart_p << std::endl;
    std::cout << "*shared_smart_p_copy = " << *shared_smart_p_copy << std::endl;
    *shared_smart_p_copy = 50;
    std::cout << "*shared_smart_p = " << *shared_smart_p << std::endl;
    std::cout << "*shared_smart_p_copy = " << *shared_smart_p_copy << std::endl;
}

/*===========================================================================*
 * Threads Example
 *===========================================================================*/
std::mutex mtx;
int resource = 0;

void task1() {
    for(int i=0; i<10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Thread 1 is running. ID: " << std::this_thread::get_id() << "\n";

        mtx.lock();
        resource++;
        std::cout << "Resource: " << resource << std::endl;
        mtx.unlock();
    }
}

void task2() {
    for(int i=0; i<10; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Thread 2 is running. ID: " << std::this_thread::get_id() << "\n";

        // mtx.lock();
        std::lock_guard<std::mutex> lock(mtx);
        resource--;
        std::cout << "Resource: " << resource << std::endl;
        // mtx.unlock();
    }
}

void test_threads()
{
    std::thread t1(task1);
    std::thread t2(task2);
    t1.join();
    t2.join();
}

/*===========================================================================*
 * Cryptography Example
 *===========================================================================*/
std::string sha256(const std::string &input) {
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLength = 0;

    EVP_MD_CTX* ctx = EVP_MD_CTX_new();

    if (ctx == nullptr)
        throw std::runtime_error("Cannot create digest context");

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1 ||
        EVP_DigestUpdate(ctx, input.data(), input.size()) != 1 ||
        EVP_DigestFinal_ex(ctx, hash, &hashLength) != 1)
    {
        EVP_MD_CTX_free(ctx);
        throw std::runtime_error("SHA-256 failed");
    }

    EVP_MD_CTX_free(ctx);

    std::ostringstream result;

    for (unsigned int i = 0; i < hashLength; ++i)
    {
        result << std::hex
               << std::setw(2)
               << std::setfill('0')
               << static_cast<unsigned int>(hash[i]);
    }

    return result.str();
}

/*****************************************************************************
 * @fn         main
 * @brief      The main entry point
 * @param [in] void
 * @return     0 -success, -1 -Error
 *****************************************************************************/
int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << "=== Start ===" << std::endl;
    
    // test_polymorphism();
    
    // test_template_shapes();

    // test_singleton();

    // test_threads();
    
    // test_smart_pointers();

    const std::string message = "Hello, cryptography!";
    std::cout << "Message: " << message << '\n';
    std::cout << "SHA-256: " << sha256(message) << '\n';

    std::cout << "\nChanging one character...\n";
    std::cout << "SHA-256: "
              << sha256("Hello, cryptography?")
              << '\n';

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
