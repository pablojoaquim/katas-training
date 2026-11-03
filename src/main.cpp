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
#include <unordered_set>
#include "katas.h"
#include "parser.h"
#include "encrypt.h"
#include "singleton.h"
#include "logger.h"
#include "logger_sink_stdout.h"
#include "factory.h"
#include "server.h"
#include "filters.h"
#include "fuzzy_logic.h"
#include <iomanip>
#include <sstream>
#include <mutex>

#define DR_WAV_IMPLEMENTATION
#include "dr_wav.h"

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
class Instrument
{
    int volume;

    public:
        Instrument(int v) : volume(v) {}
        virtual void play() = 0;
        virtual ~Instrument() {}
        void setVolume(int v)
        {
            volume = v;
        }
        int getVolume() const
        {
            return volume;
        }
};

class Material
{
    std::string type;
    public:
        Material(const std::string &t) : type(t) {}
        virtual ~Material() {}
        std::string getType() const
        {
            return type;
        }
};

class Guitar : public Instrument, public Material
{
    public:
        Guitar(int v, const std::string &t) : Instrument(v), Material(t) {}
        void play() override
        {
            std::cout << "Playing guitar at volume " << getVolume() << " with material " << getType() << std::endl;
        }
};

class BigGuitar : public Guitar
{
    public:
        BigGuitar(int v, const std::string &t) : Guitar(v, t) {}
        void play() override
        {
            std::cout << "Playing big guitar at volume " << getVolume() << " with material " << getType() << std::endl;
        }
};

class SongsSingleton
{
    private:
        static SongsSingleton *instance;
        SongsSingleton() {}

    public:
        static SongsSingleton *getInstance()
        {
            if (!instance)
            {
                instance = new SongsSingleton();
            }
            return instance;
        }

        void doSomething()
        {
            std::cout << "Doing something with the SongsSingleton instance." << std::endl;
        }
};

SongsSingleton *SongsSingleton::instance = nullptr;

std::mutex mtx;

void functionTask1(void)
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    lock.lock();
    SongsSingleton *songs = SongsSingleton::getInstance();
    songs->doSomething();
    lock.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void functionTask2(void)
{
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    lock.lock();
    SongsSingleton *songs = SongsSingleton::getInstance();
    songs->doSomething();
    lock.unlock();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void testThreads(void)
{
    std::thread t1(functionTask1);
    std::thread t2(functionTask2);

    t1.join();
    t2.join();
}

template <typename T>
T sum(T a, T b)
{
    return a + b;
}

template <typename T>
std::pair<T, T> makePair (T a, T b)
{
    return std::make_pair(a, b);
}

std::vector<int> str2arr(const std::string &s)
{
    std::unique_ptr<std::vector<int>> result = std::make_unique<std::vector<int>>();
    std::vector<int> result;
    for (char c : s)
    {
        if (std::isdigit(c))
        {
            result->push_back(c - '0');
        }
    }
    return *result;
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
    Guitar g(10, "wood");
    g.play();

    std::cout << "===  End  ===" << std::endl;
    return 0;
}
