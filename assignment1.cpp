// Brij Malhotra
// hw1.cpp
// Purpose: This program simulates a pet shelter and adoption menu, 
// the user can add a pet to the shelter, and also adopt a pet from it,
// the program will always let the oldest animal get adopted first, 
// implementation of a queue is being used here
// ------------------------------------------------------------------------
// Thanks Prof. Diaz, I took your advice on having a list that contains 
// all the animals. It helps make it a lot easier because I can just use the
// peek/front function and compare the name values and then pop accordingly!

#include <iostream>
#include <queue>
#include <list>

using namespace std;

// Function prototypes
int menu();
void add(string, queue<string> &, list<string> &);
void adopt(string, queue<string> &, list<string> &);
void adoptAny(queue<string> &, queue<string> &, list<string> &);

int main(){

    // Create queue for dogs & cats
    queue<string> dogs;
    queue<string> cats;

    // Create list for all animals to use for the adopt any function
    list<string> pets;

    int choice = menu();

    // Run a while loop that holds a number as a condition for breaking out
    while (choice != 6){
        switch (choice) {
            case 1:
            add("cat", cats, pets);
            break;

            case 2:
            add("dog", dogs, pets);
            break;

            case 3:
            adopt("cat", cats, pets);
            break;

            case 4:
            adopt("dog", dogs, pets);
            break;

            case 5:
            adoptAny(cats, dogs, pets);
            break;

            case 6:
            break;
        }
        
        choice = menu();
    }

    cout << endl;
    cout << "Thank you for visiting the animal shelter,";
    cout << " we hope you had a great time! ツ\n\n";
}

// Function declaration 
int menu(){
    
    int num;

    cout << endl;
    cout << "Welcome to the animal shelter. What would you like to do?\n";
    cout << "1. Add a CAT to the shelter\n";
    cout << "2. Add a DOG to the shelter\n";
    cout << "3. Adopt a CAT from the shelter\n";
    cout << "4. Adopt a DOG from the shelter\n";
    cout << "5. Adopt any animal from the shelter\n";
    cout << "6. Exit\n"; 

    cout << "Enter your choice: ";
    cin >> num;
    return num;
}

void add(string pet, queue<string> & animal, list<string> & all){
    
    string name;

    // User input for the name of the animal they want to add to the shelter
    cout << endl;
    cout << "Please enter " << pet << "'s name: ";
    cin >> name;

    // Pushing respective animal into the appropriate queue and overall list
    animal.push(name);
    all.push_back(name);
}

void adopt(string pet, queue<string> & animal, list<string> & all){

    // Taking the instance of an empty queue
    if (animal.empty()){
        cout << "Sorry no " << pet << "'s are available for adoption today\n";
    } else {
        // Retrieving the name and popping the animal from the queue and list
        string name = animal.front();
        cout << endl;
        cout << "Congrats on adopting a " << pet << "! Their name is " << name << endl;

        animal.pop();
        all.remove(name);
    }
}

void adoptAny(queue<string> & qCat, queue<string> & qDog, list<string> & all){

    // Taking the instance of the list being empty
    if (all.empty()){
        cout << endl;
        cout << "Sorry, no animals are available for adoption today\n";
    } else {
        // Comparing what animal is older and then popping them from their respective Queue
        string name = all.front();
        if (name == qCat.front()){
            cout << endl;
            cout << "Congrats on adopting a cat!";
            qCat.pop();
        } else {
            cout << endl;
            cout << "Congrats on adopting a dog!";
            qDog.pop();
        }

        cout << " Their name is " << name << endl;
        all.pop_front();
    }
}