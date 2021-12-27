; ========================================================================================
; | Modulname:   STM32G4xx_REG_ASM.inc                    | Prozessor:  STM32G474        |
; |--------------------------------------------------------------------------------------|
; | Ersteller:   Peter Raab                               | Datum:  06.11.2021           |
; |--------------------------------------------------------------------------------------|
; | Version:     V2.0            | Projekt:               | Assembler:  ARM-ASM          |
; |--------------------------------------------------------------------------------------|
; | Aufgabe:     Basisprojekt                                                            |
; |                                                                                      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Bemerkungen:                                                                         |
; |                                                                                      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Aenderungen:                                                                         |
; |     03.09.2021     Peter Raab          Initial version                               |
; |     06.11.2021     P.Raab / S.Michel   weitere Registerdefinitionen                  |
; |                                                                                      |
; ========================================================================================


;##########################################################################
;  Peripheral_memory_map

FLASH_BASE               equ  (0x08000000) ; FLASH (up to 512 kB) base address 
SRAM1_BASE               equ  (0x20000000) ;  SRAM1(up to 80 KB) base address */
SRAM2_BASE               equ  (0x20014000) ;  SRAM2(16 KB) base address */
CCMSRAM_BASE             equ  (0x10000000) ;  CCMSRAM(32 KB) base address */
PERIPH_BASE              equ  (0x40000000) ;  Peripheral base address */
FMC_BASE                 equ  (0x60000000) ;  FMC base address */
QSPI_BASE                equ  (0x90000000) ;  QUADSPI memories accessible over AHB base address */

FMC_R_BASE               equ  (0xA0000000) ;  FMC  control registers base address */
QSPI_R_BASE              equ  (0xA0001000) ;  QUADSPI control registers base address */
SRAM1_BB_BASE            equ  (0x22000000) ;  SRAM1(80 KB) base address in the bit-band region */
SRAM2_BB_BASE            equ  (0x22280000) ;  SRAM2(16 KB) base address in the bit-band region */
CCMSRAM_BB_BASE          equ  (0x22300000) ;  CCMSRAM(32 KB) base address in the bit-band region */
PERIPH_BB_BASE           equ  (0x42000000) ;  Peripheral base address in the bit-band region */
SCS_BASE                 equ  (0xE000E000) ; System Control Space Base Address  

; Legacy defines 
SRAM_BASE                equ  SRAM1_BASE
SRAM_BB_BASE             equ  SRAM1_BB_BASE

SRAM1_SIZE_MAX           equ  (0x00014000) ;  maximum SRAM1 size (up to 80 KBytes) */
SRAM2_SIZE               equ  (0x00004000) ;  SRAM2 size (16 KBytes) */
CCMSRAM_SIZE             equ  (0x00008000) ;  CCMSRAM size (32 KBytes) */

;  Peripheral memory map */
APB1PERIPH_BASE       equ   PERIPH_BASE
APB2PERIPH_BASE       equ  (PERIPH_BASE + 0x00010000)
AHB1PERIPH_BASE       equ  (PERIPH_BASE + 0x00020000)
AHB2PERIPH_BASE       equ  (PERIPH_BASE + 0x08000000)

FMC_BANK1             equ   FMC_BASE
FMC_BANK1_1           equ   FMC_BANK1
FMC_BANK1_2           equ  (FMC_BANK1 + 0x04000000)
FMC_BANK1_3           equ  (FMC_BANK1 + 0x08000000)
FMC_BANK1_4           equ  (FMC_BANK1 + 0x0C000000)
FMC_BANK3             equ  (FMC_BASE  + 0x20000000)

NVIC_BASE             equ  (SCS_BASE +  0x0100)      ;  NVIC Base Address 

;  APB1 peripherals 
TIM2_BASE             equ  (APB1PERIPH_BASE + 0x0000)
TIM3_BASE             equ  (APB1PERIPH_BASE + 0x0400)
TIM4_BASE             equ  (APB1PERIPH_BASE + 0x0800)
TIM5_BASE             equ  (APB1PERIPH_BASE + 0x0C00)
TIM6_BASE             equ  (APB1PERIPH_BASE + 0x1000)
TIM7_BASE             equ  (APB1PERIPH_BASE + 0x1400)
CRS_BASE              equ  (APB1PERIPH_BASE + 0x2000)
TAMP_BASE             equ  (APB1PERIPH_BASE + 0x2400)
RTC_BASE              equ  (APB1PERIPH_BASE + 0x2800)
WWDG_BASE             equ  (APB1PERIPH_BASE + 0x2C00)
IWDG_BASE             equ  (APB1PERIPH_BASE + 0x3000)
SPI2_BASE             equ  (APB1PERIPH_BASE + 0x3800)
SPI3_BASE             equ  (APB1PERIPH_BASE + 0x3C00)
USART2_BASE           equ  (APB1PERIPH_BASE + 0x4400)
USART3_BASE           equ  (APB1PERIPH_BASE + 0x4800)
UART4_BASE            equ  (APB1PERIPH_BASE + 0x4C00)
UART5_BASE            equ  (APB1PERIPH_BASE + 0x5000)
I2C1_BASE             equ  (APB1PERIPH_BASE + 0x5400)
I2C2_BASE             equ  (APB1PERIPH_BASE + 0x5800)
USB_BASE              equ  (APB1PERIPH_BASE + 0x5C00)  ;  USB_IP Peripheral Registers base address */
USB_PMAADDR           equ  (APB1PERIPH_BASE + 0x6000)  ;  USB_IP Packet Memory Area base address */
FDCAN1_BASE           equ  (APB1PERIPH_BASE + 0x6400)
FDCAN_CONFIG_BASE     equ  (APB1PERIPH_BASE + 0x6500)  ;  FDCAN configuration registers base address */
FDCAN2_BASE           equ  (APB1PERIPH_BASE + 0x6800)
FDCAN3_BASE           equ  (APB1PERIPH_BASE + 0x6C00)
PWR_BASE              equ  (APB1PERIPH_BASE + 0x7000)
I2C3_BASE             equ  (APB1PERIPH_BASE + 0x7800)
LPTIM1_BASE           equ  (APB1PERIPH_BASE + 0x7C00)
LPUART1_BASE          equ  (APB1PERIPH_BASE + 0x8000)
I2C4_BASE             equ  (APB1PERIPH_BASE + 0x8400)
UCPD1_BASE            equ  (APB1PERIPH_BASE + 0xA000)
SRAMCAN_BASE          equ  (APB1PERIPH_BASE + 0xA400)

