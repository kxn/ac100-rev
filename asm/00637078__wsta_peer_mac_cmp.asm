; func _wsta_peer_mac_cmp @ 0x00637078 size=0x30
  637078:	27bdffe0 	addiu	sp,sp,-32
  63707c:	00001021 	move	v0,zero
  637080:	10800006 	beqz	a0,0x63709c
  637084:	afbf001c 	sw	ra,28(sp)
  637088:	10a00005 	beqz	a1,0x6370a0
  63708c:	8fbf001c 	lw	ra,28(sp)
  637090:	0c101e4c 	jal	0x407930
  637094:	24060006 	li	a2,6
  637098:	2c420001 	sltiu	v0,v0,1
  63709c:	8fbf001c 	lw	ra,28(sp)
  6370a0:	03e00008 	jr	ra
  6370a4:	27bd0020 	addiu	sp,sp,32
