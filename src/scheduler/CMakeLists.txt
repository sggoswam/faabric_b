file(GLOB HEADERS "${FAABRIC_INCLUDE_DIR}/faabric/scheduler/*.h")

set(LIB_FILES
        ExecGraph.cpp
        FunctionCallClient.cpp
        FunctionCallServer.cpp
        Scheduler.cpp
        MpiContext.cpp
        MpiWorldRegistry.cpp
        MpiWorld.cpp
        ${HEADERS}
        )

faabric_lib(scheduler "${LIB_FILES}")

target_link_libraries(scheduler state faabricmpi redis)
