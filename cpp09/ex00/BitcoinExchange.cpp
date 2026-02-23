#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>


Date::Date () : _y (0), _m (0), _d (0) {
}

Date::Date (int y, int m, int d) : _y (y), _m (m), _d (d) {
}

Date::Date (const Date& other) {
    *this = other;
}

Date& Date::operator= (const Date& other) {
    if (this != &other) {
        _y = other._y;
        _m = other._m;
        _d = other._d;
    }
    return *this;
}

Date::~Date () {
}

int Date::key () const {
    return _y * 10000 + _m * 100 + _d;
}

Date Date::from_string (const std::string& str) {
    if (str.size () < 10)
        throw std::exception ();
    int y = std::atoi (str.substr (0, 4).c_str ());
    int m = std::atoi (str.substr (5, 2).c_str ());
    int d = std::atoi (str.substr (8, 2).c_str ());

    if (m < 1 || m > 12)
        throw std::exception ();
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        days[1] = 29;
    if (d < 1 || d > days[m - 1])
        throw std::exception ();

    return Date (y, m, d);
}

std::string Date::to_string () {
    std::stringstream ss;
    ss << _y << "-" << (_m < 10 ? "0" : "") << _m << "-" << (_d < 10 ? "0" : "") << _d;
    return ss.str ();
}

bool Date::operator< (const Date& other) const {
    return this->key () < other.key ();
}

/*
class BitcoinExchange {
    private:
    std::map<Date, double> _db;

    void _load_database (const std::string& path);
    std::string _trim (const std::string& s);

    public:
    BitcoinExchange ();
    BitcoinExchange (const BitcoinExchange& other);
    BitcoinExchange& operator= (const BitcoinExchange& other);
    ~BitcoinExchange ();

    void run (const std::string& filename);
};
*/

BitcoinExchange::BitcoinExchange () {
    _load_database (DB_PATH);
}

BitcoinExchange::BitcoinExchange (const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange () {
}

std::string BitcoinExchange::_trim (const std::string& s) {
    size_t first = s.find_first_not_of (" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = s.find_last_not_of (" \t\r\n");
    return s.substr (first, (last - first + 1));
}

void BitcoinExchange::_load_database (const std::string& path) {
    std::ifstream db_file (path.c_str ());
    if (!db_file.is_open ()) {
        throw std::runtime_error ("Error: could not open database");
    }

    std::string line;
    std::getline (db_file, line); // skip header "date , value"
    while (std::getline (db_file, line)) {
        size_t sep = line.find (',');
        if (sep != std::string::npos) {
            try {
                std::string date_str = _trim (line.substr (0, sep));
                std::string val_str  = _trim (line.substr (sep + 1));
                Date date            = Date::from_string (date_str);
                double val           = std::atof (val_str.c_str ());
                _db[date]            = val;
            } catch (...) {
            }
        }
    }
}

double BitcoinExchange::_parse_value (const std::string& s) {
    if (s.empty ()) {
        std::cerr << "Error: Not a number" << std::endl;
        return (-1);
    }
    char* endptr;
    double val = std::strtod (s.c_str (), &endptr);
    if (*endptr != '\0' && !isspace (*endptr))
        throw std::exception ();
    if (val < 0) {
        std::cerr << "Error: Not a positive number" << std::endl;
        return (-1);
    }
    if (val > 1000) {
        std::cerr << "Error: Too large number" << std::endl;
        return (-1);
    }
    return val;
}

void BitcoinExchange::run (const std::string& filename) {
    std::ifstream file (filename.c_str ());
    if (!file.is_open ()) {
        std::cerr << "Error: could not open file" << std::endl;
    }
    std::string line;
    std::getline (file, line); // Skip header "date | value"
    while (std::getline (file, line)) {
        if (line.empty ())
            continue;

        size_t sep = line.find ('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue;
        }

        std::string date_str = _trim (line.substr (0, sep));
        std::string val_str  = _trim (line.substr (sep + 1));

        try {
            Date date  = Date::from_string (date_str);
            double val = _parse_value (val_str);
            if (val == -1)
                continue;

            std::map<Date, double>::iterator it = _db.upper_bound (date);
            if (it == _db.begin ()) {
                std::cerr << "Error: date too early => " << date_str << std::endl;
            } else {
                --it;
                std::cout << date.to_string () << " => " << val << " = "
                          << (val * it->second) << std::endl;
            }
        } catch (...) {
            std::cerr << "Error: Bad input => " << date_str << std::endl;
        }
    }
}
