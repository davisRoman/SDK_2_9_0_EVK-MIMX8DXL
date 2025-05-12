if(NOT DEVICE_MIMX8DL1_STARTUP_MIMX8DL1_INCLUDED)
    
    set(DEVICE_MIMX8DL1_STARTUP_MIMX8DL1_INCLUDED true CACHE BOOL "device_MIMX8DL1_startup component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_MIMX8DL1_cm4.S
    )


    include(device_MIMX8DL1_system_MIMX8DL1)

endif()
