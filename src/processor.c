#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "processor.h"
#include "instruction.h"

/* functions to read bits of the condition code register */

inline uint8_t processor_ccr_extend_read(processor_t *processor)
{
	return (processor->sr >> 0x04) & 0x01;
}

inline uint8_t processor_ccr_negative_read(processor_t *processor)
{
	return (processor->sr >> 0x03) & 0x01; 
}

inline uint8_t processor_ccr_zero_read(processor_t *processor)
{
	return (processor->sr >> 0x02) & 0x01;
}

inline uint8_t processor_ccr_overflow_read(processor_t *processor)
{
	return (processor->sr >> 0x01) & 0x01;
}

inline uint8_t processor_ccr_carry_read(processor_t *processor)
{
	return (processor->sr >> 0x00) & 0x01;
}

/* functions to set bits of the condition code register */

inline void processor_ccr_extend_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x04);
}

inline void processor_ccr_negative_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x03);
}

inline void processor_ccr_zero_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x02);
}

inline void processor_ccr_overflow_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x01);
}

inline void processor_ccr_carry_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x00);
}

/* functions to clear bits of the condition code register */

inline void processor_ccr_extend_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x04);
}

inline void processor_ccr_negative_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x03);
}

inline void processor_ccr_zero_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x02);
}

inline void processor_ccr_overflow_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x01);
}

inline void processor_ccr_carry_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x00);
}

/* functions to read bits of the status register */

inline uint8_t processor_sr_trace_enable_read(processor_t *processor)
{
	return (processor->sr >> 0x0F) & 0x01;
}

inline uint8_t processor_sr_user_state_read(processor_t *processor)
{
	return (processor->sr >> 0x0D) & 0x01;
}

/* functions to set bits of the status register */

inline void processor_sr_trace_enable_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x0F);
}

inline void processor_sr_user_state_set(processor_t *processor)
{
	processor->sr |= (0x01 << 0x0D);
}

/* functions to clear bits of the status register */

inline void processor_sr_trace_enable_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x0F);
}

inline void processor_sr_user_state_clear(processor_t *processor)
{
	processor->sr &= ~(0x01 << 0x0D);
}

/* functions to read from and write to the interrupt priority state */

inline uint8_t processor_sr_interrupt_priority_state_read(processor_t *processor)
{
	return (processor->sr >> 0x08) & 0x07;
}

inline void processor_sr_interrupt_priority_state_write(processor_t *processor, uint8_t value)
{
	processor->sr &= ~(0x7000);
	processor->sr |= (value & 0x07) << 0x08;
}

/* function to get real index */

inline int processor_register_index(processor_t *processor, int index)
{
	if(index == A7)
	{
		if(processor_sr_user_state_read(processor) == 0x01)
		{
			index = ISP;
		}
		else
		{
			index = USP;
		}
	}
	return index;
}

/* functions to read from and write to the registers */

inline uint8_t processor_register_read_byte(processor_t *processor, int index)
{
	return (uint8_t)(processor->registers[processor_register_index(processor, index)] & 0xFF);
}

inline uint16_t processor_register_read_word(processor_t *processor, int index)
{
	return (uint16_t)(processor->registers[processor_register_index(processor, index)] & 0xFFFF);
}

inline uint32_t processor_register_read_long_word(processor_t *processor, int index)
{
	return (uint32_t)(processor->registers[processor_register_index(processor, index)]);
}

inline uint64_t processor_register_read_quad_word(processor_t *processor, int index_x, int index_y)
{
	uint32_t reg_x = processor->registers[processor_register_index(processor, index_x)];
	uint32_t reg_y = processor->registers[processor_register_index(processor, index_y)];

	return ((uint64_t)reg_x << 0x20) | (uint64_t)reg_y;
}

inline void processor_register_write_byte(processor_t *processor, int index, uint8_t value)
{
	processor->registers[processor_register_index(processor, index)] = (uint32_t)value;
}

inline void processor_register_write_word(processor_t *processor, int index, uint16_t value)
{
	processor->registers[processor_register_index(processor, index)] = (uint32_t)value;
}

inline void processor_register_write_long_word(processor_t *processor, int index, uint32_t value)
{
	processor->registers[processor_register_index(processor, index)] = value;
}

inline void processor_register_write_quad_word(processor_t *processor, int index_x, int index_y, uint64_t value)
{
	processor_register_write_long_word(processor, index_x, (uint32_t)((value >> 0x20) & 0xFFFFFFFF));
	processor_register_write_long_word(processor, index_y, (uint32_t)((value >> 0x00) & 0xFFFFFFFF));
}

/* functions to read from and write to memory */

inline uint8_t processor_memory_read_byte(processor_t *processor, uint32_t address)
{
	return processor->memory[address];
}

inline uint16_t processor_memory_read_word(processor_t *processor, uint32_t address)
{
	return (processor->memory[address] << 0x08) | (processor->memory[address + 1] << 0x00);
}

inline uint32_t processor_memory_read_long_word(processor_t *processor, uint32_t address)
{
	return (processor->memory[address] << 0x18) | (processor->memory[address + 1] << 0x10) | (processor->memory[address + 2] << 0x08) | (processor->memory[address + 3] << 0x00); 
}

inline void processor_memory_write_byte(processor_t *processor, uint32_t address, uint8_t value)
{
	processor->memory[address] = value;
}

inline void processor_memory_write_word(processor_t *processor, uint32_t address, uint16_t value)
{
	processor->memory[address] = (value >> 0x08) & 0xFF;
	processor->memory[address + 1] = (value >> 0x00) & 0xFF;
}

inline void processor_memory_write_long_word(processor_t *processor, uint32_t address, uint32_t value)
{
	processor->memory[address] = (value >> 0x18) & 0xFF;
	processor->memory[address + 1] = (value >> 0x10) & 0xFF;
	processor->memory[address + 2] = (value >> 0x08) & 0xFF;
	processor->memory[address + 3] = (value >> 0x00) & 0xFF;
}
