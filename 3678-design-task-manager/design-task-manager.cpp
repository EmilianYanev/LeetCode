class TaskManager {
    unordered_map<int, set<pair<int, int>, std::greater<>>> data;
    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskPriority;
    set<pair<int, int>, std::greater<>> stack;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (vector<int> v : tasks) {
            stack.emplace(v[2], v[1]);
            taskToUser.emplace(v[1], v[0]);   // task -> user
            taskPriority.emplace(v[1], v[2]); // task -> priority
            data[v[0]].emplace(v[2], v[1]);   // userId -> <priority, taskId>
        }
    }

    void add(int userId, int taskId, int priority) {
        data[userId].emplace(priority, taskId);
  taskToUser[taskId]   = userId;     // <-- overwrite if exists
    taskPriority[taskId] = priority; 
        stack.emplace(priority, taskId);
    }

    void edit(int taskId, int newPriority) {
        // task -> user
        int currentUser = taskToUser.find(taskId)->second;
        // memorize old priority, since you cannot change set data inplace
        int oldPriority = taskPriority.find(taskId)->second;

        // delete the memorized entry
        auto it =
            data.find(currentUser)->second; // .erase({ oldPriority, taskId });
        it.erase({oldPriority, taskId});
        taskPriority.erase(taskId);
        stack.erase({oldPriority, taskId});
        // emplace new entry
        it.emplace(newPriority, taskId);
        // taskPriority.emplace(taskId, newPriority);
        stack.emplace(newPriority, taskId);
        taskPriority[taskId] = newPriority;
    }

    void rmv(int taskId) {
        // task -> user
        int currentUser = taskToUser.find(taskId)->second;
        // memorize old priority, since you cannot change set data inplace
        int oldPriority = taskPriority.find(taskId)->second;

        // delete the memorized entry
        data.find(currentUser)->second.erase({oldPriority, taskId});
        // taskToUser.erase(taskId);
        // taskPriority.erase(taskId);
        stack.erase({oldPriority, taskId});
    }

    int execTop() {
        if (stack.empty())
            return -1;

        auto it = stack.begin();
        int pri = it->first;
        int task = it->second;
        int user = taskToUser[task];

        rmv(task);

        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */