# analogButtons
Work towards making a library for Arduino projects using analog input pins.

## misc to get this repo to work with CLI etc
git config user.name "Dawson Tennant"
git config user.email abu.exegesis@gmail.com

change the remote repo from https to ssh
git remote set-url origin git@github.com:abuexegesis/analogButtons.git

also change .git/config section [core] to look like this:

[core]
	repositoryformatversion = 0
	filemode = true
	bare = false
	logallrefupdates = true
	sshCommand = ssh -i ~/dawson/.ssh/id_rsa

## Get wokwi to work with this project
add wokwi.toml file in the root of the project:
[wokwi]
version = 1
firmware = '.pio/build/nanoatmega328/firmware.hex'
elf ='.pio/build/nanoatmega328/firmware.elf'

copy the firmware.elf and firmware.hex from another project .. I'm not quite sure where I got them from to begin with in my binaryClock project

Then build a circuit in wokwi and copy it so that you can import the diagram.json file into the root ... of the project