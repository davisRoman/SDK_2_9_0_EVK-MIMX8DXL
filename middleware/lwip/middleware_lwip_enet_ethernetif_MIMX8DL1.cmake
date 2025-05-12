if(NOT MIDDLEWARE_LWIP_ENET_ETHERNETIF_MIMX8DL1_INCLUDED)
    
    set(MIDDLEWARE_LWIP_ENET_ETHERNETIF_MIMX8DL1_INCLUDED true CACHE BOOL "middleware_lwip_enet_ethernetif component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/port/enet_ethernetif.c
    )

    if(CONFIG_USE_driver_enet_MIMX8DL1)
    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/port/enet_ethernetif_kinetis.c
    )
    elseif(CONFIG_USE_driver_enet_qos_MIMX8DL1)
    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/port/enet_ethernetif_qos.c
    )
    else()
        message(WARNING "please config platform.drivers.enet_MIMX8DL1 or driver.lpc_enet_MIMX8DL1 or platform.drivers.enet_qos_MIMX8DL1 first.")
    endif()


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/port
    )


    #OR Logic component
    if(CONFIG_USE_driver_enet_MIMX8DL1)
         include(driver_enet_MIMX8DL1)
    endif()
    if(CONFIG_USE_driver_enet_qos_MIMX8DL1)
         include(driver_enet_qos_MIMX8DL1)
    endif()
    if(NOT (CONFIG_USE_driver_enet_MIMX8DL1 OR CONFIG_USE_driver_enet_qos_MIMX8DL1))
        message(WARNING "Since driver_enet_MIMX8DL1/driver_enet_qos_MIMX8DL1 is not included at first or config in config.cmake file, use driver_enet_MIMX8DL1 by default.")
        include(driver_enet_MIMX8DL1)
    endif()

    include(middleware_lwip_MIMX8DL1)

    include(driver_phy-common_MIMX8DL1)

endif()
