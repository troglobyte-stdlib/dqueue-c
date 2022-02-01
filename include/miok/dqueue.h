//
// file: package.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef MIOK_DQUEUE_PACKAGE_H
#define MIOK_DQUEUE_PACKAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_MIOK_DQUEUE_PACKAGE
#define MIOK_DQUEUE_PUBLIC __attribute__((visibility("default")))
#else
#define MIOK_DQUEUE_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard. If you wish to use a version of this library
// that targets an older version of C append "-support" at the end of the
// package name and everything should just work.
//

typedef struct DeQueueOf DeQueueOf;

//
// Constructor and destructor functions
//

MIOK_DQUEUE_PUBLIC DeQueueOf *miok_dqueue_create(void);
MIOK_DQUEUE_PUBLIC void miok_dqueue_erase(DeQueueOf **structure_ref);

//
// Operations provided
//

MIOK_DQUEUE_PUBLIC void miok_dqueue_push(DeQueueOf *structure_ptr, const char *data);
MIOK_DQUEUE_PUBLIC void miok_dqueue_push_start(DeQueueOf *structure_ptr, const char *data);
MIOK_DQUEUE_PUBLIC void miok_dqueue_push_end(DeQueueOf *structure_ptr, const char *data);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_pop(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_pop_start(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_pop_end(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_peek(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_peek_start(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC char *miok_dqueue_peek_end(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC unsigned int miok_dqueue_its_empty(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC unsigned int miok_dqueue_not_empty(DeQueueOf *structure_ptr);
MIOK_DQUEUE_PUBLIC unsigned int miok_dqueue_get_size(DeQueueOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif // end of MIOK_PACKAGE_H
