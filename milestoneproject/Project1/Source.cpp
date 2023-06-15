#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include <forward_list>
using namespace std;

enum class death_cause
{
    alcohol, smoking, unsafewater
};

struct DeathByRisk
{
    std::string country_name;
    int year;
    death_cause dc;
    int deceased;
};

std::list<DeathByRisk> processData(std::vector<DeathByRisk> sm) {
    list<DeathByRisk> byrlist;

    //Your code here



    return byrlist;
}
int main() {
    std::vector<DeathByRisk> cases({
        { "Canada", 2019, death_cause::alcohol, 13622},
        { "Canada", 2019, death_cause::smoking, 49646 },
        { "Canada", 2019, death_cause::unsafewater, 59 },
        { "Canada", 2018, death_cause::alcohol, 13302},
        { "Canada", 2018, death_cause::smoking, 48652 },
        { "Canada", 2018, death_cause::unsafewater, 59 },
        { "USA", 2019, death_cause::alcohol, 136663},
        { "USA", 2019, death_cause::smoking, 119777 },
        { "USA", 2019, death_cause::unsafewater, 382 },
        { "USA", 2018, death_cause::alcohol, 135290},
        { "USA", 2018, death_cause::smoking, 118169 },
        { "USA", 2018, death_cause::unsafewater, 378 },
        });

    auto res = processData(cases);

    return 0;
}