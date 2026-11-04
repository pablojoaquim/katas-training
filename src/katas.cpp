/*===========================================================================*/
/**
 * @file katas.cpp
 *
 *------------------------------------------------------------------------------
 * Copyright (c) 2025 - Pablo Joaquim
 * MIT License: https://opensource.org/licenses/MIT
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 * Develop the code to solve the kata in this file
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
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include "katas.h"
#include <vector>
#include <fstream>
#include <filesystem>
#include <unordered_set>

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/
// #define NDEBUG

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
#define QUEUE_SIZE 50

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/
typedef int q_elem;

typedef struct queue
{
    q_elem buf[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} queue_t;

/*===========================================================================*
 * Local Object Declarations
 *===========================================================================*/

/*===========================================================================*
 * Local Variables Definitions
 *===========================================================================*/
// int working_arr[100];

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

static void printArr(int curr, size_t len, int *arr)
{
    std::printf("-- %d --- ", curr);
    for (size_t i = 0; i < len; ++i)
    {
        std::printf("%d ", arr[i]);
    }
    std::printf("\n");
}

static void q_init(queue_t *q)
{
    q->head = q->tail = q->count = 0;
}

static bool q_is_empty(queue_t *q)
{
    return (0 == q->count);
}

static bool q_is_full(queue_t *q)
{
    return (QUEUE_SIZE == q->count);
}

static bool q_push(queue_t *q, q_elem elem)
{
    if (q_is_full(q))
        return false;
    q->buf[q->tail] = elem;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
    q->count++;
    return true;
}

