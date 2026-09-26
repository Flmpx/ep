/*
 * Copyright (c) 2026 Flmpx
 * Licensed under MIT (see LICENSE).
 */

#include <stdlib.h>

typedef struct ep ep;

struct ep {
    void* val;                  // the pointer to element
    size_t ref_count;           // record the reference count
    void (*free)(void*);        // the function to clear content(call when ref_cout is zero)
};


extern ep* ep_new(void* val, void (*free)(void*));
extern void* ep_val(ep* e);
extern ep* ep_ref(ep* e);
extern void ep_unref(ep* e);