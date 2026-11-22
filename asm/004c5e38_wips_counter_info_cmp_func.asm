; func wips_counter_info_cmp_func @ 0x004c5e38 size=0x30
  4c5e38:	27bdffe0 	addiu	sp,sp,-32
  4c5e3c:	00001021 	move	v0,zero
  4c5e40:	10800006 	beqz	a0,0x4c5e5c
  4c5e44:	afbf001c 	sw	ra,28(sp)
  4c5e48:	10a00005 	beqz	a1,0x4c5e60
  4c5e4c:	8fbf001c 	lw	ra,28(sp)
  4c5e50:	0c101e4c 	jal	0x407930
  4c5e54:	24060006 	li	a2,6
  4c5e58:	2c420001 	sltiu	v0,v0,1
  4c5e5c:	8fbf001c 	lw	ra,28(sp)
  4c5e60:	03e00008 	jr	ra
  4c5e64:	27bd0020 	addiu	sp,sp,32
