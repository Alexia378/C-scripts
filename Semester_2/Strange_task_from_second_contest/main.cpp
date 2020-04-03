#include <iostream>
#include <vector>
#include <utility>

void heap_shift(std::vector<std::pair<int, int>> v, int first, int second)
{
    int max;
    int completed = 0;

    while ((first * 2 <= second) && (!completed))
    {
        if ((first * 2 == second) || (v[first * 2].first > v[first * 2 + 1].first))
            max = first * 2;
        else
            max = first * 2 + 1;

        if (v[first].first >= v[max].first)
            completed = 1;
        else
        {
            std::swap(v[first].first, v[max].second);

            first = max;
        }
    }
}

void heapSort(std::vector<std::pair<int, int>> v, int n)
{
    for (int i = (n / 2) - 1; i > -1; i--)
        heap_shift(v, i, n - 1);

    for (int i = n - 1; i >= 1; i--)
    {
        std::pair<int, int> t = v[0];
        v[0] = v[i];
        v[i] = t;

        heap_shift(v, 0, i - 1);
    }
}

int count_hours(int n, std::vector<std::pair<int, int>> v, int hour)
{
    int count = 0;
    int left = 0;
    int right = n;

    while(left <= right)
    {
        int middle = (left+right)/2;
        if(hour >= v[middle].first && hour <= v[middle].second)
        {
            count++;
        }

        if(hour <= v[middle].second ??)
            right = middle - 1;
        else
            left = middle + 1;

    }
    return count;
}


int main() {
    int n, x, y, k;
    std::vector <std::pair<int, int>> v;
    std::cin >> n;
    for(int i=0;i<n; i++)
    {
        std::cin >> x >> y;
        v.push_back(std::make_pair(x, y));
    }

    heapSort(v, n);

    std::cin >> k;

    int hour;
    for(int i = 0; i < k; i++) {
        std::cin >> hour;
        int count = count_hours(n, v, hour);
        std::cout  << count << "\n";
    }
}