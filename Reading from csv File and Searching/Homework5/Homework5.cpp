
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<vector<string>> csvDosyaOku(const string& filename) {
    vector<vector<string>> books;

    ifstream dosya(filename);

    string line;

    if (!dosya.is_open()) {
        cerr << "file can not open" << endl;
    }
    
    while (getline(dosya, line)) {
        vector<string> row;
        stringstream ss(line);
        
        string cell;
        
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
            
        }
        books.push_back(row);
    }

    dosya.close();
    return books;
}

unordered_map<string, string> csvHashDosyaOku(const string& filename) {
    unordered_map<string, string>books;

    ifstream dosya(filename);

    string line;

    if (!dosya.is_open()) {
        cerr << "file can not open" << endl;
    }

    while (getline(dosya, line)) {
   
        stringstream ss(line);
      
        string cell;

        while (getline(ss, cell, ',')) {
            
            books[cell] = line;
        }
        
    }

    dosya.close();
    return books;
}

string linearSearch(const vector<vector<string>>& books, string key) {
    
    for (const auto& item: books) {
        if (find(item.begin(), item.end(), key) != item.end()) {
            return item[0]+" , "+item[1] +" , "+ item[2]+" , " + item[3];
            break;
        }
    }
   
    return "bulunamadı";
    
}

string hashTable(const unordered_map<string, string>table,string key) {
    auto it = table.find(key);

    if (it != table.end()) {
        return (it->second); 
    }
    else {
        return "bulunamadı";
    }
}



void booksPrint(const string& filename,vector<vector<string>>book) {
    
    for (const auto& row : book) {
        for (const auto& cell : row) {
            cout << cell << "\t";
        }
        cout << endl;
        cout << endl;
    }
}

int main()
{
    string filename = "books.csv";
    vector<vector<string>> book = csvDosyaOku(filename);
    unordered_map<string, string>table = csvHashDosyaOku(filename);

    string searching;
    cout << "Aranakcak kitabı yazınız" << endl;
    cin >> searching;
    
    string result = linearSearch(book, searching);
    booksPrint(filename, book);
    
    string result1 = hashTable(table, searching);
    /*cout << "Linear Seraching: " << endl;
    cout << result << endl;
    cout << "Hash Table Seraching: " << endl;
    cout << result1 << endl;*/
        
}
