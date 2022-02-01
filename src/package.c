//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "miok/dqueue.h"


#include <stdlib.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Chicken Libraries
// 'DeQueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
// > [_prev_ptr] is the pointer to the prev node
//
typedef struct DeQueueNode
{
    char *_data;
    struct DeQueueNode *_prev_ptr;
    struct DeQueueNode *_next_ptr;
} DeQueueNode; // end of struct

//
// This is the official definition for the Chicken Libraries
// 'DeQueueOf' type.
//
// Members:
// > _begin_ptr is the pointer to queue begin
// > _end_ptr is the pointer to queue end
//
struct DeQueueOf
{
    size_t _size;
    struct DeQueueNode *_end_ptr;
    struct DeQueueNode *_begin_ptr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
DeQueueOf *miok_dqueue_create(void)
{
    DeQueueOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_begin_ptr = NULL;
    new_structure->_end_ptr = NULL;
    new_structure->_size = 0;
    return new_structure;    
} // end of function miok_dqueue_create

//
// Should erase the queue structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structure_ref]: Reference pointer to your structure
//
void miok_dqueue_erase(DeQueueOf **structure_ref)
{
    if (!structure_ref || !*structure_ref)
    {
        return;
    } // end if

    while (miok_dqueue_not_empty(*structure_ref))
    {
        miok_dqueue_pop_end(*structure_ref);
    } // end while

    free(*structure_ref);
    *structure_ref = NULL;
} // end of function miok_dqueue_erase

//
// Should perform same behavior as miok_dqueue_push_start
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_dqueue_push(DeQueueOf *structure_ptr, const char *data)
{
    miok_dqueue_push_start(structure_ptr, data);
} // end of function miok_dqueue_push

//
// Should push a new recored into start of the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_dqueue_push_start(DeQueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_next_ptr = structure_ptr->_begin_ptr;
    temp->_prev_ptr = NULL;
    temp->_data = (char *)data;

    if (miok_dqueue_its_empty(structure_ptr))
    {
        structure_ptr->_end_ptr = temp;
    } // end if
    else
    {
        structure_ptr->_begin_ptr->_prev_ptr = temp;
    } // end else
    
    structure_ptr->_begin_ptr = temp;
    ++structure_ptr->_size;
} // end of function miok_dqueue_push_start

//
// Should push a new recored into end of the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_dqueue_push_end(DeQueueOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if
    DeQueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_next_ptr = NULL;
    temp->_prev_ptr = structure_ptr->_end_ptr;
    temp->_data = (char *)data;

    if (miok_dqueue_its_empty(structure_ptr))
    {
        structure_ptr->_begin_ptr = temp;
    } // end if
    else
    {
        structure_ptr->_end_ptr->_next_ptr = temp;
    } // end else
    
    structure_ptr->_end_ptr = temp;
    ++structure_ptr->_size;
} // end of function miok_dqueue_push_end

//
// Should perform same behavior as miok_dqueue_pop_start
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_pop(DeQueueOf *structure_ptr)
{
    return miok_dqueue_pop_start(structure_ptr);
} // end of function miok_dqueue_pop

//
// Should return the value stored in the removed node from
// start of structure if the structure is both not nullptr
// and or empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_pop_start(DeQueueOf *structure_ptr)
{
    if (!structure_ptr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structure_ptr->_begin_ptr;
    char *value;
    structure_ptr->_begin_ptr = temp->_next_ptr;

    if (!structure_ptr->_begin_ptr)
    {
        structure_ptr->_end_ptr = NULL;
    } // end if
    else
    {
        structure_ptr->_begin_ptr->_prev_ptr = NULL;
    } // end else
    --structure_ptr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of function miok_dqueue_pop_start

//
// Should return the value stored in the removed node from
// end structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_pop_end(DeQueueOf *structure_ptr)
{
    if (!structure_ptr)
    {
        return NULL;
    } // end if

    DeQueueNode *temp = structure_ptr->_end_ptr;
    char *value;
    structure_ptr->_end_ptr = temp->_prev_ptr;

    if (!structure_ptr->_end_ptr)
    {
        structure_ptr->_begin_ptr = NULL;
    } // end if
    else
    {
        structure_ptr->_end_ptr->_next_ptr = NULL;
    } // end else
    --structure_ptr->_size;
    value = temp->_data;
    free(temp);
    return value;
} // end of function miok_dqueue_pop_end


//
// Should perform the same behavior as miok_dqueue_peek_start
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_peek(DeQueueOf *structure_ptr)
{
    return miok_dqueue_peek_start(structure_ptr);
} // end of function miok_dqueue_peek

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_peek_start(DeQueueOf *structure_ptr)
{
    return (miok_dqueue_not_empty(structure_ptr)) ? structure_ptr->_begin_ptr->_data : NULL;
} // end of function miok_dqueue_peek_start

//
// Should return the value stored in end pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_dqueue_peek_end(DeQueueOf *structure_ptr)
{
    return (miok_dqueue_not_empty(structure_ptr)) ? structure_ptr->_end_ptr->_data : NULL;
} // end of function miok_dqueue_peek_end

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_dqueue_its_empty(DeQueueOf *structure_ptr)
{
    return (!structure_ptr->_begin_ptr || !structure_ptr->_end_ptr) ? success : failed;
} // end of functions miok_dqueue_its_empty

//
// Should return a success value if the structure is not
// empty in anyway.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_dqueue_not_empty(DeQueueOf *structure_ptr)
{
    return (structure_ptr->_begin_ptr || structure_ptr->_end_ptr) ? success : failed;
} // end of functions miok_dqueue_not_empty

//
// Should return the number of items stored in the structure if it's not
// empty in anyway.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_dqueue_get_size(DeQueueOf *structure_ptr)
{
    return (miok_dqueue_not_empty(structure_ptr)) ? structure_ptr->_size : failed;
} // end of functions miok_dqueue_not_empty
