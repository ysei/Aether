#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>

inline uint8_t instruction_operation_extract_operation_code(uint16_t instruction);
inline uint8_t instruction_operation_extract_mode(uint16_t instruction);
inline uint8_t instruction_operation_extract_register_low(uint16_t instruction);
inline uint8_t instruction_operation_extract_register_high(uint16_t instruction);
inline uint8_t instruction_extension_extract_da(uint16_t instruction);
inline uint8_t instruction_extension_extract_register(uint16_t instruction);
inline uint8_t instruction_extension_extract_wl(uint16_t instruction);
inline uint8_t instruction_extension_extract_scale(uint16_t instruction);
inline uint8_t instruction_extension_extract_type(uint16_t instruction);
inline uint8_t instruction_extension_extract_displacement(uint16_t instruction);
inline uint8_t instruction_extension_extract_bs(uint16_t instruction);
inline uint8_t instruction_extension_extract_is(uint16_t instruction);
inline uint8_t instruction_extension_extract_bd_size(uint16_t instruction);
inline uint8_t instruction_extension_extract_iis(uint16_t instruction);

#endif /* INSTRUCTION_H */
