; func _uac_rdmngr_rd_chnl_cmp @ 0x00624218 size=0x4c
  624218:	27bdffe0 	addiu	sp,sp,-32
  62421c:	24020001 	li	v0,1
  624220:	afb00018 	sw	s0,24(sp)
  624224:	00808021 	move	s0,a0
  624228:	afbf001c 	sw	ra,28(sp)
  62422c:	12000009 	beqz	s0,0x624254
  624230:	00a02021 	move	a0,a1
  624234:	10a00008 	beqz	a1,0x624258
  624238:	8fbf001c 	lw	ra,28(sp)
  62423c:	0c101db4 	jal	0x4076d0
  624240:	00000000 	nop
  624244:	8603000c 	lh	v1,12(s0)
  624248:	7c021620 	seh	v0,v0
  62424c:	00621826 	xor	v1,v1,v0
  624250:	0003102b 	sltu	v0,zero,v1
  624254:	8fbf001c 	lw	ra,28(sp)
  624258:	8fb00018 	lw	s0,24(sp)
  62425c:	03e00008 	jr	ra
  624260:	27bd0020 	addiu	sp,sp,32
