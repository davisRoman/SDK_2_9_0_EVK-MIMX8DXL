if(NOT DEVICE_MIMX8DL1_SYSTEM_MIMX8DL1_INCLUDED)
    
    set(DEVICE_MIMX8DL1_SYSTEM_MIMX8DL1_INCLUDED true CACHE BOOL "device_MIMX8DL1_system component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/system_MIMX8DL1_cm4.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(device_MIMX8DL1_CMSIS_MIMX8DL1)

endif()