;  APB2 peripherals */
SYSCFG_BASE           equ  (APB2PERIPH_BASE + 0x0000)
VREFBUF_BASE          equ  (APB2PERIPH_BASE + 0x0030)
COMP1_BASE            equ  (APB2PERIPH_BASE + 0x0200)
COMP2_BASE            equ  (APB2PERIPH_BASE + 0x0204)
COMP3_BASE            equ  (APB2PERIPH_BASE + 0x0208)
COMP4_BASE            equ  (APB2PERIPH_BASE + 0x020C)
COMP5_BASE            equ  (APB2PERIPH_BASE + 0x0210)
COMP6_BASE            equ  (APB2PERIPH_BASE + 0x0214)
COMP7_BASE            equ  (APB2PERIPH_BASE + 0x0218)
OPAMP_BASE            equ  (APB2PERIPH_BASE + 0x0300)
OPAMP1_BASE           equ  (APB2PERIPH_BASE + 0x0300)
OPAMP2_BASE           equ  (APB2PERIPH_BASE + 0x0304)
OPAMP3_BASE           equ  (APB2PERIPH_BASE + 0x0308)
OPAMP4_BASE           equ  (APB2PERIPH_BASE + 0x030C)
OPAMP5_BASE           equ  (APB2PERIPH_BASE + 0x0310)
OPAMP6_BASE           equ  (APB2PERIPH_BASE + 0x0314)

EXTI_BASE             equ  (APB2PERIPH_BASE + 0x0400)
TIM1_BASE             equ  (APB2PERIPH_BASE + 0x2C00)
SPI1_BASE             equ  (APB2PERIPH_BASE + 0x3000)
TIM8_BASE             equ  (APB2PERIPH_BASE + 0x3400)
USART1_BASE           equ  (APB2PERIPH_BASE + 0x3800)
SPI4_BASE             equ  (APB2PERIPH_BASE + 0x3C00)
TIM15_BASE            equ  (APB2PERIPH_BASE + 0x4000)
TIM16_BASE            equ  (APB2PERIPH_BASE + 0x4400)
TIM17_BASE            equ  (APB2PERIPH_BASE + 0x4800)
TIM20_BASE            equ  (APB2PERIPH_BASE + 0x5000)
SAI1_BASE             equ  (APB2PERIPH_BASE + 0x5400)
SAI1_Block_A_BASE     equ  (SAI1_BASE + 0x0004)
SAI1_Block_B_BASE     equ  (SAI1_BASE + 0x0024)
HRTIM1_BASE           equ  (APB2PERIPH_BASE + 0x6800)
HRTIM1_TIMA_BASE      equ  (HRTIM1_BASE + 0x0080)
HRTIM1_TIMB_BASE      equ  (HRTIM1_BASE + 0x0100)
HRTIM1_TIMC_BASE      equ  (HRTIM1_BASE + 0x0180)
HRTIM1_TIMD_BASE      equ  (HRTIM1_BASE + 0x0200)
HRTIM1_TIME_BASE      equ  (HRTIM1_BASE + 0x0280)
HRTIM1_TIMF_BASE      equ  (HRTIM1_BASE + 0x0300)
HRTIM1_COMMON_BASE    equ  (HRTIM1_BASE + 0x0380)

;  AHB1 peripherals */
DMA1_BASE             equ  (AHB1PERIPH_BASE)
DMA2_BASE             equ  (AHB1PERIPH_BASE + 0x0400)
DMAMUX1_BASE          equ  (AHB1PERIPH_BASE + 0x0800)
CORDIC_BASE           equ  (AHB1PERIPH_BASE + 0x0C00)
RCC_BASE              equ  (AHB1PERIPH_BASE + 0x1000)
FMAC_BASE             equ  (AHB1PERIPH_BASE + 0x1400)
FLASH_R_BASE          equ  (AHB1PERIPH_BASE + 0x2000)
CRC_BASE              equ  (AHB1PERIPH_BASE + 0x3000)

DMA1_Channel1_BASE    equ  (DMA1_BASE + 0x0008)
DMA1_Channel2_BASE    equ  (DMA1_BASE + 0x001C)
DMA1_Channel3_BASE    equ  (DMA1_BASE + 0x0030)
DMA1_Channel4_BASE    equ  (DMA1_BASE + 0x0044)
DMA1_Channel5_BASE    equ  (DMA1_BASE + 0x0058)
DMA1_Channel6_BASE    equ  (DMA1_BASE + 0x006C)
DMA1_Channel7_BASE    equ  (DMA1_BASE + 0x0080)
DMA1_Channel8_BASE    equ  (DMA1_BASE + 0x0094)

DMA2_Channel1_BASE    equ  (DMA2_BASE + 0x0008)
DMA2_Channel2_BASE    equ  (DMA2_BASE + 0x001C)
DMA2_Channel3_BASE    equ  (DMA2_BASE + 0x0030)
DMA2_Channel4_BASE    equ  (DMA2_BASE + 0x0044)
DMA2_Channel5_BASE    equ  (DMA2_BASE + 0x0058)
DMA2_Channel6_BASE    equ  (DMA2_BASE + 0x006C)
DMA2_Channel7_BASE    equ  (DMA2_BASE + 0x0080)
DMA2_Channel8_BASE    equ  (DMA2_BASE + 0x0094)

