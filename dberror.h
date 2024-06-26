#ifndef DBERROR_H
#define DBERROR_H

#include "stdio.h"

/* module wide constants */
#define PAGE_SIZE 4096

/* return code definitions */
typedef int RC;

#define RC_OK 0
#define RC_FILE_NOT_FOUND 1
#define RC_FILE_HANDLE_NOT_INIT 2
#define RC_WRITE_FAILED 3
#define RC_READ_NON_EXISTING_PAGE 4

#define RC_PINNED_PAGES_IN_BUFFER 5
#define RC_BUFFER_POOL_NOT_INIT 6
#define RC_BUFFERPOOL_PAGE_NOTFOUND_IN_MARKDIRTY 7
#define RC_BUFFERPOOL_PAGE_NOTFOUND_IN_UNPINPAGE 8
#define RC_BUFFERPOOL_PAGE_NOTFOUND_IN_FORCEPAGE 9
#define RC_ERROR 10
#define RC_NUMPAGES_NEGATIVE 11

#define RC_RM_NO_RECORD_FOUND 12
#define RC_PRIMARYKEY_VIOLATION 13
#define RC_ORDER_TOO_HIGH_FOR_PAGE 14
#define RC_INVALID_PARAMETER 17
#define RC_INVALID_ORDER 18
#define RC_NO_RECORDS_FOUND 16
#define RC_CALLOC_FAILED 19
#define RC_RM_NO_TUPLE_WITH_GIVEN_RID 600
#define RC_SCAN_CONDITION_NOT_FOUND 601
#define RC_MEM_ALLOCATION_FAILED 602
#define RC_MALLOC_FAILED 603
#define RC_SCHEMA_NOT_CREATED 604
#define RC_RM_UNINITIALIZED_TABLE 605

#define RC_RM_COMPARE_VALUE_OF_DIFFERENT_DATATYPE 200
#define RC_RM_EXPR_RESULT_IS_NOT_BOOLEAN 201
#define RC_RM_BOOLEAN_EXPR_ARG_IS_NOT_BOOLEAN 202
#define RC_RM_NO_MORE_TUPLES 203
#define RC_RM_NO_PRINT_FOR_DATATYPE 204
#define RC_RM_UNKOWN_DATATYPE 205
#define RC_RM_SCHEMA_SIZE_TOO_BIG 206
#define RC_RM_RECORD_SIZE_TOO_BIG 207
#define RC_TABLE_NOT_FOUND 208

#define RC_IM_KEY_NOT_FOUND 300
#define RC_IM_KEY_ALREADY_EXISTS 301
#define RC_IM_N_TO_LAGE 302
#define RC_IM_NO_MORE_ENTRIES 303
#define RC_OK 0
#define RC_FILE_NOT_FOUND 1
#define RC_FILE_HANDLE_NOT_INIT 2
#define RC_WRITE_FAILED 3
#define RC_READ_NON_EXISTING_PAGE 4

/* holder for error messages */
extern char *RC_message;

/* print a message to standard out describing the error */
extern void printError (RC error);
extern char *errorMessage (RC error);

#define THROW(rc,message) \
		do {			  \
			RC_message=message;	  \
			return rc;		  \
		} while (0)		  \

// check the return code and exit if it is an error
#define CHECK(code)							\
		do {									\
			int rc_internal = (code);						\
			if (rc_internal != RC_OK)						\
			{									\
				char *message = errorMessage(rc_internal);			\
				printf("[%s-L%i-%s] ERROR: Operation returned error: %s\n",__FILE__, __LINE__, __TIME__, message); \
				free(message);							\
				exit(1);							\
			}									\
		} while(0);


#endif
