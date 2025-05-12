if(NOT MIDDLEWARE_MULTICORE_RPMSG_LITE_IMX8DXL_M4_FREERTOS_MIMX8DL1_INCLUDED)
    
    set(MIDDLEWARE_MULTICORE_RPMSG_LITE_IMX8DXL_M4_FREERTOS_MIMX8DL1_INCLUDED true CACHE BOOL "middleware_multicore_rpmsg_lite_imx8dxl_m4_freertos component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/rpmsg_lite/lib/rpmsg_lite/porting/platform/imx8dxl_m4/rpmsg_platform.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/rpmsg_lite/lib/include/platform/imx8dxl_m4
    )


    include(middleware_multicore_rpmsg_lite_MIMX8DL1)

endif()
