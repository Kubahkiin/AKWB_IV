//
// Created by kubah on 10.06.2023.
//

#ifndef AKWB4_MAP_FUNCTIONS_H
#define AKWB4_MAP_FUNCTIONS_H

void szukaj(...,int ind,int *jest)
{
...

if (ind==maxind)
{
<wypisz rozwiązanie>
*jest=1;
}
else for (...)
{
...
if (<warto kontynuować bieżące rozwiązanie>)
szukaj(...,ind+1,jest);
if (*jest==1) break;
...
}
}

int main(...)
{
    ...
    int jest;

    ...
    szukaj(...,0,&jest);
    if (jest==0) {<poinformuj o braku rozwiązania>}
    ...
}

#endif //AKWB4_MAP_FUNCTIONS_H