DMAMUX1_Channel0_BASE    equ  (DMAMUX1_BASE)
DMAMUX1_Channel1_BASE    equ  (DMAMUX1_BASE + 0x0004)
DMAMUX1_Channel2_BASE    equ  (DMAMUX1_BASE + 0x0008)
DMAMUX1_Channel3_BASE    equ  (DMAMUX1_BASE + 0x000C)
DMAMUX1_Channel4_BASE    equ  (DMAMUX1_BASE + 0x0010)
DMAMUX1_Channel5_BASE    equ  (DMAMUX1_BASE + 0x0014)
DMAMUX1_Channel6_BASE    equ  (DMAMUX1_BASE + 0x0018)
DMAMUX1_Channel7_BASE    equ  (DMAMUX1_BASE + 0x001C)
DMAMUX1_Channel8_BASE    equ  (DMAMUX1_BASE + 0x0020)
DMAMUX1_Channel9_BASE    equ  (DMAMUX1_BASE + 0x0024)
DMAMUX1_Channel10_BASE   equ  (DMAMUX1_BASE + 0x0028)
DMAMUX1_Channel11_BASE   equ  (DMAMUX1_BASE + 0x002C)
DMAMUX1_Channel12_BASE   equ  (DMAMUX1_BASE + 0x0030)
DMAMUX1_Channel13_BASE   equ  (DMAMUX1_BASE + 0x0034)
DMAMUX1_Channel14_BASE   equ  (DMAMUX1_BASE + 0x0038)
DMAMUX1_Channel15_BASE   equ  (DMAMUX1_BASE + 0x003C)
DMAMUX1_RequestGenerator0_BASE  equ  (DMAMUX1_BASE + 0x0100)
DMAMUX1_RequestGenerator1_BASE  equ  (DMAMUX1_BASE + 0x0104)
DMAMUX1_RequestGenerator2_BASE  equ  (DMAMUX1_BASE + 0x0108)
DMAMUX1_RequestGenerator3_BASE  equ  (DMAMUX1_BASE + 0x010C)

DMAMUX1_ChannelStatus_BASE      equ  (DMAMUX1_BASE + 0x0080)
DMAMUX1_RequestGenStatus_BASE   equ  (DMAMUX1_BASE + 0x0140)

;  AHB2 peripherals */
GPIOA_BASE            equ  (AHB2PERIPH_BASE + 0x0000)
GPIOB_BASE            equ  (AHB2PERIPH_BASE + 0x0400)
GPIOC_BASE            equ  (AHB2PERIPH_BASE + 0x0800)
GPIOD_BASE            equ  (AHB2PERIPH_BASE + 0x0C00)
GPIOE_BASE            equ  (AHB2PERIPH_BASE + 0x1000)
GPIOF_BASE            equ  (AHB2PERIPH_BASE + 0x1400)
GPIOG_BASE            equ  (AHB2PERIPH_BASE + 0x1800)

ADC1_BASE             equ  (AHB2PERIPH_BASE + 0x08000000)
ADC2_BASE             equ  (AHB2PERIPH_BASE + 0x08000100)
ADC12_COMMON_BASE     equ  (AHB2PERIPH_BASE + 0x08000300)
ADC3_BASE             equ  (AHB2PERIPH_BASE + 0x08000400)
ADC4_BASE             equ  (AHB2PERIPH_BASE + 0x08000500)
ADC5_BASE             equ  (AHB2PERIPH_BASE + 0x08000600)
ADC345_COMMON_BASE    equ  (AHB2PERIPH_BASE + 0x08000700)

DAC_BASE              equ  (AHB2PERIPH_BASE + 0x08000800)
DAC1_BASE             equ  (AHB2PERIPH_BASE + 0x08000800)
DAC2_BASE             equ  (AHB2PERIPH_BASE + 0x08000C00)
DAC3_BASE             equ  (AHB2PERIPH_BASE + 0x08001000)
DAC4_BASE             equ  (AHB2PERIPH_BASE + 0x08001400)

;  FMC Banks registers base  address */
FMC_Bank1_R_BASE      equ  (FMC_R_BASE + 0x0000)
FMC_Bank1E_R_BASE     equ  (FMC_R_BASE + 0x0104)
FMC_Bank3_R_BASE      equ  (FMC_R_BASE + 0x0080)
RNG_BASE              equ  (AHB2PERIPH_BASE + 0x08060800)
; Debug MCU registers base address */
DBGMCU_BASE              equ     (0xE0042000)

PACKAGE_BASE             equ     (0x1FFF7500)        ;  Package data register base address     */
UID_BASE                 equ     (0x1FFF7590)        ;  Unique device ID register base address */
FLASHSIZE_BASE           equ     (0x1FFF75E0)        ;  Flash size data register base address  */


;##########################################################
; @addtogroup Peripheral_declaration

