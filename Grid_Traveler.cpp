#include <iostream>
#include <unordered_map>
#include <chrono>
#include <string>

uint64_t gridTraveler(const uint64_t &n, const uint64_t &m){

    if (n == 1 && m == 1)
    {
        return 1;
    }
    if(n == 0 || m == 0){
        return 0;
    }
    return gridTraveler(n-1, m) + gridTraveler(n, m-1);
}

uint64_t gridTraveler_hashed(const uint64_t &n, const uint64_t &m){
    
    static std::unordered_map<std::string, uint64_t> container;

    std::string key = std::to_string(n) + "|" + std::to_string(m);

    if (n == 1 || m == 1)
    {
        return 1;
    }
    if(n == 0 || m == 0){
        return 0;
    }
    if (container.count(key))
    {
        return container[key];
    }    
    container[key] = gridTraveler_hashed(n-1, m) + gridTraveler_hashed(n, m-1);
    return container[key];
}

int main(){

    bool keep_going = true;

    while (keep_going)
    {
        uint64_t n, m;
        std::cout << "Insert the first grid dimension: \n";
        std::cin >> n;

        std::cout << "Insert the second grid dimension: \n";
        std::cin >> m;
        
        auto start_hashed = std::chrono::steady_clock::now();
        std::cout << "Case one: " << gridTraveler_hashed(n, m) << std::endl;

        auto end_hashed = std::chrono::steady_clock::now();

        std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_hashed - start_hashed).count() << " ms" << std::endl;

        auto start = std::chrono::steady_clock::now();

        std::cout << "Case two: " << gridTraveler(n, m) << std::endl;

        auto end = std::chrono::steady_clock::now();

        std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

        std::cout << "Do you want to do another time test? (1 or 0) " << std::endl;

        int loop;

        std::cin >>  loop;

        switch (loop)
        {
            case 0:
                keep_going = false;
                break;
            case 1:
                std::cout << "Here we go again " << std::endl;
                break;
            default:
                std::cout << "Invalid answer however i will consider as one :) " << std::endl;
                break;
        }
        
    }
}