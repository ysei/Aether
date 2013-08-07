#include <stdlib.h>
#include <stdint.h>

#include <check.h>

#include "../src/instruction.h"

START_TEST(test_instruction_operation_extract_operation_code)
{
	uint8_t operation_code = instruction_operation_extract_operation_code(0xF000);

	ck_assert_int_eq(operation_code, 0x0F);
}
END_TEST

START_TEST(test_instruction_operation_extract_mode)
{
	uint8_t mode = instruction_operation_extract_mode(0x0038);

	ck_assert_int_eq(mode, 0x07);
}
END_TEST

START_TEST(test_instruction_operation_extract_register)
{
	uint8_t reg = instruction_operation_extract_register_low(0x0007);

	ck_assert_int_eq(reg, 0x07);

	reg = instruction_operation_extract_register_high(0x0E00);

	ck_assert_int_eq(reg, 0x07);
}
END_TEST

START_TEST(test_instruction_extension_extract_da)
{
	uint8_t da = instruction_extension_extract_da(0x8000);

	ck_assert_int_eq(da, 0x01);
}
END_TEST

START_TEST(test_instruction_extension_extract_register)
{
	uint8_t reg = instruction_extension_extract_register(0x7000);

	ck_assert_int_eq(reg, 0x07);
}
END_TEST

START_TEST(test_instruction_extension_extract_wl)
{
	uint8_t wl = instruction_extension_extract_wl(0x0800);

	ck_assert_int_eq(wl, 0x01);
}
END_TEST

START_TEST(test_instruction_extension_extract_scale)
{
	uint8_t scale = instruction_extension_extract_scale(0x0600);

	ck_assert_int_eq(scale, 0x03);
}
END_TEST

START_TEST(test_instruction_extension_extract_type)
{
	uint8_t type = instruction_extension_extract_type(0x0100);

	ck_assert_int_eq(type, 0x01);
}
END_TEST

START_TEST(test_instruction_extension_extract_displacement)
{
	uint8_t displacement = instruction_extension_extract_displacement(0x00FF);

	ck_assert_int_eq(displacement, 0xFF);
}
END_TEST

START_TEST(test_instruction_extension_extract_bs)
{
	uint8_t bs = instruction_extension_extract_bs(0x0080);

	ck_assert_int_eq(bs, 0x01);
}
END_TEST

START_TEST(test_instruction_extension_extract_is)
{
	uint8_t is = instruction_extension_extract_is(0x0040);

	ck_assert_int_eq(is, 0x01);
}
END_TEST

START_TEST(test_instruction_extension_extract_bd_size)
{
	uint8_t bd_size = instruction_extension_extract_bd_size(0x0030);

	ck_assert_int_eq(bd_size, 0x03);
}
END_TEST

START_TEST(test_instruction_extension_extract_iis)
{
	uint8_t iis = instruction_extension_extract_iis(0x0007);

	ck_assert_int_eq(iis, 0x07);
}
END_TEST

Suite *instruction_suite(void)
{
	Suite *suite = suite_create("instruction");
	
	TCase *tcase_core = tcase_create("core");

	tcase_add_test(tcase_core, test_instruction_operation_extract_operation_code);
	tcase_add_test(tcase_core, test_instruction_operation_extract_mode);
	tcase_add_test(tcase_core, test_instruction_operation_extract_register);	
	tcase_add_test(tcase_core, test_instruction_extension_extract_da);
	tcase_add_test(tcase_core, test_instruction_extension_extract_register);
	tcase_add_test(tcase_core, test_instruction_extension_extract_wl);
	tcase_add_test(tcase_core, test_instruction_extension_extract_scale);
	tcase_add_test(tcase_core, test_instruction_extension_extract_type);
	tcase_add_test(tcase_core, test_instruction_extension_extract_displacement);
	tcase_add_test(tcase_core, test_instruction_extension_extract_bs);
	tcase_add_test(tcase_core, test_instruction_extension_extract_is);
	tcase_add_test(tcase_core, test_instruction_extension_extract_bd_size);
	tcase_add_test(tcase_core, test_instruction_extension_extract_iis);

	suite_add_tcase(suite, tcase_core);

	return suite;
}

int main(void)
{
	Suite *suite = instruction_suite();
	SRunner *srunner = srunner_create(suite);
	
	srunner_run_all(srunner, CK_VERBOSE);

	int failed = srunner_ntests_failed(srunner);

	srunner_free(srunner);

	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

	return 0;
}
