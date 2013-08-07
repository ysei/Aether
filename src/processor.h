#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>

typedef struct processor_s
{
	uint32_t registers[17];
	uint32_t pc;
	uint16_t sr;

	uint8_t *memory;
} processor_t;

inline uint8_t processor_ccr_extend_read(processor_t *processor);
inline uint8_t processor_ccr_negative_read(processor_t *processor);
inline uint8_t processor_ccr_zero_read(processor_t *processor);
inline uint8_t processor_ccr_overflow_read(processor_t *processor);
inline uint8_t processor_ccr_carry_read(processor_t *processor);

inline void processor_ccr_extend_set(processor_t *processor);
inline void processor_ccr_negative_set(processor_t *processor);
inline void processor_ccr_zero_set(processor_t *processor);
inline void processor_ccr_overflow_set(processor_t *processor);
inline void processor_ccr_carry_set(processor_t *processor);

inline void processor_ccr_extend_clear(processor_t *processor);
inline void processor_ccr_negative_clear(processor_t *processor);
inline void processor_ccr_zero_clear(processor_t *processor);
inline void processor_ccr_overflow_clear(processor_t *processor);
inline void processor_ccr_carry_clear(processor_t *processor);

inline uint8_t processor_sr_trace_enable_read(processor_t *processor);
inline uint8_t processor_sr_user_state_read(processor_t *processor);

inline void processor_sr_trace_enable_set(processor_t *processor);
inline void processor_sr_user_state_set(processor_t *processor);

inline void processor_sr_trace_enable_clear(processor_t *processor);
inline void processor_sr_user_state_clear(processor_t *processor);

inline uint8_t processor_sr_interrupt_priority_state_read(processor_t *processor);

inline void processor_sr_interrupt_priority_state_write(processor_t *processor, uint8_t value);

enum registers
{
	D0,
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	USP,
	ISP
};

#endif /* PROCESSOR_H */
