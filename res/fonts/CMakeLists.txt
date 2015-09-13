set(FONT_NAME "ArtosSans" CACHE STRING "Font to use")
set(FONT_IN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/${FONT_NAME}.png")
set(FONT_OUT_FILE "${GENERATED_DIR}/${FONT_NAME}.h")
add_custom_command(
	DEPENDS ${FONT_IN_FILE}
	OUTPUT ${FONT_OUT_FILE}
	COMMENT "Compiling font ${FONT_NAME}"
	COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/convert.sh" ${FONT_IN_FILE} ${FONT_OUT_FILE}
)
add_custom_target(compile_font ALL DEPENDS ${FONT_OUT_FILE})