;TIM2                ((TIM_TypeDef *) TIM2_BASE)
;TIM3                ((TIM_TypeDef *) TIM3_BASE)
;TIM4                ((TIM_TypeDef *) TIM4_BASE)
;TIM5                ((TIM_TypeDef *) TIM5_BASE)
;TIM6                ((TIM_TypeDef *) TIM6_BASE)
;TIM7                ((TIM_TypeDef *) TIM7_BASE)
;CRS                 ((CRS_TypeDef *) CRS_BASE)
;TAMP                ((TAMP_TypeDef *) TAMP_BASE)
;RTC                 ((RTC_TypeDef *) RTC_BASE)
;WWDG                ((WWDG_TypeDef *) WWDG_BASE)
;IWDG                ((IWDG_TypeDef *) IWDG_BASE)
;SPI2                ((SPI_TypeDef *) SPI2_BASE)
;SPI3                ((SPI_TypeDef *) SPI3_BASE)
;USART2              ((USART_TypeDef *) USART2_BASE)
;USART3              ((USART_TypeDef *) USART3_BASE)
;UART4               ((USART_TypeDef *) UART4_BASE)
;UART5               ((USART_TypeDef *) UART5_BASE)
;I2C1                ((I2C_TypeDef *) I2C1_BASE)
;I2C2                ((I2C_TypeDef *) I2C2_BASE)
;USB                 ((USB_TypeDef *) USB_BASE)
;FDCAN1              ((FDCAN_GlobalTypeDef *) FDCAN1_BASE)
;FDCAN_CONFIG        ((FDCAN_Config_TypeDef *) FDCAN_CONFIG_BASE)
;FDCAN2              ((FDCAN_GlobalTypeDef *) FDCAN2_BASE)
;FDCAN3              ((FDCAN_GlobalTypeDef *) FDCAN3_BASE)
;PWR                 ((PWR_TypeDef *) PWR_BASE)
;I2C3                ((I2C_TypeDef *) I2C3_BASE)
;LPTIM1              ((LPTIM_TypeDef *) LPTIM1_BASE)
;LPUART1             ((USART_TypeDef *) LPUART1_BASE)
;I2C4                ((I2C_TypeDef *) I2C4_BASE)
;UCPD1              ((UCPD_TypeDef *) UCPD1_BASE)

;SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
;VREFBUF             ((VREFBUF_TypeDef *) VREFBUF_BASE)
;COMP1               ((COMP_TypeDef *) COMP1_BASE)
;COMP2               ((COMP_TypeDef *) COMP2_BASE)
;COMP3               ((COMP_TypeDef *) COMP3_BASE)
;COMP4               ((COMP_TypeDef *) COMP4_BASE)
;COMP5               ((COMP_TypeDef *) COMP5_BASE)
;COMP6               ((COMP_TypeDef *) COMP6_BASE)
;COMP7               ((COMP_TypeDef *) COMP7_BASE)

;OPAMP               ((OPAMP_TypeDef *) OPAMP_BASE)
;OPAMP1              ((OPAMP_TypeDef *) OPAMP1_BASE)
;OPAMP2              ((OPAMP_TypeDef *) OPAMP2_BASE)
;OPAMP3              ((OPAMP_TypeDef *) OPAMP3_BASE)
;OPAMP4              ((OPAMP_TypeDef *) OPAMP4_BASE)
;OPAMP5              ((OPAMP_TypeDef *) OPAMP5_BASE)
;OPAMP6              ((OPAMP_TypeDef *) OPAMP6_BASE)

;EXTI                ((EXTI_TypeDef *) EXTI_BASE)
;TIM1                ((TIM_TypeDef *) TIM1_BASE)
;SPI1                ((SPI_TypeDef *) SPI1_BASE)
;TIM8                ((TIM_TypeDef *) TIM8_BASE)
;USART1              ((USART_TypeDef *) USART1_BASE)
;SPI4                ((SPI_TypeDef *) SPI4_BASE)
;TIM15               ((TIM_TypeDef *) TIM15_BASE)
;TIM16               ((TIM_TypeDef *) TIM16_BASE)
;TIM17               ((TIM_TypeDef *) TIM17_BASE)
;TIM20               ((TIM_TypeDef *) TIM20_BASE)
;SAI1                ((SAI_TypeDef *) SAI1_BASE)
;SAI1_Block_A        ((SAI_Block_TypeDef *)SAI1_Block_A_BASE)
;SAI1_Block_B        ((SAI_Block_TypeDef *)SAI1_Block_B_BASE)
;HRTIM1              ((HRTIM_TypeDef *) HRTIM1_BASE)
;HRTIM1_TIMA         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIMA_BASE)
;HRTIM1_TIMB         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIMB_BASE)
;HRTIM1_TIMC         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIMC_BASE)
;HRTIM1_TIMD         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIMD_BASE)
;HRTIM1_TIME         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIME_BASE)
;HRTIM1_TIMF         ((HRTIM_Timerx_TypeDef *) HRTIM1_TIMF_BASE)
;HRTIM1_COMMON       ((HRTIM_Common_TypeDef *) HRTIM1_COMMON_BASE)
;DMA1                ((DMA_TypeDef *) DMA1_BASE)
;DMA2                ((DMA_TypeDef *) DMA2_BASE)
;DMAMUX1             ((DMAMUX_Channel_TypeDef *) DMAMUX1_BASE)
;CORDIC              ((CORDIC_TypeDef *) CORDIC_BASE)




