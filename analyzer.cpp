#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // 1. Open the file
    std::ifstream priceFile("stock_prices.txt");

    // 2. Check if the file opened successfully
    if (!priceFile.is_open()) {
        std::cout << "Error: Could not open file stock_prices.txt" << std::endl;
        return 1; // Exit with an error code if the file couldn't be opened
    }

    // 3. Read data into a vector
    std::vector<double> prices;
    double price;
    while (priceFile >> price) {
        prices.push_back(price);
    }

    // 4. Perform safety check before calculating
    if (prices.empty()) { // .empty() is a clean way to check if the vector's size is 0
        std::cout << "File is empty, cannot calculate average." << std::endl;
    } else {
        // 5. Calculate the sum
        double sum = 0.0;
        for (double p : prices) {
            sum += p;
        }

        // 6. Calculate the average
        double average = sum / prices.size();

        // 7. Display the results
        std::cout << "Number of prices found: " << prices.size() << std::endl;
        std::cout << "Sum of prices: " << sum << std::endl;
        std::cout << "Average price: " << average << std::endl;
    }

    return 0;
}