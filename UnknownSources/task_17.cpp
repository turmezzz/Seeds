#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TEventsStats {
private:
    int window_size = 5;
    unordered_map <int, int> uid_to_activity_count_;
    unordered_map <int, unordered_set <int>> activity_count_to_uids_;
    list <pair <int, int>> users_queue_;

    void PopOld(int time) {
        while (not users_queue_.empty() and users_queue_.front().second <= time - window_size) {
            auto[pop_uid, pop_time] = users_queue_.front();
            users_queue_.pop_front();

            int activity_count = uid_to_activity_count_[pop_uid];
            activity_count_to_uids_[activity_count].erase(pop_uid);
            --activity_count;
            activity_count_to_uids_[activity_count].insert(pop_uid);
            uid_to_activity_count_[pop_uid] = activity_count;
        }
    }

public:
    void RegisterEvent(int uid, int time) {
        PopOld(time);
        users_queue_.emplace_back(uid, time);
        ++uid_to_activity_count_[uid];

        int activity_count = uid_to_activity_count_[uid];
        if (activity_count != 1) {
            activity_count_to_uids_[activity_count - 1].erase(uid);
        }
        activity_count_to_uids_[activity_count].insert(uid);
    }

    int Query(int count, int time) {
        PopOld(time);
        return activity_count_to_uids_[count].size();
    }
};

int main() {
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(12, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(14, 5);
        cout << (sol.Query(1, 6) == 4)<< endl;
    }
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(11, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(13, 5);
        cout << (sol.Query(1, 6) == 0)<< endl;
    }
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(11, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(13, 5);
        cout << (sol.Query(2, 6) == 2)<< endl;
    }
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(11, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(13, 5);
        cout << (sol.Query(0, 6) == 1)<< endl;
    }
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(11, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(13, 5);
        cout << (sol.Query(0, 1000) == 3)<< endl;
    }
    {
        TEventsStats sol;
        sol.RegisterEvent(10, 1);
        sol.RegisterEvent(11, 2);
        sol.RegisterEvent(12, 3);
        sol.RegisterEvent(13, 4);
        sol.RegisterEvent(14, 5);
        sol.RegisterEvent(15, 6);
        sol.RegisterEvent(16, 7);
        sol.RegisterEvent(17, 8);
        sol.RegisterEvent(18, 9);
        sol.RegisterEvent(19, 10);
        sol.RegisterEvent(20, 11);
        sol.RegisterEvent(21, 12);
        sol.RegisterEvent(22, 13);

        cout << (sol.Query(0, 1000) == 13)<< endl;
    }


    return 0;
}