; func cw_priv_ap_user_create @ 0x005a9b4c size=0xdc
  5a9b4c:	27bdffd8 	addiu	sp,sp,-40
  5a9b50:	24050080 	li	a1,128
  5a9b54:	afb0001c 	sw	s0,28(sp)
  5a9b58:	afbf0024 	sw	ra,36(sp)
  5a9b5c:	0c15c8cc 	jal	0x572330
  5a9b60:	afb10020 	sw	s1,32(sp)
  5a9b64:	1040000d 	beqz	v0,0x5a9b9c
  5a9b68:	00408021 	move	s0,v0
  5a9b6c:	2404003d 	li	a0,61
  5a9b70:	24050080 	li	a1,128
  5a9b74:	0c15c943 	jal	0x57250c
  5a9b78:	00403021 	move	a2,v0
  5a9b7c:	10400017 	beqz	v0,0x5a9bdc
  5a9b80:	00408821 	move	s1,v0
  5a9b84:	8fbf0024 	lw	ra,36(sp)
  5a9b88:	02201021 	move	v0,s1
  5a9b8c:	8fb10020 	lw	s1,32(sp)
  5a9b90:	8fb0001c 	lw	s0,28(sp)
  5a9b94:	03e00008 	jr	ra
  5a9b98:	27bd0028 	addiu	sp,sp,40
  5a9b9c:	3c020075 	lui	v0,0x75
  5a9ba0:	8c42cf58 	lw	v0,-12456(v0)
  5a9ba4:	1040fff7 	beqz	v0,0x5a9b84
  5a9ba8:	00008821 	move	s1,zero
  5a9bac:	0c16276a 	jal	0x589da8
  5a9bb0:	00000000 	nop
  5a9bb4:	5040fff4 	beqzl	v0,0x5a9b88
  5a9bb8:	8fbf0024 	lw	ra,36(sp)
  5a9bbc:	3c04006d 	lui	a0,0x6d
  5a9bc0:	3c05006f 	lui	a1,0x6f
  5a9bc4:	248434fc 	addiu	a0,a0,13564
  5a9bc8:	24a58ff0 	addiu	a1,a1,-28688
  5a9bcc:	0c101b74 	jal	0x406dd0
  5a9bd0:	240600b1 	li	a2,177
  5a9bd4:	0816a6e2 	j	0x5a9b88
  5a9bd8:	8fbf0024 	lw	ra,36(sp)
  5a9bdc:	3c020075 	lui	v0,0x75
  5a9be0:	8c42cf58 	lw	v0,-12456(v0)
  5a9be4:	14400005 	bnez	v0,0x5a9bfc
  5a9be8:	00000000 	nop
  5a9bec:	0c101f7c 	jal	0x407df0
  5a9bf0:	02002021 	move	a0,s0
  5a9bf4:	0816a6e2 	j	0x5a9b88
  5a9bf8:	8fbf0024 	lw	ra,36(sp)
  5a9bfc:	0c16276a 	jal	0x589da8
  5a9c00:	00000000 	nop
  5a9c04:	1040fff9 	beqz	v0,0x5a9bec
  5a9c08:	3c04006d 	lui	a0,0x6d
  5a9c0c:	3c05006f 	lui	a1,0x6f
  5a9c10:	248447f0 	addiu	a0,a0,18416
  5a9c14:	24a58ff0 	addiu	a1,a1,-28688
  5a9c18:	0c101b74 	jal	0x406dd0
  5a9c1c:	240600b9 	li	a2,185
  5a9c20:	0816a6fb 	j	0x5a9bec
  5a9c24:	00000000 	nop
