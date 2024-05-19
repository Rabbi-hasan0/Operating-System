#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int  wt[N], tat[N], prefix[N];

bool cmp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.second.first < b.second.first;
}
bool comp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first < b.first;
}

void findWaitingTime(int n, vector<pair<int, pair<int, int>>> &vp) {
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + vp[i - 1].second.second;
    }
    wt[vp[0].first] = 0;
    for (int i = 1; i < n; i++) {
        wt[vp[i].first] = max(0, prefix[i] - vp[i].second.first);
    }
}

void findTurnAroundTime(int n, vector<pair<int, pair<int, int>>> &vp) {
    for (int i = 1; i <= n; i++) {
        tat[i] = wt[i] + vp[i - 1].second.second;
    }
}

void findAvgTime(int n, vector<pair<int, pair<int, int>>> &vp) {
    int total_wt = 0, total_tat = 0;

    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "Process " << i << ":  Waiting Time:  " << wt[i]
             << "      Turnaround Time: " << tat[i] << '\n';
    }

    cout << "\nAverage Waiting time: " << (float)total_wt / n << '\n';
    cout << "Average Turnaround time: " << (float)total_tat / n << '\n';
}

int main() {
    int n; cin >> n;
    vector<pair<int, pair<int, int>>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i].first = i + 1;
        cin >> vp[i].second.first;
    }
    for (int i = 0; i < n; i++) {
        cin >> vp[i].second.second;
    }
    sort(vp.begin(), vp.end(), cmp);
    findWaitingTime(n, vp);
    sort(vp.begin(), vp.end(), comp);
    findTurnAroundTime(n, vp);
    findAvgTime(n, vp);
    return 0;
}
