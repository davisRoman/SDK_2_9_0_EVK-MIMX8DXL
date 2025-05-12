if(NOT DRIVER_RGPIO_MIMX8DL1_INCLUDED)
    
    set(DRIVER_RGPIO_MIMX8DL1_INCLUDED true CACHE BOOL "driver_rgpio component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_rgpio.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

endif()
