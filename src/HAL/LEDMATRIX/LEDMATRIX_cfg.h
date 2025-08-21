#ifndef HAL_LEDMATRIX_LEDMATRIX_CFG_H_
#define HAL_LEDMATRIX_LEDMATRIX_CFG_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "LEDMATRIX_int.h"   // so compiler knows LEDMATRIX_Config_t

#define NO_ROWS     8
#define NO_COLS     8

#define SCAN_TIME   2.5

/* External configuration struct (defined in .c) */
extern const LEDMATRIX_Config_t LEDMATRIX_cfg;

#endif /* HAL_LEDMATRIX_LEDMATRIX_CFG_H_ */
