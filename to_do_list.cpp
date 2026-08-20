#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class ToDoListManager
{
private:
    vector<string> tasks;
    static int task_counter;

public:
    void save_tasks()
    {
        ofstream outFile("tasks.txt");

        for (int i = 0; i < tasks.size(); i++)
        {
            outFile << tasks[i] << endl;
        }
    }

    void load_tasks()
    {
        ifstream inFile("tasks.txt");

        while (inFile.eof() == 0)
        {
            string task;

            getline(inFile, task);

            if (task != "")
            {
                tasks.push_back(task);
                task_counter++;
            }
        }
    }
    void add_task()
    {
        string task;

        cout << "Enter the task -";

        cin.ignore();
        getline(cin, task);

        tasks.push_back(task);
    }

    void print_tasks()
    {
        cout << "-----------Your Tasks-------------" << endl
             << endl
             << "|" << "Sr No" << setw(2) << "|" << setw(13) << "Task Name" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << left << setw(2) << "|" << setw(2) << i + 1 << setw(3) << ")" << setw(4) << "|" << tasks[i] << endl;
        }

        cout << endl;
    }

    void delete_task()
    {
        int task_no;

        cout << "enter task no to be deleted -";

        cin >> task_no;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }

        if (task_no > tasks.size())
        {
            cout << "enter valid task no " << endl;
        }
        else if (task_no <= tasks.size())
        {
            tasks.erase(tasks.begin() + (task_no - 1));
        }
        else
        {
            cout << "enter valid task no " << endl;
        }
    }
};

int ToDoListManager::task_counter = 0;

int main()
{
    int choice;
    ToDoListManager to_do_list;
    bool isInvalidChoice;

    to_do_list.load_tasks();

    while (true)
    {
        system("cls");

        cout << "1) Add task" << endl;
        cout << "2) remove task" << endl;
        cout << "3) save and quit" << endl
             << endl;

        to_do_list.print_tasks();

        if (isInvalidChoice)
        {
            cout << endl
                 << "enter valid choice" << endl;
        }

        cout << "enter choice -";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }

        switch (choice)
        {
        case 1:
            isInvalidChoice = false;
            to_do_list.add_task();
            break;
        case 2:
            isInvalidChoice = false;
            to_do_list.delete_task();
            break;
        case 3:
            isInvalidChoice = false;
            cout << endl
                 << endl
                 << "saving tasks...." << endl;

            to_do_list.save_tasks();

            cout << "your tasks are saved" << endl;
            return 0;

        default:
            isInvalidChoice = true;
            break;
        }
    }
    return 0;
}
