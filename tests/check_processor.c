#include <stdlib.h>
#include <stdint.h>

#include <check.h>

#include "../src/processor.h"

START_TEST(test_processor_ccr_extend_read)
{
	processor_t processor;

	processor.sr = 0x0010;

	uint8_t ccr_extend = processor_ccr_extend_read(&processor);

	ck_assert_int_eq(ccr_extend, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_negative_read)
{
	processor_t processor;

	processor.sr = 0x0008;

	uint8_t ccr_negative = processor_ccr_negative_read(&processor);

	ck_assert_int_eq(ccr_negative, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_zero_read)
{
	processor_t processor;

	processor.sr = 0x0004;

	uint8_t ccr_zero = processor_ccr_zero_read(&processor);

	ck_assert_int_eq(ccr_zero, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_overflow_read)
{
	processor_t processor;

	processor.sr = 0x0002;

	uint8_t ccr_overflow = processor_ccr_overflow_read(&processor);

	ck_assert_int_eq(ccr_overflow, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_carry_read)
{
	processor_t processor;

	processor.sr = 0x0001;

	uint8_t ccr_carry = processor_ccr_carry_read(&processor);

	ck_assert_int_eq(ccr_carry, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_extend_set)
{
	processor_t processor;

	processor_ccr_extend_set(&processor);

	ck_assert_int_eq(processor.sr, 0x10);
}
END_TEST

START_TEST(test_processor_ccr_negative_set)
{
	processor_t processor;

	processor_ccr_negative_set(&processor);

	ck_assert_int_eq(processor.sr, 0x08);
}
END_TEST

START_TEST(test_processor_ccr_zero_set)
{
	processor_t processor;

	processor_ccr_zero_set(&processor);

	ck_assert_int_eq(processor.sr, 0x04);
}
END_TEST

START_TEST(test_processor_ccr_overflow_set)
{
	processor_t processor;

	processor_ccr_overflow_set(&processor);

	ck_assert_int_eq(processor.sr, 0x02);
}
END_TEST

START_TEST(test_processor_ccr_carry_set)
{
	processor_t processor;

	processor_ccr_carry_set(&processor);

	ck_assert_int_eq(processor.sr, 0x01);
}
END_TEST

START_TEST(test_processor_ccr_extend_clear)
{
	processor_t processor;

	processor.sr = 0x0010;

	processor_ccr_extend_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_ccr_negative_clear)
{
	processor_t processor;

	processor.sr = 0x0008;

	processor_ccr_negative_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_ccr_zero_clear)
{
	processor_t processor;

	processor.sr = 0x0004;

	processor_ccr_zero_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_ccr_overflow_clear)
{
	processor_t processor;

	processor.sr = 0x0002;

	processor_ccr_overflow_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_ccr_carry_clear)
{
	processor_t processor;

	processor.sr = 0x0001;

	processor_ccr_carry_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_sr_trace_enable_read)
{
	processor_t processor;

	processor.sr = 0x8000;

	uint8_t sr_trace_enable = processor_sr_trace_enable_read(&processor);

	ck_assert_int_eq(sr_trace_enable, 0x01);
}
END_TEST

START_TEST(test_processor_sr_user_state_read)
{
	processor_t processor;

	processor.sr = 0x2000;

	uint8_t sr_user_state = processor_sr_user_state_read(&processor);

	ck_assert_int_eq(sr_user_state, 0x01);
}
END_TEST

START_TEST(test_processor_sr_trace_enable_set)
{
	processor_t processor;

	processor_sr_trace_enable_set(&processor);

	ck_assert_int_eq(processor.sr, 0x8000);
}
END_TEST

START_TEST(test_processor_sr_user_state_set)
{
	processor_t processor;

	processor_sr_user_state_set(&processor);

	ck_assert_int_eq(processor.sr, 0x2000);
}
END_TEST

START_TEST(test_processor_sr_trace_enable_clear)
{
	processor_t processor;

	processor.sr = 0x8000;

	processor_sr_trace_enable_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_sr_user_state_clear)
{
	processor_t processor;

	processor.sr = 0x2000;

	processor_sr_user_state_clear(&processor);

	ck_assert_int_eq(processor.sr, 0x00);
}
END_TEST

START_TEST(test_processor_sr_interrupt_priority_state_read)
{
	processor_t processor;

	processor.sr = 0x0700;

	uint8_t sr_interrupt_priority_state = processor_sr_interrupt_priority_state_read(&processor);

	ck_assert_int_eq(sr_interrupt_priority_state, 0x07);
}
END_TEST

START_TEST(test_processor_sr_interrupt_priority_state_write)
{
	processor_t processor;

	processor_sr_interrupt_priority_state_write(&processor, 0x07);

	ck_assert_int_eq(processor.sr, 0x0700);
}
END_TEST

START_TEST(test_processor_register_index)
{
	processor_t processor;

	processor_sr_user_state_set(&processor);

	ck_assert_int_eq(processor_register_index(&processor, A7), ISP);

	processor_sr_user_state_clear(&processor);

	ck_assert_int_eq(processor_register_index(&processor, A7), USP);
	ck_assert_int_eq(processor_register_index(&processor, D0), D0);
}
END_TEST

START_TEST(test_processor_register_read_byte)
{
	processor_t processor;

	processor.registers[processor_register_index(&processor, D0)] = 0xFF;

	ck_assert_int_eq(processor_register_read_byte(&processor, D0), 0xFF);
}
END_TEST

START_TEST(test_processor_register_read_word)
{
	processor_t processor;

	processor.registers[processor_register_index(&processor, D0)] = 0xFFFF;

	ck_assert_int_eq(processor_register_read_word(&processor, D0), 0xFFFF);
}
END_TEST

START_TEST(test_processor_register_read_long_word)
{
	processor_t processor;

	processor.registers[processor_register_index(&processor, D0)] = 0xFFFFFFFF;

	ck_assert_int_eq(processor_register_read_long_word(&processor, D0), 0xFFFFFFFF);
}
END_TEST

START_TEST(test_processor_register_read_quad_word)
{
	processor_t processor;

	processor.registers[processor_register_index(&processor, D0)] = 0xFFFF0000;
	processor.registers[processor_register_index(&processor, D1)] = 0xFFFF0000;

	ck_assert_int_eq(processor_register_read_quad_word(&processor, D0, D1), 0xFFFF0000FFFF0000);
}
END_TEST

START_TEST(test_processor_register_write_byte)
{
	processor_t processor;

	processor_register_write_byte(&processor, D0, 0xFF);

	ck_assert_int_eq(processor.registers[processor_register_index(&processor, D0)], 0xFF);
}
END_TEST

START_TEST(test_processor_register_write_word)
{
	processor_t processor;

	processor_register_write_word(&processor, D0, 0xFFFF);

	ck_assert_int_eq(processor.registers[processor_register_index(&processor, D0)], 0xFFFF);
}
END_TEST

START_TEST(test_processor_register_write_long_word)
{
	processor_t processor;

	processor_register_write_long_word(&processor, D0, 0xFFFFFFFF);

	ck_assert_int_eq(processor.registers[processor_register_index(&processor, D0)], 0xFFFFFFFF);
}
END_TEST

START_TEST(test_processor_register_write_quad_word)
{
	processor_t processor;

	processor_register_write_quad_word(&processor, D0, D1, 0xFFFF0000FFFF0000);

	ck_assert_int_eq(processor.registers[processor_register_index(&processor, D0)], 0xFFFF0000);
	ck_assert_int_eq(processor.registers[processor_register_index(&processor, D1)], 0xFFFF0000);
}
END_TEST

START_TEST(test_processor_memory_read_byte)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor.memory[0x00] = 0xFF;

	ck_assert_int_eq(processor_memory_read_byte(&processor, 0x00), 0xFF);
}
END_TEST

START_TEST(test_processor_memory_read_word)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor.memory[0x00] = 0xFF;
	processor.memory[0x01] = 0x00;

	ck_assert_int_eq(processor_memory_read_word(&processor, 0x00), 0xFF00);
}
END_TEST

START_TEST(test_processor_memory_read_long_word)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor.memory[0x00] = 0xFF;
	processor.memory[0x01] = 0x00;
	processor.memory[0x02] = 0xFF;
	processor.memory[0x03] = 0x00;

	ck_assert_int_eq(processor_memory_read_long_word(&processor, 0x00), 0xFF00FF00);
}
END_TEST

START_TEST(test_processor_memory_write_byte)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor_memory_write_byte(&processor, 0x00, 0xFF);
	
	ck_assert_int_eq(processor_memory_read_byte(&processor, 0x00), 0xFF);
}
END_TEST

START_TEST(test_processor_memory_write_word)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor_memory_write_word(&processor, 0x00, 0xFF00);

	ck_assert_int_eq(processor_memory_read_word(&processor, 0x00), 0xFF00);
}
END_TEST

