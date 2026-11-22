; func _stats_sta_mac_cmp @ 0x00668bf8 size=0x30
  668bf8:	27bdffe0 	addiu	sp,sp,-32
  668bfc:	00001021 	move	v0,zero
  668c00:	10800006 	beqz	a0,0x668c1c
  668c04:	afbf001c 	sw	ra,28(sp)
  668c08:	10a00004 	beqz	a1,0x668c1c
  668c0c:	24840002 	addiu	a0,a0,2
  668c10:	0c101e4c 	jal	0x407930
  668c14:	24060006 	li	a2,6
  668c18:	2c420001 	sltiu	v0,v0,1
  668c1c:	8fbf001c 	lw	ra,28(sp)
  668c20:	03e00008 	jr	ra
  668c24:	27bd0020 	addiu	sp,sp,32
