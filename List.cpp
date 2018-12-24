#include <vector>
#include "List.hpp"
#include "point.hpp"

using namespace std;

void List :: insert (double a, double b) {
    point * tmp = new point;
    tmp->setCoordinates(a, b);
    
    if ( is_empty() ) {
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    else {
        tmp->next = cur->next;
        cur->next = tmp;
        tmp->prev = cur;
        tmp->next->prev = tmp;
    }
    cur = tmp; 

    size++;
}

void List :: insert (double *a, int n) {
    point * tail = 0;
    
    if ( is_empty() ) {
        for ( int i = 0; i < n; i += 2 ) {
            insert (a[i], a[i + 1]);
            
            if ( i == 0 )
                tail = cur;
        }
        //замыкаем список
        cur->next = tail;
        cur->next->prev = cur;
        cur = cur->next;
    }
}

point * List :: find (double a, double b) {
    point * tmp = cur;
    if ( !is_empty() ) {
        do {
            if ( a == tmp->getX() && b == tmp->getY() )
                return tmp;
            else
                tmp = tmp->next;
        } while ( tmp != cur );
    }
    return 0;
}

void List :: delete_node (double a, double b) {
    point * tmp = find (a, b);
    if (tmp) { 
        if ( tmp == cur ) cur = cur->prev;
        
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        delete tmp;
        size--;
    }
}