;##############################################
;RCC                 
RCC_CR            equ (RCC_BASE + 0x00)    ; RCC clock control register,                                              Address offset: 0x00 */
RCC_ICSCR         equ (RCC_BASE + 0x04)    ; RCC internal clock sources calibration register,                         Address offset: 0x04 */
RCC_CFGR          equ (RCC_BASE + 0x08)    ; RCC clock configuration register,                                        Address offset: 0x08 */
RCC_PLLCFGR       equ (RCC_BASE + 0x0C)    ; RCC system PLL configuration register,                                   Address offset: 0x0C */
RCC_CIER          equ (RCC_BASE + 0x18)    ; RCC clock interrupt enable register,                                     Address offset: 0x18 */
RCC_CIFR          equ (RCC_BASE + 0x1C)    ; RCC clock interrupt flag register,                                       Address offset: 0x1C */
RCC_CICR          equ (RCC_BASE + 0x20)    ; RCC clock interrupt clear register,                                      Address offset: 0x20 */
RCC_AHB1RSTR      equ (RCC_BASE + 0x28)    ; RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
RCC_AHB2RSTR      equ (RCC_BASE + 0x2C)    ; RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
RCC_AHB3RSTR      equ (RCC_BASE + 0x30)    ; RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
RCC_APB1RSTR1     equ (RCC_BASE + 0x38)    ; RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
RCC_APB1RSTR2     equ (RCC_BASE + 0x3C)    ; RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
RCC_APB2RSTR      equ (RCC_BASE + 0x40)    ; RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
RCC_AHB1ENR       equ (RCC_BASE + 0x48)    ; RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
RCC_AHB2ENR       equ (RCC_BASE + 0x4C)    ; RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
RCC_AHB3ENR       equ (RCC_BASE + 0x50)    ; RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
RCC_APB1ENR1      equ (RCC_BASE + 0x58)    ; RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
RCC_APB1ENR2      equ (RCC_BASE + 0x5C)    ; RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
RCC_APB2ENR       equ (RCC_BASE + 0x60)    ; RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
RCC_AHB1SMENR     equ (RCC_BASE + 0x68)    ; RCC AHB1 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x68 */
RCC_AHB2SMENR     equ (RCC_BASE + 0x6C)    ; RCC AHB2 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x6C */
RCC_AHB3SMENR     equ (RCC_BASE + 0x70)    ; RCC AHB3 peripheral clocks enable in sleep and stop modes register,      Address offset: 0x70 */
RCC_APB1SMENR1    equ (RCC_BASE + 0x78)    ; RCC APB1 peripheral clocks enable in sleep mode and stop modes register 1, Address offset: 0x78 */
RCC_APB1SMENR2    equ (RCC_BASE + 0x7C)    ; RCC APB1 peripheral clocks enable in sleep mode and stop modes register 2, Address offset: 0x7C */
RCC_APB2SMENR     equ (RCC_BASE + 0x80)    ; RCC APB2 peripheral clocks enable in sleep mode and stop modes register, Address offset: 0x80 */
RCC_CCIPR         equ (RCC_BASE + 0x88)    ; RCC peripherals independent clock configuration register,                Address offset: 0x88 */
RCC_BDCR          equ (RCC_BASE + 0x90)    ; RCC backup domain control register,                                      Address offset: 0x90 */
RCC_CSR           equ (RCC_BASE + 0x94)    ; RCC clock control & status register,                                     Address offset: 0x94 */
RCC_CRRCR         equ (RCC_BASE + 0x98)    ; RCC clock recovery RC register,                                          Address offset: 0x98 */
RCC_CCIPR2        equ (RCC_BASE + 0x9C)    ; RCC peripherals independent clock configuration register 2,              Address offset: 0x9C */




;FMAC                ((FMAC_TypeDef *) FMAC_BASE)
;FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
;CRC                 ((CRC_TypeDef *) CRC_BASE)

