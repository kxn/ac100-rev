; func cw_capwap_control_ipv6_address_free @ 0x00570ad8 size=0x3c
  570ad8:	27bdffe0 	addiu	sp,sp,-32
  570adc:	afb00018 	sw	s0,24(sp)
  570ae0:	00808021 	move	s0,a0
  570ae4:	afbf001c 	sw	ra,28(sp)
  570ae8:	8c840010 	lw	a0,16(a0)
  570aec:	10800005 	beqz	a0,0x570b04
  570af0:	8fbf001c 	lw	ra,28(sp)
  570af4:	0c101f7c 	jal	0x407df0
  570af8:	00000000 	nop
  570afc:	ae000010 	sw	zero,16(s0)
  570b00:	8fbf001c 	lw	ra,28(sp)
  570b04:	00001021 	move	v0,zero
  570b08:	8fb00018 	lw	s0,24(sp)
  570b0c:	03e00008 	jr	ra
  570b10:	27bd0020 	addiu	sp,sp,32
