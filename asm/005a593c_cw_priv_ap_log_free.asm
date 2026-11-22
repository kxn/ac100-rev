; func cw_priv_ap_log_free @ 0x005a593c size=0xa4
  5a593c:	27bdffd8 	addiu	sp,sp,-40
  5a5940:	afbf0024 	sw	ra,36(sp)
  5a5944:	afb20020 	sw	s2,32(sp)
  5a5948:	afb1001c 	sw	s1,28(sp)
  5a594c:	afb00018 	sw	s0,24(sp)
  5a5950:	8c900010 	lw	s0,16(a0)
  5a5954:	5200001c 	beqzl	s0,0x5a59c8
  5a5958:	8fbf0024 	lw	ra,36(sp)
  5a595c:	96020000 	lhu	v0,0(s0)
  5a5960:	10400016 	beqz	v0,0x5a59bc
  5a5964:	00000000 	nop
  5a5968:	8e020004 	lw	v0,4(s0)
  5a596c:	10400013 	beqz	v0,0x5a59bc
  5a5970:	00008821 	move	s1,zero
  5a5974:	96020000 	lhu	v0,0(s0)
  5a5978:	0222102a 	slt	v0,s1,v0
  5a597c:	1040000c 	beqz	v0,0x5a59b0
  5a5980:	8e040004 	lw	a0,4(s0)
  5a5984:	001190c0 	sll	s2,s1,0x3
  5a5988:	00922021 	addu	a0,a0,s2
  5a598c:	8c840004 	lw	a0,4(a0)
  5a5990:	1080fff8 	beqz	a0,0x5a5974
  5a5994:	26310001 	addiu	s1,s1,1
  5a5998:	0c101f7c 	jal	0x407df0
  5a599c:	00000000 	nop
  5a59a0:	8e020004 	lw	v0,4(s0)
  5a59a4:	00529021 	addu	s2,v0,s2
  5a59a8:	0816965d 	j	0x5a5974
  5a59ac:	ae400004 	sw	zero,4(s2)
  5a59b0:	0c101f7c 	jal	0x407df0
  5a59b4:	00000000 	nop
  5a59b8:	ae000004 	sw	zero,4(s0)
  5a59bc:	0c101f7c 	jal	0x407df0
  5a59c0:	02002021 	move	a0,s0
  5a59c4:	8fbf0024 	lw	ra,36(sp)
  5a59c8:	00001021 	move	v0,zero
  5a59cc:	8fb20020 	lw	s2,32(sp)
  5a59d0:	8fb1001c 	lw	s1,28(sp)
  5a59d4:	8fb00018 	lw	s0,24(sp)
  5a59d8:	03e00008 	jr	ra
  5a59dc:	27bd0028 	addiu	sp,sp,40
