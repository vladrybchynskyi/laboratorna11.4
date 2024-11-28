#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

// Функція для підрахунку кількості чисел і слів у рядку
void analyzeLine(const string& line, int& positiveCount, int& negativeCount, int& zeroCount, int& wordCount) {
    stringstream ss(line);
    string token;
    while (ss >> token) {
        bool isNumber = true;
        int number = 0;

        // Перевірка, чи є токен числом
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

// Функція для обробки файлу
void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Помилка: Не вдалося відкрити вхідний файл!" << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cerr << "Помилка: Не вдалося відкрити вихідний файл!" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(inputFile, line)) {
        lineNumber++;
        int positiveCount = 0, negativeCount = 0, zeroCount = 0, wordCount = 0;
        analyzeLine(line, positiveCount, negativeCount, zeroCount, wordCount);

        outputFile << "Рядок " << lineNumber << ":" << endl;
        outputFile << "Додатних чисел: " << positiveCount << endl;
        outputFile << "Від'ємних чисел: " << negativeCount << endl;
        outputFile << "Нульових чисел: " << zeroCount << endl;
        outputFile << "Слів: " << wordCount << endl;
        outputFile << "---------------------------" << endl;
    }

    inputFile.close();
    outputFile.close();
}

// Меню програми
void displayMenu() {
    cout << "Меню програми:" << endl;
    cout << "1. Аналіз текстового файлу" << endl;
    cout << "2. Вихід" << endl;
    cout << "Виберіть опцію: ";
}

int main() {
    string inputFileName, outputFileName;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введіть ім'я вхідного файлу: ";
                cin >> inputFileName;
                cout << "Введіть ім'я вихідного файлу: ";
                cin >> outputFileName;

                processFile(inputFileName, outputFileName);
                cout << "Аналіз завершено. Результати записано у файл: " << outputFileName << endl;
                break;

            case 2:
                cout << "Вихід із програми." << endl;
                break;

            default:
                cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 2);

    return 0;
}