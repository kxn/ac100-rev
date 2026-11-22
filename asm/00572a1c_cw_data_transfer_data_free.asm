; func cw_data_transfer_data_free @ 0x00572a1c size=0x54
  572a1c:	27bdffd8 	addiu	sp,sp,-40
  572a20:	afb10020 	sw	s1,32(sp)
  572a24:	afbf0024 	sw	ra,36(sp)
  572a28:	afb0001c 	sw	s0,28(sp)
  572a2c:	8c900010 	lw	s0,16(a0)
  572a30:	12000009 	beqz	s0,0x572a58
  572a34:	00808821 	move	s1,a0
  572a38:	8e040004 	lw	a0,4(s0)
  572a3c:	10800003 	beqz	a0,0x572a4c
  572a40:	00000000 	nop
  572a44:	0c101f7c 	jal	0x407df0
  572a48:	00000000 	nop
  572a4c:	0c101f7c 	jal	0x407df0
  572a50:	02002021 	move	a0,s0
  572a54:	ae200010 	sw	zero,16(s1)
  572a58:	8fbf0024 	lw	ra,36(sp)
  572a5c:	00001021 	move	v0,zero
  572a60:	8fb10020 	lw	s1,32(sp)
  572a64:	8fb0001c 	lw	s0,28(sp)
  572a68:	03e00008 	jr	ra
  572a6c:	27bd0028 	addiu	sp,sp,40
