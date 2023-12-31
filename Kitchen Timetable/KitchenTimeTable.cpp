/*

Problem
Read problems statements in Mandarin Chinese, Russian and Vietnamese as well.
There are N students living in the dormitory of Berland State University. Each of them sometimes wants to use the kitchen, so the head of the dormitory came up with a timetable for kitchen's usage in order to avoid the conflicts:

The first student starts to use the kitchen at the time 0 and should finish the cooking not later than at the time A1.
The second student starts to use the kitchen at the time A1 and should finish the cooking not later than at the time A2.
And so on.
The N-th student starts to use the kitchen at the time AN-1 and should finish the cooking not later than at the time AN
The holidays in Berland are approaching, so today each of these N students wants to cook some pancakes. The i-th student needs Bi units of time to cook.

The students have understood that probably not all of them will be able to cook everything they want. How many students will be able to cook without violating the schedule?

Input Format
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains 3 lines of input

The first line of each test case contains a single integer N denoting the number of students.
The second line contains N space-separated integers A1, A2, ..., AN denoting the moments of time by when the corresponding student should finish cooking.
The third line contains N space-separated integers B1, B2, ..., BN denoting the time required for each of the students to cook.
Output Format
For each test case, output a single line containing the number of students that will be able to finish the cooking.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 104
0 < A1 < A2 < ... < AN < 109
1 ≤ Bi ≤ 109

Sample 1:
Input                   Output
2                          2
3                          1
1 10 15
1 10 3
3
10 20 30
15 5 20

*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    int numberOfStudents;
    int time1, time2;
    int startTime;
    int finishTime = 0;
    int arr[T];
    vector<int> finishCookingTime;
    vector<int> timeRequiredToFinishCooking;
    for (int i = 0; i < T; i++)
    {
        cin >> numberOfStudents;
        for (int j = 0; j < numberOfStudents; j++)
        {
            cin >> time1;
            finishCookingTime.push_back(time1);
        }
        for (int k = 0; k < numberOfStudents; k++)
        {
            cin >> time2;
            timeRequiredToFinishCooking.push_back(time2);
        }
        int count = 0;
        startTime = 0;
        for (int l = 0; l < numberOfStudents; l++)
        {
            // cout << "start time " << startTime << endl;
            finishTime = finishCookingTime[l] - startTime;
            // cout << "Finish time is " << finishTime << endl;
            // cout << "Time Required to finish cooking " << timeRequiredToFinishCooking[l] << endl;
            startTime = finishCookingTime[l];
            // cout << "start time is " << startTime << endl;
            if (finishTime >= timeRequiredToFinishCooking[l])
            {
                count++;
                // cout << "Now the value of count is " << count << endl;
            }
        }
        arr[i] = count;
        finishCookingTime.clear();
        timeRequiredToFinishCooking.clear();
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}