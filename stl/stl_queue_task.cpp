#include <iostream>
#include <queue>
using namespace std;

class TaskScheduler
{
private:
    queue<string> myTasks;

public:
    void addTask(const string &task)
    {
        myTasks.push(task);
    }

    void currentTask()
    {
        if (myTasks.empty())
        {
            cout << "You have completed all your tasks!!" << endl;
        }
        else
        {
            cout << "Current task: " << myTasks.front() << endl;
        }
    }

    void completeTask()
    {
        if (myTasks.empty())
        {
            cout << "You have completed all your tasks!!" << endl;
        }
        else
        {
            cout << "Completed: " << myTasks.front() << endl;
            myTasks.pop();
        }
    }

    void displayAllTasks()
    {
        queue<string> tasks = myTasks;
        if (tasks.empty())
        {
            cout << "You have completed all your tasks!!" << endl;
        }
        else
        {
            cout << "All Tasks: " << endl;
            while (!tasks.empty())
            {
                cout << tasks.front() << endl;
                tasks.pop();
            }
            cout << endl;
        }
    }
};

int main()
{
    TaskScheduler ts;
    ts.currentTask();

    ts.addTask("Wake up at 8 AM");
    ts.addTask("Get ready for work");
    ts.displayAllTasks();

    ts.completeTask();
    ts.currentTask();
    ts.completeTask();
    ts.completeTask();

    return 0;
}