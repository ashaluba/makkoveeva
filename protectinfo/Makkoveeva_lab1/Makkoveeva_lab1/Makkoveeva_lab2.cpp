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

// ������� ��� ������ ����� � ������ char
vector<char> readFile(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        throw runtime_error("�� ������� ������� ����: " + filename);
    }
    vector<char> v((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    return v;
}

// ������� ��� ������ ������� char � ����
void writeFile(const string& filename, const vector<char>& data) {
    ofstream out(filename, ios::binary);
    if (!out) {
        throw runtime_error("�� ������� ������� ����: " + filename);
    }
    out.write(data.data(), data.size());
}

// ������� ��� ���������� ������� ������������
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

// ������� ��� ����������� ����� �����
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

    // ������� ����� � ������������ �������� ������������
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

// ������� ��� ���������� ���������� �������������
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

// ������� ��������� ������� (���������)
map<char, double> russianFrequencyTable() {
    return {
        {'�', 0.1097}, {'�', 0.0845}, {'�', 0.0801}, {'�', 0.0735},
        {'�', 0.0670}, {'�', 0.0626}, {'�', 0.0547}, {'�', 0.0473},
        {'�', 0.0454}, {'�', 0.0440}, {'�', 0.0349}, {'�', 0.0321},
        {'�', 0.0298}, {'�', 0.0281}, {'�', 0.0262}, {'�', 0.0201},
        {'�', 0.0190}, {'�', 0.0174}, {'�', 0.0170}, {'�', 0.0165},
        {'�', 0.0159}, {'�', 0.0144}, {'�', 0.0121}, {'�', 0.0097},
        {'�', 0.0094}, {'�', 0.0073}, {'�', 0.0064}, {'�', 0.0048},
        {'�', 0.0036}, {'�', 0.0032}, {'�', 0.0026}, {'�', 0.0004}
    };
}

// ������� ��� ���������� ������ ����� ����� ���������� ���������������
int findShift(const map<char, double>& freq1, const map<char, double>& freq2) {
    double minDiff = numeric_limits<double>::max();
    int bestShift = 0;

    for (int shift = 0; shift < 32; shift++) { // 32 ����� � ������� ��������
        double diff = 0.0;

        for (char c = '�'; c <= '�'; c++) {
            char shifted = '�' + (c - '�' + shift) % 32;
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

// ������� ��� ����������� ������ ��������
vector<char> decryptVigenere(const vector<char>& encrypted, const string& key) {
    vector<char> decrypted;
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : encrypted) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            char base = isUpper ? '�' : '�';

            int shift = tolower(key[keyIndex]) - '�';
            char decryptedChar = base + (tolower(c) - '�' - shift + 32) % 32;

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

// �������� ������� ������ ����� ��������
string crackVigenere(const vector<char>& encrypted, const vector<char>& reference) {
    // ���������� ����� �����
    int keyLength = findKeyLength(encrypted);
    cout << "�������������� ����� �����: " << keyLength << endl;

    // ������ ��������� ������� ��� ����� ��������
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

    // ������ ��������� ��������� �������
    map<char, double> referenceFreq = buildFrequencyTable(reference);

    // ������� ������ ��� ������ ������� �����
    string key;
    for (int i = 0; i < keyLength; i++) {
        int shift = findShift(referenceFreq, encryptedFreq[i]);
        key += '�' + shift;
    }

    return key;
}

// ������� ��� ����������� ������ � ������� � ���������� �������� �����
void displayText(const vector<char>& text, const string& title = "") {
    if (!title.empty()) {
        cout << title << ":" << endl;
    }

    string output;
    for (char c : text) {
        output += c;
        if (output.length() >= 500) { // ������������ �����
            output += "...";
            break;
        }
    }
    cout << output << endl << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "=== ��������� ������ ����� �������� ===" << endl;
    cout << "������������ ��������� ������ ��� ����������� �����" << endl << endl;

    while (true) {
        try {
            string encryptedFile, referenceFile, outputFile;

            // �������� �������������� ������
            cout << "������� ��� ����� � ������������� �������: ";
            cin >> encryptedFile;
            vector<char> encrypted = readFile(encryptedFile);
            cout << "������������� ����� �������� (" << encrypted.size() << " ����)" << endl;

            // �������� ���������� ������
            cout << "������� ��� ����� � ��������� �������: ";
            cin >> referenceFile;
            vector<char> reference = readFile(referenceFile);
            cout << "��������� ����� �������� (" << reference.size() << " ����)" << endl;

            // ������ � �����
            cout << "\n�������� ������..." << endl;
            string foundKey = crackVigenere(encrypted, reference);

            cout << "��������� ����: " << foundKey << endl;

            // �����������
            vector<char> decrypted = decryptVigenere(encrypted, foundKey);

            // ����� �����������
            cout << "\n=== ���������� ===" << endl;
            cout << "����: " << foundKey << endl;
            displayText(decrypted, "�������������� �����");

            // ���������� ����������
            cout << "������� ��� ����� ��� ���������� ����������: ";
            cin >> outputFile;
            writeFile(outputFile, decrypted);
            cout << "��������� �������� � ����: " << outputFile << endl;

        }
        catch (const exception& e) {
            cerr << "������: " << e.what() << endl;
        }

        // ������ �� �����������
        cout << "\n������ ���������� ������ ����? (y/n): ";
        char choice;
        cin >> choice;
        if (tolower(choice) != 'y') {
            break;
        }
        cout << endl;
    }

    cout << "��������� ���������." << endl;
    return 0;
}