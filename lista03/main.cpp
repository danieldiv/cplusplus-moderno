#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <climits>

using namespace std;

template<typename T>
double distancia(const T &orig, const T &dest) {
    const double R = 6371.0;
    // raio médio da Terra em Km
    const double PI = 3.14159265; // constante PI
    auto lat1_rad = orig.first * PI / 180.0;
    auto lat2_rad = dest.first * PI / 180.0;
    auto lon1_rad = orig.second * PI / 180.0;
    auto lon2_rad = dest.second * PI / 180.0;
    auto delta_lat = lat2_rad - lat1_rad;
    auto delta_lon = lon2_rad - lon1_rad;
    auto h = std::pow(std::sin(delta_lat / 2.0), 2.0)
        + std::cos(lat1_rad) * std::cos(lat2_rad) * std::pow(std::sin(delta_lon / 2.0), 2.0);
    auto d = 2.0 * R * std::asin(std::pow(h, 0.5));
    return d;
}

template<typename T>
decltype(auto) menorDistancia(T &roteiros) {
    auto it = roteiros.begin()->second;
    double max = INT_MAX;

    for (const auto &[key, value] : roteiros) {
        decltype(key) &nome = key;
        decltype(value) &rota = value;

        auto distancia_total = 0.0;

        auto origem = rota.begin();
        auto destino = ++rota.begin();

        while (destino != rota.end()) {
            double d = distancia(*origem, *destino);
            distancia_total += d;
            ++origem;
            ++destino;
        }
        std::cout << nome << ": " << distancia_total << " Km" << std::endl;

        if (distancia_total < max) {
            it = value;
            max = distancia_total;
        }
    }
    cout << endl;
    return it;
}

int main() {
    std::map<std::string, std::vector<std::pair<double, double>>> roteiros = {
    {"Estrada Real (MG)", {
    {-20.387058648132697, -43.50276489546531},
    {-21.110096884824063, -44.17400882389444},
    {-21.135392099979775, -44.26168702763076},
    {-23.219718444240385, -44.71541419792069}}},

    {"Caminho dos Príncipes (SC)", {
    {-26.45903196178978, -48.60186925577256},
    {-26.484889252846987, -49.08265794057286},
    {-26.301589093945626, -48.84812743826987}}},

    {"Serra Gaúcha (RS)", {
    {-29.165328627526332, -51.51579840115089},
    {-29.363757873430096, -50.81285822760663},
    {-29.377433015152402, -50.87455594332935},
    {-28.74764895560134, -50.065278332356094}}} };

    for (const auto &[origem, destino] : menorDistancia(roteiros))
        std::cout << origem << " " << destino << std::endl;

    return 0;
}