; func _uac_wserv_packet_type_set_by_wlan_id @ 0x005d8a58 size=0x10c
  5d8a58:	27bdffd0 	addiu	sp,sp,-48
  5d8a5c:	afb30028 	sw	s3,40(sp)
  5d8a60:	00e09821 	move	s3,a3
  5d8a64:	afb20024 	sw	s2,36(sp)
  5d8a68:	00809021 	move	s2,a0
  5d8a6c:	afb10020 	sw	s1,32(sp)
  5d8a70:	00a08821 	move	s1,a1
  5d8a74:	afb0001c 	sw	s0,28(sp)
  5d8a78:	00c08021 	move	s0,a2
  5d8a7c:	04800006 	bltz	a0,0x5d8a98
  5d8a80:	afbf002c 	sw	ra,44(sp)
  5d8a84:	0c1506a9 	jal	0x541aa4
  5d8a88:	00000000 	nop
  5d8a8c:	0242102a 	slt	v0,s2,v0
  5d8a90:	1440000c 	bnez	v0,0x5d8ac4
  5d8a94:	00000000 	nop
  5d8a98:	3c02007d 	lui	v0,0x7d
  5d8a9c:	8c42bee4 	lw	v0,-16668(v0)
  5d8aa0:	14400020 	bnez	v0,0x5d8b24
  5d8aa4:	00000000 	nop
  5d8aa8:	8fbf002c 	lw	ra,44(sp)
  5d8aac:	8fb30028 	lw	s3,40(sp)
  5d8ab0:	8fb20024 	lw	s2,36(sp)
  5d8ab4:	8fb10020 	lw	s1,32(sp)
  5d8ab8:	8fb0001c 	lw	s0,28(sp)
  5d8abc:	03e00008 	jr	ra
  5d8ac0:	27bd0030 	addiu	sp,sp,48
  5d8ac4:	0620fff5 	bltz	s1,0x5d8a9c
  5d8ac8:	3c02007d 	lui	v0,0x7d
  5d8acc:	0c1868f4 	jal	0x61a3d0
  5d8ad0:	00000000 	nop
  5d8ad4:	0222102b 	sltu	v0,s1,v0
  5d8ad8:	1040fff0 	beqz	v0,0x5d8a9c
  5d8adc:	3c02007d 	lui	v0,0x7d
  5d8ae0:	0c1868f7 	jal	0x61a3dc
  5d8ae4:	00000000 	nop
  5d8ae8:	0202102b 	sltu	v0,s0,v0
  5d8aec:	1040ffeb 	beqz	v0,0x5d8a9c
  5d8af0:	3c02007d 	lui	v0,0x7d
  5d8af4:	2403000c 	li	v1,12
  5d8af8:	3c020076 	lui	v0,0x76
  5d8afc:	72439002 	mul	s2,s2,v1
  5d8b00:	00118880 	sll	s1,s1,0x2
  5d8b04:	8c4298e8 	lw	v0,-26392(v0)
  5d8b08:	00529021 	addu	s2,v0,s2
  5d8b0c:	8e420008 	lw	v0,8(s2)
  5d8b10:	00518821 	addu	s1,v0,s1
  5d8b14:	8e220000 	lw	v0,0(s1)
  5d8b18:	00508021 	addu	s0,v0,s0
  5d8b1c:	081762aa 	j	0x5d8aa8
  5d8b20:	a2130000 	sb	s3,0(s0)
  5d8b24:	0c16276a 	jal	0x589da8
  5d8b28:	00000000 	nop
  5d8b2c:	1040ffdf 	beqz	v0,0x5d8aac
  5d8b30:	8fbf002c 	lw	ra,44(sp)
  5d8b34:	3c04006f 	lui	a0,0x6f
  5d8b38:	3c05006f 	lui	a1,0x6f
  5d8b3c:	8fb30028 	lw	s3,40(sp)
  5d8b40:	02003821 	move	a3,s0
  5d8b44:	8fb20024 	lw	s2,36(sp)
  5d8b48:	8fb10020 	lw	s1,32(sp)
  5d8b4c:	24843648 	addiu	a0,a0,13896
  5d8b50:	8fb0001c 	lw	s0,28(sp)
  5d8b54:	24a56c88 	addiu	a1,a1,27784
  5d8b58:	240600bb 	li	a2,187
  5d8b5c:	08101b74 	j	0x406dd0
  5d8b60:	27bd0030 	addiu	sp,sp,48
