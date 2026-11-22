; func cw_80211_delete_wlan_free @ 0x00564e58 size=0x3c
  564e58:	27bdffe0 	addiu	sp,sp,-32
  564e5c:	afb00018 	sw	s0,24(sp)
  564e60:	00808021 	move	s0,a0
  564e64:	afbf001c 	sw	ra,28(sp)
  564e68:	8c840010 	lw	a0,16(a0)
  564e6c:	10800005 	beqz	a0,0x564e84
  564e70:	8fbf001c 	lw	ra,28(sp)
  564e74:	0c101f7c 	jal	0x407df0
  564e78:	00000000 	nop
  564e7c:	ae000010 	sw	zero,16(s0)
  564e80:	8fbf001c 	lw	ra,28(sp)
  564e84:	00001021 	move	v0,zero
  564e88:	8fb00018 	lw	s0,24(sp)
  564e8c:	03e00008 	jr	ra
  564e90:	27bd0020 	addiu	sp,sp,32
