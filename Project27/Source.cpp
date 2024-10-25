#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;
/*На основе примера , реализовать словарь. Предусмотреть функциональность:
1. Добавить слово с переводом
2. Удаление с поиском
3. Поиск 
4. Сохранение в файл, (текстовый)
5. Вывод на консоль*/
int main()
{ 
   
    //Create
    setlocale(0, "ukr");
    map<string, string> dict;
    dict.insert(make_pair("dog", "собака"));
    dict.insert(make_pair("deer", "олень"));
    dict.insert(make_pair("parrot", "папуга"));
    cout << "\t Dicionary: " << endl;
    for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
    {
        cout << ptr->first << " - " << ptr->second << endl;
    }
    //Add word
    string first;
    string second;
    cout << "Enter the word you want to add in english: ";
    cin >> first;
    cout << "Enter the translation: ";
    cin >> second;
    dict.insert(make_pair(first,second));
    cout << "\t Dicionary: " << endl;
    for (auto ptr = dict.begin(); ptr != dict.end(); ptr++)
    {
        cout << ptr->first << " - " << ptr->second << endl;
    }
    //Find
    string s;
    cout << "Enter the word you are looking for: ";
    cin >> s;
    auto ptrf = dict.find(s);
    if (ptrf != dict.end())
    {
        system("cls");
        system("color 0B");
        cout << ptrf->second << endl;
    }
    else
    {
        system("cls");
        system("color 0C");
    }

    //Find and erase
    cout << "Which word do you want to delete: ";
    cin >> s;
    auto ptre = dict.find(s);
    if (ptre != dict.end())
    {
        system("cls");
        cout <<"Delete -> "<< ptre->second << endl;
        dict.erase(ptre);
    }
    else
    {
        system("cls");
        system("color 0C");
    }
    cout << "\t Dicionary: " << endl;
    for (auto ptrf = dict.begin(); ptrf != dict.end(); ptrf++)
    {
        cout << ptrf->first << " - " << ptrf->second << endl;
    }

    //Add to file
    string filename;
    ofstream out(filename);
    out.open("Dictionary.txt", ios::out | ios::trunc);
    for (auto ptrf = dict.begin(); ptrf != dict.end(); ptrf++)
    {
        out << ptrf->first << " - " << ptrf->second << endl;
    }
    out.close();

}