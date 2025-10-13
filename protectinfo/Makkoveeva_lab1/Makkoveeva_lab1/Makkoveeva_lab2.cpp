#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

// Функция для чтения файла в вектор char
vector<char> readFile(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }
    vector<char> v((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    return v;
}

// Функция для записи вектора char в файл
void writeFile(const string& filename, const vector<char>& data) {
    ofstream out(filename, ios::binary);
    if (!out) {
        throw runtime_error("Не удалось создать файл: " + filename);
    }
    out.write(data.data(), data.size());
}

// Функция для вычисления индекса соответствия
double coincidenceIndex(const vector<char>& text) {
    map<char, int> freq;
    int total = 0;

    for (char c : text) {
        if (isalpha(c)) {
            freq[tolower(c)]++;
            total++;
        }
    }

    if (total == 0) return 0.0;

    double sum = 0.0;
    for (auto& p : freq) {
        sum += p.second * (p.second - 1);
    }

    return sum / (total * (total - 1));
}

// Функция для определения длины ключа
int findKeyLength(const vector<char>& encrypted, int maxLength = 30) {
    vector<double> indices(maxLength, 0.0);

    for (int length = 1; length <= maxLength; length++) {
        vector<vector<char>> groups(length);

        for (size_t i = 0; i < encrypted.size(); i++) {
            if (isalpha(encrypted[i])) {
                groups[i % length].push_back(tolower(encrypted[i]));
            }
        }

        double avgIndex = 0.0;
        int validGroups = 0;

        for (int i = 0; i < length; i++) {
            if (groups[i].size() > 1) {
                avgIndex += coincidenceIndex(groups[i]);
                validGroups++;
            }
        }

        if (validGroups > 0) {
            indices[length - 1] = avgIndex / validGroups;
        }
    }

    // Находим длину с максимальным индексом соответствия
    int bestLength = 1;
    double maxIndex = indices[0];

    for (int i = 1; i < maxLength; i++) {
        if (indices[i] > maxIndex) {
            maxIndex = indices[i];
            bestLength = i + 1;
        }
    }

    return bestLength;
}

// Функция для построения частотного распределения
map<char, double> buildFrequencyTable(const vector<char>& text) {
    map<char, int> count;
    int total = 0;

    for (char c : text) {
        if (isalpha(c)) {
            count[tolower(c)]++;
            total++;
        }
    }

    map<char, double> freq;
    for (auto& p : count) {
        freq[p.first] = static_cast<double>(p.second) / total;
    }

    return freq;
}

// Русская частотная таблица (примерная)
map<char, double> russianFrequencyTable() {
    return {
        {'о', 0.1097}, {'е', 0.0845}, {'а', 0.0801}, {'и', 0.0735},
        {'н', 0.0670}, {'т', 0.0626}, {'с', 0.0547}, {'р', 0.0473},
        {'в', 0.0454}, {'л', 0.0440}, {'к', 0.0349}, {'м', 0.0321},
        {'д', 0.0298}, {'п', 0.0281}, {'у', 0.0262}, {'я', 0.0201},
        {'ы', 0.0190}, {'ь', 0.0174}, {'г', 0.0170}, {'з', 0.0165},
        {'б', 0.0159}, {'ч', 0.0144}, {'й', 0.0121}, {'х', 0.0097},
        {'ж', 0.0094}, {'ш', 0.0073}, {'ю', 0.0064}, {'ц', 0.0048},
        {'щ', 0.0036}, {'э', 0.0032}, {'ф', 0.0026}, {'ъ', 0.0004}
    };
}

// Функция для вычисления сдвига между двумя частотными распределениями
int findShift(const map<char, double>& freq1, const map<char, double>& freq2) {
    double minDiff = numeric_limits<double>::max();
    int bestShift = 0;

    for (int shift = 0; shift < 32; shift++) { // 32 буквы в русском алфавите
        double diff = 0.0;

        for (char c = 'а'; c <= 'я'; c++) {
            char shifted = 'а' + (c - 'а' + shift) % 32;
            if (freq1.count(c) && freq2.count(shifted)) {
                diff += abs(freq1.at(c) - freq2.at(shifted));
            }
        }

        if (diff < minDiff) {
            minDiff = diff;
            bestShift = shift;
        }
    }

    return bestShift;
}

// Функция для расшифровки текста Виженера
vector<char> decryptVigenere(const vector<char>& encrypted, const string& key) {
    vector<char> decrypted;
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : encrypted) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            char base = isUpper ? 'А' : 'а';

            int shift = tolower(key[keyIndex]) - 'а';
            char decryptedChar = base + (tolower(c) - 'а' - shift + 32) % 32;

            if (isUpper) {
                decryptedChar = toupper(decryptedChar);
            }

            decrypted.push_back(decryptedChar);
            keyIndex = (keyIndex + 1) % keyLength;
        }
        else {
            decrypted.push_back(c);
        }
    }

    return decrypted;
}

