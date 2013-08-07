#include <stdint.h>

#include "processor.h"

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

/* functions to read to and write from the interrupt priority state */

inline uint8_t processor_sr_interrupt_priority_state_read(processor_t *processor)
{
	return (processor->sr >> 0x08) & 0x07;
}

inline void processor_sr_interrupt_priority_state_write(processor_t *processor, uint8_t value)
{
	processor->sr &= ~(0x7000);
	processor->sr |= (value & 0x07) << 0x08;
}
