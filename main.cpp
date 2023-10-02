#include "map_functions.h"

int main()
{
    vector < int > multi_a;
    vector < int > not_used;
    vector < int > restriction_map;
    load_vector(multi_a);
    copy(multi_a.begin(), multi_a.end(), back_inserter(not_used));
    sort(multi_a.begin(), multi_a.end());

    int site_count = check_size(multi_a.size());
    if(!site_count) {
        cout << "\nNieprawidlowy rozmiar instancji";
        return 101;
    }

    vector < int > maxes = find_maxes(multi_a);
    int max = maxes[0];
    int nd_max = maxes[1];
    if (!check_first_element(multi_a, not_used, restriction_map, max, nd_max)) {
        cout << "\nBrak pierwszego elementu w zbiorze";
        return 202;
    }

    cout << "\nInstancja ma prawidlowy rozmiar, oraz pierwszy element mapy znajduje sie w multizbiorze";

    cout << "\nSkladanie mapy dla multizbioru:\n";
    display_vector(multi_a);

    int found = 0;

    auto start = high_resolution_clock::now();

    seek(not_used, restriction_map, site_count, &found, max);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Czas wykonania: "
         << (double)duration.count() / 1000000 << " sekund" << endl;


    if (!found) {
        cout << "\nBrak rozwiazania";
    }

    return 0;
}