; func cw_priv_ap_wire_vlan_2_create @ 0x005aa970 size=0xdc
  5aa970:	27bdffd8 	addiu	sp,sp,-40
  5aa974:	24050008 	li	a1,8
  5aa978:	afb0001c 	sw	s0,28(sp)
  5aa97c:	afbf0024 	sw	ra,36(sp)
  5aa980:	0c15c8cc 	jal	0x572330
  5aa984:	afb10020 	sw	s1,32(sp)
  5aa988:	1040000d 	beqz	v0,0x5aa9c0
  5aa98c:	00408021 	move	s0,v0
  5aa990:	24040043 	li	a0,67
  5aa994:	24050008 	li	a1,8
  5aa998:	0c15c943 	jal	0x57250c
  5aa99c:	00403021 	move	a2,v0
  5aa9a0:	10400017 	beqz	v0,0x5aaa00
  5aa9a4:	00408821 	move	s1,v0
  5aa9a8:	8fbf0024 	lw	ra,36(sp)
  5aa9ac:	02201021 	move	v0,s1
  5aa9b0:	8fb10020 	lw	s1,32(sp)
  5aa9b4:	8fb0001c 	lw	s0,28(sp)
  5aa9b8:	03e00008 	jr	ra
  5aa9bc:	27bd0028 	addiu	sp,sp,40
  5aa9c0:	3c020075 	lui	v0,0x75
  5aa9c4:	8c42cf58 	lw	v0,-12456(v0)
  5aa9c8:	1040fff7 	beqz	v0,0x5aa9a8
  5aa9cc:	00008821 	move	s1,zero
  5aa9d0:	0c16276a 	jal	0x589da8
  5aa9d4:	00000000 	nop
  5aa9d8:	5040fff4 	beqzl	v0,0x5aa9ac
  5aa9dc:	8fbf0024 	lw	ra,36(sp)
  5aa9e0:	3c04006d 	lui	a0,0x6d
  5aa9e4:	3c05006f 	lui	a1,0x6f
  5aa9e8:	248434fc 	addiu	a0,a0,13564
  5aa9ec:	24a594d0 	addiu	a1,a1,-27440
  5aa9f0:	0c101b74 	jal	0x406dd0
  5aa9f4:	240600a9 	li	a2,169
  5aa9f8:	0816aa6b 	j	0x5aa9ac
  5aa9fc:	8fbf0024 	lw	ra,36(sp)
  5aaa00:	3c020075 	lui	v0,0x75
  5aaa04:	8c42cf58 	lw	v0,-12456(v0)
  5aaa08:	14400005 	bnez	v0,0x5aaa20
  5aaa0c:	00000000 	nop
  5aaa10:	0c101f7c 	jal	0x407df0
  5aaa14:	02002021 	move	a0,s0
  5aaa18:	0816aa6b 	j	0x5aa9ac
  5aaa1c:	8fbf0024 	lw	ra,36(sp)
  5aaa20:	0c16276a 	jal	0x589da8
  5aaa24:	00000000 	nop
  5aaa28:	1040fff9 	beqz	v0,0x5aaa10
  5aaa2c:	3c04006d 	lui	a0,0x6d
  5aaa30:	3c05006f 	lui	a1,0x6f
  5aaa34:	248447f0 	addiu	a0,a0,18416
  5aaa38:	24a594d0 	addiu	a1,a1,-27440
  5aaa3c:	0c101b74 	jal	0x406dd0
  5aaa40:	240600b1 	li	a2,177
  5aaa44:	0816aa84 	j	0x5aaa10
  5aaa48:	00000000 	nop
