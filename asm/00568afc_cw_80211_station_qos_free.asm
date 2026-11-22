; func cw_80211_station_qos_free @ 0x00568afc size=0x3c
  568afc:	27bdffe0 	addiu	sp,sp,-32
  568b00:	afb00018 	sw	s0,24(sp)
  568b04:	00808021 	move	s0,a0
  568b08:	afbf001c 	sw	ra,28(sp)
  568b0c:	8c840010 	lw	a0,16(a0)
  568b10:	10800005 	beqz	a0,0x568b28
  568b14:	8fbf001c 	lw	ra,28(sp)
  568b18:	0c101f7c 	jal	0x407df0
  568b1c:	00000000 	nop
  568b20:	ae000010 	sw	zero,16(s0)
  568b24:	8fbf001c 	lw	ra,28(sp)
  568b28:	00001021 	move	v0,zero
  568b2c:	8fb00018 	lw	s0,24(sp)
  568b30:	03e00008 	jr	ra
  568b34:	27bd0020 	addiu	sp,sp,32
