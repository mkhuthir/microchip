/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/
#ifndef _SST26VF064B_H
#define _SST26VF064B_H

#include <stdint.h>
#include <stdbool.h>

void SST26VF064B_CS_Low();
void SST26VF064B_CS_High();
void SST26VF064B_WP_Low();
void SST26VF064B_WP_High();
void SST26VF064B_Hold( bool state );
uint8_t SST26VF064B_Busy();
uint8_t SST26VF064B_SPI_ReadByte( uint8_t value );
void SST26VF064B_SPI_WriteByte( uint8_t value );
void SST26VF064B_SPI_ReadBuffer( uint8_t *buffer, uint16_t count );
void SST26VF064B_SPI_WriteBuffer( uint8_t *buffer, uint16_t count );
void SST26VF064B_Reset( void );
void SST26VF064B_WriteAddress( uint32_t address );
void SST26VF064B_SectorErase( uint32_t address );
void SST26VF064B_BlockErase( uint32_t address );
void SST26VF064B_ChipErase( void );
void SST26VF064B_Lock_BPR( void );
void SST26VF064B_GlobalBlockUnlock( void );
void SST26VF064B_WriteEnable( void );
void SST26VF064B_WriteDisable( void );
void SST26VF064B_WriteSuspend( void );
void SST26VF064B_WriteResume( void );
void SST26VF064B_PageProgram_Cmd( void );
void SST26VF064B_Read_Cmd( void );
void SST26VF064B_JEDECID_Cmd( void );

#endif // _SST26VF064B_H
