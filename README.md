**How to build:**
**First ask yourself:** Do I really want to?

If the answer is no, I would not recommend it. 

If the answer is yes, then you'll need the Arm GNU embedded toolchain and openocd. I have the paths setup for openocd installed via brew on my Mac, so you'll have to change those 
if you don't use brew. 

The linker scripts in this project are not my own, and come from NXPs IDE, you are always free to write your own. 
If you're looking to build for this specific board, and you're on Linux or Windows, check out Erich Stygers blog for help: 
https://mcuoneclipse.com/2013/07/20/dyi-free-toolchain-for-kinetis-part-1-gnu-arm-build-tools/
