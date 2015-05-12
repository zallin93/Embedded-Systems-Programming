These files show the block information from a FAT16 filesystem on a 2GB SD
card with a single file on it named "HelloWorld.txt". The contents of the file
are the phrase, "hello world".

The hex files show a 512 byte block at the given 512 byte sector offset.

Block 0 is a MBR entry, but since the SD card is not bootable it is mostly
empty. However, it does contain partition entry which indicates that the first
partition begins at sector 0x81. This is from bytes 1c6 to 1c9: 0x81000000.
This is a little endian number, so it is just 0x81.

If we jump to block 129 (hex 0x81) we see the FAT system entry. In this entry
byte 13 indicates that there are 64 (hex 0x40) sectors per cluster, for a
total of 32768 bytes in a cluster. A cluster is the logical unit of the FAT
filesystem. Bytes 17-18 specify the number of root directory entries to be 512
sectors. All of the next sectors aren't interesting until we get to sector
609.  This may seem like a weird sector number, but if we remember that our
filesystem started after sector 129, this is exactly 480 sectors later. This
entry has the directory information which holds information about our single
file.

This entry is actually a complicated mess known as VFAT. This is basically a
newer kind of file entry with an older kind interleaved. Starting at offset
0x20 in this file the name of our file, in Unicode, begins. After characters
1-5 0x0f001b appears to fool older systems into ignoring most of the entry and
then characters 6-11 appear. The starting cluster is in the two bytes after
character 11 and before characters 12 and 13. This starting cluster refers to
sector number 641, which is 512 sectors from the beginning of the FAT
partition (remember these were reserved for the 512 root directory entries).

Finally, we jump to block 641 and we see our file contents.
