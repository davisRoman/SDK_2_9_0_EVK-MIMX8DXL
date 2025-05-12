if(NOT DRIVER_CMSIS_LPSPI_MIMX8DL1_INCLUDED)
    
    set(DRIVER_CMSIS_LPSPI_MIMX8DL1_INCLUDED true CACHE BOOL "driver_cmsis_lpspi component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_lpspi_cmsis.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_lpspi_MIMX8DL1)

    include(CMSIS_Driver_Include_SPI_MIMX8DL1)

endif()
