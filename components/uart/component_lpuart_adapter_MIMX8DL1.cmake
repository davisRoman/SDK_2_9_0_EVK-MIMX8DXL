if(NOT COMPONENT_LPUART_ADAPTER_MIMX8DL1_INCLUDED)
    
    set(COMPONENT_LPUART_ADAPTER_MIMX8DL1_INCLUDED true CACHE BOOL "component_lpuart_adapter component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_adapter_lpuart.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

    include(driver_lpuart_MIMX8DL1)

endif()
