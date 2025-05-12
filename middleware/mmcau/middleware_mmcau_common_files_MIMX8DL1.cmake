if(NOT MIDDLEWARE_MMCAU_COMMON_FILES_MIMX8DL1_INCLUDED)
    
    set(MIDDLEWARE_MMCAU_COMMON_FILES_MIMX8DL1_INCLUDED true CACHE BOOL "middleware_mmcau_common_files component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_mmcau.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


endif()