START_TEST(test_processor_memory_write_long_word)
{
	processor_t processor;

	processor.memory = malloc(32);

	processor_memory_write_long_word(&processor, 0x00, 0xFF00FF00);

	ck_assert_int_eq(processor_memory_read_long_word(&processor, 0x00), 0xFF00FF00);
}
END_TEST

Suite *processor_suite()
{
	Suite *suite = suite_create("processor");

	TCase *tc_core = tcase_create("core");

	tcase_add_test(tc_core, test_processor_ccr_extend_read);
	tcase_add_test(tc_core, test_processor_ccr_negative_read);
	tcase_add_test(tc_core, test_processor_ccr_zero_read);
	tcase_add_test(tc_core, test_processor_ccr_overflow_read);
	tcase_add_test(tc_core, test_processor_ccr_carry_read);
	tcase_add_test(tc_core, test_processor_ccr_extend_set);
	tcase_add_test(tc_core, test_processor_ccr_negative_set);
	tcase_add_test(tc_core, test_processor_ccr_zero_set);
	tcase_add_test(tc_core, test_processor_ccr_overflow_set);
	tcase_add_test(tc_core, test_processor_ccr_carry_set);		
	tcase_add_test(tc_core, test_processor_ccr_extend_clear);
	tcase_add_test(tc_core, test_processor_ccr_negative_clear);
	tcase_add_test(tc_core, test_processor_ccr_zero_clear);
	tcase_add_test(tc_core, test_processor_ccr_overflow_clear);
	tcase_add_test(tc_core, test_processor_ccr_carry_clear);		

	tcase_add_test(tc_core, test_processor_sr_trace_enable_read);
	tcase_add_test(tc_core, test_processor_sr_user_state_read);
	tcase_add_test(tc_core, test_processor_sr_trace_enable_set);
	tcase_add_test(tc_core, test_processor_sr_user_state_set);
	tcase_add_test(tc_core, test_processor_sr_trace_enable_clear);
	tcase_add_test(tc_core, test_processor_sr_user_state_clear);

	tcase_add_test(tc_core, test_processor_sr_interrupt_priority_state_read);
	tcase_add_test(tc_core, test_processor_sr_interrupt_priority_state_write);

	tcase_add_test(tc_core, test_processor_register_index);
	tcase_add_test(tc_core, test_processor_register_read_byte);	
	tcase_add_test(tc_core, test_processor_register_read_word);
	tcase_add_test(tc_core, test_processor_register_read_long_word);
	tcase_add_test(tc_core, test_processor_register_read_quad_word);
	tcase_add_test(tc_core, test_processor_register_write_byte);
	tcase_add_test(tc_core, test_processor_register_write_word);
	tcase_add_test(tc_core, test_processor_register_write_long_word);
	tcase_add_test(tc_core, test_processor_register_write_quad_word);

	tcase_add_test(tc_core, test_processor_memory_read_byte);	
	tcase_add_test(tc_core, test_processor_memory_read_word);
	tcase_add_test(tc_core, test_processor_memory_read_long_word);
	tcase_add_test(tc_core, test_processor_memory_write_byte);
	tcase_add_test(tc_core, test_processor_memory_write_word);
	tcase_add_test(tc_core, test_processor_memory_write_long_word);

	suite_add_tcase(suite, tc_core);

	return suite;
}

int main(void)
{
	Suite *suite = processor_suite();

	SRunner *srunner = srunner_create(suite);
	
	srunner_run_all(srunner, CK_VERBOSE);

	int failed = srunner_ntests_failed(srunner);

	srunner_free(srunner);

	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

	return 0;
}
