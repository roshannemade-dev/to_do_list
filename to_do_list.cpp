#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

class ToDoListManager
{
private:
    vector<string> tasks, date, time;

public:
    void save_tasks()
    {
        ofstream outFile("tasks.txt");

        for (int i = 0; i < tasks.size(); i++)
        {
            outFile << date[i] << "|" << time[i] << "|" << tasks[i] << endl;
        }
    }

    void load_tasks()
    {
        ifstream inFile("tasks.txt");
        string line, date, time, task;
        stringstream ss;

        while (getline(inFile, line))
        {
            ss << line;
            if (line != "")
            {
                getline(ss, date, '|');
                getline(ss, time, '|');
                getline(ss, task);

                ToDoListManager::date.push_back(date);
                ToDoListManager::time.push_back(time);
                ToDoListManager::tasks.push_back(task);
            }
            ss.clear();
        }
    }
    void add_task()
    {
        stringstream date, time;
        string task;

        cout << "Enter the task -";

        cin.ignore();
        getline(cin, task);

        auto now = chrono::system_clock::now();
        auto to_time_t = chrono::system_clock::to_time_t(now);

        tm *localTime = localtime(&to_time_t);

        date << put_time(localTime, "%d-%m-%Y");
        time << put_time(localTime, "%H:%M:%S");

        ToDoListManager::time.push_back(time.str());
        ToDoListManager::date.push_back(date.str());
        tasks.push_back(task);

        save_tasks();
    }

    void print_tasks()
    {
        cout << "-----------Your Tasks-------------" << endl
             << endl
             << left << setw(10) << "Sr No" << setw(13) << "Date" << setw(16) << "Time" << setw(13) << "Task Name" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << left << "  " << i + 1 << setw(5) << ")" << setw(14) << date[i] << setw(14) << time[i] << tasks[i] << endl;
        }

        cout << endl;
        system("pause");
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
            system("pause");
        }
        else if (task_no <= tasks.size())
        {
            tasks.erase(tasks.begin() + (task_no - 1));
            date.erase(date.begin() + (task_no - 1));
            time.erase(time.begin() + (task_no - 1));
        }
        else
        {
            cout << "enter valid task no " << endl;
            system("pause");
        }

        save_tasks();
    }
};

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
        cout << "3) print task" << endl;
        cout << "4) quit" << endl
             << endl;

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
            to_do_list.print_tasks();
            break;
        case 4:
            return 0;

        default:
            isInvalidChoice = true;
            break;
        }
    }
    return 0;
}
