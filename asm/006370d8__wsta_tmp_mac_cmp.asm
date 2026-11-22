; func _wsta_tmp_mac_cmp @ 0x006370d8 size=0x30
  6370d8:	27bdffe0 	addiu	sp,sp,-32
  6370dc:	00001021 	move	v0,zero
  6370e0:	10800006 	beqz	a0,0x6370fc
  6370e4:	afbf001c 	sw	ra,28(sp)
  6370e8:	10a00004 	beqz	a1,0x6370fc
  6370ec:	24840068 	addiu	a0,a0,104
  6370f0:	0c101e4c 	jal	0x407930
  6370f4:	24060006 	li	a2,6
  6370f8:	2c420001 	sltiu	v0,v0,1
  6370fc:	8fbf001c 	lw	ra,28(sp)
  637100:	03e00008 	jr	ra
  637104:	27bd0020 	addiu	sp,sp,32
