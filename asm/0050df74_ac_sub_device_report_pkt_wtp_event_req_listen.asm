; func ac_sub_device_report_pkt_wtp_event_req_listen @ 0x0050df74 size=0x94
  50df74:	27bdffd8 	addiu	sp,sp,-40
  50df78:	afb0001c 	sw	s0,28(sp)
  50df7c:	00a08021 	move	s0,a1
  50df80:	24050080 	li	a1,128
  50df84:	afb10020 	sw	s1,32(sp)
  50df88:	afbf0024 	sw	ra,36(sp)
  50df8c:	0c160c45 	jal	0x583114
  50df90:	00808821 	move	s1,a0
  50df94:	10400009 	beqz	v0,0x50dfbc
  50df98:	00402021 	move	a0,v0
  50df9c:	0c143038 	jal	0x50c0e0
  50dfa0:	02002821 	move	a1,s0
  50dfa4:	8fbf0024 	lw	ra,36(sp)
  50dfa8:	00001021 	move	v0,zero
  50dfac:	8fb10020 	lw	s1,32(sp)
  50dfb0:	8fb0001c 	lw	s0,28(sp)
  50dfb4:	03e00008 	jr	ra
  50dfb8:	27bd0028 	addiu	sp,sp,40
  50dfbc:	24050083 	li	a1,131
  50dfc0:	0c160c45 	jal	0x583114
  50dfc4:	02202021 	move	a0,s1
  50dfc8:	10400005 	beqz	v0,0x50dfe0
  50dfcc:	00402021 	move	a0,v0
  50dfd0:	0c14353b 	jal	0x50d4ec
  50dfd4:	02002821 	move	a1,s0
  50dfd8:	081437e9 	j	0x50dfa4
  50dfdc:	00000000 	nop
  50dfe0:	240500a5 	li	a1,165
  50dfe4:	0c160c45 	jal	0x583114
  50dfe8:	02202021 	move	a0,s1
  50dfec:	1040ffed 	beqz	v0,0x50dfa4
  50dff0:	00402021 	move	a0,v0
  50dff4:	02202821 	move	a1,s1
  50dff8:	0c144662 	jal	0x511988
  50dffc:	02003021 	move	a2,s0
  50e000:	081437e9 	j	0x50dfa4
  50e004:	00000000 	nop
