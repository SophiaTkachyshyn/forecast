#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <numeric>
#include "forecast.h"

using namespace std;

int main() {
	std::ifstream file("forecast.txt");

	std::vector<Forecast> forecasts;

	std::copy(std::istream_iterator<Forecast>(file), std::istream_iterator<Forecast>(), std::back_inserter(forecasts));
	
	std::sort(forecasts.begin(), forecasts.end());

	std::for_each(forecasts.begin(), forecasts.end(), [](const auto& forecast) {
		std::cout << forecast << std::endl;
	});

    int targetMonth = 6;

    double totalPrecipitation = std::accumulate(forecasts.begin(), forecasts.end(), 0.0, [&](double total, const Forecast& forecast) {
        return total + (forecast.getMonth() == targetMonth ? forecast.getPrecipitation() : 0.0);
    });

    int daysWithoutPrecipitation = std::count_if(forecasts.begin(), forecasts.end(), [&](const Forecast& forecast) {
        return forecast.getMonth() == targetMonth && forecast.getPrecipitation() == 0.0;
    });

    std::cout << "Total precipitation in " << targetMonth << ": " << totalPrecipitation << "mm" << std::endl;
    std::cout << "Days without precipitation in " << targetMonth << ": " << daysWithoutPrecipitation << std::endl << std::endl;

    std::vector<Forecast> forecastsWithoutPrecipitation;

    std::copy_if(forecasts.begin(), forecasts.end(), std::back_inserter(forecastsWithoutPrecipitation), [](const Forecast& forecast) {
        return forecast.getPrecipitation() == 0.0;
    });

    std::sort(forecastsWithoutPrecipitation.begin(), forecastsWithoutPrecipitation.end(), [](const Forecast& a, const Forecast& b) {
        return a.getTemperature() > b.getTemperature();
    });

    if (!forecastsWithoutPrecipitation.empty()) {
        std::cout << "Warmest day without precipitation: " << forecastsWithoutPrecipitation.front() << std::endl;
        std::cout << "Coldest day without precipitation: " << forecastsWithoutPrecipitation.back() << std::endl;
    }
    else {
        std::cout << "No forecasts without precipitation available." << std::endl;
    }

    std::string targetDayOfWeek ="Monday";

    std::vector<double> temperaturesForTargetDay;

    std::for_each(forecasts.begin(), forecasts.end(), [&](const Forecast& forecast) {
        if (forecast.getDayOfWeek() == targetDayOfWeek) {
            temperaturesForTargetDay.push_back(forecast.getTemperature());
        }
    });

    std::sort(temperaturesForTargetDay.begin(), temperaturesForTargetDay.end());
    temperaturesForTargetDay.erase(std::unique(temperaturesForTargetDay.begin(), temperaturesForTargetDay.end()), temperaturesForTargetDay.end());

    std::cout << "Unique temperatures for target day of week:" << std::endl;
    std::copy(temperaturesForTargetDay.begin(), temperaturesForTargetDay.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;





	return 0;
}