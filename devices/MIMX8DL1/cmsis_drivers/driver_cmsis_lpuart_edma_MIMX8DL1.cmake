if(NOT DRIVER_CMSIS_LPUART_EDMA_MIMX8DL1_INCLUDED)
    
    set(DRIVER_CMSIS_LPUART_EDMA_MIMX8DL1_INCLUDED true CACHE BOOL "driver_cmsis_lpuart_edma component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_lpuart_cmsis.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_lpuart_edma_MIMX8DL1)

    include(CMSIS_Driver_Include_USART_MIMX8DL1)

endif()
