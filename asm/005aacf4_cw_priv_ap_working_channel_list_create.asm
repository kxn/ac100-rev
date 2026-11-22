; func cw_priv_ap_working_channel_list_create @ 0x005aacf4 size=0xdc
  5aacf4:	27bdffd8 	addiu	sp,sp,-40
  5aacf8:	24050018 	li	a1,24
  5aacfc:	afb0001c 	sw	s0,28(sp)
  5aad00:	afbf0024 	sw	ra,36(sp)
  5aad04:	0c15c8cc 	jal	0x572330
  5aad08:	afb10020 	sw	s1,32(sp)
  5aad0c:	1040000d 	beqz	v0,0x5aad44
  5aad10:	00408021 	move	s0,v0
  5aad14:	24040066 	li	a0,102
  5aad18:	24050018 	li	a1,24
  5aad1c:	0c15c943 	jal	0x57250c
  5aad20:	00403021 	move	a2,v0
  5aad24:	10400017 	beqz	v0,0x5aad84
  5aad28:	00408821 	move	s1,v0
  5aad2c:	8fbf0024 	lw	ra,36(sp)
  5aad30:	02201021 	move	v0,s1
  5aad34:	8fb10020 	lw	s1,32(sp)
  5aad38:	8fb0001c 	lw	s0,28(sp)
  5aad3c:	03e00008 	jr	ra
  5aad40:	27bd0028 	addiu	sp,sp,40
  5aad44:	3c020075 	lui	v0,0x75
  5aad48:	8c42cf58 	lw	v0,-12456(v0)
  5aad4c:	1040fff7 	beqz	v0,0x5aad2c
  5aad50:	00008821 	move	s1,zero
  5aad54:	0c16276a 	jal	0x589da8
  5aad58:	00000000 	nop
  5aad5c:	5040fff4 	beqzl	v0,0x5aad30
  5aad60:	8fbf0024 	lw	ra,36(sp)
  5aad64:	3c04006d 	lui	a0,0x6d
  5aad68:	3c05006f 	lui	a1,0x6f
  5aad6c:	248434fc 	addiu	a0,a0,13564
  5aad70:	24a595a0 	addiu	a1,a1,-27232
  5aad74:	0c101b74 	jal	0x406dd0
  5aad78:	240600b4 	li	a2,180
  5aad7c:	0816ab4c 	j	0x5aad30
  5aad80:	8fbf0024 	lw	ra,36(sp)
  5aad84:	3c020075 	lui	v0,0x75
  5aad88:	8c42cf58 	lw	v0,-12456(v0)
  5aad8c:	14400005 	bnez	v0,0x5aada4
  5aad90:	00000000 	nop
  5aad94:	0c101f7c 	jal	0x407df0
  5aad98:	02002021 	move	a0,s0
  5aad9c:	0816ab4c 	j	0x5aad30
  5aada0:	8fbf0024 	lw	ra,36(sp)
  5aada4:	0c16276a 	jal	0x589da8
  5aada8:	00000000 	nop
  5aadac:	1040fff9 	beqz	v0,0x5aad94
  5aadb0:	3c04006d 	lui	a0,0x6d
  5aadb4:	3c05006f 	lui	a1,0x6f
  5aadb8:	248447f0 	addiu	a0,a0,18416
  5aadbc:	24a595a0 	addiu	a1,a1,-27232
  5aadc0:	0c101b74 	jal	0x406dd0
  5aadc4:	240600bc 	li	a2,188
  5aadc8:	0816ab65 	j	0x5aad94
  5aadcc:	00000000 	nop
