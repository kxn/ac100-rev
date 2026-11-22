; func rdmngr_ele_set_adm_state @ 0x00612f50 size=0xb8
  612f50:	27bdffd8 	addiu	sp,sp,-40
  612f54:	00003821 	move	a3,zero
  612f58:	a3a40018 	sb	a0,24(sp)
  612f5c:	00a02021 	move	a0,a1
  612f60:	a3a60019 	sb	a2,25(sp)
  612f64:	2405001f 	li	a1,31
  612f68:	27a60018 	addiu	a2,sp,24
  612f6c:	afbf0024 	sw	ra,36(sp)
  612f70:	0c1621be 	jal	0x5886f8
  612f74:	afb00020 	sw	s0,32(sp)
  612f78:	1040000e 	beqz	v0,0x612fb4
  612f7c:	3c02007d 	lui	v0,0x7d
  612f80:	3c020075 	lui	v0,0x75
  612f84:	8c42feb4 	lw	v0,-332(v0)
  612f88:	10400005 	beqz	v0,0x612fa0
  612f8c:	2410ffff 	li	s0,-1
  612f90:	0c16276a 	jal	0x589da8
  612f94:	00000000 	nop
  612f98:	14400016 	bnez	v0,0x612ff4
  612f9c:	3c040070 	lui	a0,0x70
  612fa0:	8fbf0024 	lw	ra,36(sp)
  612fa4:	02001021 	move	v0,s0
  612fa8:	8fb00020 	lw	s0,32(sp)
  612fac:	03e00008 	jr	ra
  612fb0:	27bd0028 	addiu	sp,sp,40
  612fb4:	8c42c63c 	lw	v0,-14788(v0)
  612fb8:	1040fff9 	beqz	v0,0x612fa0
  612fbc:	00008021 	move	s0,zero
  612fc0:	0c16276a 	jal	0x589da8
  612fc4:	00000000 	nop
  612fc8:	5040fff6 	beqzl	v0,0x612fa4
  612fcc:	8fbf0024 	lw	ra,36(sp)
  612fd0:	3c040070 	lui	a0,0x70
  612fd4:	3c050070 	lui	a1,0x70
  612fd8:	248454e8 	addiu	a0,a0,21736
  612fdc:	24a57728 	addiu	a1,a1,30504
  612fe0:	240601c2 	li	a2,450
  612fe4:	0c101b74 	jal	0x406dd0
  612fe8:	00000000 	nop
  612fec:	08184be9 	j	0x612fa4
  612ff0:	8fbf0024 	lw	ra,36(sp)
  612ff4:	3c050070 	lui	a1,0x70
  612ff8:	248454a8 	addiu	a0,a0,21672
  612ffc:	24a57728 	addiu	a1,a1,30504
  613000:	08184bf9 	j	0x612fe4
  613004:	240601bd 	li	a2,445
