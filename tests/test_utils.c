/* See LICENSE file for license and copyright information */

#include <check.h>

#include "../utils.h"

START_TEST(test_file_valid_extension_null) {
  fail_unless(file_valid_extension(NULL, NULL) == false, NULL);
  fail_unless(file_valid_extension((void*) 0xDEAD, NULL) == false, NULL);
  fail_unless(file_valid_extension(NULL, "pdf") == false, NULL);
} END_TEST

Suite* suite_utils()
{
  TCase* tcase = NULL;
  Suite* suite = suite_create("Utils");

  /* file valid extension */
  tcase = tcase_create("file_valid_extension");
  tcase_add_test(tcase, test_file_valid_extension_null);
  suite_add_tcase(suite, tcase);

  return suite;
}