static bool q_pop(queue_t *q, q_elem *out)
{
    if (q_is_empty(q))
        return false;
    *out = q->buf[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count--;
    return true;
}

/*****************************************************************************
 * Name         Methods declaration
 *****************************************************************************/
Vehicle::Vehicle()
    : Speed(0),
      Accel(0)
{
    std::cout << "Constructor called" << std::endl;
}

Vehicle::~Vehicle()
{
    std::cout << "Destructor called" << std::endl;
}

void Vehicle::SetSpeed(int speed)
{
    this->Speed = speed;
}

int Vehicle::GetSpeed() const
{
    return this->Speed;
}

void Vehicle::SetAccel(int accel)
{
    this->Accel = accel;
}

void Vehicle::Periodic1SCalc()
{
    this->Speed += this->Accel;
}

// void Vehicle::GetSound()
// {
//     std::cout << "Vroom!" << std::endl;
// }

Car::Car()
    : Model(),
      ModelYear(0),
      Color()
{
    std::cout << "Constructor called" << std::endl;
}

Car::~Car()
{
    std::cout << "Destructor called" << std::endl;
}

void Car::SetModel(std::string model)
{
    this->Model = model;
}

std::string Car::GetModel() const
{
    return this->Model;
}

void Car::SetModel(std::string model, int model_year)
{
    this->Model = model;
    this->ModelYear = model_year;
}

void Car::SetModel(std::string model, int model_year, std::string color)
{
    this->Model = model;
    this->ModelYear = model_year;
    this->Color = color;
}

int Car::GetModelYear() const
{
    return this->ModelYear;
}

std::string Car::GetColor() const
{
    return this->Color;
}

void Car::GetSound()
{
    std::cout << "Beep!" << std::endl;
}

std::string operator+(const Vehicle &v1, const Vehicle &v2)
{
    return "Combined speed: " + std::to_string(v1.GetSpeed() + v2.GetSpeed());
}

std::ostream &operator<<(std::ostream &os, const Vehicle &v)
{
    os << "Speed: " << v.Speed << ", Accel: " << v.Accel;
    return os;
}

void filesystem_example()
{
    try
    {
        Car car1, car2, car3, car4;
        car1.SetModel("Sedan", 2020, "Red");
        car2.SetModel("SUV", 2021, "Blue");
        car3.SetModel("Coupe", 2019, "Black");
        car4.SetModel("Hatchback", 2022, "White");
        std::vector<Car> cars;
        cars.push_back(car1);
        cars.push_back(car2);
        cars.push_back(car3);
        cars.push_back(car4);

        std::cout << car1 + car2 << std::endl;
        std::cout << "Vehicle 1: " << car1 << std::endl;
        std::cout << "Vehicle 2: " << car2 << std::endl;

        std::ofstream WriteFile("example.txt");
        // Enable exceptions
        WriteFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

        std::cout << std::filesystem::current_path() << std::endl;

        if (WriteFile.is_open())
        {
            std::cout << "File opened successfully" << std::endl;
            WriteFile << "Info: System started" << std::endl;
            WriteFile << "Debug: Value received" << std::endl;

            for (auto &car : cars)
            {
                WriteFile << "Model: " << car.GetModel() << ", Year: " << car.GetModelYear() << ", Color: " << car.GetColor() << std::endl;
            }

            WriteFile.close();
        }
        else
        {
            std::cerr << "Failed to open file" << std::endl;
        }

        std::ifstream ReadFile("example.txt");
        // Enable exceptions
        ReadFile.exceptions(std::ifstream::badbit);

        if (ReadFile.is_open())
        {
            std::string line;
            while (std::getline(ReadFile, line))
            {
                std::cout << line << std::endl;
            }
            ReadFile.close();
        }
        else
        {
            std::cerr << "Failed to read file" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

/*****************************************************************************
 * Name         is_pangram
 * Description  A pangram is a sentence that contains every single letter of
 *              the alphabet at least once.
 *****************************************************************************/
bool is_pangram(const std::string &s)
{
    unsigned char abc[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if (c >= 'A' && c <= 'Z')
        {
            c -= 'A';
            c += 'a';
        }
        if (c >= 'a' && c <= 'z')
            abc[c - 'a'] = 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (abc[i] == 0)
            return false;
    }

    return true;
}

/*****************************************************************************
 * Name         is_palindrome
 * Description  Detects whether a string is a palindrome.
 *****************************************************************************/
bool is_palindrome(const std::string &s)
{
    std::string normalized;
    normalized.reserve(s.length());

    for (char c : s)
    {
        unsigned char uc = static_cast<unsigned char>(c);
        if ((uc >= '0' && uc <= '9') || (uc >= 'A' && uc <= 'Z') || (uc >= 'a' && uc <= 'z'))
        {
            if (uc >= 'A' && uc <= 'Z')
            {
                uc = static_cast<unsigned char>(uc - 'A' + 'a');
            }
            normalized.push_back(static_cast<char>(uc));
        }
    }

    size_t left = 0;
    size_t right = (normalized.empty() ? 0 : normalized.length() - 1);

    while (left < right)
    {
        if (normalized[left] != normalized[right])
            return false;
        left++;
        right--;
    }

    return true;
}

/*****************************************************************************
 * Name         add_binary
 * Description  Adds two numbers and return the solution in binary represented as strings.
 *****************************************************************************/
std::string add_binary(uint64_t a, uint64_t b)
{
    uint64_t sum = a + b;

    std::string binary = "";

    if (sum == 0)
        return "0";

    while (sum != 0)
    {
        binary = std::to_string(sum % 2) + binary;
        sum /= 2;
    }

    return binary;
}

/*****************************************************************************
 * Name         rtrim
 * Description  Removes trailing whitespace from a string.
 *****************************************************************************/
std::string rtrim(std::string str)
{
    for (size_t i = str.length(); i > 0; --i)
    {
        if (!std::isspace(str[i - 1]))
        {
            return str.substr(0, i);
        }
    }
    return "";
}

/*****************************************************************************
 * Name         stripComments
 * Description  Removes comments from a string based on the provided marker characters.
 *****************************************************************************/
std::string stripComments(const std::string &str, const std::unordered_set<char> &markers)
{
    std::string result;
    std::vector<std::string> lines;

    for (size_t i = 0, last_pos = 0; i < str.length(); ++i)
    {
        if (str[i] == '\n' || i == str.length() - 1)
        {
            lines.push_back(str.substr(last_pos, i - last_pos + 1)); // Get the line up to the newline
            last_pos = i + 1;                                        // Update the position of the last newline
        }
    }

    size_t pos = 0;
    bool found_marker = false;
    for (const auto &line : lines)
    {
        pos = std::string::npos; // Reset position for each line
        found_marker = false;    // Reset marker found flag for each line

        // Check for each marker in the line and find the earliest occurrence
        for (auto &marker : markers)
        {
            pos = line.find(marker);
            if (pos != std::string::npos)
            {
                // Extract the part of the line before the marker and trim trailing whitespace
                std::string comment_free_line = rtrim(line.substr(0, pos));
                // Append the comment-free line to the result
                result.append(comment_free_line);
                // If the original line had a newline, we need to maintain it in the result
                if(line.find('\n') != std::string::npos)
                {
                    result.append("\n");
                }
                found_marker = true;
                break; // Stop checking other markers for this line
            }
        }

        // No marker found, add the whole line
        if (!found_marker)
        {
            result.append(rtrim(line));
            // If the original line had a newline, we need to maintain it in the result
            if(line.find('\n') != std::string::npos)
            {
                result.append("\n");
            }
        }
    }

    return result;
}

/*****************************************************************************
 * Name         snail
 * Description  Traverses a 2D array in a snail pattern and returns the elements in order.
 *****************************************************************************/
std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
    std::vector<int> result={};

    int col=0;
    int row=0;

    int max_col=snail_map[0].size();
    int max_row=snail_map.size();

    while (col < max_col && row < max_row) {
        // Traverse right
        for (int i = col; i < max_col; ++i) {
            result.push_back(snail_map[row][i]);
        }
        row++;

        // Traverse down
        for (int i = row; i < max_row; ++i) {
            result.push_back(snail_map[i][max_col - 1]);
        }
        max_col--;

        if (row < max_row) {
            // Traverse left
            for (int i = max_col - 1; i >= col; --i) {
                result.push_back(snail_map[max_row - 1][i]);
            }
            max_row--;
        }

        if (col < max_col) {
            // Traverse up
            for (int i = max_row - 1; i >= row; --i) {
                result.push_back(snail_map[i][col]);
            }
            col++;
        }
    }

  return {result};
}

/*****************************************************************************
 * Name         decodeMorse
 * Description  Decodes a Morse code string into a human-readable string.
 *****************************************************************************/
const std::unordered_map<std::string, std::string> MORSE_CODE = {
    {".-", "A"},    {"-...", "B"},  {"-.-.", "C"},  {"-..", "D"},
    {".", "E"},     {"..-.", "F"},  {"--.", "G"},   {"....", "H"},
    {"..", "I"},    {".---", "J"},  {"-.-", "K"},   {".-..", "L"},
    {"--", "M"},    {"-.", "N"},    {"---", "O"},   {".--.", "P"},
    {"--.-", "Q"},  {".-.", "R"},   {"...", "S"},   {"-", "T"},
    {"..-", "U"},   {"...-", "V"},  {".--", "W"},   {"-..-", "X"},
    {"-.--", "Y"},  {"--..", "Z"},

    {"-----", "0"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"},
    {"....-", "4"}, {".....", "5"}, {"-....", "6"}, {"--...", "7"},
    {"---..", "8"}, {"----.", "9"}
};

std::string decodeMorse(const std::string& morseCode)
{
    std::vector<std::string> words;
    std::string word;

    size_t pos = 0;
    size_t start = 0;
    std::string token;
    std::string result;

    while (pos < morseCode.length()) {
        pos = morseCode.find("   ", start);
        if (pos == std::string::npos) {
            word = morseCode.substr(start);
            start = morseCode.length();
        } else {
            word = morseCode.substr(start, pos - start);
            start = pos + 3;
        }
        words.push_back(word);
    }

    for (const auto& w : words) {
        size_t start = 0;
        pos = 0;
        while(pos < w.length())
        {
            pos = w.find(" ", pos);

            if (pos == std::string::npos) {
                pos = w.length();
            }
            token = w.substr(start, pos-start);
            std::cout << start << "-" << pos << " >> " << token << std::endl;
            
            if(token != "")
            {
                result += MORSE_CODE.at(token);
            }
            
            start = pos + 1;
            pos += 1;
        }
        result += " "; // Add space between words
    }

    // Remove spaces from the beginning and end of the result string
    while(!result.empty() && result[0] == ' ') {
        result.erase(result.begin()); // Remove leading space
    }
    while(!result.empty() && result.back() == ' ') {
        result.pop_back(); // Remove trailing space
    }

    return result;
}

/*****************************************************************************
 * Name         decodeBits
 * Description  Decodes a string of bits into a Morse code string.
 *****************************************************************************/
std::string decodeBits(const std::string& bits) 
{
    std::string morseCode = "";

    // Remove extra leading and trailing zeros
    size_t firstOne = bits.find('1');
    size_t lastOne = bits.rfind('1');
    std::string trimmedBits = bits.substr(firstOne, lastOne - firstOne + 1);

    // Find the rate of the signal (the length of the shortest sequence of 1s or 0s)
    int minLength = trimmedBits.length();
    char currentChar = trimmedBits[0];
    int count = 1;
    for (size_t i = 1; i < trimmedBits.length(); i++) 
    {
        if (trimmedBits[i] == currentChar) 
        {
            count++;
        } 
        else 
        {
            if (count < minLength) 
            {
                minLength = count;
            }
            currentChar = trimmedBits[i];
            count = 1;
        }
    }
    if (count < minLength) 
    {
        minLength = count;
    }

    std::cout << minLength << std::endl;

    // Convert the bit string to Morse code using the determined rate
    // "Dot" – is 1 time unit long.
    // "Dash" – is 3 time units long.
    // Pause between dots and dashes in a character – is 1 time unit long.
    // Pause between characters inside a word – is 3 time units long.
    // Pause between words – is 7 time units long.
    int cnt_dots_and_dashes=0;
    int cnt_pauses = 0;
    for (size_t i=0; i<trimmedBits.length(); i+=minLength)
    {
        std::string segment = trimmedBits.substr(i, minLength);
        if (segment[0] == '1') 
        {
            cnt_dots_and_dashes++;
            cnt_pauses = 0;
        } 
        else 
        {
            cnt_pauses++;
            if(cnt_pauses == 1)
            {
                if(cnt_dots_and_dashes == 1)
                {
                    morseCode += ".";
                }
                if(cnt_dots_and_dashes == 3)
                {
                    morseCode += "-";
                }
                cnt_dots_and_dashes = 0;
            }
            if(cnt_pauses == 3)
            {
                morseCode += " ";
            }
            if(cnt_pauses == 7)
            {
                morseCode.pop_back(); // Remove the previously added space
                morseCode += "   ";
            }            
        }
    }

    // check for any remaining dots or dashes at the end of the signal
    if(cnt_dots_and_dashes == 1)
    {
        morseCode += ".";
    }
    if(cnt_dots_and_dashes == 3)
    {
        morseCode += "-";
    }

    // std::cout << morseCode << std::endl;
    return morseCode;
}