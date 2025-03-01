from os.path import join
Import("env", "projenv")

platform = env.PioPlatform()

# Relocate firmware from 0x08000000 to 0x08002000
#env['CPPDEFINES'].remove(("VECT_TAB_ADDR", 134217728))
#env['CPPDEFINES'].append(("VECT_TAB_ADDR", "0x08010000"))
#env.Replace(LDSCRIPT_PATH="buildroot/share/PlatformIO/ldscripts/fysetc_aio_ii.ld")

# Custom HEX from ELF
env.AddPostAction(
	"$BUILD_DIR/${PROGNAME}.elf",
	env.VerboseAction(" ".join([
				"$OBJCOPY",
				"-O",
				"ihex",
				'"$BUILD_DIR/${PROGNAME}.elf"',
				'"$BUILD_DIR/${PROGNAME}.hex"'
			]), "Building $TARGET"))

# please keep $SOURCE variable, it will be replaced with a path to firmware

# Generic
#env.Replace(
#	UPLOADER="serial_upload.bat"
#	UPLOADCMD="$UPLOADER stm32loader.py $SOURCE"
#)

# In-line command with arguments
env.Replace(
	UPLOADER=platform.get_package_dir("tool-stm32duino") + '/stm32flash/stm32flash',
	UPLOADCMD='"${UPLOADER}" -v -i rts,-dtr,dtr,-rts -R -b 115200 -g 0x8000000 -w "${BUILD_DIR}/${PROGNAME}.hex" ${UPLOAD_PORT}'
)


# Python callback
#def on_upload(source, target, env):
#    print source, target
#    firmware_path = str(source[0])
#    # do something
#    env.Execute(".\serial_upload.bat")

#env.Replace(UPLOADCMD=on_upload)
