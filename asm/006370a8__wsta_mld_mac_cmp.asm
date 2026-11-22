; func _wsta_mld_mac_cmp @ 0x006370a8 size=0x30
  6370a8:	27bdffe0 	addiu	sp,sp,-32
  6370ac:	00001021 	move	v0,zero
  6370b0:	10800006 	beqz	a0,0x6370cc
  6370b4:	afbf001c 	sw	ra,28(sp)
  6370b8:	10a00004 	beqz	a1,0x6370cc
  6370bc:	2484000c 	addiu	a0,a0,12
  6370c0:	0c101e4c 	jal	0x407930
  6370c4:	24060006 	li	a2,6
  6370c8:	2c420001 	sltiu	v0,v0,1
  6370cc:	8fbf001c 	lw	ra,28(sp)
  6370d0:	03e00008 	jr	ra
  6370d4:	27bd0020 	addiu	sp,sp,32
