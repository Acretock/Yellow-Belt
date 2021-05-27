#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
enum class TaskStatus
{
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};

using TaskInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
    const TaskInfo& GetPersonTaskInfo(const string& person) const { 
        if (table.count(person) != 0) {
            return table.at(person);
        }
    }
    void AddNewTask(const string& person) {        
            table[person][TaskStatus::NEW] += 1;        
    }
        
    tuple<TaskInfo, TaskInfo> PerformPersonTasks(const string& person, int task_count) {
        if (table.count(person) == 0) {
    }
        TaskInfo remains = table.at(person);
        TaskInfo changed;
        int num_of_tasks = table.at(person)[TaskStatus::NEW] +  //max number of tasks
            table.at(person)[TaskStatus::IN_PROGRESS] +
            table.at(person)[TaskStatus::TESTING];
        if (num_of_tasks > task_count) {
            num_of_tasks = task_count;
        }
        while (table.at(person)[TaskStatus::NEW] != 0 && num_of_tasks != 0) {           // if there is new, start it
            table[person][TaskStatus::NEW]--;
            table[person][TaskStatus::IN_PROGRESS]++;
            changed[TaskStatus::IN_PROGRESS]++;
            remains[TaskStatus::NEW]--;
            num_of_tasks--;
        }
        while (table.at(person)[TaskStatus::IN_PROGRESS] != 0 && num_of_tasks != 0) {   // if there is no new, in progres goes to testing
            table[person][TaskStatus::IN_PROGRESS]--;
            table[person][TaskStatus::TESTING]++;
            changed[TaskStatus::TESTING]++;
            remains[TaskStatus::IN_PROGRESS]--;
            num_of_tasks--;
        }while (table.at(person)[TaskStatus::TESTING] != 0 && num_of_tasks != 0) {      // if there is no in progres, testing goes to done
            table[person][TaskStatus::TESTING]--;
            table[person][TaskStatus::DONE]++;
            changed[TaskStatus::DONE]++;
            remains[TaskStatus::TESTING]--;
            num_of_tasks--;
        }
        return tie(changed, remains);
        
    }

private:
    map<string, TaskInfo> table;

    void RemoveTask(int& Status, int& num, int& cnew) {
        while (Status != 0 || num != 0) {
            Status--;
            num--;
            cnew++;
        }
    }
};


void PrintTasksInfo(TaskInfo task_info) {
    cout << task_info[TaskStatus::NEW] << " new tasks, "
        << task_info[TaskStatus::IN_PROGRESS] << " tasks in progress, "
        << task_info[TaskStatus::TESTING] << " tasks are being tested, "
        << task_info[TaskStatus::DONE] << " tasks done" << endl;
}

int main()
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTaskInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTaskInfo("Ivan"));

    TaskInfo updated_tasks, untoched_tasks;

    tie(updated_tasks, untoched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untoched Ivan's tasks: ";
    PrintTasksInfo(untoched_tasks);

    tie(updated_tasks, untoched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untoched Ivan's tasks: ";
    PrintTasksInfo(untoched_tasks);

    return 0;
}