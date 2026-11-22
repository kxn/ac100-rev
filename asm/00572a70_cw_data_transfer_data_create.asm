; func cw_data_transfer_data_create @ 0x00572a70 size=0x178
  572a70:	27bdffd8 	addiu	sp,sp,-40
  572a74:	24050008 	li	a1,8
  572a78:	afb10020 	sw	s1,32(sp)
  572a7c:	afb0001c 	sw	s0,28(sp)
  572a80:	afbf0024 	sw	ra,36(sp)
  572a84:	0c15c8cc 	jal	0x572330
  572a88:	00808021 	move	s0,a0
  572a8c:	10400027 	beqz	v0,0x572b2c
  572a90:	00408821 	move	s1,v0
  572a94:	ac400004 	sw	zero,4(v0)
  572a98:	96050002 	lhu	a1,2(s0)
  572a9c:	50a00009 	beqzl	a1,0x572ac4
  572aa0:	96250002 	lhu	a1,2(s1)
  572aa4:	8e040004 	lw	a0,4(s0)
  572aa8:	50800006 	beqzl	a0,0x572ac4
  572aac:	96250002 	lhu	a1,2(s1)
  572ab0:	0c15c8cc 	jal	0x572330
  572ab4:	00000000 	nop
  572ab8:	10400038 	beqz	v0,0x572b9c
  572abc:	ae220004 	sw	v0,4(s1)
  572ac0:	96250002 	lhu	a1,2(s1)
  572ac4:	2404000d 	li	a0,13
  572ac8:	02203021 	move	a2,s1
  572acc:	24a50004 	addiu	a1,a1,4
  572ad0:	0c15c943 	jal	0x57250c
  572ad4:	30a5ffff 	andi	a1,a1,0xffff
  572ad8:	10400007 	beqz	v0,0x572af8
  572adc:	00408021 	move	s0,v0
  572ae0:	8fbf0024 	lw	ra,36(sp)
  572ae4:	02001021 	move	v0,s0
  572ae8:	8fb10020 	lw	s1,32(sp)
  572aec:	8fb0001c 	lw	s0,28(sp)
  572af0:	03e00008 	jr	ra
  572af4:	27bd0028 	addiu	sp,sp,40
  572af8:	3c020075 	lui	v0,0x75
  572afc:	8c42cf58 	lw	v0,-12456(v0)
  572b00:	1440001a 	bnez	v0,0x572b6c
  572b04:	00000000 	nop
  572b08:	8e240004 	lw	a0,4(s1)
  572b0c:	10800003 	beqz	a0,0x572b1c
  572b10:	00000000 	nop
  572b14:	0c101f7c 	jal	0x407df0
  572b18:	00000000 	nop
  572b1c:	0c101f7c 	jal	0x407df0
  572b20:	02202021 	move	a0,s1
  572b24:	0815cab9 	j	0x572ae4
  572b28:	8fbf0024 	lw	ra,36(sp)
  572b2c:	3c020075 	lui	v0,0x75
  572b30:	8c42cf58 	lw	v0,-12456(v0)
  572b34:	1040ffea 	beqz	v0,0x572ae0
  572b38:	00008021 	move	s0,zero
  572b3c:	0c16276a 	jal	0x589da8
  572b40:	00000000 	nop
  572b44:	5040ffe7 	beqzl	v0,0x572ae4
  572b48:	8fbf0024 	lw	ra,36(sp)
  572b4c:	3c04006d 	lui	a0,0x6d
  572b50:	3c05006e 	lui	a1,0x6e
  572b54:	248434fc 	addiu	a0,a0,13564
  572b58:	24a58110 	addiu	a1,a1,-32496
  572b5c:	0c101b74 	jal	0x406dd0
  572b60:	240600da 	li	a2,218
  572b64:	0815cab9 	j	0x572ae4
  572b68:	8fbf0024 	lw	ra,36(sp)
  572b6c:	0c16276a 	jal	0x589da8
  572b70:	00000000 	nop
  572b74:	5040ffe5 	beqzl	v0,0x572b0c
  572b78:	8e240004 	lw	a0,4(s1)
  572b7c:	3c04006d 	lui	a0,0x6d
  572b80:	3c05006e 	lui	a1,0x6e
  572b84:	24843580 	addiu	a0,a0,13696
  572b88:	24a58110 	addiu	a1,a1,-32496
  572b8c:	0c101b74 	jal	0x406dd0
  572b90:	240600ef 	li	a2,239
  572b94:	0815cac3 	j	0x572b0c
  572b98:	8e240004 	lw	a0,4(s1)
  572b9c:	3c020075 	lui	v0,0x75
  572ba0:	8c42cf58 	lw	v0,-12456(v0)
  572ba4:	14400005 	bnez	v0,0x572bbc
  572ba8:	00000000 	nop
  572bac:	0c101f7c 	jal	0x407df0
  572bb0:	02202021 	move	a0,s1
  572bb4:	0815cab8 	j	0x572ae0
  572bb8:	00008021 	move	s0,zero
  572bbc:	0c16276a 	jal	0x589da8
  572bc0:	00000000 	nop
  572bc4:	1040fff9 	beqz	v0,0x572bac
  572bc8:	3c04006e 	lui	a0,0x6e
  572bcc:	3c05006e 	lui	a1,0x6e
  572bd0:	24848050 	addiu	a0,a0,-32688
  572bd4:	24a58110 	addiu	a1,a1,-32496
  572bd8:	0c101b74 	jal	0x406dd0
  572bdc:	240600e5 	li	a2,229
  572be0:	0815caeb 	j	0x572bac
  572be4:	00000000 	nop
