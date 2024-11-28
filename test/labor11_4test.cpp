#include "gtest/gtest.h"
#include <string>
#include <sstream>
using namespace std;

// Реалізація функції analyzeLine
void analyzeLine(const string& line, int& positiveCount, int& negativeCount, int& zeroCount, int& wordCount) {
    stringstream ss(line);
    string token;
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;
    wordCount = 0;

    while (ss >> token) {
        bool isNumber = true;
        int number = 0;

        // Спроба перетворення токена в число
        try {
            number = stoi(token);
        } catch (...) {
            isNumber = false;
        }

        if (isNumber) {
            if (number > 0) {
                positiveCount++;
            } else if (number < 0) {
                negativeCount++;
            } else {
                zeroCount++;
            }
        } else {
            wordCount++;
        }
    }
}

// Тести функції analyzeLine
TEST(AnalyzeLineTest, HandlesEmptyLine) {
    int positiveCount, negativeCount, zeroCount, wordCount;
    analyzeLine("", positiveCount, negativeCount, zeroCount, wordCount);

    EXPECT_EQ(positiveCount, 0);
    EXPECT_EQ(negativeCount, 0);
    EXPECT_EQ(zeroCount, 0);
    EXPECT_EQ(wordCount, 0);
}

TEST(AnalyzeLineTest, HandlesNumbersOnly) {
    int positiveCount, negativeCount, zeroCount, wordCount;
    analyzeLine("10 -5 0 3 -8", positiveCount, negativeCount, zeroCount, wordCount);

    EXPECT_EQ(positiveCount, 2);
    EXPECT_EQ(negativeCount, 2);
    EXPECT_EQ(zeroCount, 1);
    EXPECT_EQ(wordCount, 0);
}

TEST(AnalyzeLineTest, HandlesWordsOnly) {
    int positiveCount, negativeCount, zeroCount, wordCount;
    analyzeLine("hello world test", positiveCount, negativeCount, zeroCount, wordCount);

    EXPECT_EQ(positiveCount, 0);
    EXPECT_EQ(negativeCount, 0);
    EXPECT_EQ(zeroCount, 0);
    EXPECT_EQ(wordCount, 3);
}

TEST(AnalyzeLineTest, HandlesMixedInput) {
    int positiveCount, negativeCount, zeroCount, wordCount;
    analyzeLine("42 hello -7 0 world 15", positiveCount, negativeCount, zeroCount, wordCount);

    EXPECT_EQ(positiveCount, 2);
    EXPECT_EQ(negativeCount, 1);
    EXPECT_EQ(zeroCount, 1);
    EXPECT_EQ(wordCount, 2);
}

// Основна функція для запуску тестів
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
