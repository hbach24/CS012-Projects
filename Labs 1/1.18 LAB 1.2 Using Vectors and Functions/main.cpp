#include <iostream>
#include <vector>
using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int>& jerseyNum, const vector<int>& jerseyRating);
void addPlayer(vector<int>& jerseyNum, vector<int>& jerseyRating);
void removePlayer(vector<int>& jerseyNum, vector<int>& jerseyRating);
void updatePlayerRating(const vector<int>& jerseyNum, vector<int>& jerseyRating);
void outputPlayersAboveRating(const vector<int>& jerseyNum, const vector<int>& jerseyRating);
void outputMenu();


int main() {
    int vsize = 5;
    vector<int> jerseyNum(vsize);
    vector<int> jerseyRating(vsize);
    char option;

    for (int i = 0; i < vsize; i++) {
        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> jerseyNum.at(i);
        //cout << endl;
        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> jerseyRating.at(i);
        cout << endl;
    }

    outputRoster(jerseyNum, jerseyRating);
    outputMenu();

    cin >> option;

    while (option != 'q') {
        if (option == 'a') {
            addPlayer(jerseyNum, jerseyRating);
            outputMenu();
            cin >> option;
        }
        if (option == 'd') {
            removePlayer(jerseyNum, jerseyRating);
            outputMenu();
            cin >> option;
        }
        if (option == 'u') {
            updatePlayerRating(jerseyNum, jerseyRating);
            outputMenu();
            cin >> option;

        }
        if (option == 'r') {
            outputPlayersAboveRating(jerseyNum, jerseyRating);
            outputMenu();
            cin >> option;
        }
        if (option == 'o') {
            outputRoster(jerseyNum, jerseyRating);
            outputMenu();
            cin >> option;
        }
        //cin >> option;
    }
    return 0;
}

void outputRoster(const vector<int>& jerseyNum, const vector<int>& jerseyRating) {
    cout << "ROSTER" << endl;

    for (unsigned int i = 0; i < jerseyNum.size(); i++) {
        cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << jerseyRating.at(i);
        cout << endl;
    }
    //cout << endl;

}

void addPlayer(vector<int>& jerseyNum, vector<int>& jerseyRating) {
    int jNum;
    int pRat;

    cout << "Enter another player's jersey number:" << endl;
    cin >> jNum;
    jerseyNum.push_back(jNum);

    cout << "Enter another player's rating:" << endl;
    cin >> pRat;
    jerseyRating.push_back(pRat);
}

void removePlayer(vector<int>& jerseyNum, vector<int>& jerseyRating) {
    int num;
    cout << "Enter a jersey number:" << endl;
    cin >> num;

    for (unsigned int i = 0; i < jerseyNum.size(); i++) {
        if (jerseyNum.at(i) == num) {
            jerseyNum.erase(jerseyNum.begin() + i);
            jerseyRating.erase(jerseyRating.begin() + i);
        }
    }
}



void updatePlayerRating(const vector<int>& jerseyNum, vector<int>& jerseyRating) {
    int jNum;
    int newNum;

    cout << "Enter a jersey number:" << endl;
    cin >> jNum;



    for (unsigned int i = 0; i < jerseyNum.size(); i++) {
        if (jerseyNum.at(i) == jNum) {
            cout << "Enter a new rating for player:" << endl;
            cin >> newNum;
            jerseyRating.at(i) = newNum;
        }
    }
}

void outputPlayersAboveRating(const vector<int>& jerseyNum, const vector<int>& jerseyRating) {
    int rating;
    cout << "Enter a rating:" << endl;
    cin >> rating;
    cout << "ABOVE " << rating << endl;
    for (unsigned int i = 0; i < jerseyRating.size(); i++) {
        if (jerseyRating.at(i) > rating) {
            cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNum.at(i) << ", Rating: " << jerseyRating.at(i) << endl;
        }
    }
}

void outputMenu() {
    cout << endl;
    cout << "MENU" << endl;
    cout << "a - Add player" << endl;
    cout << "d - Remove player" << endl;
    cout << "u - Update player rating" << endl;
    cout << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;

}