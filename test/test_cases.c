//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "miok/dqueue.h"
#include <unity.h>

DeQueueOf *queue;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    queue = miok_dqueue_create();
} // end of function setUp

void tearDown(void)
{
    miok_dqueue_erase(&queue);
} // end of function tearDown

//
// list of all the test cases for this project
//
static void test_miok_dqueue_push_start(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_dqueue_push_start(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", miok_dqueue_peek_start(queue));

    miok_dqueue_push_start(queue, "2077");
    miok_dqueue_push_start(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2010", miok_dqueue_peek_start(queue));
} // end of test case

static void test_miok_dqueue_push_start_with_nullptr(void)
{
    miok_dqueue_push_start(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));

    miok_dqueue_push_start(NULL, "2077");
    miok_dqueue_push_start(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));
} // end of test case

static void test_miok_dqueue_push_end(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_dqueue_push_end(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", miok_dqueue_peek_start(queue));
    TEST_ASSERT_EQUAL_STRING("2021", miok_dqueue_peek_end(queue));

    miok_dqueue_push_end(queue, "2077");
    miok_dqueue_push_end(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2021", miok_dqueue_peek_start(queue));
    TEST_ASSERT_EQUAL_STRING("2010", miok_dqueue_peek_end(queue));
} // end of test case

static void test_miok_dqueue_push_end_with_nullptr(void)
{
    miok_dqueue_push_end(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_end(queue));

    miok_dqueue_push_end(NULL, "2077");
    miok_dqueue_push_end(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));
    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_end(queue));
} // end of test case

static void test_miok_dqueue_pop_start(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_dqueue_push_start(queue, "red chicken");
    miok_dqueue_push_start(queue, "blue chicken");
    miok_dqueue_push_start(queue, "black chicken");
    miok_dqueue_push_start(queue, "green chicken");
    miok_dqueue_push_start(queue, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("yellow chicken", miok_dqueue_peek_start(queue));
    miok_dqueue_pop_start(queue);
    TEST_ASSERT_EQUAL_STRING("green chicken", miok_dqueue_peek_start(queue));
    miok_dqueue_pop_start(queue);
    TEST_ASSERT_EQUAL_STRING("black chicken", miok_dqueue_peek_start(queue));

} // end of test case

static void test_miok_dqueue_pop_end(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_dqueue_push_end(queue, "red chicken");
    miok_dqueue_push_end(queue, "blue chicken");
    miok_dqueue_push_end(queue, "black chicken");
    miok_dqueue_push_end(queue, "green chicken");
    miok_dqueue_push_end(queue, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_dqueue_peek_start(queue));
    miok_dqueue_pop_end(queue);
    TEST_ASSERT_EQUAL_STRING("red chicken", miok_dqueue_peek_start(queue));
    miok_dqueue_pop_end(queue);
    TEST_ASSERT_EQUAL_STRING("red chicken", miok_dqueue_peek_start(queue));

} // end of test case

static void test_miok_dqueue_its_empty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(miok_dqueue_its_empty(queue));
    miok_dqueue_push_start(queue, "red chicken");
    TEST_ASSERT_FALSE(miok_dqueue_its_empty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_dqueue_peek_start(queue));
} // end of test case

static void test_miok_dqueue_its_empty_with_nullptr(void)
{
    miok_dqueue_push_start(NULL, "red chicken");
    TEST_ASSERT_TRUE(miok_dqueue_its_empty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));
} // end of test case

static void test_miok_dqueue_not_empty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_FALSE(miok_dqueue_not_empty(queue));
    miok_dqueue_push_start(queue, "red chicken");
    TEST_ASSERT_TRUE(miok_dqueue_not_empty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", miok_dqueue_peek_start(queue));
} // end of test case

static void test_miok_dqueue_not_empty_with_nullptr(void)
{
    miok_dqueue_push_start(NULL, "red chicken");
    TEST_ASSERT_FALSE(miok_dqueue_not_empty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_dqueue_peek_start(queue));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_miok_dqueue_push_start);
    RUN_TEST(test_miok_dqueue_push_end);
    RUN_TEST(test_miok_dqueue_pop_start);
    RUN_TEST(test_miok_dqueue_pop_end);
    RUN_TEST(test_miok_dqueue_its_empty);
    RUN_TEST(test_miok_dqueue_not_empty);
    RUN_TEST(test_miok_dqueue_push_start_with_nullptr);
    RUN_TEST(test_miok_dqueue_push_end_with_nullptr);
    RUN_TEST(test_miok_dqueue_its_empty_with_nullptr);
    RUN_TEST(test_miok_dqueue_not_empty_with_nullptr);

    return UNITY_END();
} // end of function main