// Основная функция взлома шифра Виженера
string crackVigenere(const vector<char>& encrypted, const vector<char>& reference) {
    // Определяем длину ключа
    int keyLength = findKeyLength(encrypted);
    cout << "Предполагаемая длина ключа: " << keyLength << endl;

    // Строим частотные таблицы для групп символов
    vector<map<char, double>> encryptedFreq(keyLength);
    vector<vector<char>> groups(keyLength);

    for (size_t i = 0; i < encrypted.size(); i++) {
        if (isalpha(encrypted[i])) {
            groups[i % keyLength].push_back(tolower(encrypted[i]));
        }
    }

    for (int i = 0; i < keyLength; i++) {
        encryptedFreq[i] = buildFrequencyTable(groups[i]);
    }

    // Строим эталонную частотную таблицу
    map<char, double> referenceFreq = buildFrequencyTable(reference);

    // Находим сдвиги для каждой позиции ключа
    string key;
    for (int i = 0; i < keyLength; i++) {
        int shift = findShift(referenceFreq, encryptedFreq[i]);
        key += 'а' + shift;
    }

    return key;
}

// Функция для отображения текста в консоли с поддержкой русского языка
void displayText(const vector<char>& text, const string& title = "") {
    if (!title.empty()) {
        cout << title << ":" << endl;
    }

    string output;
    for (char c : text) {
        output += c;
        if (output.length() >= 500) { // Ограничиваем вывод
            output += "...";
            break;
        }
    }
    cout << output << endl << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "=== Программа взлома шифра Виженера ===" << endl;
    cout << "Используется частотный анализ для определения ключа" << endl << endl;

    while (true) {
        try {
            string encryptedFile, referenceFile, outputFile;

            // Загрузка зашифрованного текста
            cout << "Введите имя файла с зашифрованным текстом: ";
            cin >> encryptedFile;
            vector<char> encrypted = readFile(encryptedFile);
            cout << "Зашифрованный текст загружен (" << encrypted.size() << " байт)" << endl;

            // Загрузка эталонного текста
            cout << "Введите имя файла с эталонным текстом: ";
            cin >> referenceFile;
            vector<char> reference = readFile(referenceFile);
            cout << "Эталонный текст загружен (" << reference.size() << " байт)" << endl;

            // Анализ и взлом
            cout << "\nНачинаем анализ..." << endl;
            string foundKey = crackVigenere(encrypted, reference);

            cout << "Найденный ключ: " << foundKey << endl;

            // Расшифровка
            vector<char> decrypted = decryptVigenere(encrypted, foundKey);

            // Вывод результатов
            cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
            cout << "Ключ: " << foundKey << endl;
            displayText(decrypted, "Декодированный текст");

            // Сохранение результата
            cout << "Введите имя файла для сохранения результата: ";
            cin >> outputFile;
            writeFile(outputFile, decrypted);
            cout << "Результат сохранен в файл: " << outputFile << endl;

        }
        catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }

        // Запрос на продолжение
        cout << "\nХотите обработать другой файл? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) != 'y') {
            break;
        }
        cout << endl;
    }

    cout << "Программа завершена." << endl;
    return 0;
}