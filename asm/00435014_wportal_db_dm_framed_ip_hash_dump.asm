; func wportal_db_dm_framed_ip_hash_dump @ 0x00435014 size=0x3c
  435014:	3c040068 	lui	a0,0x68
  435018:	27bdffe0 	addiu	sp,sp,-32
  43501c:	afbf001c 	sw	ra,28(sp)
  435020:	0c101dd4 	jal	0x407750
  435024:	2484e8fc 	addiu	a0,a0,-5892
  435028:	3c020076 	lui	v0,0x76
  43502c:	3c050043 	lui	a1,0x43
  435030:	00003021 	move	a2,zero
  435034:	8c44a170 	lw	a0,-24208(v0)
  435038:	0c10215c 	jal	0x408570
  43503c:	24a5b070 	addiu	a1,a1,-20368
  435040:	2404000a 	li	a0,10
  435044:	8fbf001c 	lw	ra,28(sp)
  435048:	08101ce4 	j	0x407390
  43504c:	27bd0020 	addiu	sp,sp,32
