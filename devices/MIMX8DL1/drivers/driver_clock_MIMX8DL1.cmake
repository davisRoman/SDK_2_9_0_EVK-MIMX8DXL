if(NOT DRIVER_CLOCK_MIMX8DL1_INCLUDED)
    
    set(DRIVER_CLOCK_MIMX8DL1_INCLUDED true CACHE BOOL "driver_clock component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_clock.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

    include(driver_scfw_api_MIMX8DL1)

endif()
