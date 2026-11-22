; func _wsta_roam_ap_disconnect_cb @ 0x00480658 size=0x30
  480658:	27bdffe0 	addiu	sp,sp,-32
  48065c:	10800006 	beqz	a0,0x480678
  480660:	afbf001c 	sw	ra,28(sp)
  480664:	8c82000c 	lw	v0,12(a0)
  480668:	10400004 	beqz	v0,0x48067c
  48066c:	8fbf001c 	lw	ra,28(sp)
  480670:	0c1209e0 	jal	0x482780
  480674:	94840010 	lhu	a0,16(a0)
  480678:	8fbf001c 	lw	ra,28(sp)
  48067c:	00001021 	move	v0,zero
  480680:	03e00008 	jr	ra
  480684:	27bd0020 	addiu	sp,sp,32
