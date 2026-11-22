; func wsta_roam_chnl_data_free @ 0x00483f10 size=0x6c
  483f10:	27bdffe0 	addiu	sp,sp,-32
  483f14:	afb00018 	sw	s0,24(sp)
  483f18:	00808021 	move	s0,a0
  483f1c:	10800013 	beqz	a0,0x483f6c
  483f20:	afbf001c 	sw	ra,28(sp)
  483f24:	8c820018 	lw	v0,24(a0)
  483f28:	1040000c 	beqz	v0,0x483f5c
  483f2c:	02002021 	move	a0,s0
  483f30:	8c440004 	lw	a0,4(v0)
  483f34:	10800005 	beqz	a0,0x483f4c
  483f38:	00000000 	nop
  483f3c:	0c101f7c 	jal	0x407df0
  483f40:	00000000 	nop
  483f44:	8e020018 	lw	v0,24(s0)
  483f48:	ac400004 	sw	zero,4(v0)
  483f4c:	0c101f7c 	jal	0x407df0
  483f50:	8e040018 	lw	a0,24(s0)
  483f54:	ae000018 	sw	zero,24(s0)
  483f58:	02002021 	move	a0,s0
  483f5c:	8fbf001c 	lw	ra,28(sp)
  483f60:	8fb00018 	lw	s0,24(sp)
  483f64:	08101f7c 	j	0x407df0
  483f68:	27bd0020 	addiu	sp,sp,32
  483f6c:	8fbf001c 	lw	ra,28(sp)
  483f70:	8fb00018 	lw	s0,24(sp)
  483f74:	03e00008 	jr	ra
  483f78:	27bd0020 	addiu	sp,sp,32
