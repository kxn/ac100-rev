; func _apdb_ap_model_phy_info_free @ 0x005f9a44 size=0x60
  5f9a44:	27bdffd8 	addiu	sp,sp,-40
  5f9a48:	afb1001c 	sw	s1,28(sp)
  5f9a4c:	00a08821 	move	s1,a1
  5f9a50:	afbf0024 	sw	ra,36(sp)
  5f9a54:	afb20020 	sw	s2,32(sp)
  5f9a58:	1080000c 	beqz	a0,0x5f9a8c
  5f9a5c:	afb00018 	sw	s0,24(sp)
  5f9a60:	18a0000a 	blez	a1,0x5f9a8c
  5f9a64:	00009021 	move	s2,zero
  5f9a68:	00808021 	move	s0,a0
  5f9a6c:	8e04002c 	lw	a0,44(s0)
  5f9a70:	10800004 	beqz	a0,0x5f9a84
  5f9a74:	26520001 	addiu	s2,s2,1
  5f9a78:	0c101f7c 	jal	0x407df0
  5f9a7c:	00000000 	nop
  5f9a80:	ae00002c 	sw	zero,44(s0)
  5f9a84:	1651fff9 	bne	s2,s1,0x5f9a6c
  5f9a88:	26100038 	addiu	s0,s0,56
  5f9a8c:	8fbf0024 	lw	ra,36(sp)
  5f9a90:	8fb20020 	lw	s2,32(sp)
  5f9a94:	8fb1001c 	lw	s1,28(sp)
  5f9a98:	8fb00018 	lw	s0,24(sp)
  5f9a9c:	03e00008 	jr	ra
  5f9aa0:	27bd0028 	addiu	sp,sp,40