;##############################
; GPIOA
GPIOA_MODER       equ     (GPIOA_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOA_OTYPER      equ     (GPIOA_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOA_OSPEEDR     equ     (GPIOA_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOA_PUPDR       equ     (GPIOA_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOA_IDR         equ     (GPIOA_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOA_ODR         equ     (GPIOA_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOA_BSRR        equ     (GPIOA_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOA_LCKR        equ     (GPIOA_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOA_AFRL        equ     (GPIOA_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOA_AFRH        equ     (GPIOA_BASE + 0x24)   ; 
GPIOA_BRR         equ     (GPIOA_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */


;##############################
; GPIOB
GPIOB_MODER       equ     (GPIOB_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOB_OTYPER      equ     (GPIOB_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOB_OSPEEDR     equ     (GPIOB_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOB_PUPDR       equ     (GPIOB_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOB_IDR         equ     (GPIOB_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOB_ODR         equ     (GPIOB_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOB_BSRR        equ     (GPIOB_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOB_LCKR        equ     (GPIOB_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOB_AFRL        equ     (GPIOB_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOB_AFRH        equ     (GPIOB_BASE + 0x24)   ; 
GPIOB_BRR         equ     (GPIOB_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */



;##############################
; GPIOC
GPIOC_MODER       equ     (GPIOC_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOC_OTYPER      equ     (GPIOC_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOC_OSPEEDR     equ     (GPIOC_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOC_PUPDR       equ     (GPIOC_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOC_IDR         equ     (GPIOC_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOC_ODR         equ     (GPIOC_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOC_BSRR        equ     (GPIOC_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOC_LCKR        equ     (GPIOC_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOC_AFRL        equ     (GPIOC_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOC_AFRH        equ     (GPIOC_BASE + 0x24)   ; 
GPIOC_BRR         equ     (GPIOC_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */


;##############################
; GPIOD
GPIOD_MODER       equ     (GPIOD_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOD_OTYPER      equ     (GPIOD_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOD_OSPEEDR     equ     (GPIOD_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOD_PUPDR       equ     (GPIOD_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOD_IDR         equ     (GPIOD_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOD_ODR         equ     (GPIOD_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOD_BSRR        equ     (GPIOD_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOD_LCKR        equ     (GPIOD_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOD_AFR0        equ     (GPIOD_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOD_AFR1        equ     (GPIOD_BASE + 0x24)   ; 
GPIOD_BRR         equ     (GPIOD_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */



;##############################
; GPIOE
GPIOE_MODER       equ     (GPIOE_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOE_OTYPER      equ     (GPIOE_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOE_OSPEEDR     equ     (GPIOE_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOE_PUPDR       equ     (GPIOE_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOE_IDR         equ     (GPIOE_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOE_ODR         equ     (GPIOE_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOE_BSRR        equ     (GPIOE_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOE_LCKR        equ     (GPIOE_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOE_AFR0        equ     (GPIOE_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOE_AFR1        equ     (GPIOE_BASE + 0x24)   ; 
GPIOE_BRR         equ     (GPIOE_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */



;##############################
; GPIOF
GPIOF_MODER       equ     (GPIOF_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOF_OTYPER      equ     (GPIOF_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOF_OSPEEDR     equ     (GPIOF_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOF_PUPDR       equ     (GPIOF_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOF_IDR         equ     (GPIOF_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOF_ODR         equ     (GPIOF_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOF_BSRR        equ     (GPIOF_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOF_LCKR        equ     (GPIOF_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOF_AFR0        equ     (GPIOF_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOF_AFR1        equ     (GPIOF_BASE + 0x24)   ; 
GPIOF_BRR         equ     (GPIOF_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */


;##############################
; GPIOG
GPIOG_MODER       equ     (GPIOG_BASE + 0x00)   ;  GPIO port mode register,               Address offset: 0x00      */
GPIOG_OTYPER      equ     (GPIOG_BASE + 0x04)   ;  GPIO port output type register,        Address offset: 0x04      */
GPIOG_OSPEEDR     equ     (GPIOG_BASE + 0x08)   ;  GPIO port output speed register,       Address offset: 0x08      */
GPIOG_PUPDR       equ     (GPIOG_BASE + 0x0C)   ;  GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
GPIOG_IDR         equ     (GPIOG_BASE + 0x10)   ;  GPIO port input data register,         Address offset: 0x10      */
GPIOG_ODR         equ     (GPIOG_BASE + 0x14)   ;  GPIO port output data register,        Address offset: 0x14      */
GPIOG_BSRR        equ     (GPIOG_BASE + 0x18)   ;  GPIO port bit set/reset  register,     Address offset: 0x18      */
GPIOG_LCKR        equ     (GPIOG_BASE + 0x1C)   ;  GPIO port configuration lock register, Address offset: 0x1C      */
GPIOG_AFR0        equ     (GPIOG_BASE + 0x20)   ;  GPIO alternate function registers,     Address offset: 0x20-0x24 */
GPIOG_AFR1        equ     (GPIOG_BASE + 0x24)   ; 
GPIOG_BRR         equ     (GPIOG_BASE + 0x28)   ;  GPIO Bit Reset register,               Address offset: 0x28      */



;ADC1                ((ADC_TypeDef *) ADC1_BASE)
;ADC2                ((ADC_TypeDef *) ADC2_BASE)
;ADC12_COMMON        ((ADC_Common_TypeDef *) ADC12_COMMON_BASE)
;ADC3                ((ADC_TypeDef *) ADC3_BASE)
;ADC4                ((ADC_TypeDef *) ADC4_BASE)
;ADC5                ((ADC_TypeDef *) ADC5_BASE)
;ADC345_COMMON       ((ADC_Common_TypeDef *) ADC345_COMMON_BASE)
;DAC                 ((DAC_TypeDef *) DAC_BASE)
;DAC1                ((DAC_TypeDef *) DAC1_BASE)
;DAC2                ((DAC_TypeDef *) DAC2_BASE)
;DAC3                ((DAC_TypeDef *) DAC3_BASE)
;DAC4                ((DAC_TypeDef *) DAC4_BASE)
;RNG                 ((RNG_TypeDef *) RNG_BASE)

;DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
;DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
;DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
;DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
;DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
;DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
;DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
;DMA1_Channel8       ((DMA_Channel_TypeDef *) DMA1_Channel8_BASE)

;DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
;DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
;DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
;DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
;DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
;DMA2_Channel6       ((DMA_Channel_TypeDef *) DMA2_Channel6_BASE)
;DMA2_Channel7       ((DMA_Channel_TypeDef *) DMA2_Channel7_BASE)
;DMA2_Channel8       ((DMA_Channel_TypeDef *) DMA2_Channel8_BASE)

;DMAMUX1_Channel0    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel0_BASE)
;DMAMUX1_Channel1    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel1_BASE)
;DMAMUX1_Channel2    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel2_BASE)
;DMAMUX1_Channel3    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel3_BASE)
;DMAMUX1_Channel4    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel4_BASE)
;DMAMUX1_Channel5    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel5_BASE)
;DMAMUX1_Channel6    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel6_BASE)
;DMAMUX1_Channel7    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel7_BASE)
;DMAMUX1_Channel8    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel8_BASE)
;DMAMUX1_Channel9    ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel9_BASE)
;DMAMUX1_Channel10   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel10_BASE)
;DMAMUX1_Channel11   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel11_BASE)
;DMAMUX1_Channel12   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel12_BASE)
;DMAMUX1_Channel13   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel13_BASE)
;DMAMUX1_Channel14   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel14_BASE)
;DMAMUX1_Channel15   ((DMAMUX_Channel_TypeDef *) DMAMUX1_Channel15_BASE)

;DMAMUX1_RequestGenerator0  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator0_BASE)
;DMAMUX1_RequestGenerator1  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator1_BASE)
;DMAMUX1_RequestGenerator2  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator2_BASE)
;DMAMUX1_RequestGenerator3  ((DMAMUX_RequestGen_TypeDef *) DMAMUX1_RequestGenerator3_BASE)

;DMAMUX1_ChannelStatus      ((DMAMUX_ChannelStatus_TypeDef *) DMAMUX1_ChannelStatus_BASE)
;DMAMUX1_RequestGenStatus   ((DMAMUX_RequestGenStatus_TypeDef *) DMAMUX1_RequestGenStatus_BASE)

;FMC_Bank1_R         ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE)
;FMC_Bank1E_R        ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE)
;FMC_Bank3_R         ((FMC_Bank3_TypeDef *) FMC_Bank3_R_BASE)

;QUADSPI             ((QUADSPI_TypeDef *) QSPI_R_BASE)

;DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)


NVIC_ISER0      equ      (NVIC_BASE + 0x00)   ;Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
NVIC_ISER1      equ      (NVIC_BASE + 0x04)
NVIC_ISER2      equ      (NVIC_BASE + 0x08)
NVIC_ISER3      equ      (NVIC_BASE + 0x0C)
NVIC_ISER4      equ      (NVIC_BASE + 0x10)
NVIC_ISER5      equ      (NVIC_BASE + 0x14)
NVIC_ISER6      equ      (NVIC_BASE + 0x18)
NVIC_ISER7      equ      (NVIC_BASE + 0x1C)

	
NVIC_ICER0      equ      (NVIC_BASE + 0x80) ; Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
NVIC_ICER1      equ      (NVIC_BASE + 0x84)
NVIC_ICER2      equ      (NVIC_BASE + 0x88)
NVIC_ICER3      equ      (NVIC_BASE + 0x8C)
NVIC_ICER4      equ      (NVIC_BASE + 0x90)
NVIC_ICER5      equ      (NVIC_BASE + 0x94)
NVIC_ICER6      equ      (NVIC_BASE + 0x98)
NVIC_ICER7      equ      (NVIC_BASE + 0x9C)
	
NVIC_ISPR0      equ      (NVIC_BASE + 0x100)  ; Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
NVIC_ISPR1      equ      (NVIC_BASE + 0x104)
NVIC_ISPR2      equ      (NVIC_BASE + 0x108)
NVIC_ISPR3      equ      (NVIC_BASE + 0x10C)
NVIC_ISPR4      equ      (NVIC_BASE + 0x110)
NVIC_ISPR5      equ      (NVIC_BASE + 0x114)
NVIC_ISPR6      equ      (NVIC_BASE + 0x118)
NVIC_ISPR7      equ      (NVIC_BASE + 0x11C)

NVIC_ICPR0      equ      (NVIC_BASE + 0x180) ; Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
NVIC_ICPR1      equ      (NVIC_BASE + 0x184)
NVIC_ICPR2      equ      (NVIC_BASE + 0x188)
NVIC_ICPR3      equ      (NVIC_BASE + 0x18C)
NVIC_ICPR4      equ      (NVIC_BASE + 0x190)
NVIC_ICPR5      equ      (NVIC_BASE + 0x194)
NVIC_ICPR6      equ      (NVIC_BASE + 0x198)	
NVIC_ICPR7      equ      (NVIC_BASE + 0x19C)
	

NVIC_IABR0      equ      (NVIC_BASE + 0x200)  ; Offset: 0x200 (R/W)  Interrupt Active bit Register           */
NVIC_IABR1      equ      (NVIC_BASE + 0x204)
NVIC_IABR2      equ      (NVIC_BASE + 0x208)
NVIC_IABR3      equ      (NVIC_BASE + 0x20C)
NVIC_IABR4      equ      (NVIC_BASE + 0x210)
NVIC_IABR5      equ      (NVIC_BASE + 0x214)
NVIC_IABR6      equ      (NVIC_BASE + 0x218)
NVIC_IABR7      equ      (NVIC_BASE + 0x21C)
		
NVIC_IPR0       equ      (NVIC_BASE + 0x300)  ; Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */

	
;##############################
; TIMER6
TIM6_CR1		equ		(TIM6_BASE + 0x00)		;	TIM control register 1,                   Address offset: 0x00 */
TIM6_CR2		equ		(TIM6_BASE + 0x04)		;	TIM control register 2,                   Address offset: 0x04 */
TIM6_DIER		equ		(TIM6_BASE + 0x0C)		;	TIM DMA/interrupt enable register,        Address offset: 0x0C */
TIM6_SR		    equ		(TIM6_BASE + 0x10)		;	TIM status register,                      Address offset: 0x10 */
TIM6_EGR		equ		(TIM6_BASE + 0x14)		;	TIM event generation register,            Address offset: 0x14 */
TIM6_CNT		equ		(TIM6_BASE + 0x24)		;	TIM counter register,                     Address offset: 0x24 */
TIM6_PSC		equ		(TIM6_BASE + 0x28)		;	TIM prescaler,                            Address offset: 0x28 */
TIM6_ARR		equ		(TIM6_BASE + 0x2C)		;	TIM auto-reload register,                 Address offset: 0x2C */
	
;##############################
; TIMER7
TIM7_CR1		equ		(TIM7_BASE + 0x00)		;	TIM control register 1,                   Address offset: 0x00 */
TIM7_CR2		equ		(TIM7_BASE + 0x04)		;	TIM control register 2,                   Address offset: 0x04 */
TIM7_DIER		equ		(TIM7_BASE + 0x0C)		;	TIM DMA/interrupt enable register,        Address offset: 0x0C */
TIM7_SR		    equ		(TIM7_BASE + 0x10)		;	TIM status register,                      Address offset: 0x10 */
TIM7_EGR		equ		(TIM7_BASE + 0x14)		;	TIM event generation register,            Address offset: 0x14 */
TIM7_CNT		equ		(TIM7_BASE + 0x24)		;	TIM counter register,                     Address offset: 0x24 */
TIM7_PSC		equ		(TIM7_BASE + 0x28)		;	TIM prescaler,                            Address offset: 0x28 */
TIM7_ARR		equ		(TIM7_BASE + 0x2C)		;	TIM auto-reload register,                 Address offset: 0x2C */


;##############################
; UART1
USART1_CR1		equ (USART1_BASE + 0x00 )
USART1_CR2  	equ (USART1_BASE + 0x04 )
USART1_CR3  	equ (USART1_BASE + 0x08 )
USART1_BRR  	equ (USART1_BASE + 0x0C )
USART1_GTPR 	equ (USART1_BASE + 0x10 )
USART1_RTOR 	equ (USART1_BASE + 0x14 )
USART1_RQR  	equ (USART1_BASE + 0x18 )
USART1_ISR  	equ (USART1_BASE + 0x1C )
USART1_ICR  	equ (USART1_BASE + 0x20 )
USART1_RDR  	equ (USART1_BASE + 0x24 )
USART1_TDR 		equ (USART1_BASE + 0x28 )
USART1_PRESC	equ (USART1_BASE + 0x2C )

;##############################
; UART3
USART3_CR1		equ (USART3_BASE + 0x00 )
USART3_CR2  	equ (USART3_BASE + 0x04 )
USART3_CR3  	equ (USART3_BASE + 0x08 )
USART3_BRR  	equ (USART3_BASE + 0x0C )
USART3_GTPR 	equ (USART3_BASE + 0x10 )
USART3_RTOR 	equ (USART3_BASE + 0x14 )
USART3_RQR  	equ (USART3_BASE + 0x18 )
USART3_ISR  	equ (USART3_BASE + 0x1C )
USART3_ICR  	equ (USART3_BASE + 0x20 )
USART3_RDR  	equ (USART3_BASE + 0x24 )
USART3_TDR 		equ (USART3_BASE + 0x28 )
USART3_PRESC	equ (USART3_BASE + 0x2C )



;##############################
; System configuration controller
SYSCFG_MEMRMP     equ     (SYSCFG_BASE + 0x00)  ; SYSCFG memory remap register,                        Address offset: 0x00      */
SYSCFG_CFGR1      equ     (SYSCFG_BASE + 0x04)  ; SYSCFG configuration register 1,                     Address offset: 0x04      */
SYSCFG_EXTICR1    equ     (SYSCFG_BASE + 0x08)  
SYSCFG_EXTICR2    equ     (SYSCFG_BASE + 0x0C)
SYSCFG_EXTICR3    equ     (SYSCFG_BASE + 0x10)
SYSCFG_EXTICR4    equ     (SYSCFG_BASE + 0x14)
SYSCFG_SCSR       equ     (SYSCFG_BASE + 0x18)  ; SYSCFG CCMSRAM control and status register,          Address offset: 0x18      */
SYSCFG_CFGR2      equ     (SYSCFG_BASE + 0x1C)  ; SYSCFG configuration register 2,                     Address offset: 0x1C      */
SYSCFG_SWPR       equ     (SYSCFG_BASE + 0x20)  ; SYSCFG CCMSRAM write protection register,            Address offset: 0x20      */
SYSCFG_SKR        equ     (SYSCFG_BASE + 0x24)  ; SYSCFG CCMSRAM Key Register,                         Address offset: 0x24      */




;##############################
; External Interrupt/Event Controller
EXTI_IMR1         equ     (EXTI_BASE + 0x00)  ;  EXTI Interrupt mask register 1,             Address offset: 0x00 */
EXTI_EMR1         equ     (EXTI_BASE + 0x04)  ;  EXTI Event mask register 1,                 Address offset: 0x04 */
EXTI_RTSR1        equ     (EXTI_BASE + 0x08)  ;  EXTI Rising trigger selection register 1,   Address offset: 0x08 */
EXTI_FTSR1        equ     (EXTI_BASE + 0x0C)  ;  EXTI Falling trigger selection register 1,  Address offset: 0x0C */
EXTI_SWIER1       equ     (EXTI_BASE + 0x10)  ;  EXTI Software interrupt event register 1,   Address offset: 0x10 */
EXTI_PR1          equ     (EXTI_BASE + 0x14)  ;  EXTI Pending register 1,                    Address offset: 0x14 */
EXTI_IMR2         equ     (EXTI_BASE + 0x20)  ;  EXTI Interrupt mask register 2,             Address offset: 0x20 */
EXTI_EMR2         equ     (EXTI_BASE + 0x24)  ;  EXTI Event mask register 2,                 Address offset: 0x24 */
EXTI_RTSR2        equ     (EXTI_BASE + 0x28)  ;  EXTI Rising trigger selection register 2,   Address offset: 0x28 */
EXTI_FTSR2        equ     (EXTI_BASE + 0x2C)  ;  EXTI Falling trigger selection register 2,  Address offset: 0x2C */
EXTI_SWIER2       equ     (EXTI_BASE + 0x30)  ;  EXTI Software interrupt event register 2,   Address offset: 0x30 */
EXTI_PR2          equ     (EXTI_BASE + 0x34)  ;  EXTI Pending register 2,                    Address offset: 0x34 */





;##############################
; FMC_Bank1_R          ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE)
FMC_BCR1       equ     (FMC_Bank1_R_BASE + 0x00)   ;   NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
FMC_BCR2       equ     (FMC_Bank1_R_BASE + 0x08)
FMC_BCR3       equ     (FMC_Bank1_R_BASE + 0x10)
FMC_BCR4       equ     (FMC_Bank1_R_BASE + 0x18)	
FMC_BTR1       equ     (FMC_Bank1_R_BASE + 0x04)
FMC_BTR2       equ     (FMC_Bank1_R_BASE + 0x0C)
FMC_BTR3       equ     (FMC_Bank1_R_BASE + 0x14)
FMC_BTR4       equ     (FMC_Bank1_R_BASE + 0x1C)	
FMC_PCSCNTR    equ     (FMC_Bank1_R_BASE + 0x20)   ; PSRAM chip-select counter register, Address offset:    0x20 */
;FMC_Bank1E_R        ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE)
FMC_BWTR1      equ     (FMC_Bank1E_R_BASE + 0x104)  ; NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
FMC_BWTR2      equ     (FMC_Bank1E_R_BASE + 0x10C)
FMC_BWTR3      equ     (FMC_Bank1E_R_BASE + 0x114)
FMC_BWTR4      equ     (FMC_Bank1E_R_BASE + 0x11C)	


   END