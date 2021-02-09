cmake_minimum_required(VERSION 3.19.4)
set(TYRANT_LIB_NAME TYRANT)

file(GLOB_RECURSE TyrantSrcList
	include/*.h
	src/*.cpp
)

add_library(${TYRANT_LIB_NAME} SHARED ${TyrantSrcList})
target_include_directories(${TYRANT_LIB_NAME} PUBLIC include)
target_compile_definitions(${TYRANT_LIB_NAME} PRIVATE TYRANT_DLL_EXP)
target_precompile_headers(${TYRANT_LIB_NAME} PUBLIC include/typch.h)

add_custom_command(TARGET ${TYRANT_LIB_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:${TYRANT_LIB_NAME}>
	$<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_subdirectory(vendor/sflm)
target_link_libraries(${TYRANT_LIB_NAME} PUBLIC
	sfml-audio
	sfml-graphics
	sfml-network
	sfml-system
	sfml-window
)
target_include_directories(${TYRANT_LIB_NAME} PUBLIC vendor/sflm/include)

add_custom_command(TARGET ${TYRANT_LIB_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	$<TARGET_FILE_DIR:sfml-system>
	$<TARGET_FILE_DIR:${PROJECT_NAME}>
)
