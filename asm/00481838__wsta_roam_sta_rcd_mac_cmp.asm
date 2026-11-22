; func _wsta_roam_sta_rcd_mac_cmp @ 0x00481838 size=0x30
  481838:	27bdffe0 	addiu	sp,sp,-32
  48183c:	00001021 	move	v0,zero
  481840:	10800006 	beqz	a0,0x48185c
  481844:	afbf001c 	sw	ra,28(sp)
  481848:	10a00005 	beqz	a1,0x481860
  48184c:	8fbf001c 	lw	ra,28(sp)
  481850:	0c101e4c 	jal	0x407930
  481854:	24060006 	li	a2,6
  481858:	2c420001 	sltiu	v0,v0,1
  48185c:	8fbf001c 	lw	ra,28(sp)
  481860:	03e00008 	jr	ra
  481864:	27bd0020 	addiu	sp,sp,32
