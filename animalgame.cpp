#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    Node * left;
    Node * right;
    string text;

public:
    Node * getLeft() const { return left; }
    Node * getRight() const { cout << "getting right...\n";  return right; }
    string getText() const { return text; }

    void setLeft(Node * newLeft) { left = newLeft; }
    void setRight(Node * newRight) { right = newRight; }
    void setText(const string & s) { text = s; }

    Node(const string & s) 
    {
        text = s;
        left = NULL;
        right = NULL;
    }

    Node(const Node & n)
    {
        text = n.text;
        left = n.left;
        right = n.right;
    }
};

bool isCorrect();
bool askQuestion(Node * n);
bool playAgain();
Node * learnNewAnimal(Node * n);


int main()
{
    Node * root = new Node("Cat");
    Node * current = root;
    Node * prev = NULL;

    bool done = false;

    while(!done)
    {
        // if we are at a leaf then it is an animal and we must guess
        if (current->getLeft() == NULL)
        {
            cout << "Your animal is a " << current->getText() << endl;
            if (isCorrect())
            {
                cout << "I win!\n";
                done = playAgain();
                prev = NULL;
                current = root;
                continue;
            }
            else
            {
                // guess was wrong so we learn a new animal

                if (current == NULL)
                {
                    cout << "Current is null for some reason...\n";
                }
                else
                {
                    cout << "Current is good...\n";
                }

                Node * newNode = learnNewAnimal(current);

                cout << "Just learned...\n";

                if (prev == NULL)
                {
                    cout << "Previous is null...\n";
                }

                // if current is on the right then we add this to the right
                // otherwise we add it to the left
                if (current == prev->getRight())
                {
                    cout << "setting to right node...\n";
                    prev->setRight(newNode);
                }
                else
                {
                    cout << "setting to left node...\n";
                    prev->setLeft(newNode);
                }

                cout << "setting current...\n";
                current = newNode;


                cout << "ask if play again...\n";
                if (playAgain())
                {
                    cout << "Play again said yes...\n";
                    prev = NULL;
                    current = root;
                }
            }
        }
        else
        {
            prev = current;
            if (askQuestion(current))
            {
                current = current->getRight();
            }
            else
            {
                current = current->getLeft();
            }
        }
    }

    return 0;
}



bool isCorrect()
{
    cout << "Is that correct? (yes/no): " << endl;
    string answer;
    getline(cin, answer);
    return answer == "yes";
}

bool askQuestion(Node * n)
{
    cout << n->getText() << " (yes/no): " << endl;

    string answer;
    getline(cin, answer);
    return answer == "yes";
}


bool playAgain()
{
    cout << "\nDo you want to play again? (yes/no): " << endl;
    string answer;
    getline(cin, answer);
    return answer == "yes";
}

Node * learnNewAnimal(Node * n)
{
    cout << "What is the animal? " << endl;
    string newAnimal;
    getline(cin, newAnimal);

    Node * newAnimalNode = new Node(newAnimal);

    cout << "Enter a new question that is a yes for " << newAnimal << " and no for "
        << n->getText() << "?" << endl;

    string newQuestion;
    getline(cin, newQuestion);
    Node * newQuestionNode = new Node(newQuestion);

    newQuestionNode->setLeft(n);
    newQuestionNode->setRight(newAnimalNode);
    return newQuestionNode;
}

