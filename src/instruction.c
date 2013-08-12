#include <stdint.h>

#include "processor.h"

/* functions to extract fields from single effective operation word format instructions */

inline uint8_t instruction_operation_extract_operation_code(uint16_t instruction)
{
	return (instruction >> 0x0C) & 0x0F;
}

inline uint8_t instruction_operation_extract_condition(uint16_t instruction)
{
	return (instruction >> 0x08) & 0x0F;
}

inline uint8_t instruction_operation_extract_operation_mode(uint16_t instruction)
{
	return (instruction >> 0x06) & 0x07;
}

inline uint8_t instruction_operation_extract_mode(uint16_t instruction)
{
	return (instruction >> 0x03) & 0x07;
}

inline uint8_t instruction_operation_extract_register_low(uint16_t instruction)
{
	return (instruction >> 0x00) & 0x07;
}

inline uint8_t instruction_operation_extract_register_high(uint16_t instruction)
{
	return (instruction >> 0x09) & 0x07;
}

/* functions to extract fields from brief- and full extension word format instructions */

inline uint8_t instruction_extension_extract_da(uint16_t instruction)
{
	return (instruction >> 0x0F) & 0x01;
}

inline uint8_t instruction_extension_extract_register(uint16_t instruction)
{
	return (instruction >> 0x0C) & 0x07;
}

inline uint8_t instruction_extension_extract_wl(uint16_t instruction)
{
	return (instruction >> 0x0B) & 0x01;
}

inline uint8_t instruction_extension_extract_scale(uint16_t instruction)
{
	return (instruction >> 0x09) & 0x03;
}

inline uint8_t instruction_extension_extract_type(uint16_t instruction)
{
	return (instruction >> 0x08) & 0x01;
}

inline uint8_t instruction_extension_extract_displacement(uint16_t instruction)
{
	return (instruction >> 0x00) & 0xFF;
}

inline uint8_t instruction_extension_extract_bs(uint16_t instruction)
{
	return (instruction >> 0x07) & 0x01;
}

inline uint8_t instruction_extension_extract_is(uint16_t instruction)
{
	return (instruction >> 0x06) & 0x01;
}

inline uint8_t instruction_extension_extract_bd_size(uint16_t instruction)
{
	return (instruction >> 0x04) & 0x03;
}

inline uint8_t instruction_extension_extract_iis(uint16_t instruction)
{
	return (instruction >> 0x00) & 0x07;
}
