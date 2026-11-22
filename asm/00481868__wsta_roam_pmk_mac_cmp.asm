; func _wsta_roam_pmk_mac_cmp @ 0x00481868 size=0x30
  481868:	27bdffe0 	addiu	sp,sp,-32
  48186c:	00001021 	move	v0,zero
  481870:	10800006 	beqz	a0,0x48188c
  481874:	afbf001c 	sw	ra,28(sp)
  481878:	10a00004 	beqz	a1,0x48188c
  48187c:	24840010 	addiu	a0,a0,16
  481880:	0c101e4c 	jal	0x407930
  481884:	24060006 	li	a2,6
  481888:	2c420001 	sltiu	v0,v0,1
  48188c:	8fbf001c 	lw	ra,28(sp)
  481890:	03e00008 	jr	ra
  481894:	27bd0020 	addiu	sp,sp,32
