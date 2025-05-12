if(NOT DEVICE_MIMX8DL1_CMSIS_MIMX8DL1_INCLUDED)
    
    set(DEVICE_MIMX8DL1_CMSIS_MIMX8DL1_INCLUDED true CACHE BOOL "device_MIMX8DL1_CMSIS component is included.")


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )

    include(CMSIS_Include_core_cm4_MIMX8DL1)

endif()
