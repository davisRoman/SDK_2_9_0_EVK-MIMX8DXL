if(NOT MIDDLEWARE_LWIP_APPS_HTTPD_SUPPORT_MIMX8DL1_INCLUDED)
    
    set(MIDDLEWARE_LWIP_APPS_HTTPD_SUPPORT_MIMX8DL1_INCLUDED true CACHE BOOL "middleware_lwip_apps_httpd_support component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/apps/http/fs.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/apps/http
        ${CMAKE_CURRENT_LIST_DIR}/src/include/lwip/apps
    )


    include(middleware_lwip_MIMX8DL1)

endif()
