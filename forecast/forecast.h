#pragma once
#include <iostream>
#include <string>

class Forecast {
private:
    std::string dayOfWeek;
    int dayOfMonth;
    int month;
    double temperature;
    double precipitation;

public:
    Forecast();
    Forecast(const std::string& daí_fWeek, int day_Month, int m, double t, double p); 
    Forecast(const Forecast& F); 
    ~Forecast();

    void setTemperature(double t);
    void setPrecipitation(double p); 

    std::string getDayOfWeek() const;
    int getDayOfMonth() const;
    int getMonth() const;
    double getTemperature() const;
    double getPrecipitation() const;

    void readFromStream(std::istream& in); 
    void writeToStream(std::ostream& out) const; 

    bool operator<(const Forecast& F) const; 
};


std::ostream& operator<<(std::ostream& out, const Forecast& F);
std::istream& operator>>(std::istream& in, Forecast& F);

