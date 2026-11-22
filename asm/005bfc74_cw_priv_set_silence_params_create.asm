; func cw_priv_set_silence_params_create @ 0x005bfc74 size=0xf0
  5bfc74:	27bdffd8 	addiu	sp,sp,-40
  5bfc78:	24050004 	li	a1,4
  5bfc7c:	afb10020 	sw	s1,32(sp)
  5bfc80:	afb0001c 	sw	s0,28(sp)
  5bfc84:	afbf0024 	sw	ra,36(sp)
  5bfc88:	0c15c8cc 	jal	0x572330
  5bfc8c:	00808021 	move	s0,a0
  5bfc90:	10400011 	beqz	v0,0x5bfcd8
  5bfc94:	00408821 	move	s1,v0
  5bfc98:	92020000 	lbu	v0,0(s0)
  5bfc9c:	2404009d 	li	a0,157
  5bfca0:	24050003 	li	a1,3
  5bfca4:	02203021 	move	a2,s1
  5bfca8:	a2220000 	sb	v0,0(s1)
  5bfcac:	96020002 	lhu	v0,2(s0)
  5bfcb0:	0c15c943 	jal	0x57250c
  5bfcb4:	a6220002 	sh	v0,2(s1)
  5bfcb8:	10400017 	beqz	v0,0x5bfd18
  5bfcbc:	00408021 	move	s0,v0
  5bfcc0:	8fbf0024 	lw	ra,36(sp)
  5bfcc4:	02001021 	move	v0,s0
  5bfcc8:	8fb10020 	lw	s1,32(sp)
  5bfccc:	8fb0001c 	lw	s0,28(sp)
  5bfcd0:	03e00008 	jr	ra
  5bfcd4:	27bd0028 	addiu	sp,sp,40
  5bfcd8:	3c020075 	lui	v0,0x75
  5bfcdc:	8c42cf58 	lw	v0,-12456(v0)
  5bfce0:	1040fff7 	beqz	v0,0x5bfcc0
  5bfce4:	00008021 	move	s0,zero
  5bfce8:	0c16276a 	jal	0x589da8
  5bfcec:	00000000 	nop
  5bfcf0:	5040fff4 	beqzl	v0,0x5bfcc4
  5bfcf4:	8fbf0024 	lw	ra,36(sp)
  5bfcf8:	3c04006d 	lui	a0,0x6d
  5bfcfc:	3c05006f 	lui	a1,0x6f
  5bfd00:	248434fc 	addiu	a0,a0,13564
  5bfd04:	24a5eee0 	addiu	a1,a1,-4384
  5bfd08:	0c101b74 	jal	0x406dd0
  5bfd0c:	240600a6 	li	a2,166
  5bfd10:	0816ff31 	j	0x5bfcc4
  5bfd14:	8fbf0024 	lw	ra,36(sp)
  5bfd18:	3c020075 	lui	v0,0x75
  5bfd1c:	8c42cf58 	lw	v0,-12456(v0)
  5bfd20:	14400005 	bnez	v0,0x5bfd38
  5bfd24:	00000000 	nop
  5bfd28:	0c101f7c 	jal	0x407df0
  5bfd2c:	02202021 	move	a0,s1
  5bfd30:	0816ff31 	j	0x5bfcc4
  5bfd34:	8fbf0024 	lw	ra,36(sp)
  5bfd38:	0c16276a 	jal	0x589da8
  5bfd3c:	00000000 	nop
  5bfd40:	1040fff9 	beqz	v0,0x5bfd28
  5bfd44:	3c04006d 	lui	a0,0x6d
  5bfd48:	3c05006f 	lui	a1,0x6f
  5bfd4c:	248447f0 	addiu	a0,a0,18416
  5bfd50:	24a5eee0 	addiu	a1,a1,-4384
  5bfd54:	0c101b74 	jal	0x406dd0
  5bfd58:	240600b1 	li	a2,177
  5bfd5c:	0816ff4a 	j	0x5bfd28
  5bfd60:	00000000 	nop
	...
