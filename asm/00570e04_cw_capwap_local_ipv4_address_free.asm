; func cw_capwap_local_ipv4_address_free @ 0x00570e04 size=0x3c
  570e04:	27bdffe0 	addiu	sp,sp,-32
  570e08:	afb00018 	sw	s0,24(sp)
  570e0c:	00808021 	move	s0,a0
  570e10:	afbf001c 	sw	ra,28(sp)
  570e14:	8c840010 	lw	a0,16(a0)
  570e18:	10800005 	beqz	a0,0x570e30
  570e1c:	8fbf001c 	lw	ra,28(sp)
  570e20:	0c101f7c 	jal	0x407df0
  570e24:	00000000 	nop
  570e28:	ae000010 	sw	zero,16(s0)
  570e2c:	8fbf001c 	lw	ra,28(sp)
  570e30:	00001021 	move	v0,zero
  570e34:	8fb00018 	lw	s0,24(sp)
  570e38:	03e00008 	jr	ra
  570e3c:	27bd0020 	addiu	sp,sp,32
