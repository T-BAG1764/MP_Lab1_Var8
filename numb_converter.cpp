#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

double mean(const vector<double>& a) {
    double sum = accumulate(a.begin(), a.end(), 0.0);
    return sum / a.size();
}

double median(vector<double> a) {
    sort(a.begin(), a.end());
    int n = a.size();
    if (n % 2 == 0)
        return (a[n / 2 - 1] + a[n / 2]) / 2.0;
    else
        return a[n / 2];
}

vector<double> mode(const vector<double>& a) {
    map<double, int> freq;
    for (double x : a) {
        freq[x]++;
    }

    int maxFreq = 0;
    for (auto& p : freq) {
        if (p.second > maxFreq)
            maxFreq = p.second;
    }

    vector<double> modes;
    for (auto& p : freq) {
        if (p.second == maxFreq)
            modes.push_back(p.first);
    }

    return modes;
}

double variance(const vector<double>& a) {
    double avg = mean(a);
    double sum = 0.0;
    for (double x : a) {
        sum += (x - avg) * (x - avg);
    }
    return sum / a.size(); // дисперсия генеральной совокупности
}

double stddev(const vector<double>& a) {
    return sqrt(variance(a));
}

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;

    if (n <= 0) {
        cout << "Массив пуст." << endl;
        return 0;
    }

    vector<double> numbers(n);
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << fixed << setprecision(6);
    cout << "Среднее: " << mean(numbers) << endl;
    cout << "Медиана: " << median(numbers) << endl;

    vector<double> modes = mode(numbers);
    if (modes.size() == 1) {
        cout << "Мода: " << modes[0] << endl;
    }
    else {
        cout << "Мода: ";
        for (double x : modes)
            cout << x << " ";
        cout << endl;
    }

    cout << "Дисперсия: " << variance(numbers) << endl;
    cout << "Стандартное отклонение: " << stddev(numbers) << endl;

    return 0;
}