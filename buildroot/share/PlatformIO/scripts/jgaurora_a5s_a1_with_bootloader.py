Import("env")

my_flags = env.ParseFlags(env['BUILD_FLAGS'])
#print(my_flags['CPPDEFINES'])
for defines in my_flags['CPPDEFINES']:
	try: 
			#print defines[0]
			#print defines[1]
			if defines[0]=='PRINTERMODEL':
				printermodel = defines[1]
			if defines[0]=='LCD_LANGUAGE':
				lcd_language = defines[1]
			if defines[0]=='BUILDNUMBER':
				buildnumber = defines[1]

	except:
		stillok = 1 

# Relocate firmware from 0x08000000 to 0x0800A000
env['CPPDEFINES'].remove(("VECT_TAB_ADDR", "0x8000000"))
#alternatively, for STSTM <=5.1.0 use line below
#env['CPPDEFINES'].remove(("VECT_TAB_ADDR", 134217728))
env['CPPDEFINES'].append(("VECT_TAB_ADDR", "0x0800A000"))
env.Replace(LDSCRIPT_PATH="buildroot/share/PlatformIO/ldscripts/jgaurora_a5s_a1.ld")

#append ${PROGNAME}.bin firmware after bootloader and save it as 'jgaurora_firmware.bin'
def addboot(source,target,env):
	import os

	firmware = open(target[0].path, "rb")
	lengthfirmware = os.path.getsize(target[0].path)
	bootloader_dir = "buildroot/share/PlatformIO/scripts/jgaurora_bootloader.bin"
	bootloader = open(bootloader_dir, "rb")
	lengthbootloader = os.path.getsize(bootloader_dir)
	firmware_with_boothloader_dir = target[0].dir.path +'/firmware_with_bootloader.bin'
	if os.path.exists(firmware_with_boothloader_dir):
		os.remove(firmware_with_boothloader_dir)
	firmwareimage = open(firmware_with_boothloader_dir, "wb")
	position = 0
	while position < lengthbootloader:
		byte = bootloader.read(1)
		firmwareimage.write(byte)
		position += 1
	position = 0
	while position < lengthfirmware:
		byte = firmware.read(1)
		firmwareimage.write(byte)
		position += 1
	bootloader.close()
	firmware.close()
	firmwareimage.close()
	binfilename = printermodel+'_v'+buildnumber+'_'+lcd_language+'.bin' # file without bootloader
	buildfolder = target[0].dir.path+'/'+ binfilename
	if os.path.exists(buildfolder):
		os.remove(buildfolder)
	os.rename(target[0].path, buildfolder)

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", addboot);

