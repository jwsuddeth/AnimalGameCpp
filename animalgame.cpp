#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Node {
public:
    
    string text;
    Node * right;
    Node * left;

public:
    
    Node(const string& data) : text(data), right(nullptr), left(nullptr) {}
};

class AnimalGame {
private:
    Node * root;
    
public:
    AnimalGame()
    {
        root = new Node("Cat");
        root->right = nullptr;
        root->left = nullptr;
    }

    void play() {
        Node* current = root;
        while (current->right != nullptr && current->left != nullptr)
        {
            char answer;
            cout << current->text << " (y/n): ";
            cin >> answer;
            cout << endl;
            
            if (answer == 'y') {
                current = current->right;
            } else if (answer == 'n') {
                current = current->left;
            } else {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        }

        cout << "Is it a " << current->text << "? (y/n): ";
        char final_answer;
        cin >> final_answer;
        cout << endl;

        if (final_answer == 'y') {
            cout << "I win!" << endl;
        } else {
            learn_animal(current);
        }
    }

private:
    void learn_animal(Node* current) {
        
        string correct_animal;
        cout << "What is the animal? ";
        cin.ignore();
        getline(std::cin, correct_animal);
        cout << endl;

        string new_question;
        cout << "Enter a question to distinguish a " << correct_animal << " from a " << current->text << ": ";
        getline(cin, new_question);
        cout << endl;

        char answer;
        cout << "For " << correct_animal << ", what is the answer to the question? (y/n): ";
        cin >> answer;
        cout << endl;

        if (answer == 'y') {
            current->right = new Node(correct_animal);
            current->left = new Node(current->text);
        } else {
            current->right = new Node(current->text);
            current->left = new Node(correct_animal);
        }
        current->text = new_question;

        cout << "Thank you! I've learned a new animal." << endl;
    }
};

int main() {
    AnimalGame game;
    char play_again = 'y';

    while(play_again == 'y') {
        game.play();
        cout << "Play again? (y/n): ";
        cin >> play_again;
        cout << endl;
    }

    return 0;
}
