if(NOT DRIVER_SAI_MIMX8DL1_INCLUDED)
    
    set(DRIVER_SAI_MIMX8DL1_INCLUDED true CACHE BOOL "driver_sai component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_sai.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MIMX8DL1)

endif()
