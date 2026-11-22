; func cw_priv_data_tunnel_mode_create @ 0x005aef34 size=0xdc
  5aef34:	27bdffd8 	addiu	sp,sp,-40
  5aef38:	24050004 	li	a1,4
  5aef3c:	afb0001c 	sw	s0,28(sp)
  5aef40:	afbf0024 	sw	ra,36(sp)
  5aef44:	0c15c8cc 	jal	0x572330
  5aef48:	afb10020 	sw	s1,32(sp)
  5aef4c:	1040000d 	beqz	v0,0x5aef84
  5aef50:	00408021 	move	s0,v0
  5aef54:	2404001d 	li	a0,29
  5aef58:	24050004 	li	a1,4
  5aef5c:	0c15c943 	jal	0x57250c
  5aef60:	00403021 	move	a2,v0
  5aef64:	10400017 	beqz	v0,0x5aefc4
  5aef68:	00408821 	move	s1,v0
  5aef6c:	8fbf0024 	lw	ra,36(sp)
  5aef70:	02201021 	move	v0,s1
  5aef74:	8fb10020 	lw	s1,32(sp)
  5aef78:	8fb0001c 	lw	s0,28(sp)
  5aef7c:	03e00008 	jr	ra
  5aef80:	27bd0028 	addiu	sp,sp,40
  5aef84:	3c020075 	lui	v0,0x75
  5aef88:	8c42cf58 	lw	v0,-12456(v0)
  5aef8c:	1040fff7 	beqz	v0,0x5aef6c
  5aef90:	00008821 	move	s1,zero
  5aef94:	0c16276a 	jal	0x589da8
  5aef98:	00000000 	nop
  5aef9c:	5040fff4 	beqzl	v0,0x5aef70
  5aefa0:	8fbf0024 	lw	ra,36(sp)
  5aefa4:	3c04006d 	lui	a0,0x6d
  5aefa8:	3c05006f 	lui	a1,0x6f
  5aefac:	248434fc 	addiu	a0,a0,13564
  5aefb0:	24a5a700 	addiu	a1,a1,-22784
  5aefb4:	0c101b74 	jal	0x406dd0
  5aefb8:	240600a3 	li	a2,163
  5aefbc:	0816bbdc 	j	0x5aef70
  5aefc0:	8fbf0024 	lw	ra,36(sp)
  5aefc4:	3c020075 	lui	v0,0x75
  5aefc8:	8c42cf58 	lw	v0,-12456(v0)
  5aefcc:	14400005 	bnez	v0,0x5aefe4
  5aefd0:	00000000 	nop
  5aefd4:	0c101f7c 	jal	0x407df0
  5aefd8:	02002021 	move	a0,s0
  5aefdc:	0816bbdc 	j	0x5aef70
  5aefe0:	8fbf0024 	lw	ra,36(sp)
  5aefe4:	0c16276a 	jal	0x589da8
  5aefe8:	00000000 	nop
  5aefec:	1040fff9 	beqz	v0,0x5aefd4
  5aeff0:	3c04006d 	lui	a0,0x6d
  5aeff4:	3c05006f 	lui	a1,0x6f
  5aeff8:	248447f0 	addiu	a0,a0,18416
  5aeffc:	24a5a700 	addiu	a1,a1,-22784
  5af000:	0c101b74 	jal	0x406dd0
  5af004:	240600ab 	li	a2,171
  5af008:	0816bbf5 	j	0x5aefd4
  5af00c:	00000000 	nop
