# Everything is a pointer
Easy to use  

## Example  

Code:  
```c
#include "ep.h"
#include <stdlib.h>
#include <stdio.h>

void print1(ep* e) {
    printf("This is print1: %d\n", *(int*)ep_val(e));

    ep_unref(e);
}

void print2(ep* e) {
    printf("This is print2: %d\n", *(int*)ep_val(e));

    ep_unref(e);
}

int main() 
{
    int* val = malloc(sizeof(int));
    ep* e = ep_new(val, free);
    
    *val = 0;
    print1(ep_ref(e));
    print2(ep_ref(e));

    *val = 99;
    print1(ep_ref(e));
    print2(ep_ref(e));
    
    ep_unref(e);
    
    return 0;
}
```

Result:  
```txt
This is print1: 0
This is print2: 0
This is print1: 99
This is print2: 99
```