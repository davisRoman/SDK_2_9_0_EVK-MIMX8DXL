if(NOT DRIVER_LPSPI_EDMA_MIMX8DL1_INCLUDED)
    
    set(DRIVER_LPSPI_EDMA_MIMX8DL1_INCLUDED true CACHE BOOL "driver_lpspi_edma component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_lpspi_edma.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_dma3_MIMX8DL1)

    include(driver_lpspi_MIMX8DL1)

endif()
