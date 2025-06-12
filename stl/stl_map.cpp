#include <iostream>
#include <map>
#include <list>
using namespace std;

int main()
{

    map<string, list<string>> pokedex;

    list<string> pikachuAttacks = {"Thunderbolt", "Quick Attack", "Electro Ball"};
    list<string> charmanderAttacks = {"Flamethrower", "Scratch"};
    list<string> bulbasaurAttacks = {"Vine Whip", "Razor Leaf"};

    pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
    pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttacks));
    pokedex.insert(pair<string, list<string>>("Bulbasaur", bulbasaurAttacks));

    for (const auto &pair : pokedex)
    {
        cout << pair.first << " - ";
        for (const string &attack : pair.second)
            cout << attack << ", ";

        cout << endl;
    }

    // map<string, string> myDictionary;
    // myDictionary.insert(pair<string, string>("Last Name", "Patel"));
    // myDictionary.insert(pair<string, string>("First Name", "Aniket"));
    // myDictionary.insert(pair<string, string>("Branch", "IT"));
    // myDictionary.insert(pair<string, string>("Course", "Engineering"));

    // cout << myDictionary["First Name"] << endl;
    // myDictionary["First Name"] = "ANIKET";
    // cout << "Dictionary Size: " << myDictionary.size() << endl;

    // cout << "Dictionary Elements: " << endl;
    // for (auto pair : myDictionary)
    //     cout << "\t" << pair.first << " - " << pair.second << endl;

    // myDictionary.clear();
    // cout << "Dictionary Size: " << myDictionary.size() << endl;

    return 0;
}