; func _wsta_mac_cmp @ 0x00637108 size=0x30
  637108:	27bdffe0 	addiu	sp,sp,-32
  63710c:	00001021 	move	v0,zero
  637110:	10800006 	beqz	a0,0x63712c
  637114:	afbf001c 	sw	ra,28(sp)
  637118:	10a00004 	beqz	a1,0x63712c
  63711c:	24840068 	addiu	a0,a0,104
  637120:	0c101e4c 	jal	0x407930
  637124:	24060006 	li	a2,6
  637128:	2c420001 	sltiu	v0,v0,1
  63712c:	8fbf001c 	lw	ra,28(sp)
  637130:	03e00008 	jr	ra
  637134:	27bd0020 	addiu	sp,sp,32
