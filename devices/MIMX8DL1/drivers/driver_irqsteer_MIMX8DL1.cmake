if(NOT DRIVER_IRQSTEER_MIMX8DL1_INCLUDED)
    
    set(DRIVER_IRQSTEER_MIMX8DL1_INCLUDED true CACHE BOOL "driver_irqsteer component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_irqsteer.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

endif()
