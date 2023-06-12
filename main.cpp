#include "map_functions.h"

int main()
{
    vector < int > multi_a;
    vector < int > not_used;
    vector < int > restriction_map;
    load_vector(multi_a);
    copy(multi_a.begin(), multi_a.end(), back_inserter(not_used));

    int site_count = check_size(multi_a.size()); //ilosc przeciec obliczona ze wzoru
    if(!site_count) {
        cout << "\nNieprawidlowy rozmiar instancji";
        return 101;
    }

//    display_vector(not_used);
    if (!check_first_element(multi_a, not_used, restriction_map)) {
        cout << "\nBrak pierwszego elementu w zbiorze";
        return 202;
    }
//    display_vector(not_used);
//    display_vector(restriction_map);
    cout << "\nInstancja ma prawidlowy rozmiar, oraz pierwszy element mapy znajduje sie w multizbiorze";

    cout << "\nSkladanie mapy dla multizbioru:\n";
    display_vector(multi_a);

    int found = 0;

    seek(multi_a, not_used, restriction_map, site_count, &found);

    if (!found) {
        cout << "\nBrak rozwiazania";
    }

    return 0;
}