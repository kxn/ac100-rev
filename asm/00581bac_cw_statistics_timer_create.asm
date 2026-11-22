; func cw_statistics_timer_create @ 0x00581bac size=0xdc
  581bac:	27bdffd8 	addiu	sp,sp,-40
  581bb0:	24050002 	li	a1,2
  581bb4:	afb0001c 	sw	s0,28(sp)
  581bb8:	afbf0024 	sw	ra,36(sp)
  581bbc:	0c15c8cc 	jal	0x572330
  581bc0:	afb10020 	sw	s1,32(sp)
  581bc4:	1040000d 	beqz	v0,0x581bfc
  581bc8:	00408021 	move	s0,v0
  581bcc:	24040024 	li	a0,36
  581bd0:	24050002 	li	a1,2
  581bd4:	0c15c943 	jal	0x57250c
  581bd8:	00403021 	move	a2,v0
  581bdc:	10400017 	beqz	v0,0x581c3c
  581be0:	00408821 	move	s1,v0
  581be4:	8fbf0024 	lw	ra,36(sp)
  581be8:	02201021 	move	v0,s1
  581bec:	8fb10020 	lw	s1,32(sp)
  581bf0:	8fb0001c 	lw	s0,28(sp)
  581bf4:	03e00008 	jr	ra
  581bf8:	27bd0028 	addiu	sp,sp,40
  581bfc:	3c020075 	lui	v0,0x75
  581c00:	8c42cf58 	lw	v0,-12456(v0)
  581c04:	1040fff7 	beqz	v0,0x581be4
  581c08:	00008821 	move	s1,zero
  581c0c:	0c16276a 	jal	0x589da8
  581c10:	00000000 	nop
  581c14:	5040fff4 	beqzl	v0,0x581be8
  581c18:	8fbf0024 	lw	ra,36(sp)
  581c1c:	3c04006d 	lui	a0,0x6d
  581c20:	3c05006e 	lui	a1,0x6e
  581c24:	248434fc 	addiu	a0,a0,13564
  581c28:	24a5bef0 	addiu	a1,a1,-16656
  581c2c:	0c101b74 	jal	0x406dd0
  581c30:	240600a3 	li	a2,163
  581c34:	081606fa 	j	0x581be8
  581c38:	8fbf0024 	lw	ra,36(sp)
  581c3c:	3c020075 	lui	v0,0x75
  581c40:	8c42cf58 	lw	v0,-12456(v0)
  581c44:	14400005 	bnez	v0,0x581c5c
  581c48:	00000000 	nop
  581c4c:	0c101f7c 	jal	0x407df0
  581c50:	02002021 	move	a0,s0
  581c54:	081606fa 	j	0x581be8
  581c58:	8fbf0024 	lw	ra,36(sp)
  581c5c:	0c16276a 	jal	0x589da8
  581c60:	00000000 	nop
  581c64:	1040fff9 	beqz	v0,0x581c4c
  581c68:	3c04006d 	lui	a0,0x6d
  581c6c:	3c05006e 	lui	a1,0x6e
  581c70:	248447f0 	addiu	a0,a0,18416
  581c74:	24a5bef0 	addiu	a1,a1,-16656
  581c78:	0c101b74 	jal	0x406dd0
  581c7c:	240600ab 	li	a2,171
  581c80:	08160713 	j	0x581c4c
  581c84:	00000000 	nop
