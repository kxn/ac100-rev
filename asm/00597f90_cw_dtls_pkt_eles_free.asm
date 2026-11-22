; func cw_dtls_pkt_eles_free @ 0x00597f90 size=0x68
  597f90:	27bdffd8 	addiu	sp,sp,-40
  597f94:	afb10020 	sw	s1,32(sp)
  597f98:	24910004 	addiu	s1,a0,4
  597f9c:	afbf0024 	sw	ra,36(sp)
  597fa0:	1480000c 	bnez	a0,0x597fd4
  597fa4:	afb0001c 	sw	s0,28(sp)
  597fa8:	08165ffa 	j	0x597fe8
  597fac:	8fbf0024 	lw	ra,36(sp)
  597fb0:	0c102140 	jal	0x408500
  597fb4:	02002021 	move	a0,s0
  597fb8:	8e04001c 	lw	a0,28(s0)
  597fbc:	10800003 	beqz	a0,0x597fcc
  597fc0:	00000000 	nop
  597fc4:	0c101f7c 	jal	0x407df0
  597fc8:	00000000 	nop
  597fcc:	0c101f7c 	jal	0x407df0
  597fd0:	02002021 	move	a0,s0
  597fd4:	0c10206c 	jal	0x4081b0
  597fd8:	02202021 	move	a0,s1
  597fdc:	1440fff4 	bnez	v0,0x597fb0
  597fe0:	00408021 	move	s0,v0
  597fe4:	8fbf0024 	lw	ra,36(sp)
  597fe8:	8fb10020 	lw	s1,32(sp)
  597fec:	8fb0001c 	lw	s0,28(sp)
  597ff0:	03e00008 	jr	ra
  597ff4:	27bd0028 	addiu	sp,sp,40
