if(NOT MIDDLEWARE_MMCAU_CM4_CM7_MIMX8DL1_INCLUDED)
    
    set(MIDDLEWARE_MMCAU_CM4_CM7_MIMX8DL1_INCLUDED true CACHE BOOL "middleware_mmcau_cm4_cm7 component is included.")


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )

    include(middleware_mmcau_common_files_MIMX8DL1)

    include(driver_clock_MIMX8DL1)

endif()
