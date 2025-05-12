if(NOT DRIVER_MDIO-ENET-QOS_MIMX8DL1_INCLUDED)
    
    set(DRIVER_MDIO-ENET-QOS_MIMX8DL1_INCLUDED true CACHE BOOL "driver_mdio-enet-qos component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_enet_qos_mdio.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_mdio-common_MIMX8DL1)

    include(driver_enet_qos_MIMX8DL1)

endif()
