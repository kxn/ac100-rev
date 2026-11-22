; func uac_wservice_sync_all_wlan_to_re @ 0x005daf4c size=0x2c
  5daf4c:	3c05005e 	lui	a1,0x5e
  5daf50:	27bdffe0 	addiu	sp,sp,-32
  5daf54:	3c04000e 	lui	a0,0xe
  5daf58:	24a582a8 	addiu	a1,a1,-32088
  5daf5c:	afbf001c 	sw	ra,28(sp)
  5daf60:	0c14e0b9 	jal	0x5382e4
  5daf64:	00003021 	move	a2,zero
  5daf68:	00001021 	move	v0,zero
  5daf6c:	8fbf001c 	lw	ra,28(sp)
  5daf70:	03e00008 	jr	ra
  5daf74:	27bd0020 	addiu	sp,sp,32
