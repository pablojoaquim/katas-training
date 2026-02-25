#ifndef KATAS_H
#define KATAS_H

/*===========================================================================*/
/**
 * @file kata.h
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION: API for the Person module
 *
 * @todo Add full description here
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
 * Header Files (Common to C and C++)
 *===========================================================================*/
#include <stdint.h>
#include <stddef.h>
#include <unordered_map>

#ifdef __cplusplus
/*===========================================================================*
 * Header Files (C++ only)
 *===========================================================================*/
#include <string>
#endif

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Classes (C++ only)
 *===========================================================================*/
#ifdef __cplusplus
template <typename T>
int add(T param1, T param2)
{
  return param1 + param2;
}

template <typename T>
class Box
{
    public:
        Box(T value) 
        {
            this->value = value;
        }
        
        T getValue() const 
        { 
            return value; 
        }

    private:
        T value;
};

template <typename T1,  typename T2>
class Pair
{
    public:
        Pair(T1 first, T2 second) 
        {
            this->first = first;
            this->second = second;
        }
        
        T1 getFirst() const 
        { 
            return first; 
        }

        T2 getSecond() const 
        { 
            return second; 
        }

        void display() const
        {
            std::cout << "First: " << first << ", Second: " << second << std::endl;
        }
        
    private:
        T1 first;
        T2 second;
};

// @todo: Add C++ class declarations here.
class Vehicle
{
    public:
        Vehicle();
        ~Vehicle();

        void SetSpeed(int speed);
        int GetSpeed();

        void SetAccel(int accel);
        void Periodic1SCalc();

        virtual void GetSound() = 0;

    private:
        int Speed;
        int Accel;
};


class Car: public Vehicle
{
    public:
        Car();
        ~Car();

        void SetModel(std::string model);
        void SetModel(std::string model, int model_year);
        void SetModel(std::string model, int model_year, std::string color);
        std::string GetModel();
        int GetModelYear();
        std::string GetColor();

        void GetSound() override;
        
    private:
        std::string Model;
        int ModelYear;
        std::string Color;
};
#endif

/*===========================================================================*
 * Exported C Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif
    // @todo: Add pure C function prototypes here.

#ifdef __cplusplus
} /* extern "C" */
#endif

/*===========================================================================*
 * Exported C++ Function Prototypes
 *===========================================================================*/
#ifdef __cplusplus
// @todo: Add pure C++ function prototypes here.

/*****************************************************************************
 * @fn         encode
 * @brief      Takes a string and encode it
 * @param [in] p_what - The string to encode
 * @return     The encoded string
 ******************************************************************************/
std::string encode(const std::string &p_what);

/*****************************************************************************
 * @fn         decode
 * @brief      Takes an encoded string and decode it
 * @param [in] p_what - The string to decode
 * @return     The decoded string
 ******************************************************************************/
std::string decode(const std::string& p_what);

#endif /* __cplusplus */

/*===========================================================================*/
/*===========================================================================*/
#endif /* KATAS_H */
