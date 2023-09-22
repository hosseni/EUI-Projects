/*
 * bitwise_operation.h
 *
 *  Created on: Aug 13, 2023
 *      Author: mohas
 */

#ifndef BITWISE_OPERATION_H_
#define BITWISE_OPERATION_H_

#define getBit(regName, bitNum)   ((regName>>bitNum)&1)
#define clearBit(regName, bitNum) (regName &= (~(1<<bitNum)))
#define setBit(regName, bitNum) (regName |= (1<<bitNum))
#define Toggle_Bit(regName, bitNum) (regName ^= (1<<bitNum))


#endif /* BITWISE_OPERATION_H_ */
