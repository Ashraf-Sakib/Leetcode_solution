class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int mov = 0;
        int pos = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int n = seats.size();
        for (int i = 0; i < n; i++) {

            if (seats[i] != students[i]) {
                mov += abs(seats[i] - students[i]);
            }
        }
        return mov;
    }
};