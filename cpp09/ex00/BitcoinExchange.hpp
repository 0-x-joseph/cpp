#ifndef __BITCOINEXCHANGE__
#define __BITCOINEXCHANGE__

#include <map>
#include <string>

#define DB_PATH "data.csv"

class Date {
    private:
    int _y;
    int _m;
    int _d;

    public:
    Date ();
    Date (int y, int m, int d);
    Date (const Date& other);
    Date& operator= (const Date& other);
    ~Date ();

    int key () const;
    std::string to_string ();
    static Date from_string (const std::string& s);
    bool operator< (const Date& other) const;
};

class BitcoinExchange {
    private:
    std::map<Date, double> _db;

    void _load_database (const std::string& path);
    std::string _trim (const std::string& s);
    double _parse_value (const std::string& s);

    public:
    BitcoinExchange ();
    BitcoinExchange (const BitcoinExchange& other);
    BitcoinExchange& operator= (const BitcoinExchange& other);
    ~BitcoinExchange ();

    void run (const std::string& filename);
};

#endif /* __BITCOINEXCHANGE__ */
