if(NOT DRIVER_IGPIO_MIMX8DL1_INCLUDED)
    
    set(DRIVER_IGPIO_MIMX8DL1_INCLUDED true CACHE BOOL "driver_igpio component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_gpio.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

endif()
