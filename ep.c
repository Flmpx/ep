#include "./ep.h"
#include <assert.h>

/* Create a ep */
ep* ep_new(void* val, void (*free)(void*)) {
    ep* ret = (ep*)malloc(sizeof(ep));
    if (ret == NULL) {
        return NULL;
    }

    ret->free = free;
    ret->val = val;
    ret->ref_count = 1;

    return ret;
}

/* The val of ep */
void* ep_val(ep* e) {
    return e->val;
}

/* Increase reference count */
ep* ep_ref(ep* e) {
    assert(e != NULL);

    e->ref_count++;

    return e;
}

/* Decrease reference count and it will destroy val by pass-in free funciton when count is zero*/
void ep_unref(ep* e) {
    if (e == NULL || e->ref_count == 0) return;

    e->ref_count--;
    if (e->ref_count == 0) {
        if (e->free) {
            e->free(e->val);
        }
        free(e);
    }
}