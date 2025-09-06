#include "Compare.hpp"
#include "HashInventory.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "ItemAVL.hpp"
#include "ItemGenerator.hpp"
#include "TreeInventory.hpp"
#include <algorithm>
#include <chrono>
#include <list>
#include <ratio>
#include <thread>
// IMPLEMENTED
template <class Comparator, class Container>
float timeQuery(Inventory<Comparator, Container> inv, Item start, Item end) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    inv.query(start, end);
    const auto t2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> queryTime = t2 - t1;
    return queryTime.count();
}

template <class Comparator, class Container>
float timeContains(Inventory<Comparator, Container> inv, std::vector<std::string> contained, std::vector<std::string> missing) {
    float total = 0.0;
    for (int i = 0; i < 100; i++) {

        auto c1 = std::chrono::high_resolution_clock::now();
        inv.contains(contained[i]);
        auto c2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> containTime = c2 - c1;
        total += containTime.count();

        auto m1 = std::chrono::high_resolution_clock::now();
        inv.contains(missing[i]);
        auto m2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> missingTime = m2 - m1;
        total += missingTime.count();
    }

    return total / 200;
}

int main() {
    ItemGenerator generator(42);
    Inventory<CompareItemName, Tree> inv;
    for (int n = 0; n < 8000; n++) {
        inv.pickup(generator.randomItem());
    }

    // Query
    Item start, end;
    float total = 0.0;
    //for (int i = 0; i < 10; i++) {
        // Name
        /* start.name_ = generator.randomUsedName();
         end.name_ = generator.randomUsedName();
         while (start.name_ > end.name_) {
             start.name_ = generator.randomUsedName();
             end.name_ = generator.randomUsedName();
         }*/

        // Weight
        start.weight_ = generator.randomFloat(generator.MIN_WEIGHT, generator.MAX_WEIGHT);
        end.weight_ = start.weight_ + 0.1;
        total += timeQuery(inv, start, end);
    //}
    std::cout << "Time for Query: " << total  << std::endl;
    return 0;

    // Contains
    /*std::vector<std::string> contained;
    for (int i = 0; i < 100; i++) {
        contained.push_back(generator.randomUsedName());
    }

    std::vector<std::string> missing;
    for (int j = 0; j < 100; j++) {
        missing.push_back(generator.randomItem().name_);
    }

    std::cout << "Time for Contains: " << timeContains(inv, contained, missing) << std::endl;  */

    /*Inventory<CompareItemName, std::list<Item>>
    Inventory<CompareItemName, std::unordered_set<Item>>
    Inventory<CompareItemName, Tree>*/
}