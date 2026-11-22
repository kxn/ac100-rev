; func cw_priv_lldp_report_free @ 0x005b4fd0 size=0x48
  5b4fd0:	27bdffe0 	addiu	sp,sp,-32
  5b4fd4:	afbf001c 	sw	ra,28(sp)
  5b4fd8:	afb00018 	sw	s0,24(sp)
  5b4fdc:	8c900010 	lw	s0,16(a0)
  5b4fe0:	12000009 	beqz	s0,0x5b5008
  5b4fe4:	8fbf001c 	lw	ra,28(sp)
  5b4fe8:	8e040004 	lw	a0,4(s0)
  5b4fec:	10800003 	beqz	a0,0x5b4ffc
  5b4ff0:	00000000 	nop
  5b4ff4:	0c101f7c 	jal	0x407df0
  5b4ff8:	00000000 	nop
  5b4ffc:	0c101f7c 	jal	0x407df0
  5b5000:	02002021 	move	a0,s0
  5b5004:	8fbf001c 	lw	ra,28(sp)
  5b5008:	00001021 	move	v0,zero
  5b500c:	8fb00018 	lw	s0,24(sp)
  5b5010:	03e00008 	jr	ra
  5b5014:	27bd0020 	addiu	sp,sp,32
