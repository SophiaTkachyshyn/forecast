#include "forecast.h"

Forecast::Forecast() : dayOfWeek(""), dayOfMonth(1), month(1), temperature(0.0), precipitation(0.0) {}

Forecast::Forecast(const std::string& dayOfWeek, int dayOfMonth, int month, double temperature, double precipitation)
    : dayOfWeek(dayOfWeek), dayOfMonth(dayOfMonth), month(month), temperature(temperature), precipitation(precipitation) {}

Forecast::Forecast(const Forecast& F)
    : dayOfWeek(F.dayOfWeek), dayOfMonth(F.dayOfMonth), month(F.month), temperature(F.temperature), precipitation(F.precipitation) {}

Forecast::~Forecast() {}

void Forecast::setTemperature(double t) {
    temperature = t;
}

void Forecast::setPrecipitation(double p) {
    precipitation = p;
}

std::string Forecast::getDayOfWeek() const {
    return dayOfWeek;
}

int Forecast::getDayOfMonth() const {
    return dayOfMonth;
}

int Forecast::getMonth() const {
    return month;
}

double Forecast::getTemperature() const {
    return temperature;
}

double Forecast::getPrecipitation() const {
    return precipitation;
}

void Forecast::readFromStream(std::istream& in) {
    in >> dayOfWeek >> dayOfMonth >> month >> temperature >> precipitation;
}

void Forecast::writeToStream(std::ostream& out) const {
    out << "Day of the week: " << dayOfWeek << std::endl;
    out << "Day of the month: " << dayOfMonth << std::endl;
    out << "Month: " << month << std::endl;
    out << "Temperature: " << temperature << "C" << std::endl;
    out << "Precipitation: " << precipitation << "mm" << std::endl;
}


bool Forecast::operator<(const Forecast& other) const {
    if (month != other.month)
        return month < other.month;
    return dayOfMonth < other.dayOfMonth;
}

std::ostream& operator<<(std::ostream& out, const Forecast& F) {
    F.writeToStream(out);
    return out;
}

std::istream& operator>>(std::istream& in, Forecast& F) {
    F.readFromStream(in);
    return in;
}
