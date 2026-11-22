; func _stats_bssid_cmp @ 0x00668bc8 size=0x30
  668bc8:	27bdffe0 	addiu	sp,sp,-32
  668bcc:	00001021 	move	v0,zero
  668bd0:	10800006 	beqz	a0,0x668bec
  668bd4:	afbf001c 	sw	ra,28(sp)
  668bd8:	10a00005 	beqz	a1,0x668bf0
  668bdc:	8fbf001c 	lw	ra,28(sp)
  668be0:	0c101e4c 	jal	0x407930
  668be4:	24060006 	li	a2,6
  668be8:	2c420001 	sltiu	v0,v0,1
  668bec:	8fbf001c 	lw	ra,28(sp)
  668bf0:	03e00008 	jr	ra
  668bf4:	27bd0020 	addiu	sp,sp,32
