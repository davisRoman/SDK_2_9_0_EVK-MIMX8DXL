# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 3.1.1)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})
SET(LIBRARY_OUTPUT_PATH ${ProjDirPath}/${CMAKE_BUILD_TYPE})


project(ftm_simple_pwm)

set(MCUX_SDK_PROJECT_NAME ftm_simple_pwm.elf)

include(${ProjDirPath}/flags.cmake)

include(${ProjDirPath}/config.cmake)

add_executable(${MCUX_SDK_PROJECT_NAME} 
"${ProjDirPath}/../ftm_simple_pwm.c"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../empty_rsc_table.c"
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
    ${ProjDirPath}/..
)

set(CMAKE_MODULE_PATH
    ${ProjDirPath}/../../../../../../devices/MIMX8DL1/drivers
    ${ProjDirPath}/../../../../../../devices/MIMX8DL1/utilities/debug_console_lite
    ${ProjDirPath}/../../../../../../devices/MIMX8DL1
    ${ProjDirPath}/../../../../../../components/uart
    ${ProjDirPath}/../../../../../../components/lists
    ${ProjDirPath}/../../../../../../devices/MIMX8DL1/scfw_api
    ${ProjDirPath}/../../../../../../CMSIS/Include
    ${ProjDirPath}/../../../../../../devices/MIMX8DL1/utilities
)

# include modules
include(driver_irqsteer_MIMX8DL1)

include(utility_debug_console_lite_MIMX8DL1)

include(utility_assert_lite_MIMX8DL1)

include(driver_ftm_MIMX8DL1)

include(driver_clock_MIMX8DL1)

include(driver_common_MIMX8DL1)

include(device_MIMX8DL1_CMSIS_MIMX8DL1)

include(component_lpuart_adapter_MIMX8DL1)

include(component_lists_MIMX8DL1)

include(driver_lpuart_MIMX8DL1)

include(device_MIMX8DL1_startup_MIMX8DL1)

include(driver_scfw_api_MIMX8DL1)

include(driver_igpio_MIMX8DL1)

include(CMSIS_Include_core_cm4_MIMX8DL1)

include(CMSIS_Include_common_MIMX8DL1)

include(CMSIS_Include_dsp_MIMX8DL1)

include(utilities_misc_utilities_MIMX8DL1)

include(device_MIMX8DL1_system_MIMX8DL1)


TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--start-group)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE m)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE c)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE gcc)

target_link_libraries(${MCUX_SDK_PROJECT_NAME} PRIVATE nosys)

TARGET_LINK_LIBRARIES(${MCUX_SDK_PROJECT_NAME} PRIVATE -Wl,--end-group)

ADD_CUSTOM_COMMAND(TARGET ${MCUX_SDK_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_OBJCOPY}
-Obinary ${EXECUTABLE_OUTPUT_PATH}/${MCUX_SDK_PROJECT_NAME} ${EXECUTABLE_OUTPUT_PATH}/ftm_simple_pwm.bin)

