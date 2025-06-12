#include <iostream>
#include <list>
using namespace std;

void displayRatings(const list<int> &Ratings)
{
    for (list<int>::const_iterator it = Ratings.begin(); it != Ratings.end(); it++)
    {
        cout << "Player rating: " << *it << endl;
    }
}

void insertIntoOrderedList(int playerRating, list<int> &Ratings)
{
    for (list<int>::const_iterator it = Ratings.begin(); it != Ratings.end(); it++)
    {
        if (*it > playerRating)
        {
            Ratings.insert(it, playerRating);
            return;
        }
    }
    Ratings.push_back(playerRating);
}

int main()
{

    list<int> allPlayers = {2, 9, 6, 7, 3, 1, 4, 8, 3, 2, 9, 7};
    // list<int> allPlayers{2, 9, 6, 7, 3, 1, 4, 8, 3, 2, 9, 7};
    list<int> beginners, pros;

    for (list<int>::iterator it = allPlayers.begin(); it != allPlayers.end(); it++)
    {
        int playerRating = *it;
        if (playerRating >= 1 && playerRating <= 5)
        {
            // beginners.push_back(playerRating);
            insertIntoOrderedList(playerRating, beginners);
        }
        else if (playerRating >= 6 && playerRating <= 10)
        {
            // pros.push_back(playerRating);
            insertIntoOrderedList(playerRating, pros);
        }
    }

    cout << "Beginners: " << endl;
    displayRatings(beginners);
    cout << "Pros: " << endl;
    displayRatings(pros);

    // list<int> myList;
    // myList.push_back(10);
    // myList.push_back(20);
    // myList.push_front(30);
    // myList.insert(myList.begin(), 100);
    // // myList.erase(myList.begin());

    // for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    return 0;
}