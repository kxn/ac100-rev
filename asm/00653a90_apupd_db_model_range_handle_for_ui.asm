; func apupd_db_model_range_handle_for_ui @ 0x00653a90 size=0x12c
  653a90:	27bdffd0 	addiu	sp,sp,-48
  653a94:	afb00018 	sw	s0,24(sp)
  653a98:	3c10007d 	lui	s0,0x7d
  653a9c:	afb40028 	sw	s4,40(sp)
  653aa0:	00a0a021 	move	s4,a1
  653aa4:	afb20020 	sw	s2,32(sp)
  653aa8:	afbf002c 	sw	ra,44(sp)
  653aac:	afb30024 	sw	s3,36(sp)
  653ab0:	afb1001c 	sw	s1,28(sp)
  653ab4:	8e02c798 	lw	v0,-14440(s0)
  653ab8:	1040002f 	beqz	v0,0x653b78
  653abc:	00809021 	move	s2,a0
  653ac0:	10800020 	beqz	a0,0x653b44
  653ac4:	3c02007d 	lui	v0,0x7d
  653ac8:	3c11007d 	lui	s1,0x7d
  653acc:	2405ffff 	li	a1,-1
  653ad0:	02209821 	move	s3,s1
  653ad4:	0c1020b4 	jal	0x4082d0
  653ad8:	8e24c778 	lw	a0,-14472(s1)
  653adc:	0c10206c 	jal	0x4081b0
  653ae0:	8e04c798 	lw	a0,-14440(s0)
  653ae4:	00408021 	move	s0,v0
  653ae8:	1200000b 	beqz	s0,0x653b18
  653aec:	00000000 	nop
  653af0:	0c1021a0 	jal	0x408680
  653af4:	02002021 	move	a0,s0
  653af8:	2604fff4 	addiu	a0,s0,-12
  653afc:	00408821 	move	s1,v0
  653b00:	02802821 	move	a1,s4
  653b04:	0240c821 	move	t9,s2
  653b08:	0320f809 	jalr	t9
  653b0c:	02208021 	move	s0,s1
  653b10:	1600fff7 	bnez	s0,0x653af0
  653b14:	00000000 	nop
  653b18:	0c101fcc 	jal	0x407f30
  653b1c:	8e64c778 	lw	a0,-14472(s3)
  653b20:	8fbf002c 	lw	ra,44(sp)
  653b24:	02001021 	move	v0,s0
  653b28:	8fb40028 	lw	s4,40(sp)
  653b2c:	8fb30024 	lw	s3,36(sp)
  653b30:	8fb20020 	lw	s2,32(sp)
  653b34:	8fb1001c 	lw	s1,28(sp)
  653b38:	8fb00018 	lw	s0,24(sp)
  653b3c:	03e00008 	jr	ra
  653b40:	27bd0030 	addiu	sp,sp,48
  653b44:	8c42c758 	lw	v0,-14504(v0)
  653b48:	1040fff5 	beqz	v0,0x653b20
  653b4c:	00008021 	move	s0,zero
  653b50:	0c16276a 	jal	0x589da8
  653b54:	00000000 	nop
  653b58:	1040fff2 	beqz	v0,0x653b24
  653b5c:	8fbf002c 	lw	ra,44(sp)
  653b60:	3c040071 	lui	a0,0x71
  653b64:	3c050072 	lui	a1,0x72
  653b68:	24846d00 	addiu	a0,a0,27904
  653b6c:	24a5a3f8 	addiu	a1,a1,-23560
  653b70:	08194eeb 	j	0x653bac
  653b74:	24061dd9 	li	a2,7641
  653b78:	3c020076 	lui	v0,0x76
  653b7c:	8c428c08 	lw	v0,-29688(v0)
  653b80:	1040ffe7 	beqz	v0,0x653b20
  653b84:	2410ffff 	li	s0,-1
  653b88:	0c16276a 	jal	0x589da8
  653b8c:	00000000 	nop
  653b90:	1040ffe4 	beqz	v0,0x653b24
  653b94:	8fbf002c 	lw	ra,44(sp)
  653b98:	3c040071 	lui	a0,0x71
  653b9c:	3c050072 	lui	a1,0x72
  653ba0:	24840720 	addiu	a0,a0,1824
  653ba4:	24a5a3f8 	addiu	a1,a1,-23560
  653ba8:	24061dd2 	li	a2,7634
  653bac:	0c101b74 	jal	0x406dd0
  653bb0:	00000000 	nop
  653bb4:	08194ec8 	j	0x653b20
  653bb8:	00000000 	nop
