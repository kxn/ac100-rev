; func _ac_passthrough_response_clean_all_aps_one_hash_node @ 0x0050ce40 size=0x90
  50ce40:	27bdffd8 	addiu	sp,sp,-40
  50ce44:	afb10020 	sw	s1,32(sp)
  50ce48:	00808821 	move	s1,a0
  50ce4c:	afbf0024 	sw	ra,36(sp)
  50ce50:	10a00016 	beqz	a1,0x50ceac
  50ce54:	afb0001c 	sw	s0,28(sp)
  50ce58:	8ca50000 	lw	a1,0(a1)
  50ce5c:	2402ffff 	li	v0,-1
  50ce60:	10a20017 	beq	a1,v0,0x50cec0
  50ce64:	00000000 	nop
  50ce68:	0c143363 	jal	0x50cd8c
  50ce6c:	00000000 	nop
  50ce70:	1040000e 	beqz	v0,0x50ceac
  50ce74:	00408021 	move	s0,v0
  50ce78:	0c102140 	jal	0x408500
  50ce7c:	00402021 	move	a0,v0
  50ce80:	8e040018 	lw	a0,24(s0)
  50ce84:	10800004 	beqz	a0,0x50ce98
  50ce88:	00000000 	nop
  50ce8c:	0c101f7c 	jal	0x407df0
  50ce90:	00000000 	nop
  50ce94:	ae000018 	sw	zero,24(s0)
  50ce98:	0c101f7c 	jal	0x407df0
  50ce9c:	02002021 	move	a0,s0
  50cea0:	8e220000 	lw	v0,0(s1)
  50cea4:	2442ffff 	addiu	v0,v0,-1
  50cea8:	ae220000 	sw	v0,0(s1)
  50ceac:	8fbf0024 	lw	ra,36(sp)
  50ceb0:	8fb10020 	lw	s1,32(sp)
  50ceb4:	8fb0001c 	lw	s0,28(sp)
  50ceb8:	03e00008 	jr	ra
  50cebc:	27bd0028 	addiu	sp,sp,40
  50cec0:	0c1432af 	jal	0x50cabc
  50cec4:	00000000 	nop
  50cec8:	081433ab 	j	0x50ceac
  50cecc:	ae200000 	sw	zero,0(s1)
